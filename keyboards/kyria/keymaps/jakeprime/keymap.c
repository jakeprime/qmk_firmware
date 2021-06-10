/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _QWERTY = 0,
    _HALMAK,
    _SYMB,
    _NAV,
    _NUMS,
    _MEDIA
};

enum my_keycodes {
    JP_COLN = SAFE_RANGE,
    JP_RED,
    JP_RNBW
};

uint16_t show_rgb_stats_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | A  ↑ | S  ^ | D  ⎇ | F  ⌘ |   G  |                              |   H  | J  ⌘ | K  ⎇ | L  ^ | ;  ↑ |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |CmdEsc|Sy/Tab|Np/Del|HALMAK|  | Caps | Enter|Nv/Spc| Bspc |      |
 *                        `----------------------------------'  `----------------------------------'
 */

#define HALMAK TG(_HALMAK)

#define QWRT_A LCTL_T(KC_A)
#define QWRT_S LALT_T(KC_S)
#define QWRT_D LGUI_T(KC_D)
#define QWRT_F LSFT_T(KC_F)

#define QWRT_J RSFT_T(KC_J)
#define QWRT_K RGUI_T(KC_K)
#define QWRT_L LALT_T(KC_L)
#define QWRT_SC RCTL_T(KC_SCLN)

#define ESC_CMD LGUI_T(KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_SYM LT(_SYMB, KC_TAB)
#define NUM_DEL LT(_NUMS, KC_DEL)
#define MED_ENT LT(_MEDIA, KC_ENT)

    [_QWERTY] = LAYOUT(
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        XXXXXXX, QWRT_A,  QWRT_S,  QWRT_D,  QWRT_F,  KC_G,                                        KC_H,    QWRT_J,  QWRT_K,  QWRT_L,  QWRT_SC, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                   XXXXXXX, ESC_CMD, TAB_SYM, NUM_DEL, HALMAK,  KC_CAPS, MED_ENT, SPC_NAV, KC_BSPC, XXXXXXX
    ),

