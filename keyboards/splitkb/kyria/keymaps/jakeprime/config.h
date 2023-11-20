#pragma once

/* #define JP_LIGHT_SIDE */
#define JP_MASTER
/* #define CLEO */
#define SATANIC
#define FULL_LIGHTS

#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_EFFECT_BREATHING
#  define RGBLIGHT_EFFECT_RAINBOW_MOOD
#  define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#  define RGBLIGHT_EFFECT_SNAKE
#  define RGBLIGHT_EFFECT_KNIGHT
#  define RGBLIGHT_EFFECT_CHRISTMAS
#  define RGBLIGHT_EFFECT_STATIC_GRADIENT
#  define RGBLIGHT_EFFECT_RGB_TEST
#  define RGBLIGHT_EFFECT_ALTERNATING
#  define RGBLIGHT_EFFECT_TWINKLE
#  define RGBLIGHT_HUE_STEP 8
#  define RGBLIGHT_SAT_STEP 8
#  define RGBLIGHT_VAL_STEP 8
#  ifdef RGBLED_NUM
#    undef RGBLED_NUM
#  endif
#  ifdef RGBLED_SPLIT
#    undef RGBLED_SPLIT
#  endif
#  ifdef FULL_LIGHTS
#    define RGBLED_NUM 32
#    define RGBLED_SPLIT { 16, 16 }
#    define RGBLIGHT_LED_MAP { 7, 5, 3, 5, 3, 0, 0, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 10, 12, 15, 15, 14, 15, 14, 13, 12, 11, 10, 9, 8 }
#    ifdef RGBLIGHT_LIMIT_VAL
#      undef RGBLIGHT_LIMIT_VAL
#    endif
#    define RGBLIGHT_LIMIT_VAL 220
#  else
#    define RGBLED_NUM 16
#    define RGBLED_SPLIT { 8, 8 }
#    define RGBLIGHT_LED_MAP { 7, 5, 3, 5, 3, 0, 0, 1, 8, 10, 12, 10, 12, 15, 15 }
#  endif
#endif

// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
#define PERMISSIVE_HOLD

// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_FORCE_HOLD

#define TAPPING_TERM 175

// Without this double tapping a key will use the tap even if you hold it and that
// is bad news for home row mods
#define QUICK_TAP_TERM 0
