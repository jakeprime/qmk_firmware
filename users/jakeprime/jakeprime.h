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
    _MEDIA
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
//                                                        ╰-------------┴-------------╯

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DEF_R_3  KC_Y,         KC_U,         KC_I,         KC_O,         KC_P
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_R_2  KC_H,         QWRT_J,       QWRT_K,       QWRT_L,       QWRT_SC
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_R_1  KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define DEF_R_0  ENT_MED,      SPC_NAV
//              ╰-------------┴-------------╯

// SYMBOLS
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define SYM_L_3  KC_PLUS,      S(KC_6),      KC_LCBR,      KC_RCBR,      JP_HASH
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_L_2  H_AMPR,       H_PIPE,       H_LPRN,       H_RPRN,       KC_DLR
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_L_1  KC_PERC,      KC_ASTR,      KC_LBRC,      KC_RBRC,      S(KC_3)
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define SYM_L_0                                            _______,      _______
//                                                        ╰-------------┴-------------╯

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define SYM_R_3  KC_BSLS,      KC_QUOT,      KC_DQUO,      KC_GRV,       KC_AT
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_R_2  KC_TILD,      H_UNDS,       H_MINS,       H_PLUS,       H_COLN
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define SYM_R_1  KC_EXLM,      KC_EQL,       KC_LT,        KC_GT,        KC_QUES
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define SYM_R_0  KC_SPC,       KC_BSPC
//              ╰-------------┴-------------╯

// NAVIGATION
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NAV_L_3  KC_PLUS,      S(KC_6),      KC_LCBR,      KC_RCBR,      JP_HASH
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_L_2  H_AMPR,       H_PIPE,       H_LPRN,       H_RPRN,       KC_DLR
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_L_1  KC_PERC,      KC_ASTR,      KC_LBRC,      KC_RBRC,      S(KC_3)
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define NAV_L_0                                            KC_ESC,       KC_DEL
//                                                        ╰-------------┴-------------╯

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NAV_R_3  XXXXXXX,      KC_BTN1,      KC_BTN2,      KC_BTN3,      XXXXXXX
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_R_2  KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      XXXXXXX
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NAV_R_1  KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      XXXXXXX
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define NAV_R_0  _______,      _______
//              ╰-------------┴-------------╯

// NUMBERS
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NUM_L_3  _______,      _______,      _______,      _______,      _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_L_2  _______,      _______,      _______,      _______,      _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_L_1  _______,      _______,      _______,      _______,      _______
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define NUM_L_0                                            _______,      _______
//                                                        ╰-------------┴-------------╯

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define NUM_R_3  XXXXXXX,      KC_7,         KC_8,         KC_9,         XXXXXXX
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_R_2  KC_PLUS,      KC_4,         KC_5,         KC_6,         KC_ASTR
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define NUM_R_1  KC_MINS,      KC_1,         KC_2,         KC_3,         KC_SLSH
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define NUM_R_0  KC_DOT,       KC_0
//              ╰-------------┴-------------╯

// MEDIA
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define MED_L_3  _______,      JP_BLUE,      JP_RNBW,      JP_RED,       _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_L_2  RGB_TOG,      RGB_SAI,      RGB_HUI,      RGB_VAI,      RGB_MOD
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_L_1  KC_SLEP,      RGB_SAD,      RGB_HUD,      RGB_VAD,      RGB_RMOD
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define MED_L_0                                            _______,      _______
//                                                        ╰-------------┴-------------╯

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define MED_R_3  _______,      FINE_VD,      FINE_VU,      _______,      _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_R_2  KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      RGB_TOG
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_R_1  SCR_CPY,      KC_MPLY,      KC_MUTE,      _______,      KC_SLEP
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define MED_R_0  _______,      _______
//              ╰-------------┴-------------╯

#define DEF_3_KYRIA XX, DEF_L_3, DEF_R_3, XX
#define DEF_2_KYRIA XX, DEF_L_2, DEF_R_2, XX
#define DEF_1_KYRIA XX, DEF_L_1, XX, XX, XX, XX, DEF_R_1, XX
#define DEF_0_KYRIA XX, ESC_CMD, DEF_L_0, XX, XX, DEF_R_0, KC_BSPC, XX

#define SYM_3_KYRIA XX, SYM_L_3, SYM_R_3, XX
#define SYM_2_KYRIA XX, SYM_L_2, SYM_R_2, XX
#define SYM_1_KYRIA XX, SYM_L_1, XX, XX, XX, XX, SYM_R_1, XX
#define SYM_0_KYRIA XX, OO, SYM_L_0, XX, XX, SYM_R_0, OO, XX

#define NAV_3_KYRIA XX, NAV_L_3, NAV_R_3, XX
#define NAV_2_KYRIA XX, NAV_L_2, NAV_R_2, XX
#define NAV_1_KYRIA XX, NAV_L_1, XX, XX, XX, XX, NAV_R_1, XX
#define NAV_0_KYRIA XX, OO, NAV_L_0, XX, XX, NAV_R_0, OO, XX

#define NUM_3_KYRIA XX, NUM_L_3, NUM_R_3, XX
#define NUM_2_KYRIA XX, NUM_L_2, NUM_R_2, XX
#define NUM_1_KYRIA XX, NUM_L_1, XX, XX, XX, XX, NUM_R_1, XX
#define NUM_0_KYRIA XX, OO, NUM_L_0, XX, XX, NUM_R_0, OO, XX

#define MED_3_KYRIA XX, MED_L_3, MED_R_3, XX
#define MED_2_KYRIA XX, MED_L_2, MED_R_2, XX
#define MED_1_KYRIA XX, MED_L_1, XX, XX, XX, XX, MED_R_1, XX
#define MED_0_KYRIA XX, OO, MED_L_0, XX, XX, MED_R_0, OO, XX

#define DEF_KYRIA DEF_3_KYRIA, DEF_2_KYRIA, DEF_1_KYRIA, DEF_0_KYRIA
#define SYM_KYRIA SYM_3_KYRIA, SYM_2_KYRIA, SYM_1_KYRIA, SYM_0_KYRIA
#define NAV_KYRIA NAV_3_KYRIA, NAV_2_KYRIA, NAV_1_KYRIA, NAV_0_KYRIA
#define NUM_KYRIA NUM_3_KYRIA, NUM_2_KYRIA, NUM_1_KYRIA, NUM_0_KYRIA
#define MED_KYRIA MED_3_KYRIA, MED_2_KYRIA, MED_1_KYRIA, MED_0_KYRIA
