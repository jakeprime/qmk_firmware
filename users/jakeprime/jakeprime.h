#include "quantum.h"

// #ifndef USERSPACE
// #define USERSPACE

#define XX KC_NO
#define OO _______

enum layers {
    _QWERTY = 0,
    _SYMB,
    _NAV,
    _NUMS,
    _MEDIA,
    _DO1,
    _DO2,
    _DO3
};

enum my_keycodes {
  JP_COLN = SAFE_RANGE,
  JP_BLUE,
  JP_RED,
  JP_RNBW
};

#define QWRT_A LCTL_T(KC_A)
#define QWRT_S LALT_T(KC_S)
#define QWRT_D LGUI_T(KC_D)
#define QWRT_F LSFT_T(KC_F)

#define QWRT_J RSFT_T(KC_J)
#define QWRT_K RGUI_T(KC_K)
#define QWRT_L LALT_T(KC_L)
#define QWRT_SC RCTL_T(KC_SCLN)

#define TAB_SYM LT(_SYMB, KC_TAB)
#define CAP_NUM LT(_NUMS, KC_CAPS)
#define ESC_CMD LGUI_T(KC_ESC)

#define ENT_MED LT(_MEDIA, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)
#define X_DO2 LT(_DO2, KC_X)
#define SPC_DO3 LT(_DO3, KC_SPC)

#define H_AMPR LCTL_T(KC_AMPR)
#define H_PIPE LALT_T(KC_PIPE)
#define H_LPRN LGUI_T(KC_LPRN)
#define H_RPRN LSFT_T(KC_RPRN)

#define H_UNDS RSFT_T(KC_UNDS)
#define H_MINS RGUI_T(KC_MINS)
#define H_PLUS LALT_T(KC_PLUS)
#define H_COLN RCTL_T(JP_COLN)
#define JP_HASH RALT(KC_3)

#define FINE_VU LSA(KC_KB_VOLUME_UP)
#define FINE_VD LSA(KC_KB_VOLUME_DOWN)
#define SCR_CPY S(C(G(KC_4)))

// DEFAULT
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DEF_L_3  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_L_2  QWRT_A,       QWRT_S,       QWRT_D,       QWRT_F,       KC_G
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_L_1  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define DEF_L_0                                            TAB_SYM,      CAP_NUM
//                                                        ╰─────────────┴─────────────╯
#define DEF_L_0_3                            ESC_CMD,                DEF_L_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DEF_R_3  KC_Y,         KC_U,         KC_I,         KC_O,         KC_P
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_R_2  KC_H,         QWRT_J,       QWRT_K,       QWRT_L,       QWRT_SC
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_R_1  KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define DEF_R_0  ENT_MED,      SPC_NAV
//              ╰─────────────┴─────────────╯

#define DEF_R_0_3          DEF_R_0,          KC_BSPC

// SYMBOLS
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define SYM_L_3  KC_PLUS,      S(KC_6),      KC_LCBR,      KC_RCBR,      JP_HASH
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_L_2  H_AMPR,       H_PIPE,       H_LPRN,       H_RPRN,       KC_DLR
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_L_1  KC_PERC,      KC_ASTR,      KC_LBRC,      KC_RBRC,      S(KC_3)
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define SYM_L_0                                            _______,      _______
//                                                        ╰─────────────┴─────────────╯
#define SYM_L_0_3                            _______,                SYM_L_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define SYM_R_3  KC_BSLS,      KC_QUOT,      KC_DQUO,      KC_GRV,       KC_AT
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_R_2  KC_TILD,      H_UNDS,       H_MINS,       H_PLUS,       H_COLN
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_R_1  KC_EXLM,      KC_EQL,       KC_LT,        KC_GT,        KC_QUES
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define SYM_R_0  KC_SPC,       KC_BSPC
//              ╰─────────────┴─────────────╯
#define SYM_R_0_3          SYM_R_0,          KC_BSPC

// NAVIGATION
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NAV_L_3  KC_PLUS,      S(KC_6),      KC_LCBR,      KC_RCBR,      JP_HASH
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_L_2  H_AMPR,       H_PIPE,       H_LPRN,       H_RPRN,       KC_DLR
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_L_1  KC_PERC,      KC_ASTR,      KC_LBRC,      KC_RBRC,      S(KC_3)
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define NAV_L_0                                            KC_ESC,       KC_DEL
//                                                        ╰─────────────┴─────────────╯
#define NAV_L_0_3                            _______,                NAV_L_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NAV_R_3  XXXXXXX,      MS_BTN1,      MS_BTN2,      MS_BTN3,      XXXXXXX
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_R_2  KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      XXXXXXX
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_R_1  MS_LEFT,      MS_DOWN,      MS_UP,        MS_RGHT,      XXXXXXX
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define NAV_R_0  _______,      _______
//              ╰─────────────┴─────────────╯
#define NAV_R_0_3          NAV_R_0,          _______

