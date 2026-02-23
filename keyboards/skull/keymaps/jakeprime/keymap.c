#include QMK_KEYBOARD_H
#include "jakeprime.h"

/* enum keymap_keycodes { */
/*     EY_TOGG = QK_USER_0, */
/*     EY_HUE, */
/*     EY_SAT, */
/*     EY_VAL, */
/* }; */

#include "transactions.h"
#include "color.h"

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
#define NAV_L_1  KC_PERC,      KC_ASTR,      KC_LBRC,      KC_RBRC,      JP_POUND
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
#define MED_R_3  _______,      FINE_VD,      FINE_VU,      _______,      _______
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_R_2  KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      UG_TOGG
//              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
#define MED_R_1  SCR_CPY,      KC_MPLY,      KC_MUTE,      _______,      KC_SLEP
//              ├─────────────┼─────────────┼─────────────┴─────────────┴─────────────╯
#define MED_R_0  _______,      _______
//              ╰─────────────┴─────────────╯
#define MED_R_0_3          MED_R_0,          _______


#define DEF_3_5 DEF_L_3, DEF_R_3
#define DEF_2_5 DEF_L_2, DEF_R_2
#define DEF_1_5 DEF_L_1, DEF_R_1
#define DEF_0_2 DEF_L_0, DEF_R_0
#define DEF_3_6 XX, DEF_3_5, XX
#define DEF_2_6 XX, DEF_2_5, XX
#define DEF_1_6 XX, DEF_1_5, XX
#define DEF_1_8 XX, DEF_L_1, XX, XX, XX, XX, DEF_R_1, XX
#define DEF_0_5 XX, DEF_L_0_3, XX, XX, DEF_R_0_3, XX
#define DEF_0_3 DEF_L_0_3, DEF_R_0_3

#define SYM_3_5 SYM_L_3, SYM_R_3
#define SYM_2_5 SYM_L_2, SYM_R_2
#define SYM_1_5 SYM_L_1, SYM_R_1
#define SYM_0_2 SYM_L_0, SYM_R_0
#define SYM_3_6 XX, SYM_3_5, XX
#define SYM_2_6 XX, SYM_2_5, XX
#define SYM_1_6 XX, SYM_1_5, XX
#define SYM_1_8 XX, SYM_L_1, XX, XX, XX, XX, SYM_R_1, XX
#define SYM_0_5 XX, SYM_L_0_3, XX, XX, SYM_R_0_3, XX
#define SYM_0_3 SYM_L_0_3, SYM_R_0_3

#define NAV_3_5 NAV_L_3, NAV_R_3
#define NAV_2_5 NAV_L_2, NAV_R_2
#define NAV_1_5 NAV_L_1, NAV_R_1
#define NAV_0_2 NAV_L_0, NAV_R_0
#define NAV_3_6 XX, NAV_3_5, XX
#define NAV_2_6 XX, NAV_2_5, XX
#define NAV_1_6 XX, NAV_1_5, XX
#define NAV_1_8 XX, NAV_L_1, XX, XX, XX, XX, NAV_R_1, XX
#define NAV_0_5 XX, NAV_L_0_3, XX, XX, NAV_R_0_3, XX
#define NAV_0_3 NAV_L_0_3, NAV_R_0_3

#define NUM_3_5 NUM_L_3, NUM_R_3
#define NUM_2_5 NUM_L_2, NUM_R_2
#define NUM_1_5 NUM_L_1, NUM_R_1
#define NUM_0_2 NUM_L_0, NUM_R_0
#define NUM_3_6 XX, NUM_3_5, XX
#define NUM_2_6 XX, NUM_2_5, XX
#define NUM_1_6 XX, NUM_1_5, XX
#define NUM_1_8 XX, NUM_L_1, XX, XX, XX, XX, NUM_R_1, XX
#define NUM_0_5 XX, NUM_L_0_3, XX, XX, NUM_R_0_3, XX
#define NUM_0_3 NUM_L_0_3, NUM_R_0_3

#define MED_3_5 MED_L_3, MED_R_3
#define MED_2_5 MED_L_2, MED_R_2
#define MED_1_5 MED_L_1, MED_R_1
#define MED_0_2 MED_L_0, MED_R_0
#define MED_3_6 XX, MED_3_5, XX
#define MED_2_6 XX, MED_2_5, XX
#define MED_1_6 XX, MED_1_5, XX
#define MED_1_8 XX, MED_L_1, XX, XX, XX, XX, MED_R_1, XX
#define MED_0_5 XX, MED_L_0_3, XX, XX, MED_R_0_3, XX
#define MED_0_3 MED_L_0_3, MED_R_0_3

