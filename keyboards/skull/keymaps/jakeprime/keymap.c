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

const rgblight_segment_t PROGMEM my_eyes_layer[] = RGBLIGHT_LAYER_SEGMENTS(
                                                                           {10, 3, HSV_RED},
                                                                           {23, 3, HSV_RED}
                                                                          );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
                                                                               my_eyes_layer
                                                                              );
void update_lights(void) {
    /* if (user_eyeconfig.enable) { */
    /*     rgblight_set_clipping_range(10, 3); */
    /*     rgblight_set_effect_range(0, 26); */
    /*     /\*     rgblight_set_effect_range(6, 20); *\/ */
    /*     /\*     // Actual per-half LED index, not mapping dependent *\/ */
    /*     /\*     for (uint8_t i = 10; i < 13; i++) { *\/ */
    /*     /\*         rgblight_driver.set_color(i, 255, 0, 0); *\/ */
    /*     /\*         rgblight_driver.flush(); *\/ */
    /*     /\*     } *\/ */
    /*     /\* } else { *\/ */
    /*     /\*     rgblight_set_effect_range(0, 26); *\/ */
    /* } else { */
    /*     rgblight_set_clipping_range(0, 26); */
    /*     rgblight_set_effect_range(0, 26); */
    /* } */
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
    rgblight_layers = my_rgb_layers;
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

static bool last_caps_lock = false;
static bool last_rgb_enabled = true;
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock != last_caps_lock) {
        last_caps_lock = led_state.caps_lock;
        if (led_state.caps_lock) {
            last_rgb_enabled = rgblight_is_enabled();
            rgblight_disable();
            rgblight_set_layer_state(0, led_state.caps_lock);
            // blink is only working on the left split
            /* rgblight_blink_layer_repeat(0, 400, 100); */
        } else {
            /* rgblight_unblink_layer(0); */
            rgblight_set_layer_state(0, led_state.caps_lock);
            if (last_rgb_enabled) {
                rgblight_enable();
            }
        }
    }

    return true;
}
