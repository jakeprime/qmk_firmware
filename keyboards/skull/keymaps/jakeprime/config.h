#pragma once

#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK

// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
#define PERMISSIVE_HOLD

#define TAPPING_FORCE_HOLD

#define TAPPING_TERM 175

// Without this double tapping a key will use the tap even if you hold it and that
// is bad news for home row mods
#define QUICK_TAP_TERM 0

// I think this is the right map, but I suspect it doesn't play nice with the eyes
/* #define RGBLIGHT_LED_MAP { 3, 4, 2, 5, 1, 6, 0, 7, 10, 11, 12, 8, 9, 22, 21, 23, 24, 25, 13, 20, 19, 14, 18, 15, 17, 16} */
