/* Copyright 2019 Ryota Goto
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
enum custom_keycodes {
  C_S_A_G  = SAFE_RANGE,
  C_A_G,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case C_S_A_G:
        if (record->event.pressed) {
            // キーコード C_S_A_G が押された時
            register_code(KC_RCTL);
            register_code(KC_RSFT);
            register_code(KC_RALT);
            register_code(KC_RGUI);
        } else {
            // キーコード C_S_A_G が放された時
            unregister_code(KC_RCTL);
            unregister_code(KC_RSFT);
            unregister_code(KC_RALT);
            unregister_code(KC_RGUI);
        }
        break;
    case C_A_G:
        if (record->event.pressed) {
            // キーコード C_A_G が押された時
            register_code(KC_RCTL);
            register_code(KC_RALT);
            register_code(KC_RGUI);
        } else {
            // キーコード C_A_G が放された時
            unregister_code(KC_RCTL);
            unregister_code(KC_RALT);
            unregister_code(KC_RGUI);
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MO(3),
    KC_LALT, KC_LGUI, KC_LGUI,          KC_SPC,           MO(2),         MO(1),      KC_RGUI, KC_RGUI, C_S_A_G
  ),
  [1] = LAYOUT( /* Extra Keys */
    KC_ESC,  _______, KC_PGUP, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______,
    _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_QUOT, _______,
    _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  ),
  [2] = LAYOUT( /* Num and FN */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______,
    _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, QK_BOOT
  ),
  [3] = LAYOUT( /* Num and FN */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_UP,   KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
    _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_END,  KC_PGDN, KC_DOWN, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  )
};