#define DEF_KYRIA DEF_3_6, DEF_2_6, DEF_1_8, DEF_0_5
#define SYM_KYRIA SYM_3_6, SYM_2_6, SYM_1_8, SYM_0_5
#define NAV_KYRIA NAV_3_6, NAV_2_6, NAV_1_8, NAV_0_5
#define NUM_KYRIA NUM_3_6, NUM_2_6, NUM_1_8, NUM_0_5
#define MED_KYRIA MED_3_6, MED_2_6, MED_1_8, MED_0_5

#define DEF_CRKBD DEF_3_6, DEF_2_6, DEF_1_6, DEF_0_3
#define SYM_CRKBD SYM_3_6, SYM_2_6, SYM_1_6, SYM_0_3
#define NAV_CRKBD NAV_3_6, NAV_2_6, NAV_1_6, NAV_0_3
#define NUM_CRKBD NUM_3_6, NUM_2_6, NUM_1_6, NUM_0_3
#define MED_CRKBD MED_3_6, MED_2_6, MED_1_6, MED_0_3

#define DEF_SKULL DEF_3_5, DEF_2_5, DEF_1_5, DEF_0_3
#define SYM_SKULL SYM_3_5, SYM_2_5, SYM_1_5, SYM_0_3
#define NAV_SKULL NAV_3_5, NAV_2_5, NAV_1_5, NAV_0_3
#define NUM_SKULL NUM_3_5, NUM_2_5, NUM_1_5, NUM_0_3
#define MED_SKULL MED_3_5, MED_2_5, MED_1_5, MED_0_3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY]=LAYOUT_split_3x5_2(
KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,QWRT_A,QWRT_S,QWRT_D,QWRT_F,KC_G,KC_H,QWRT_J,QWRT_K,QWRT_L,QWRT_SC,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,TAB_SYM,CAP_NUM,ENT_MED,SPC_NAV
                             ),
[_SYMB]=LAYOUT_split_3x5_2(
                           KC_PLUS,S(KC_6),KC_LCBR,KC_RCBR,JP_HASH,KC_BSLS,KC_QUOT,KC_DQUO,KC_GRV,KC_AT,H_AMPR,H_PIPE,H_LPRN,H_RPRN,KC_DLR,KC_TILD,H_UNDS,H_MINS,H_PLUS,H_COLN,KC_PERC,KC_ASTR,KC_LBRC,KC_RBRC,S(KC_3),KC_EXLM,KC_EQL,KC_LT,KC_GT,KC_QUES,_______,_______,KC_SPC,KC_BSPC
                           ),

[_NAV] = LAYOUT_split_3x5_2(
                            KC_PLUS,      S(KC_6),      KC_LCBR,      KC_RCBR,      JP_HASH,
                            XXXXXXX,      MS_BTN1,      MS_BTN2,      MS_BTN3,      XXXXXXX,
                            H_AMPR,       H_PIPE,       H_LPRN,       H_RPRN,       KC_DLR,
                            KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      XXXXXXX,
                            KC_PERC,      KC_ASTR,      KC_LBRC,      KC_RBRC,      JP_POUND,
                            MS_LEFT,      MS_DOWN,      MS_UP,        MS_RGHT,      XXXXXXX,
                            KC_ESC,       KC_DEL,
                            _______,      _______
                            ),

[_NUMS] = LAYOUT_split_3x5_2(
_______,      KC_7,         KC_8,         KC_9,         _______,
XXXXXXX,      KC_7,         KC_8,         KC_9,         XXXXXXX,
_______,      KC_4,         KC_5,         KC_6,         _______,
KC_PLUS,      KC_4,         KC_5,         KC_6,         KC_ASTR,
KC_0,         KC_1,         KC_2,         KC_3,         _______,
KC_MINS,      KC_1,         KC_2,         KC_3,         KC_SLSH,
_______,      _______,
KC_DOT,       KC_0
                             ),

[_MEDIA] = LAYOUT_split_3x5_2(
_______,      JP_BLUE,      JP_RNBW,      JP_RED,       _______,
_______,      FINE_VD,      FINE_VU,      _______,      _______,
UG_TOGG,      UG_SATU,      UG_HUEU,      UG_VALU,      UG_NEXT,
KC_MPRV,      KC_VOLD,      KC_VOLU,      KC_MNXT,      UG_TOGG,
KC_SLEP,      UG_SATD,      UG_HUED,      UG_VALD,      UG_PREV,
SCR_CPY,      KC_MPLY,      KC_MUTE,      _______,      KC_SLEP,
                                          _______,      _______,
_______,      _______
                              )
};

