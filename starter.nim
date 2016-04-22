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

type
  CommandStarter* = object
    path*: string

iterator commands*(this: var CommandStarter):string =
  if dirExists(this.path):
    for kind, path in walkDir(this.path):
      if existsFile(path):
        yield path

iterator start*(this: var CommandStarter, argument: string ):int {.inline.} =
  for script in this.commands():
    yield execCmd("$# $#" % [script, argument])


# This code will be executed
# only if you will build this file
# separate from another sources
# so, it is only testing approaches here
when isMainModule:
  var starter = CommandStarter(path: "/etc/yoga-ambient-light/update.d")
  for command in starter.commands():
    echo(command)

  for error in starter.start("12"):
    echo(error)
