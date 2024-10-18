enum custom_keycodes {
    MA_SUP1 = SAFE_RANGE,
    MA_SUP2,
    MA_SUP3,
    MA_SUP4,
    MA_RES,
};

#include "timer.h"

static uint16_t ma_res_timer;

bool press_super(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(keycode);
    } else {
        unregister_code(keycode);
        unregister_code(KC_LGUI);
    }
    return true;
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
        case MA_RES:
            press_reset(record);
            break;
    }
}
