/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// additional key definitions

#include "keys.h"

// clang-format off

enum layers {
    MAC_B,
    PC_B,
    PC_N,
    MAC_N,
    _FUN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// macros

#include "common.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_macros(keycode, record);
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return other_key_press_exceptions(keycode, record);
}

// keymaps

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_B] = LAYOUT_iso_70(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        LT_TNAV, KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                    KC_DEL,
        MT_CTES, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_PSCR,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     MO(_FUN), KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT,  MT_GUBS,           MT_ALSP,          LT_DFUN,  MO(_FUN),          MT_ALEN,           KC_LGUI,            KC_LEFT, KC_DOWN, KC_RGHT),

    [PC_B] = LAYOUT_iso_70(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        LT_TNAV, KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,                    KC_DEL,
        MT_CTES, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,           KC_PSCR,
        KC_LSFT, KC_NUBS,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     MO(_FUN), KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT,  MT_GUBS,           MT_ALSP,          LT_DFUN,  MO(_FUN),          MT_ALEN,           KC_LGUI,            KC_LEFT, KC_DOWN, KC_RGHT),

    [PC_N] = LAYOUT_iso_70(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RM_VALD, RM_VALU,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RM_TOGG,
        _______, _______,  _______,  _______, _______, _______, MA_SUP4,  MA_SUP1,  MA_SUP2, MA_SUP3, KC_PGUP,  _______,  _______,                    _______,
        _______, _______,  _______,  _______, _______, _______, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  KC_PGDN, KC_HOME, C_LEFT,   C_RIGHT,  KC_END,   _______, _______,
        _______, _______,  _______,           _______,          KC_DEL,   _______,           _______,           _______,            _______, _______, _______),

    [MAC_N] = LAYOUT_iso_70(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RM_VALD, RM_VALU,  KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RM_TOGG,
        _______, _______,  _______,  _______, _______, _______, MA_SUP4,  MA_SUP1,  MA_SUP2, MA_SUP3, KC_PGUP,  _______,  _______,                    _______,
        _______, _______,  _______,  _______, _______, _______, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______, _______,  _______,  KC_PGDN, KC_HOME, C_LEFT,   C_RIGHT,  KC_END,   _______, _______,
        _______, _______,  _______,           _______,          KC_DEL,   _______,           _______,           _______,            _______, _______, _______),

    [_FUN] = LAYOUT_iso_70(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          RM_TOGG,
        RM_TOGG, RM_NEXT,  RM_VALU,  RM_HUEU, RM_SATU, RM_SPDU, _______,  _______,  _______, _______, _______,  _______,  _______,                    _______,
        KC_CAPS, RM_PREV,  RM_VALD,  RM_HUED, RM_SATD, RM_SPDD, _______,  _______,  _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, MA_RES,   _______,  _______, _______, _______, _______,  _______,  _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,           _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_B] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [PC_B] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [PC_N]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [_FUN]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE
