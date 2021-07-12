#include QMK_KEYBOARD_H

enum combos {
  KU_Q,
  JU_Z
};

const uint16_t PROGMEM ku_combo[] = {KC_K, KC_U, COMBO_END};
const uint16_t PROGMEM ju_combo[] = {KC_J, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [KU_Q] = COMBO(ku_combo, KC_Q),
    [JU_Z] = COMBO(ju_combo, KC_Z),
};
