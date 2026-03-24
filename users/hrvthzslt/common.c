enum custom_keycodes {
    MA_SUP1 = SAFE_RANGE,
    MA_SUP2,
    MA_SUP3,
    MA_SUP4,
    MA_ALT1,
    MA_ALT2,
    MA_ALT3,
    MA_ALT4,
    MA_RES,
    C_LEFT,
    C_RIGHT,
    A_LEFT,
    A_RIGHT,
};

#include "timer.h"

static uint16_t ma_res_timer;

bool press_modifier(uint16_t modifier, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(modifier);
        register_code(keycode);
    } else {
        unregister_code(keycode);
        unregister_code(modifier);
    }
    return true;
}

bool press_super(uint16_t keycode, keyrecord_t *record) {
    return press_modifier(KC_LGUI, keycode, record);
}

bool press_alt(uint16_t keycode, keyrecord_t *record) {
    return press_modifier(KC_LALT, keycode, record);
}

bool press_reset(keyrecord_t *record) {
    if (record->event.pressed) {
        ma_res_timer = timer_read();
    } else {
        if (timer_elapsed(ma_res_timer) >= 4000) {
            eeconfig_init();
            soft_reset_keyboard();
        }
    }
    return true;
}

bool press_mod_button(uint16_t modifier, uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(modifier);
        register_code(keycode);
    } else {
        unregister_code(keycode);
        unregister_code(modifier);
    }
    return true;
}

bool press_ctrl_button(uint16_t keycode, keyrecord_t *record) {
    return press_mod_button(KC_LCTL, keycode, record);
}

bool press_alt_button(uint16_t keycode, keyrecord_t *record) {
    return press_mod_button(KC_LALT, keycode, record);
}

void process_macros(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MA_SUP1:
            press_super(KC_1, record);
            break;
        case MA_SUP2:
            press_super(KC_2, record);
            break;
        case MA_SUP3:
            press_super(KC_3, record);
            break;
        case MA_SUP4:
            press_super(KC_4, record);
            break;
        case MA_ALT1:
            press_alt(KC_1, record);
            break;
        case MA_ALT2:
            press_alt(KC_2, record);
            break;
        case MA_ALT3:
            press_alt(KC_3, record);
            break;
        case MA_ALT4:
            press_alt(KC_4, record);
            break;
        case MA_RES:
            press_reset(record);
            break;
        case C_LEFT:
            press_ctrl_button(KC_LEFT, record);
            break;
        case C_RIGHT:
            press_ctrl_button(KC_RGHT, record);
            break;
        case A_LEFT:
            press_alt_button(KC_LEFT, record);
            break;
        case A_RIGHT:
            press_alt_button(KC_RGHT, record);
            break;
    }
}

bool other_key_press_exceptions(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_ALSP:
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}
