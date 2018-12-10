#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0 Base layer - qwerty
   *
   * ,----------------------------------.           ,----------------------------------.
   * |   q  |   w  |   e  |   r  |   t  |           |   y  |   u  |   i  |   o  |   p  |
   * |------+------+------+------+------|           |------+------+------+------+------|
   * |   a  |   s  |  !d  |  !f  |   g  |           |   h  |  !j  |   k  |   l  |   ;  |
   * |------+------+------+------+------|           |------+------+------+------+------|
   * |   z  |   x  |   c  |   v  |   b  |           |   n  |   m  |   ,  |   .  |  LT1 |
   * `----------------------------------'           `----------------------------------'
   *               ,------------------------.    ,------------------------.
   *          tap  |       | esc  | bckspc  |    | space  | enter |       |
   *          hold |LT+gui |      | ctl     |    | alt    |       | LT2   |
   *               `-------+---------+      |    |        |-------+-------'
   *                                 `------'    `--------'
   */
  [0] = LAYOUT( \
               KC_Q, KC_W, KC_E,        KC_R,        KC_T,     KC_Y, KC_U,        KC_I,    KC_O,   KC_P, \
               KC_A, KC_S, LT(4, KC_D), SFT_T(KC_F), KC_G,     KC_H, SFT_T(KC_J), KC_K,    KC_L,   KC_SCLN, \
               KC_Z, KC_X, KC_C,        KC_V,        KC_B,     KC_N, KC_M,        KC_COMM, KC_DOT, OSL(1), \
               LM(3,MOD_LGUI), KC_ESC, CTL_T(KC_BSPC),  ALT_T(KC_SPC), KC_ENTER, MO(2) \
                ),

  /* Layer 1 programming symbols and numpad
   * Had to use S(KC_P) for colon because of qwerty to colemak translation at the OS
   * ,----------------------------------.           ,------------------------------.
   * |   !  |   @  |   {  |   }  |   |  |           |  &  |   <  |  >  |  +  |  *  |
   * |------+------+------+------+------|           |-----+------+-----+-----+-----|
   * |   #  |   $  |   (  |   )  |   `  |           |  '  |   "  |  ?  |  :  |  =  |
   * |------+------+------+------+------|           |-----+------+-----+-----+-----|
   * |   %  |   ^  |   [  |   ]  |   ~  |           |     |   -  |  _  |  /  |  \  |
   * `----------------------------------'           `------------------------------'
   */
  [1] = LAYOUT( \
               KC_EXLM, KC_AT,  KC_LCBR, KC_RCBR, KC_PIPE,      KC_AMPR, KC_LT,   KC_GT,   KC_PLUS, KC_ASTR, \
               KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,     KC_QUOT, KC_DQT,  KC_QUES, S(KC_P), KC_EQL, \
               KC_PERC, KC_CIRC,KC_LBRC, KC_RBRC, KC_TILDE,     _______, KC_MINUS, KC_UNDS, KC_SLSH, KC_BSLS, \
               _______, KC_DEL, _______,     _______, _______, _______ \
                ),

  /* layer 2 arrows, nav, etc
   * tab, app window switching, browser tab switching
   *
   * ,----------------------------------.           ,-----------------------------------.
   * |      |      | s-tab| tab  | home |           | pgup  | s-tab|  ↑   | tab  |      |
   * |------+------+------+------+------|           |-------+------+------+------+------|
   * |      |      | g-~  | g-`  | end  |           | pgdn  |   ←  |  ↓   |  →   |      |
   * |------+------+------+------+------|           |-------+------+------+------+------|
   * |      |      | ctr  | ctr  |      |           |       |      |      |      |      |
   * |      |      | s-tab| tab  |      |           |       |      |      |      |      |
   * `----------------------------------'           `-----------------------------------'
   */
  [2] = LAYOUT( \
               _______, _______, S(KC_TAB),         KC_TAB,         KC_HOME,     KC_PGUP, S(KC_TAB), KC_UP,   KC_TAB,  _______, \
               _______, _______, LGUI(S(KC_GRAVE)), LGUI(KC_GRAVE), KC_END,      KC_PGDN, KC_LEFT,   KC_DOWN, KC_RGHT, _______, \
               _______, _______, LCTL(S(KC_TAB)),   LCTL(KC_TAB),   _______,     _______, _______,   _______, _______, _______, \
               _______, _______, _______,     _______, _______, _______ \
                ),

  /* layer 3 special gui/command functions
     window functions, spectacle app combinations
     cmd tab window switcher
   */
  [3] = LAYOUT( \
               _______, _______,  _______, _______, _______,     _______, _______, _______, LALT(KC_LEFT), LALT(KC_RGHT), \
               _______, _______,  _______, _______, _______,     _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT), \
               _______, _______,  _______, _______, _______,     _______, _______, _______, LSFT(LCTL(KC_LEFT)), LSFT(LCTL(KC_RGHT)), \
               _______, KC_TAB, _______,     _______, _______, _______  \
                ),

  /* layer 4 numpad
  */
  [4] = LAYOUT( \
               _______, _______,  _______, _______, _______,     _______, KC_7, KC_8, KC_9, _______, \
               _______, _______,  _______, _______, _______,     _______, KC_4, KC_5, KC_6, _______, \
               _______, _______,  _______, _______, _______,     _______, KC_1, KC_2, KC_3, _______,
               _______, _______, _______,      KC_0, _______, _______  \
                )
};