// NUMBERS
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NUM_L_3  _______,      KC_7,         KC_8,         KC_9,         _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_L_2  _______,      KC_4,         KC_5,         KC_6,         _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_L_1  KC_0,         KC_1,         KC_2,         KC_3,         _______
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define NUM_L_0                                            _______,      _______
//                                                        ╰─────────────┴─────────────╯
#define NUM_L_0_3                            _______,                NUM_L_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NUM_R_3  XXXXXXX,      KC_7,         KC_8,         KC_9,         XXXXXXX
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_R_2  KC_PLUS,      KC_4,         KC_5,         KC_6,         KC_ASTR
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_R_1  KC_MINS,      KC_1,         KC_2,         KC_3,         KC_SLSH
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define NUM_R_0  KC_DOT,       KC_0
//              ╰─────────────┴─────────────╯
#define NUM_R_0_3          NUM_R_0,          _______

// MEDIA
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define MED_L_3  _______,      JP_BLUE,      JP_RNBW,      JP_RED,       _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_L_2  UG_TOGG,      UG_SATU,      UG_HUEU,      UG_VALU,      UG_NEXT
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_L_1  KC_SLEP,      UG_SATD,      UG_HUED,      UG_VALD,      UG_PREV
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define MED_L_0                                            _______,      _______
//                                                        ╰─────────────┴─────────────╯
#define MED_L_0_3                            _______,                MED_L_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define MED_R_3  _______,      FINE_VD,      FINE_VU,      _______,      DF(_DO1)
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_R_2  KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      UG_TOGG
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_R_1  SCR_CPY,      KC_MPLY,      KC_MUTE,      _______,      KC_SLEP
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define MED_R_0  _______,      _______
//              ╰─────────────┴─────────────╯
#define MED_R_0_3          MED_R_0,          _______

// DIVNITY: ORIGINAL SIN
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DO1_L_3  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO1_L_2  KC_LCTL,      KC_S,         KC_D,         KC_F,         KC_G
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO1_L_1  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define DO1_L_0                                            X_DO2,        SPC_DO3
//                                                        ╰─────────────┴─────────────╯
#define DO1_L_0_3                            KC_LALT,                DO1_L_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DO1_R_3  _______,      _______,      _______,      _______,      DF(_QWERTY)
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO1_R_2  _______,      _______,      _______,      _______,      _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO1_R_1  _______,      _______,      _______,      _______,      _______
//              ├─────────────┼─────────────┼────────────┴──────────────┴─────────────╯
#define DO1_R_0  _______,      _______
//              ╰─────────────┴─────────────╯
#define DO1_R_0_3          _______,                DO1_R_0

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DO2_L_3  KC_P,         KC_O,         KC_I,         KC_U,         KC_Y
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO2_L_2  KC_SCLN,      KC_L,         KC_K,         KC_J,         KC_H
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO2_L_1  KC_SLSH,      KC_DOT,       KC_COMM,      KC_M,         KC_N
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define DO2_L_0                                            MO(_DO2),     SPC_DO3
//                                                        ╰─────────────┴─────────────╯
#define DO2_L_0_3                            KC_LALT,                DO2_L_0


//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DO3_L_3  _______,      KC_7,         KC_8,         KC_9,         _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO3_L_2  KC_0,         KC_1,         KC_2,         KC_3,         _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DO3_L_1  _______,      KC_4,         KC_5,         KC_6,         _______
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define DO3_L_0                                            MO(_DO2),      SPC_DO3
//                                                        ╰─────────────┴─────────────╯
#define DO3_L_0_3                            KC_LALT,                DO3_L_0


#define DEF_3_6 XX, DEF_L_3, DEF_R_3, XX
#define DEF_2_6 XX, DEF_L_2, DEF_R_2, XX
#define DEF_1_6 XX, DEF_L_1, DEF_R_1, XX
#define DEF_1_8 XX, DEF_L_1, XX, XX, XX, XX, DEF_R_1, XX
#define DEF_0_5 XX, DEF_L_0_3, XX, XX, DEF_R_0_3, XX
#define DEF_0_3 DEF_L_0_3, DEF_R_0_3

#define SYM_3_6 XX, SYM_L_3, SYM_R_3, XX
#define SYM_2_6 XX, SYM_L_2, SYM_R_2, XX
#define SYM_1_6 XX, SYM_L_1, SYM_R_1, XX
#define SYM_1_8 XX, SYM_L_1, XX, XX, XX, XX, SYM_R_1, XX
#define SYM_0_5 XX, SYM_L_0_3, XX, XX, SYM_R_0_3, XX
#define SYM_0_3 SYM_L_0_3, SYM_R_0_3