/*
 * Base Layer: HALMAK
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   W  |   L  |   R  |   B  |   Z  |                              |   ;  |   Q  |   U  |   D  |   J  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | S  ↑ | H  ^ | N  ⎇ | T  ⌘ |   ,  |                              |   .  | A  ⌘ | E  ⎇ | O  ^ | I  ↑ |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   F  |   M  |   V  |  C   |   /  |      |      |  |      |      |   G  |   P  |   X  |   K  |   Y  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

#define HLMK_S LSFT_T(KC_S)
#define HLMK_H LCTL_T(KC_H)
#define HLMK_N LALT_T(KC_N)
#define HLMK_T LGUI_T(KC_T)

#define HLMK_A RGUI_T(KC_A)
#define HLMK_E LALT_T(KC_E)
#define HLMK_O RCTL_T(KC_O)
#define HLMK_I RSFT_T(KC_I)

    [_HALMAK] = LAYOUT(
        _______, KC_W,    KC_L,    KC_R,    KC_B,    KC_Z,                                        KC_SCLN, KC_Q,    KC_U,    KC_D,    KC_J,    _______,
        _______, HLMK_S,  HLMK_H,  HLMK_N,  HLMK_T,  KC_COMM,                                     KC_DOT,  HLMK_A,  HLMK_E,  HLMK_O,  HLMK_I,  _______,
        _______, KC_F,    KC_M,    KC_V,    KC_C,    KC_SLSH, _______, _______, _______, _______, KC_G,    KC_P,    KC_X,    KC_K,    KC_Y,    _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  +   |  ^   |  {   |  }   |  #   |                              |   \  |  '   |  "   |  `   |  @   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  &   |  |   |  (   |  )   |  $   |                              |   ~  |  _   |  -   |  +   |  :   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  *   |  [   |  ]   |  £   |      |      |  |      |      |   !  |  =   |  <   |  >   |  ?   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define H_AMPR LCTL_T(KC_AMPR)
#define H_PIPE LALT_T(KC_PIPE)
#define H_LPRN LGUI_T(KC_LPRN)
#define H_RPRN LSFT_T(KC_RPRN)

#define H_UNDS RSFT_T(KC_UNDS)
#define H_MINS RGUI_T(KC_MINS)
#define H_PLUS LALT_T(KC_PLUS)
#define H_COLN RCTL_T(JP_COLN)

    [_SYMB] = LAYOUT(
      XXXXXXX, KC_PLUS, S(KC_6), KC_LCBR, KC_RCBR, A(KC_3),                                     KC_BSLS, KC_QUOT, KC_DQUO, KC_GRV,  KC_AT,   XXXXXXX,
      XXXXXXX, H_AMPR,  H_PIPE,  H_LPRN,  H_RPRN,  KC_DLR,                                      KC_TILD, H_UNDS,  H_MINS,  H_PLUS,  H_COLN,  XXXXXXX,
      XXXXXXX, KC_PERC, KC_ASTR, KC_LBRC, KC_RBRC, S(KC_3), _______, _______, _______, _______, KC_EXLM, KC_EQL,  KC_LT,   KC_GT,   KC_QUES, XXXXXXX,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
    ),
/*
 * Navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  *   |  7   |  8   |  9   |  +   |                              |      |  M1  |  M2  |  M3  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  /   |  4   |  5   |  6   |  -   |                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  1   |  2   |  3   |      |      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  .   |  0   |  Del |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define H_SLSH LCTL_T(KC_SLSH)
#define H_4 LALT_T(KC_4)
#define H_5 LGUI_T(KC_5)
#define H_6 LSFT_T(KC_6)

    [_NAV] = LAYOUT(
      XXXXXXX, KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS,                                     XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX,
      XXXXXXX, H_SLSH,  H_4,     H_5,     H_6,     KC_MINS,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
                                 XXXXXXX, KC_DOT,  KC_0,    KC_DEL,  _______, _______, _______, _______, _______, XXXXXXX
    ),

/*
 * Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |   +  |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   -  |   1  |   2  |   3  |   /  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_7,    KC_8,    KC_9,    _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______
    ),

/*
 * Media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | Rnbw |  Red |      |                              |      | VolD-| VolU-|      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | RGB  | SAI  | HUI  | VAI  | MOD  |                              | Prev | VolD+| VolU+| Next |  RGB |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Sleep| SAD  | HUD  | VAD  | RMO  |      |      |  |      |      |      | Play | Mute |      | Sleep|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

#define FINE_VU LSA(KC__VOLUP)
#define FINE_VD LSA(KC__VOLDOWN)
#define SCR_CPY S(C(G(KC_4)))

    [_MEDIA] = LAYOUT(
      _______, _______, _______, JP_RNBW, JP_RED,  _______,                                     _______, FINE_VD, FINE_VU, _______, _______, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, RGB_TOG, _______,
      _______, KC_SLEP, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, KC_MPLY, KC_MUTE, _______, KC_SLEP, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
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

static bool show_rgb_stats = false;

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

        case JP_RED:
            rgblight_enable();
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(0, 255, 255);
            show_rgb_stats_timer = timer_read();
            show_rgb_stats = true;
            return true;
        case JP_RNBW:
            rgblight_enable();
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
            show_rgb_stats_timer = timer_read();
            show_rgb_stats = true;
            return true;

        case RGB_HUI: case RGB_HUD:
        case RGB_SAI: case RGB_SAD:
        case RGB_VAI: case RGB_VAD:
        case RGB_MOD: case RGB_RMOD:
        case RGB_TOG:
            show_rgb_stats_timer = timer_read();
            show_rgb_stats = true;
            return true;

        default:
            return true;
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_pentagram(void) {
    static const char PROGMEM pentagram[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1c, 0xfc, 0xf8, 0xf0,
        0xe0, 0xe0, 0xd8, 0xb8, 0x38, 0x3c, 0x1c, 0x1c, 0x1e, 0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f,
        0x0f, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0x1e, 0x1c, 0x1c, 0x3c, 0xb8, 0xf8, 0xd0, 0xe0, 0xf0, 0xf0,
        0xf8, 0xfc, 0x1e, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xfc, 0x7e, 0x1f, 0x0f, 0x07, 0x07, 0x3f,
        0xff, 0xff, 0xe3, 0x07, 0x0f, 0x0f, 0x1e, 0x3c, 0x7c, 0x78, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x80,
        0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0x78, 0x3c, 0x1e, 0x1e, 0x0f, 0x07, 0x07, 0xe3, 0xfd, 0xff, 0x3f,
        0x07, 0x00, 0x0f, 0x1e, 0x7c, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 0x7f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x1f, 0xff, 0xff, 0xf8, 0xc0, 0x00, 0xe0, 0xe0, 0xf0, 0x78, 0x3d, 0x3d, 0x1f, 0x0f, 0x07,
        0x0f, 0x1f, 0x3d, 0x7c, 0x78, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0xb0, 0x7e, 0x7f, 0x0f, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0xff, 0xfe, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0x78,
        0x78, 0x3c, 0x1e, 0x0f, 0x3f, 0xff, 0xfe, 0xf1, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe1, 0xfb, 0xff, 0x3f, 0x0f, 0x1e, 0x3e, 0x7c, 0x78,
        0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0x80, 0xc0, 0xe3, 0xff, 0xff, 0xff, 0xfc, 0xfe, 0xfe, 0xef, 0xe7, 0xe3, 0xe3, 0xe1, 0xe0, 0xe0,
        0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xef, 0xff, 0xff, 0xfc, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe0, 0xe0, 0x60, 0x80, 0xf0, 0xff, 0x7f, 0x4f, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe1, 0xe1, 0xe3, 0xe7, 0x6f, 0x7f, 0xfe, 0xfe, 0xff, 0xff, 0x7f, 0x70, 0x60, 0x40, 0x40,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x1e, 0x7e, 0xfc, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1f, 0xff, 0xfe, 0xf8, 0xc0, 0x00, 0x00,
        0x00, 0x00, 0xe0, 0xfc, 0xff, 0x3f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf8, 0xfe, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x3e, 0x3c,
        0x78, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x87, 0x3f, 0xff, 0xfe, 0xf0,
        0xf0, 0xff, 0x7f, 0x8f, 0x81, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0x70, 0x78, 0x3c,
        0x3e, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x06, 0x01, 0x0f, 0x7f,
        0x1f, 0x03, 0x06, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(pentagram, sizeof(pentagram));
}

static char *readable_rgb_mode(void) {
    int mode = rgblight_get_mode();
    static char buf[16];
    if (mode >= RGBLIGHT_MODE_TWINKLE) sprintf(buf, "Twinkle %d", mode - RGBLIGHT_MODE_TWINKLE + 1);
    else if (mode >= RGBLIGHT_MODE_ALTERNATING) sprintf(buf, "Alternating");
    else if (mode >= RGBLIGHT_MODE_RGB_TEST) sprintf(buf, "RGB Test");
    else if (mode >= RGBLIGHT_MODE_STATIC_GRADIENT) sprintf(buf, "Gradient %d", mode - RGBLIGHT_MODE_STATIC_GRADIENT + 1);
    else if (mode >= RGBLIGHT_MODE_CHRISTMAS) sprintf(buf, "Christmas");
    else if (mode >= RGBLIGHT_MODE_KNIGHT) sprintf(buf, "Knight %d", mode - RGBLIGHT_MODE_KNIGHT + 1);
    else if (mode >= RGBLIGHT_MODE_SNAKE) sprintf(buf, "Snake %d", mode - RGBLIGHT_MODE_SNAKE + 1);
    else if (mode >= RGBLIGHT_MODE_RAINBOW_SWIRL) sprintf(buf, "Rainbow swirl %d", mode - RGBLIGHT_MODE_RAINBOW_SWIRL + 1);
    else if (mode >= RGBLIGHT_MODE_RAINBOW_MOOD) sprintf(buf, "Rainbow mood %d", mode - RGBLIGHT_MODE_RAINBOW_MOOD + 1);
    else if (mode >= RGBLIGHT_MODE_BREATHING) sprintf(buf, "Breathing %d", mode - RGBLIGHT_MODE_BREATHING + 1);
    else if (mode >= RGBLIGHT_MODE_STATIC_LIGHT) sprintf(buf, "Solid color");
    return buf;
}

static void render_rgb_stats(void) {
#ifdef RGBLIGHT_ENABLE
    char buf[64];
    snprintf(buf, sizeof(buf), "%s\n\nHue: %d\nSat: %d\nVal: %d\n\n\n\n",
            readable_rgb_mode(),
            rgblight_get_hue(),
            rgblight_get_sat(),
            rgblight_get_val());
    oled_write(buf, false);
#endif
}

void oled_task_user(void) {
    if (timer_elapsed(show_rgb_stats_timer) > 3000) show_rgb_stats = false;

    if (show_rgb_stats) {
        render_rgb_stats();
    } else {
        render_pentagram();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(FINE_VD);
        } else {
            tap_code16(FINE_VU);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
            tap_code(KC_MS_WH_UP);
        }
    }
}
#endif
