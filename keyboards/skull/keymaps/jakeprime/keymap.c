#include QMK_KEYBOARD_H

#include "transactions.h"
#include "color.h"
#include "jakeprime.h"

enum keymap_keycodes {
  EY_TOGG = QK_USER_0
};

#define LAYOUT_WRAPPER(...) LAYOUT_split_3x5_2(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_WRAPPER(DEF_SKULL),
    [_SYMB] = LAYOUT_WRAPPER(SYM_SKULL),
    [_NAV] = LAYOUT_WRAPPER(NAV_SKULL),
    [_NUMS] = LAYOUT_WRAPPER(NUM_SKULL),
    [_MEDIA] = LAYOUT_WRAPPER(MED_SKULL)
};

typedef union eye_config_t {
    uint32_t raw;
    struct {
        bool enable: 1;
    };
} eye_config_t;

eye_config_t user_eyeconfig = {
    .enable = true
};

void update_lights(void) {
    if (user_eyeconfig.enable) {
        rgblight_set_effect_range(6, 20);
        // Actual per-half LED index, not mapping dependent
        for (uint8_t i = 10; i < 13; i++) {
            rgblight_driver.set_color(i, 255, 0, 0);
            rgblight_driver.flush();
        }
    } else {
        rgblight_set_effect_range(0, 20);
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EY_TOGG:
        if (record->event.pressed) {
            user_eyeconfig.enable = !user_eyeconfig.enable;
            update_lights();
        }
        break;
    }
    return process_record_user(keycode, record);
};

void user_sync_eyes_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const eye_config_t *m2s = (const eye_config_t*)in_data;

    if (user_eyeconfig.raw != m2s->raw){
        user_eyeconfig.raw = m2s->raw;
        update_lights();
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_A, user_sync_eyes_handler);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 100) {
            if (transaction_rpc_send(USER_SYNC_A, sizeof(user_eyeconfig), &user_eyeconfig)) {
                last_sync = timer_read32();
            }
        }
    }
}
