#include "leds.h"
#include QMK_KEYBOARD_H

void show_cleo_lights(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
  rgblight_sethsv(176, 255, 255);
}

void show_red_lights(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv(0, 255, 255);
}

void show_rainbow_lights(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
}
