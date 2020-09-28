#include "config_common.h"
#define TAPPING_TERM 200
#define FORCE_NKRO
#define QMK_KEYS_PER_SCAN 4
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* plug the usb into the right side */
#define MASTER_RIGHT

/* shorter because there is no cancel right now */
#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */
