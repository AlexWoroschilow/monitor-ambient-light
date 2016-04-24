# Copyright 2015 Alex Woroschilow (alex.woroschilow@gmail.com)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
import os
import strutils
import streams
import parseutils
import logging


proc getFileContents(source: string): string =
  if existsFile(source):
    var stream = newFileStream(source, fmRead)
    var content = strip(stream.readAll())
    stream.close()
    return content
  return nil

proc setFileContents(source: string, value: string): bool =
  if existsFile(source):
    var stream = newFileStream(source, fmWrite)
    stream.write(value)
    stream.close()
    return true
  return false


type
  SensorFinder* = object
    path*: string
    prefix*: string

iterator devices*(this: var SensorFinder):string =
  if dirExists(this.path):
    for kind, path in walkDir(this.path):
      if find(path, this.prefix) != -1:
        yield path


type
  SensorAmbientLight* = object
    path*: string
    prefix_name*: string
    prefix_element*: string
    prefix_intensity*: string

proc exists*(this: var SensorAmbientLight):bool {.inline.} =
  var source = joinPath(this.path, this.prefix_element)
  if existsDir(source):
    for kind, path_element in walkDir(source):
      return existsFile(path_element)
  return false

proc intensity*(this: var SensorAmbientLight):int {.inline.} =
  var source = joinPath(this.path, this.prefix_intensity)
  if existsFile(source):
    return parseInt(getFileContents(source))
  return 0

proc enable*(this: var SensorAmbientLight):bool {.inline.} =
  var source = joinPath(this.path, this.prefix_element)
  if existsDir(source):
    for kind, path_element in walkDir(source):
      if find(path_element, "_en") != -1:
        if not parseBool(getFileContents(path_element)):
          return setFileContents(path_element, "1")
  return true


type
  SensorBatteryPower* = object
    path*: string
    prefix_name*: string
    prefix_vendor*: string
    prefix_status*: string
    prefix_power*: string
    prefix_technology*: string
    prefix_present*: string

proc name*(this: var SensorBatteryPower):string {.inline.} =
  var source = join_path(this.path, this.prefix_name)
  if exists_file(source):
    return get_file_contents(source)
  return nil

proc vendor*(this: var SensorBatteryPower):string {.inline.} =
  var source = join_path(this.path, this.prefix_vendor)
  if exists_file(source):
    return get_file_contents(source)
  return nil

proc power*(this: var SensorBatteryPower):float {.inline.} =
  var source = join_path(this.path, this.prefix_power)
  if exists_file(source):
    return parse_int(get_file_contents(source)) / 10000
  return 0

proc exists*(this: var SensorBatteryPower):bool {.inline.} =
  var source = join_path(this.path, this.prefix_present)
  if not exists_file(source):
    return false
  return parse_bool(get_file_contents(source))

proc discharging*(this: var SensorBatteryPower):bool {.inline.} =
  var source = join_path(this.path, this.prefix_status)
  if exists_file(source):
    case to_lower(get_file_contents(source))
      of "discharging":
        return true
      else:
        return false
  return false

proc technology*(this: var SensorBatteryPower):string {.inline.} =
  var source = join_path(this.path, this.prefix_technology)
  if exists_file(source):
    return get_file_contents(source)
  return nil

proc getSensorAmbientLight*(path: string):SensorAmbientLight {.inline.} =
  var finder = SensorFinder(path: path, prefix: "iio:device")
  for device in finder.devices():
    var device_name = join_path(device, "/name")
    if file_exists(device_name):
      if get_file_contents(device_name) == "als":
        return SensorAmbientLight(
          path: device,
          prefix_name: "/name",
          prefix_element: "/scan_elements",
          prefix_intensity: "/in_intensity_both_raw"
        )

proc getSensorBattery*(path: string): SensorBatteryPower =
  var finder = SensorFinder(path: path, prefix: "BAT")
  for device in finder.devices():
    return SensorBatteryPower(
        prefix_name: "/model_name",
        prefix_vendor: "/manufacturer",
        prefix_status: "/status",
        prefix_present: "/present",
        prefix_power: "/power_now",
        prefix_technology: "/technology",
        path: device,
    )