/* typedef union eyergb_config_t { */
/*     uint32_t raw; */
/*     struct { */
/*         bool    enable : 1; */
/*         uint8_t hue : 8; */
/*         uint8_t sat : 8; */
/*         uint8_t val : 8; */
/*     }; */
/* } eyergb_config_t; */

/* eyergb_config_t user_eyeconfig = { */
/*     .enable = true, */
/*     .hue = 8, */
/*     .sat = 255, */
/*     .val = 255 */
/* }; */

/* void set_eyehsv(bool enable, uint8_t hue, uint8_t sat, uint8_t val){ */

/*     if (user_eyeconfig.enable){ */
/*         hsv_t hsv = {hue,sat,val}; */
/*         rgb_t colour = hsv_to_rgb(hsv); */
/*         for (uint8_t i = 10; i < 13; i++) { */
/*             rgblight_driver.set_color(i, colour.r, colour.g, colour.b); */
/*         } */
/*     } else { */
/*         for (uint8_t i = 10; i < 13; i++) { */
/*             rgblight_driver.set_color(i, 0, 0, 0); */
/*         } */
/*     } */

/*     rgblight_driver.flush(); */
/* } */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*     case EY_TOGG: */
/*         if (record->event.pressed) { */
/*             user_eyeconfig.enable = !user_eyeconfig.enable; */
/*             set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/*         } */
/*         break; */
/*     case EY_HUE: */
/*         if (record->event.pressed) { */
/*             user_eyeconfig.hue = user_eyeconfig.hue + RGBLIGHT_HUE_STEP; */
/*             set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/*         } */
/*         break; */
/*     case EY_SAT: */
/*         if (record->event.pressed) { */
/*             user_eyeconfig.sat = user_eyeconfig.sat + RGBLIGHT_SAT_STEP; */
/*             set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/*         } */
/*         break; */
/*     case EY_VAL: */
/*         if (record->event.pressed) { */
/*             user_eyeconfig.val = user_eyeconfig.val + RGBLIGHT_VAL_STEP; */
/*             set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/*         } */
/*         break; */
/*     } */
/*     return true; */
/* }; */

/* void user_sync_eyehsv_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) { */
/*     const eyergb_config_t *m2s = (const eyergb_config_t*)in_data; */

/*     if (user_eyeconfig.raw != m2s->raw){ */
/*         user_eyeconfig.raw = m2s->raw; */
/*         set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/*     } */
/* } */

/* void eeconfig_init_user(void) { */
/*   user_eyeconfig.raw = 0; */
/*   user_eyeconfig.enable = 1; */
/*   user_eyeconfig.hue = 0; */
/*   user_eyeconfig.sat = 255; */
/*   user_eyeconfig.val = 255; */

/*   eeconfig_update_user(user_eyeconfig.raw); */

/*   set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/* } */

/* void keyboard_post_init_user(void){ */
/*     user_eyeconfig.raw = eeconfig_read_user(); */
/*     if (is_keyboard_left()){ */
/*         rgblight_set_effect_range(0, 10); */
/*     } else { */
/*         rgblight_set_effect_range(13, 10); */
/*     } */
/*     transaction_register_rpc(USER_SYNC_A, user_sync_eyehsv_handler); */
/*     set_eyehsv(user_eyeconfig.enable,user_eyeconfig.hue,user_eyeconfig.sat,user_eyeconfig.val); */
/* } */

/* void housekeeping_task_user(void) { */
/*     if (is_keyboard_master()) { */
/*         static uint32_t last_sync = 0; */
/*         if (timer_elapsed32(last_sync) > 100) { */
/*             if(transaction_rpc_send(USER_SYNC_A, sizeof(user_eyeconfig), &user_eyeconfig)) { */
/*                 last_sync = timer_read32(); */
/*             } */
/*         } */
/*     } */

/*     static uint32_t eeprom_sync = 0; */
/*     if (timer_elapsed32(eeprom_sync) > 10000) { // check user eeprom every 10 seconds */
/*         uint32_t raw = eeconfig_read_user(); */
/*         if(raw != user_eyeconfig.raw) { */
/*                 raw = user_eyeconfig.raw; */
/*                 eeconfig_update_user(raw); */
/*         } */
/*     } */
/* } */
