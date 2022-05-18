#include QMK_KEYBOARD_H
#include "lib/lib8tion/lib8tion.h"

#ifdef RGB_MATRIX_ENABLE

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (host_keyboard_led_state().caps_lock) {

    HSV      hsv  = {HSV_RED};
    uint16_t time = scale16by8(g_rgb_timer, 50);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

#endif // RGB_MATRIX_ENABLE
