#!/bin/bash
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

BACKLIGHT_BRIGHTNESS_PERCENT=$1
INTEL_BACKLIGHT="/sys/class/backlight/intel_backlight"
INTEL_BACKLIGHT_BRIGHTNESS_MAX="${INTEL_BACKLIGHT}/max_brightness"
INTEL_BACKLIGHT_BRIGHTNESS="${INTEL_BACKLIGHT}/brightness"

if [ ! -d "${INTEL_BACKLIGHT}" ]; then
  echo "intel backlight device not found"
  exit 1;
fi

if [ ! -f "${INTEL_BACKLIGHT_BRIGHTNESS_MAX}" ]; then
  echo "intel backlight max brightness stream not found"
  exit 1;
fi

if [ ! -f "${INTEL_BACKLIGHT_BRIGHTNESS}" ]; then
  echo "intel backlight brightness stream not found"
  exit 1;
fi

BACKLIGHT_BRIGHTNESS_MAX="`cat ${INTEL_BACKLIGHT_BRIGHTNESS_MAX}`"
BACKLIGHT_BRIGHTNESS=$((${BACKLIGHT_BRIGHTNESS_MAX} / 100 * ${BACKLIGHT_BRIGHTNESS_PERCENT}))
echo ${BACKLIGHT_BRIGHTNESS} > ${INTEL_BACKLIGHT_BRIGHTNESS}
