#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_keycodes {
  GUI_LAYER = SAFE_RANGE
};

#define _KC_COMS 2
#define _KC_CENT 3
#define KC_NMPAMP   LT(_NUMP, KC_AMPR)   // press for &, hold for layer NUMPAD (numpad)
#define KC_SPCOPT   ALT_T(KC_SPC)        // press for enter, hold for option
#define KC_ESCCM    GUI_T(KC_ESC)        // press for escape, hold for gui/command
#define KC_BSPCTL   CTL_T(KC_BSPC)       // press for backspace, hold for control
#define KC_SHTB     SFT_T(KC_TAB)        // press for tab, hold for shift
#define KC_SHZ      SFT_T(KC_Z)          // press for z, hold for shift
#define KC_SHF      SFT_T(KC_F)          // press for f, hold for shift
#define KC_SHJ      SFT_T(KC_J)          // press for j, hold for shift
#define KC_SHSLSH   SFT_T(KC_SLSH)       // press for slash, hold for shift
#define KC_ENTFN    LT(_FUN, KC_ENT)     // press for enter, hold for function layer
#define KC_OPTB     RALT(KC_TAB)         // option + tab
#define KC_CCSP     RGUI(RCTL(KC_P))     // control + command + p
#define KC_CSTB     S(RGUI(KC_TAB))      // shift + control + tab
#define KC_C_TB     RGUI(KC_TAB)         // control + tab
#define KC_C_LF     RCTL(KC_LEFT)        // control + left
#define KC_C_RT     RCTL(KC_RGHT)        // control + right
#define KC_BRUP     KC_F15               // brightness up on osx
#define KC_BRDN     KC_F14               // brightness down on osx

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0 Base layer - qwerty
   *
   * ,----------------------------------.           ,----------------------------------.
   * |   q  |   w  |   e  |   r  |   t  |           |   y  |   u  |   i  |   o  |   p  |
   * |------+------+------+------+------|           |------+------+------+------+------|
   * |   a  |   s  |   d  |   f  |   g  |           |   h  |   j  |   k  |   l  |   ;  |
   * |------+------+------+------+------|           |------+------+------+------+------|
   * |   z  |   x  |   c  |   v  |   b  |           |   n  |   m  |   ,  |   .  |   /  |
   * `----------------------------------'           `----------------------------------'
   *               ,------------------------.    ,------------------------.
   *          tap  | tab   | esc  | bckspc  |    | space  | enter |  -    |
   *          hold | gui   | shift| ctl     |    | alt    | LT1   | LT2   |
   *               `-------+---------+      |    |        |-------+-------'
   *                                 `------'    `--------'
   */
  [0] = LAYOUT( \
               KC_Q,   KC_W, KC_E, KC_R,   KC_T,     KC_Y, KC_U,   KC_I,    KC_O,   KC_P, \
               KC_A,   KC_S, KC_D, KC_SHF, KC_G,     KC_H, KC_SHJ, KC_K,    KC_L,   KC_SCLN, \
               KC_SHZ, KC_X, KC_C, KC_V,   KC_B,     KC_N, KC_M,   KC_COMM, KC_DOT, KC_SHSLSH, \
               GUI_LAYER, SFT_T(KC_ESC), KC_BSPCTL,  KC_SPCOPT, LT(1,KC_ENTER), LT(2,KC_MINUS) \
                ),

  /* Layer 1 programming symbols and numpad
   *
   * ,----------------------------------.           ,---------------------------------.
   * |   !  |   @  |   {  |   }  |   |  |           |  pgup  |   7  |  8  |  9  |  *  |
   * |------+------+------+------+------|           |--------+------+-----+-----+-----|
   * |   #  |   $  |   (  |   )  |   `  |           |  pgdn  |   4  |  5  |  6  |  +  |
   * |------+------+------+------+------|           |--------+------+-----+-----+-----|
   * |   %  |   ^  |   [  |   ]  |   ~  |           |   0    |   1  |  2  |  3  |  \  |
   * `----------------------------------'           `---------------------------------'
   */
  [1] = LAYOUT( \
               KC_EXLM, KC_AT,  KC_LCBR, KC_RCBR, KC_PIPE,      KC_PGUP, KC_7, KC_8, KC_9, KC_ASTR, \
               KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,     KC_PGDN, KC_4, KC_5, KC_6, KC_PLUS, \
               KC_PERC, KC_CIRC,KC_LBRC, KC_RBRC, KC_TILDE,     KC_0,    KC_1, KC_2, KC_3, KC_BSLS, \
               _______, _______, _______,     _______, _______, _______ \
                ),

  /* layer 2 arrows, nav, etc
   *
   * ,----------------------------------.           ,-----------------------------------.
   * |      |      |⌃←  |  ⌃→ |         |           | pgup  |      |  ↑   |      |      |
   * |------+------+------+------+------|           |-------+------+------+------+------|
   * |      |  end |      |      | home |           | pgdn  |   ←  |  ↓   |  →   |   '  |
   * |------+------+------+------+------|           |-------+------+------+------+------|
   * | ⌥⇥   |      | ⇧⌃⇥ |  ⌃⇥ |      |           |       |      |      |      |  ^   |
   * `----------------------------------'           `-----------------------------------'
   */
  [2] = LAYOUT( \
               _______, _______,  KC_C_LF, KC_C_RT, _______,     KC_PGUP, _______, KC_UP, _______, _______, \
               _______,  KC_END,  _______, _______, KC_HOME,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, \
               KC_OPTB, _______, KC_CSTB, KC_C_TB, _______,     _______, _______, _______, _______, _______, \
               _______, _______, _______,     _______, _______, _______ \
                ),

  /* layer 3 special gui/command functions
     window functions, spectacle app combinations

   */
  [3] = LAYOUT( \
               _______, _______,  _______, _______, _______,     KC_TAB,       _______, _______, LALT(KC_LEFT), LALT(KC_RGHT), \
               _______, _______,  _______, _______, _______,     LSFT(KC_TAB), _______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT), \
               _______, _______,  _______, _______, _______,     _______,      _______, _______, LSFT(LCTL(KC_LEFT)), LSFT(LCTL(KC_RGHT)), \
               _______, KC_TAB, _______,     _______, _______, _______ \
                )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case GUI_LAYER:
    if (record->event.pressed) {
      register_code(KC_LGUI);
      layer_on(3);
    } else {
      layer_off(3);
      unregister_code(KC_LGUI);
    }
    return false;
  }
  return true;
};
