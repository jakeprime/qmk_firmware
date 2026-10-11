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
        bool eyes_on: 1;
        bool caps_lock: 1;
    };
} eye_config_t;

eye_config_t user_eyeconfig = {
    .eyes_on = false,
    .caps_lock = false
};

const rgblight_segment_t PROGMEM my_eyes_layer[] = RGBLIGHT_LAYER_SEGMENTS(
                                                                           {10, 3, HSV_RED},
                                                                           {23, 3, HSV_RED}
                                                                          );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
                                                                               my_eyes_layer
                                                                              );

uint8_t breathe_val(void) {
    uint8_t min_breathe_val = 128;
    uint8_t max_breathe_val = 255;
    uint16_t period = 1000; // ms
    uint16_t total_steps = (max_breathe_val - min_breathe_val) * 2;
    uint16_t temp_val = ((timer_read32() * total_steps) / period) % total_steps;
    if (temp_val > (max_breathe_val - min_breathe_val)) {
        return(max_breathe_val - (temp_val - (max_breathe_val - min_breathe_val)));
    } else {
        return(min_breathe_val + temp_val);
    }
}

void update_lights(void) {
    if (user_eyeconfig.caps_lock) {
        rgblight_disable();
        rgblight_set_layer_state(0, false);
        rgblight_set_effect_range(0, 0);
        hsv_t hsv = {0, 255, breathe_val()};
        rgb_t colour = hsv_to_rgb(hsv);
        for (uint8_t i = 10; i < 13; i++) {
            rgblight_driver.set_color(i, colour.r, colour.g, colour.b);
        }
    } else {
        rgblight_set_effect_range(0, 26);
        rgblight_set_layer_state(0, user_eyeconfig.eyes_on);
        rgblight_enable();
    }

    rgblight_driver.flush();
}

void dispatch_rpc(void) {
    transaction_rpc_send(USER_SYNC_A, sizeof(user_eyeconfig), &user_eyeconfig);
    update_lights();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EY_TOGG:
        if (record->event.pressed) {
            user_eyeconfig.eyes_on = !user_eyeconfig.eyes_on;
            dispatch_rpc();
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
    rgblight_layers = my_rgb_layers;
    transaction_register_rpc(USER_SYNC_A, user_sync_eyes_handler);
    update_lights();
}

void housekeeping_task_user(void) {
    static uint32_t last_breathe_sync = 0;
    if (user_eyeconfig.caps_lock && timer_elapsed32(last_breathe_sync) > 20) {
        update_lights();
    }
}

bool led_update_user(led_t led_state) {
    if (is_keyboard_master()) {
        if (led_state.caps_lock != user_eyeconfig.caps_lock) {
            user_eyeconfig.caps_lock = led_state.caps_lock;
            dispatch_rpc();
        }
    }

    return true;
}
