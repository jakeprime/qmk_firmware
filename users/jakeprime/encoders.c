#ifdef ENCODER_ENABLE

#include QMK_KEYBOARD_H
#include "jakeprime.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
#ifdef JP_LIGHT_SIDE
    if (clockwise) tap_code16(FINE_VU);
    else tap_code16(FINE_VD);
#else
    if (clockwise) tap_code16(FINE_VD);
    else tap_code16(FINE_VU);
#endif
  }
  else if (index == 1) {
#ifdef JP_LIGHT_SIDE
    if (clockwise) tap_code16(G(KC_EQL));
    else tap_code16(G(KC_MINS));
#else
    if (clockwise) tap_code16(G(KC_MINS));
    else tap_code16(G(KC_EQL));
#endif
  }
  return false;
}
#endif
