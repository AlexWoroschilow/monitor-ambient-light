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
import osproc
import logging

type
  CommandStarter* = object
    path*: string

iterator commands*(this: var CommandStarter):string =
  if dirExists(this.path):
    for kind, path in walkDir(this.path):
      if existsFile(path):
        yield path

iterator start*(this: var CommandStarter, command: string, argument: string ):int {.inline.} =
  if exists_file(command):
    debug("$# $#" % [command, argument])
    yield execCmd("$# $#" % [command, argument])

iterator start*(this: var CommandStarter, argument: string ):int {.inline.} =
  for script in this.commands():
    yield execCmd("$# $#" % [script, argument])
