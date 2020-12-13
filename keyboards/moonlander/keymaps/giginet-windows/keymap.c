/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Drashna Jael're  <drashna@live.com>
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
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// Windows doesn't receive any LANG key inputs from English keyboards. 
// So the function keys are assigned to toggle IME on a software side.
#define ENABLE_IME KC_F11
#define DISABLE_IME KC_F12

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,      KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,              KC_BSPC,
        KC_GRV,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,     KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,              KC_BSLS,
        CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    ENABLE_IME,  DISABLE_IME, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,           KC_QUOT,
        KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,
        TT(MDIA),      KC_QUOT, KC_LGUI, KC_LALT, KC_LGUI,          KC_SPC,      KC_ENT,           KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, MO(SYMB),
                                                  KC_SPC,  KC_LCTL, KC_PGDOWN,   KC_PGUP, KC_PSCR, KC_ENT
    ),

    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,           KC_TRNS, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS,  KC_TRNS, KC_TRNS, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_PGDOWN,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          RGB_VAI,           RGB_TOG,          KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,KC_TRNS, KC_TRNS
    ),

    [MDIA] = LAYOUT_moonlander(
        KC_TRNS, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT,
        KC_TRNS, KC_TRNS, KC_UP,   KC_MS_U, KC_TRNS, KC_TRNS, RESET,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_MS_R, KC_TRNS, KC_TRNS,           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,          KC_MPLY,           KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    switch (get_highest_layer(state)) {
        case 1:
            ML_LED_1(1);
            ML_LED_4(1);
            break;
        case 2:
            ML_LED_2(1);
            ML_LED_5(1);
            break;
        case 3:
            ML_LED_3(1);
            break;
        case 4:
            ML_LED_4(1);
            break;
        case 5:
            ML_LED_5(1);
            break;
        case 6:
            ML_LED_6(1);
            break;
        default:
            break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
