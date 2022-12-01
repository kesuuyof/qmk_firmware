/*
Copyright 2020 Holten Campbell

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

#include QMK_KEYBOARD_H
enum custom_keycodes {
  C_S_A_G  = SAFE_RANGE,
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
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_bs_rshift(
		KC_ESC,         KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV, 
		KC_TAB,         KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC, 
		KC_LCTL,        KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSFT,        KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1), 
		MO(2),          KC_LALT,                    KC_LGUI, KC_SPC,  KC_SPC,  KC_RGUI,                            C_S_A_G, KC_RCTL, MO(3)
		),
	[1] = LAYOUT_split_bs_rshift(
		C_S_T(KC_SLEP), KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,
		KC_CAPS,        KC_TRNS,  KC_MS_U, KC_BTN3, KC_BTN4, KC_BTN5, KC_VOLD, KC_MPLY, KC_INS,  KC_TRNS, KC_TRNS, KC_UP,   KC_MNXT,          KC_BSPC, 
		KC_TRNS,        KC_MS_L,  KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2, KC_VOLU, KC_MPRV, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_TRNS, 
		KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,  KC_PGDN, KC_DOWN, KC_PSCR, KC_TRNS, 
		KC_TRNS, 		    KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_split_bs_rshift(
		KC_TRNS,        KC_TRNS,  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WSCH, KC_PSLS, KC_PAST, KC_PEQL, KC_NO,   KC_NO,   RESET, 
		KC_TRNS,        RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_TRNS, KC_TRNS,          KC_TRNS, 
		KC_TRNS,        RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_COLN, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_TRNS, KC_TRNS, 
		KC_TRNS,        RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_UP,   KC_NO, 
		KC_TRNS,        KC_TRNS,                    KC_TRNS, KC_TRNS, KC_P0,   KC_PDOT,                            KC_LEFT, KC_DOWN, KC_RGHT),
	[3] = LAYOUT_split_bs_rshift(
		KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, 
		KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,        KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS)
};
