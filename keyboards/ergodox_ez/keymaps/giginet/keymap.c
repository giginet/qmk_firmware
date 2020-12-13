// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keysconst uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define GAMING 3 // gaming
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  -_  |           |  =+  |   6  |   7  |   8  |   9  |   0  |   BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | `      |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |LCtl/Tab|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '"   |
 * |--------+------+------+------+------+------| Kana |           | Alpha|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |~L1   |  '"  | LCtrl|Option| Cmd  |                                       |  -_  |  =+  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,---------------.       ,---------------.
 *                                        | Left | Right  |       | Left | Right  |
 *                                 ,------|------|--------|       |------+--------+------.
 *                                 |      |      |   Up   |       |  Up  |        |      |
 *                                 | Space| Cmd  |--------|       |------|  Cmd   |Enter |
 *                                 |      |      |  Down  |       | Down |        |      |
 *                                 `----------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_MINS,
        KC_GRV,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        CTL_T(KC_TAB), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LANG1,
        MO(MDIA),      KC_QUOT,      KC_LCTL,KC_LALT,KC_LGUI,
                                                     KC_LCTL,KC_LALT,
                                                             KC_UP,
                                             KC_SPC,KC_LGUI, KC_PGDOWN,
        // right hand KC_EQL,        KC_6,         KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
        KC_RBRC,       KC_Y,         KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                       KC_H,         KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
        KC_LANG2,      KC_N,         KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                     KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,          MO(SYMB),
        KC_LEFT,  KC_RIGHT,
        KC_UP,
        KC_PGUP,  KC_RGUI, KC_ENT),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,
                KC_LEFT, KC_DOWN,   KC_UP,    KC_RIGHT,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_BSLS, KC_TRNS,
                         KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | Prev | PLAY | Next | Mute | VolDn| VolUp| Eject  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RESET,
       KC_TRNS, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(GAMING),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_MPLY, KC_TRNS, KC_TRNS,
    // right hand
       KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,  RGB_TOG
),

[GAMING] = LAYOUT_ergodox(
       KC_ESC , KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_Z,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(BASE),
       MO(MDIA), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_SPACE,KC_TRNS, KC_TRNS,
    // right hand
       KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS,
       TO(SYMB), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(SYMB),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_ENTER
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      rgblight_setrgb_red();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      rgblight_setrgb_green();
      break;
    case GAMING:
      ergodox_right_led_3_on();
      rgblight_setrgb_blue();
      break;
    default:
      // none
      break;
  }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    rgblight_sethsv_noeeprom((keycode * 8) % 360, 255, 255);
  } else {
    rgblight_init();
  }
  return true;
}
