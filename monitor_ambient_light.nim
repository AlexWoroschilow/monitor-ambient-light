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
import logging

import src/config
import src/signal
import src/starter
import src/sensors
import src/normalizer

proc main(file: string, log: string) =
  addHandler(newRollingFileLogger(log, levelThreshold = lvlDebug))
  setControlCHook(handler)

  var config = newConfigReader(file)
  var timeout: int = parseInt(config.get("als.timeout"))

  var intensity_min: int = parseInt(config.get("als.intensity_min"))
  var intensity_max: int = parseInt(config.get("als.intensity_max"))
  var intensity_threshold: int = parseInt(config.get("als.intensity_threshold"))
  info("intensity minimal: $#" % [intToStr(intensity_min)])
  info("intensity maximal: $#" % [intToStr(intensity_max)])
  info("intensity threshold: $#" % [intToStr(intensity_threshold)])

  var backlight_min: int = parseInt(config.get("als.backlight_min"))
  var backlight_max: int = parseInt(config.get("als.backlight_max"))
  info("backlight minimal: $#" % [intToStr(backlight_min)])
  info("backlight maximal: $#" % [intToStr(backlight_max)])

  var location_sensor: string = config.get("als.location_sensor")
  var location_script: string = config.get("als.location_script")
  info("sensors:\t$#" % [location_sensor])
  info("scripts:\t$#" % [location_script])

  var starter = CommandStarter(path: location_script)
  var normalizer_backlight = Normalizer(min: backlight_min, max: backlight_max)
  var normalizer_intencity = Normalizer(min: intensity_min, max: intensity_max)

  var sensor = getSensorAmbientLight(location_sensor)
  while not sensor.exists() or not sensor.enable():
    error("sensor not found, sleep: $# " % intToStr(timeout))
    sleep(timeout)

  var previous: int = 0

  while true:
    var current = normalizer_intencity.percent(sensor.intensity())
    if abs(current-previous) >= intensity_threshold:
      var backlight = normalizer_backlight.percent(current)
      debug("ambient light: $#, backlight: $#" % [intToStr(current), intToStr(backlight)])
      for error in starter.start(intToStr(backlight)):
        debug("starter script error number: $# " % intToStr(error))
    previous = current
    sleep(timeout)


main("/etc/monitor-ambient-light/monitor-ambient-light.ini", "/var/log/monitor-ambient-light.log")
