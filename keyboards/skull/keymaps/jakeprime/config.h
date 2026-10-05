#pragma once

#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A


// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
#define PERMISSIVE_HOLD

#define TAPPING_FORCE_HOLD

#define TAPPING_TERM 175

// Without this double tapping a key will use the tap even if you hold it and that
// is bad news for home row mods
#define QUICK_TAP_TERM 0
