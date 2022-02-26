/* Copyright 2022 Vino Rodrigues (https://github.com/vinorodrigues)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "rgb_matrix_keymap.h"
#include "keymap.h"

#define CAPS_LOCK_MAX_BRIGHTNESS 0xFF
#ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #undef CAPS_LOCK_MAX_BRIGHTNESS
    #define CAPS_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#define CAPS_LOCK_VAL_STEP 8
#ifdef RGB_MATRIX_VAL_STEP
    #undef CAPS_LOCK_VAL_STEP
    #define CAPS_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

keypos_t led_index_key_position[DRIVER_LED_TOTAL];

void rgb_matrix_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);
    switch (current_layer) {
        case MAC_BASE:
        case WIN_BASE:
            if (host_keyboard_led_state().caps_lock) {

                uint8_t b = rgb_matrix_get_val();
                if (b < CAPS_LOCK_VAL_STEP) {
                    b = CAPS_LOCK_VAL_STEP;
                } else if (b < (CAPS_LOCK_MAX_BRIGHTNESS - CAPS_LOCK_VAL_STEP)) {
                    b += CAPS_LOCK_VAL_STEP;  // one step more than current brightness
                } else {
                    b = CAPS_LOCK_MAX_BRIGHTNESS;
                }

                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_caps_lock_indicator, b, 0, 0);
            }
            break;
        default:  // or rather non-default layer
            /* Transparent Keys Off */
            rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
            break;
    }
} 

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = led_min; i < led_max; i++) {
        uint16_t keycode = keymap_key_to_keycode(layer, led_index_key_position[i]);
        if ((*is_keycode)(keycode)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
} 

bool is_caps_lock_indicator(uint16_t keycode) {
    bool indicator = keycode == KC_CAPS;
    return ((KC_A <= keycode) && (keycode <= KC_Z)) || indicator;
}

bool is_transparent(uint16_t keycode) { return keycode == KC_TRNS; }
