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
#include <version.h>
#include "keymap.h"

#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_PSCR,            KC_VOLD, KC_MPLY, KC_VOLU,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,            KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_all(
        _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,            RGB_VAD, RGB_TOG, RGB_VAI,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            KC_INS,
        RGB_TOG,  RGB_MOD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            KC_HOME,
        _______,  RGB_RMOD, _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MLCK,  RGB_HUI,  RGB_SAI,              _______,            KC_END,
        _______,            _______,  _______,  _______,  KC_VERS,  RESET,    NK_TOGG,  _______,  _______,  RGB_HUD,  RGB_SAD,              _______,  RGB_VAI,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    RGB_SPD,  RGB_VAD,  RGB_SPI),

    [WIN_BASE] = LAYOUT_all(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_PSCR,            KC_VOLD, KC_MPLY, KC_VOLU,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,            KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,            KC_PGUP,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_MENU,  MO(WIN_FN), KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_all(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,            RGB_VAD, RGB_TOG, RGB_VAI,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            KC_INS,
        RGB_TOG,  RGB_MOD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            KC_HOME,
        _______,  RGB_RMOD, _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WLCK,  RGB_HUI,  RGB_SAI,              _______,            KC_END,
        _______,            _______,  _______,  _______,  KC_VERS,  RESET,    NK_TOGG,  _______,  _______,  RGB_HUD,  RGB_SAD,              _______,  RGB_VAI,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    RGB_SPD,  RGB_VAD,  RGB_SPI),

    // [FN_3] = LAYOUT_all(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______, _______, _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
    //     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
    //     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______),
};

// ---------- RGB ----------

#ifdef RGB_MATRIX_ENABLE

    #ifdef CAPS_LOCK_LED_INDEX
    #    undef CAPS_LOCK_LED_INDEX
    #endif

    void matrix_init_user(void) {
        rgb_matrix_init_user();
    }

    void rgb_matrix_indicators_user(void) {
        // do nothing / override default behaviour
    }

#endif

// ---------- Rotary Encoder ----------

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

    #define ENCODERS 1
    static uint8_t  encoder_state[ENCODERS] = {0};
    static keypos_t encoder_cw[ENCODERS]    = {{ 8, 5 }};
    static keypos_t encoder_ccw[ENCODERS]   = {{ 7, 5 }};

    void encoder_action_unregister(void) {
        for (int index = 0; index < ENCODERS; ++index) {
            if (encoder_state[index]) {
                keyevent_t encoder_event = (keyevent_t) {
                    .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                    .pressed = false,
                    .time = (timer_read() | 1)
                };
                encoder_state[index] = 0;
                action_exec(encoder_event);
            }
        }
    }

    void encoder_action_register(uint8_t index, bool clockwise) {
        keyevent_t encoder_event = (keyevent_t) {
            .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
            .pressed = true,
            .time = (timer_read() | 1)
        };
        encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
        action_exec(encoder_event);
    }

    void matrix_scan_user(void) {
        encoder_action_unregister();
    }

    bool encoder_update_user(uint8_t index, bool clockwise) {
        encoder_action_register(index, clockwise);
        return false;
    };

#endif  // ENCODER_ENABLE

// ---------- Process Keypresses ----------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // MacOS keys
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_WINDOWS);
            }
            return false;  // Skip all further processing of this key
        
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(_AC_SHOW_ALL_APPS);
            }
            return false;  // Skip all further processing of this key
        
        // print firmware version
        case KC_VERSION:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");
                }
            }
            return false;

        default:
            return true;   // Process all other keycodes normally
    }
}
