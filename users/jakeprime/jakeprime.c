#include "jakeprime.h"
#include "leds.h"

bool process_key_tap(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count > 0) {
        if (record->event.pressed) {
            register_code16(keycode);
        } else {
            unregister_code16(keycode);
        }
        return false; // disable the default action
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
    case H_AMPR:
      return process_key_tap(KC_AMPR, record);
    case H_PIPE:
      return process_key_tap(KC_PIPE, record);
    case H_LPRN:
      return process_key_tap(KC_LPRN, record);
    case H_RPRN:
      return process_key_tap(KC_RPRN, record);

    case H_UNDS:
      return process_key_tap(KC_UNDS, record);
    case H_PLUS:
      return process_key_tap(KC_PLUS, record);
    case H_COLN:
      return process_key_tap(KC_COLN, record);

    case JP_BLUE:
      show_cleo_lights();
      return true;
    case JP_RED:
      show_red_lights();
      return true;
    case JP_RNBW:
      show_rainbow_lights();
      return true;

    default:
      return true;
  }
}
