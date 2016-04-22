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
import parsecfg
import strutils
import streams
import parseutils
import logging

type
  ConfigEntity* = object
    name*: string
    value*: string
    section*: string

proc `section=`*(this: var ConfigEntity, value: string):bool {.inline.} =
  this.section = value

proc `name=`*(this: var ConfigEntity, value: string):bool {.inline.} =
  this.name = value

proc `value=`*(this: var ConfigEntity, value: string):bool {.inline.} =
  this.value = value


type
  ConfigAmbientLight* = object
    path*: string
    timeout*: int
    threshold*: int
    intensity_min*: int
    intensity_max*: int
    backlight_min*: int
    backlight_max*: int

proc get*(this: var ConfigAmbientLight, section: string, name: string):string {.inline.} =
  var stream = newFileStream(this.path, fmRead)
  assert(stream != nil, "Can not read config file stream")
  var parser = CfgParser()
  open(parser, stream, this.path)

  var entity = ConfigEntity()

  while true:
    var expression = next(parser)
    case expression.kind
      of cfgEof:
        break
      of cfgSectionStart:
        if expression.section == section:
          entity.section = section
      of cfgKeyValuePair:
        entity.name = expression.key
        entity.value = expression.value

        if entity.section == section:
          if entity.name == name:
            return entity.value

      of cfgOption:
        debug("command: " & expression.key & ": " & expression.value)
      of cfgError:
        error(expression.msg)
  close(parser)

  return nil

