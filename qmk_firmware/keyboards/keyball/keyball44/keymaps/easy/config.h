/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// to adopt newer version of QMK's split keyboards recognition
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

// longer OLED turn off time
#define OLED_TIMEOUT 600000

// Tap Dance
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Auto Mouse Layer
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 2
#define AUTO_MOUSE_TIME 800
#define AUTO_MOUSE_DELAY 1000
#define AUTO_MOUSE_THRESHOLD 64

// Mouse experience
#define KEYBALL_CPI_DEFAULT 800
#define KEYBALL_SCROLL_DIV_DEFAULT 8
#define KEYBALL_REPORTMOUSE_INTERVAL 1

// Keyboard experience
#define TAP_CODE_DELAY 5

