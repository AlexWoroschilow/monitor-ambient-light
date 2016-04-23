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
import strtabs

type
  ConfigReader* = object
    table: StringTableRef
    path*: string

proc load(this: var ConfigReader):bool {.inline.} =

  var section:string
  var option:string
  var value:string

  this.table = newStringTable()

  var stream = newFileStream(this.path, fmRead)
  assert(stream != nil, "Can not read config file stream")
  var parser = CfgParser()
  open(parser, stream, this.path)

  while true:
    var expression = next(parser)
    case expression.kind
      of cfgEof:
        break
      of cfgSectionStart:
        # set current active setion
        # and override last active
        section = expression.section
      of cfgKeyValuePair:

        # get options value and name
        # for current session
        value = expression.value
        option = expression.key

        debug("found: $#, $#" % [option, value])

        # fill config table with actial values
        this.table["$#.$#" %[section, option] ]=value

      of cfgOption:

        # get options value and name
        # for current session
        value = expression.value
        option = expression.key

        debug("command: $#, $#" % [option, value])

      of cfgError:
        error(expression.msg)
  close(parser)

  return true

proc loaded(this: var ConfigReader):bool {.inline.} =
  if this.table != nil:
    return (this.table.len() > 0)
  return false

proc get*(this: var ConfigReader, key: string):string {.inline.} =
  if not this.loaded():
    assert(this.load(), "Can not load config file")

  if this.table.hasKey(key):
    return this.table[key]

  return nil

proc get*(this: var ConfigReader, section: string, name: string):string {.inline.} =
  if not this.loaded():
    assert(this.load(), "Can not load config file")

  var key = "$#.$#" % [section, name]
  if this.table.hasKey(key):
    return this.table[key]

  return nil
