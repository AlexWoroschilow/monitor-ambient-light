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
  SensorFinder* = object
    path*: string

iterator devices*(this: var SensorFinder):string =
  if dirExists(this.path):
    for kind, path in walkDir(this.path):
      if find(path, "iio:device") != -1:
        yield path

proc device*(this: var SensorFinder, name: string ):string {.inline.} =
  for path in this.devices():
    var source = joinPath(path, "/name")
    if existsFile(source):
      if getFileContents(source) == name:
        return path
  return nil

proc get*(this: var SensorFinder, name: string ):SensorAmbientLight {.inline.} =
  var sensor_path = this.device(name)
  assert(sensor_path != nil, "Sensor path can not be empty")
  return SensorAmbientLight(
    path: sensor_path,
    prefix_name: "/name",
    prefix_element: "/scan_elements",
    prefix_intensity: "/in_intensity_both_raw"
  )