#define NAV_3_6 XX, NAV_L_3, NAV_R_3, XX
#define NAV_2_6 XX, NAV_L_2, NAV_R_2, XX
#define NAV_1_6 XX, NAV_L_1, NAV_R_1, XX
#define NAV_1_8 XX, NAV_L_1, XX, XX, XX, XX, NAV_R_1, XX
#define NAV_0_5 XX, NAV_L_0_3, XX, XX, NAV_R_0_3, XX
#define NAV_0_3 NAV_L_0_3, NAV_R_0_3

#define NUM_3_6 XX, NUM_L_3, NUM_R_3, XX
#define NUM_2_6 XX, NUM_L_2, NUM_R_2, XX
#define NUM_1_6 XX, NUM_L_1, NUM_R_1, XX
#define NUM_1_8 XX, NUM_L_1, XX, XX, XX, XX, NUM_R_1, XX
#define NUM_0_5 XX, NUM_L_0_3, XX, XX, NUM_R_0_3, XX
#define NUM_0_3 NUM_L_0_3, NUM_R_0_3

#define MED_3_6 XX, MED_L_3, MED_R_3, XX
#define MED_2_6 XX, MED_L_2, MED_R_2, XX
#define MED_1_6 XX, MED_L_1, MED_R_1, XX
#define MED_1_8 XX, MED_L_1, XX, XX, XX, XX, MED_R_1, XX
#define MED_0_5 XX, MED_L_0_3, XX, XX, MED_R_0_3, XX
#define MED_0_3 MED_L_0_3, MED_R_0_3

#define DO1_3_6 XX, DO1_L_3, DO1_R_3, XX
#define DO1_2_6 XX, DO1_L_2, DO1_R_2, XX
#define DO1_1_6 XX, DO1_L_1, DO1_R_1, XX
#define DO1_1_8 XX, DO1_L_1, XX, XX, XX, XX, DO1_R_1, XX
#define DO1_0_5 XX, DO1_L_0_3, XX, XX, DO1_R_0_3, XX
#define DO1_0_3 DO1_L_0_3, DO1_R_0_3

#define DO2_3_6 XX, DO2_L_3, DO1_R_3, XX
#define DO2_2_6 XX, DO2_L_2, DO1_R_2, XX
#define DO2_1_6 XX, DO2_L_1, DO1_R_1, XX
#define DO2_1_8 XX, DO2_L_1, XX, XX, XX, XX, DO1_R_1, XX
#define DO2_0_5 XX, DO2_L_0_3, XX, XX, DO1_R_0_3, XX
#define DO2_0_3 DO2_L_0_3, DO1_R_0_3

#define DO3_3_6 XX, DO3_L_3, DO1_R_3, XX
#define DO3_2_6 XX, DO3_L_2, DO1_R_2, XX
#define DO3_1_6 XX, DO3_L_1, DO1_R_1, XX
#define DO3_1_8 XX, DO3_L_1, XX, XX, XX, XX, DO1_R_1, XX
#define DO3_0_5 XX, DO3_L_0_3, XX, XX, DO1_R_0_3, XX
#define DO3_0_3 DO3_L_0_3, DO1_R_0_3

#define DEF_KYRIA DEF_3_6, DEF_2_6, DEF_1_8, DEF_0_5
#define SYM_KYRIA SYM_3_6, SYM_2_6, SYM_1_8, SYM_0_5
#define NAV_KYRIA NAV_3_6, NAV_2_6, NAV_1_8, NAV_0_5
#define NUM_KYRIA NUM_3_6, NUM_2_6, NUM_1_8, NUM_0_5
#define MED_KYRIA MED_3_6, MED_2_6, MED_1_8, MED_0_5
#define DO1_KYRIA DO1_3_6, DO1_2_6, DO1_1_8, DO1_0_5
#define DO2_KYRIA DO2_3_6, DO2_2_6, DO2_1_8, DO2_0_5
#define DO3_KYRIA DO3_3_6, DO3_2_6, DO3_1_8, DO3_0_5

#define DEF_CRKBD DEF_3_6, DEF_2_6, DEF_1_6, DEF_0_3
#define SYM_CRKBD SYM_3_6, SYM_2_6, SYM_1_6, SYM_0_3
#define NAV_CRKBD NAV_3_6, NAV_2_6, NAV_1_6, NAV_0_3
#define NUM_CRKBD NUM_3_6, NUM_2_6, NUM_1_6, NUM_0_3
#define MED_CRKBD MED_3_6, MED_2_6, MED_1_6, MED_0_3
