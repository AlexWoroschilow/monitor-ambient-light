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
import config


type
  Optimizer* = object
    config*: string
    name: string
    label: string
    description: string
    script: string

proc load*(this: var Optimizer):bool {.inline.} =
  var reader = newConfigReader(this.config)
  this.name = reader.get("settings.name")
  this.label = reader.get("settings.label")
  this.description = reader.get("settings.description")
  this.script = reader.get("settings.script")
  return true

proc name*(this: Optimizer):string {.inline.} =
  return this.name

proc label*(this: Optimizer):string {.inline.} =
  return this.label

proc description*(this: Optimizer):string {.inline.} =
  return this.description

proc script*(this: Optimizer):string {.inline.} =
  return this.script

proc newOptimizer*(config: string): Optimizer =
  var optimizer = Optimizer( config: config )
  if not optimizer.load():
    raise newException(IOError, "Can not load config file")
  return optimizer

type
  OptimizerFinder* = object
    path*: string
    prefix*: string

iterator optimizers*(this: var OptimizerFinder):string =
  if dirExists(this.path):
    for kind, path in walkDir(this.path):
      if find(path, this.prefix) != -1:
        yield path



when is_main_module:
  var finder = OptimizerFinder( path: "../build/etc/monitor-battery-power/update.d", prefix: "ini")
  for config in finder.optimizers():
    var optimizer = newOptimizer( config )
    echo(config)

  echo("asdf")
