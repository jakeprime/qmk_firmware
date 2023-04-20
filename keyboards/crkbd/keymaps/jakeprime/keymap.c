/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _QWERTY = 0,
    _SYMB,
    _NAV,
    _NUMS,
    _MEDIA
};

enum my_keycodes {
    JP_COLN = SAFE_RANGE,
    JP_PINK,
    JP_RED,
    JP_RNBW,
    JP_HTMP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define QWRT_A LCTL_T(KC_A)
#define QWRT_S LALT_T(KC_S)
#define QWRT_D LGUI_T(KC_D)
#define QWRT_F LSFT_T(KC_F)

#define QWRT_J RSFT_T(KC_J)
#define QWRT_K RGUI_T(KC_K)
#define QWRT_L LALT_T(KC_L)
#define QWRT_SC RCTL_T(KC_SCLN)

#define ESC_CMD LGUI_T(KC_ESC)
#define TAB_SYM LT(_SYMB, KC_TAB)
#define CAP_NUM LT(_NUMS, KC_CAPS)

#define ENT_MED LT(_MEDIA, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)

  [_QWERTY] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
      XXXXXXX, QWRT_A,  QWRT_S,  QWRT_D,  QWRT_F,  KC_G,                      KC_H,    QWRT_J,  QWRT_K,  QWRT_L,  QWRT_SC, XXXXXXX,
      XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                          ESC_CMD, TAB_SYM, CAP_NUM, ENT_MED, SPC_NAV, XXXXXXX
  ),

#define H_AMPR LCTL_T(KC_AMPR)
#define H_PIPE LALT_T(KC_PIPE)
#define H_LPRN LGUI_T(KC_LPRN)
#define H_RPRN LSFT_T(KC_RPRN)

#define H_UNDS RSFT_T(KC_UNDS)
#define H_MINS RGUI_T(KC_MINS)
#define H_PLUS LALT_T(KC_PLUS)
#define H_COLN RCTL_T(JP_COLN)

  [_SYMB] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_PLUS, S(KC_6), KC_LCBR, KC_RCBR, A(KC_3),                   KC_BSLS, KC_QUOT, KC_DQUO, KC_GRV,  KC_AT,   XXXXXXX,
    XXXXXXX, H_AMPR,  H_PIPE,  H_LPRN,  H_RPRN,  KC_DLR,                    KC_TILD, H_UNDS,  H_MINS,  H_PLUS,  H_COLN,  XXXXXXX,
    XXXXXXX, KC_PERC, KC_ASTR, KC_LBRC, KC_RBRC, S(KC_3),                   KC_EXLM, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, XXXXXXX,
                                        _______, _______, _______, _______, KC_BSPC, _______
  ),

  [_NAV] = LAYOUT_split_3x6_3(
    XXXXXXX, KC_PLUS, S(KC_6), KC_LCBR, KC_RCBR, A(KC_3),                   XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX,
    XXXXXXX, H_AMPR,  H_PIPE,  H_LPRN,  H_RPRN,  KC_DLR,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PERC, KC_ASTR, KC_LBRC, KC_RBRC, S(KC_3),                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
                                        _______, KC_TAB,  KC_DEL,  _______, _______, _______
  ),

  [_NUMS] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,                   _______, KC_7,    KC_8,    KC_9,    _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, _______,
    _______, _______, _______, _______, _______, _______,                   KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                                        _______, _______, _______, KC_DOT,  KC_0,    _______
  ),

#define FINE_VU LSA(KC__VOLUP)
#define FINE_VD LSA(KC__VOLDOWN)
#define SCR_CPY S(C(G(KC_4)))

  [_MEDIA] = LAYOUT_split_3x6_3(
    _______, _______, JP_PINK, JP_RNBW, JP_HTMP, _______,                   _______, FINE_VD, FINE_VU, _______, _______, _______,
    _______, RGB_SPI,  RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_TOG, _______,
    _______, RGB_SPD,  RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,                  SCR_CPY, KC_MPLY, KC_MUTE, _______, KC_SLEP, _______,
                                        _______, _______, KC_CAPS, _______, _______, _______
  ),
};

bool process_key_tap(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count > 0) {
        // tap
        if (record->event.pressed) {
            register_code16(keycode);
        } else {
            unregister_code16(keycode);
        }
        return false; // disable the default action
    }
    // hold - use the default action
    return true;
}

void set_keylog(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
#endif // OLED_DRIVER_ENABLE
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

#ifdef RGB_MATRIX_ENABLE
        case JP_RNBW:
            rgb_matrix_enable();
            rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            rgb_matrix_set_speed(20);
            return true;
        case JP_HTMP:
            rgb_matrix_enable();
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_jake_heatmap);
            return true;
        case JP_PINK:
            rgb_matrix_enable();
            rgb_matrix_mode(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
            rgb_matrix_sethsv(160, 255, 255);
            rgb_matrix_set_speed(50);
            return true;
#endif // RGB_MATRIX_ENABLE

        default:
            return true;
    }
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     set_keylog(keycode, record);
//   }
//   return true;
// }
#endif // OLED_DRIVER_ENABLE
