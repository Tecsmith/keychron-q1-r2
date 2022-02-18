/* Copyright 2022 Keychron (https://www.keychron.com)
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x3434
#define PRODUCT_ID   0x0107
#define DEVICE_VER   0x0203
#define MANUFACTURER Keychron
#define PRODUCT      Keychron Q1 R2

/* Key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

/* Disable DIP switch in matrix data */
#define MATRIX_MASKED

/* DIP switch */
#define DIP_SWITCH_MATRIX_GRID  { {5,4} }

/* Set USB polling rate as 1000Hz */
#define USB_POLLING_INTERVAL_MS 1

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { B5, B4, B3, A15, A14, A13 }
#define MATRIX_COL_PINS { C14, C15, A0, A1, A2, A3, A4, A5, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }
// #define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* We have 2KB EEPROM size on STM32L432 */
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 2047

#ifdef ENCODER_ENABLE
    /* Encoder used pins */
    #define ENCODERS_PAD_A { A10 }
    #define ENCODERS_PAD_B { A8 }

    /* Specifies the number of pulses the encoder registers between each detent */
    #define ENCODER_RESOLUTION 4
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
#define GRAVE_ESC_CTRL_OVERRIDE

/* Force NKRO */
//#define FORCE_NKRO  // do not eable as this will prevent Mac keys from working

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 45


/* ----------------------------------------
 * RGB Matrix
 * ---------------------------------------- */

#ifdef RGB_MATRIX_ENABLE
    /* RGB Matrix Driver Configuration */
    #define DRIVER_COUNT 2
    #define DRIVER_ADDR_1 0b1110111
    #define DRIVER_ADDR_2 0b1110100

    /* RGB Matrix Configuration */
    #define DRIVER_1_LED_TOTAL 45
    #define DRIVER_2_LED_TOTAL 37
    #define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

    /* Scan phase of led driver set as MSKPHASE_9CHANNEL(defined as 0x03 in CKLED2001.h) */
    #define PHASE_CHANNEL MSKPHASE_9CHANNEL

    /* Set the maxium brightness as 192 in order to limit the current to 450mA */
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS (24 * 8)  // 8 = RGB_MATRIX_VAL_STEP


    /* Allow VIA to edit lighting */
    #ifdef VIA_ENABLE
        #define VIA_QMK_RGBLIGHT_ENABLE
    #endif

    #define RGB_MATRIX_KEYPRESSES

    // RGB Matrix Animation modes. Explicitly enabled
    // For full list of effects, see:
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
    // #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    // #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    // #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    // #define ENABLE_RGB_MATRIX_BAND_SAT
    // #define ENABLE_RGB_MATRIX_BAND_VAL
    // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    // #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    // #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    // #define ENABLE_RGB_MATRIX_HUE_BREATHING
    // #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    // #define ENABLE_RGB_MATRIX_HUE_WAVE
    // #define ENABLE_RGB_MATRIX_PIXEL_RAIN
    // #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    // #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

    #if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
        #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
        #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #endif

    #if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
        #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
        #define ENABLE_RGB_MATRIX_SPLASH
        #define ENABLE_RGB_MATRIX_MULTISPLASH
        #define ENABLE_RGB_MATRIX_SOLID_SPLASH
        #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    #endif
#endif

/* ----------------------------------------
 * Feature disable options
 *  These options are also useful to
 *  firmware size reduction.
 * ---------------------------------------- */

/* disable action features */
#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

