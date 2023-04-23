#include QMK_KEYBOARD_H
#include "jakeprime.h"

#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_WRAPPER(DEF_KYRIA)
};
