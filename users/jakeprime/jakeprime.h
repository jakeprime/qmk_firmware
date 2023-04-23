#include "quantum.h"

#define _QWERTY 0

#define XX KC_NO

// DEFAULT
//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DEF_L_3  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_L_2  KC_A,         KC_S,         KC_D,         KC_F,         KC_G
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_L_1  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B
//              ╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┤
#define DEF_L_0                                            KC_TAB,       KC_CAPS
//                                                        ╰-------------┴-------------╯

//              ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
#define DEF_R_3  KC_Y,         KC_U,         KC_I,         KC_O,         KC_P
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_R_2  KC_H,         KC_J,         KC_K,         KC_L,         KC_SCLN
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define DEF_R_1  KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define DEF_R_0  KC_ENT,       KC_SPC
//              ╰-------------┴-------------╯

#define DEF_3_KYRIA XX, DEF_L_3, DEF_R_3, XX
#define DEF_2_KYRIA XX, DEF_L_2, DEF_R_2, XX
#define DEF_1_KYRIA XX, DEF_L_1, XX, XX, XX, XX, DEF_R_1, XX
#define DEF_0_KYRIA XX, XX, DEF_L_0, XX, XX, DEF_R_0, XX, XX

#define DEF_KYRIA DEF_3_KYRIA, DEF_2_KYRIA, DEF_1_KYRIA, DEF_0_KYRIA
