#include QMK_KEYBOARD_H

/* extern keymap_config_t keymap_config; */


#define ____ KC_TRNS

enum custom_layers {
                    _BASE,
                    _SYM,
                    _NAV,
                    _MACROS,
                    _NUMPAD
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {




  /* 0 Base layer - qwerty
   *
   * ,----------------------------------.           ,----------------------------------.
   * |   q  |   w  |   e  |   r  |   t  |           |   y  |   u  |   i  |   o  |  !p  |
   * |------+------+------+------+------|           |------+------+------+------+------|
   * |   a  |   s  |  !d  |  !f  |   g  |           |   h  |  !j  |   k  |   l  |   ;  |
   * |------+------+------+------+------|           |------+------+------+------+------|
   * |   z  |   x  |   c  |   v  |   b  |           |   n  |   m  |   ,  |   .  |  LT1 |
   * `----------------------------------'           `----------------------------------'
   *               ,------------------------.    ,------------------------.
   *        tap->  |       | esc  | bckspc  |    | space  | enter |       |
   *        hold-> |Macros |      | ctl     |    | alt    |       | LT2   |
   *               |  +gui |      |         |    |        |       |       |
   *               `-------+---------+      |    |        |-------+-------'
   *                                 `------'    `--------'
   */
  [_BASE] = LAYOUT( \
               KC_Q, KC_W, KC_E,        KC_R,        KC_T,     KC_Y, KC_U,        KC_I,    KC_O,   GUI_T(KC_P), \
               KC_A, KC_S, LT(_NUMPAD, KC_D), SFT_T(KC_F), KC_G,     KC_H, SFT_T(KC_J), KC_K,    KC_L,   KC_SCLN, \
               KC_Z, KC_X, KC_C,        KC_V,        KC_B,     KC_N, KC_M,        KC_COMM, KC_DOT, OSL(_SYM), \
               LM(_MACROS,MOD_LGUI), KC_ESC, CTL_T(KC_BSPC),  ALT_T(KC_SPC), KC_ENTER, MO(_NAV) \
                ),











  /* layer 1 programming symbols and numpad
   * Had to use S(KC_P) for colon because of qwerty to colemak translation at the OS
   * ,----------------------------------.           ,------------------------------.
   * |   !  |   @  |   {  |   }  |   |  |           |  &  |   <  |  >  |  +  |  *  |
   * |------+------+------+------+------|           |-----+------+-----+-----+-----|
   * |   #  |   $  |   (  |   )  |   `  |           |  ?  |   "  |  '  |  :  |  =  |
   * |------+------+------+------+------|           |-----+------+-----+-----+-----|
   * |   %  |   ^  |   [  |   ]  |   ~  |           |  ;  |   -  |  _  |  /  |  \  |
   * `----------------------------------'           `------------------------------'
   */
  [_SYM] = LAYOUT( \
               KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,      KC_AMPR, KC_LT,   KC_GT,   KC_PLUS, KC_ASTR, \
               KC_CIRC, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRAVE,     KC_QUES, KC_DQT,  KC_QUOT, S(KC_P), KC_EQL, \
               KC_PERC, KC_HASH, KC_LBRC, KC_RBRC, KC_TILDE,     KC_P,   KC_MINUS, KC_UNDS, KC_SLSH, KC_BSLS, \
               OSM(MOD_LGUI), KC_DEL, ____,     ____, ____, ____                    \

                ),















  /* layer 2 arrows, nav, etc
   * tab, app window switching, browser tab switching
   *
   * ,----------------------------------.           ,-----------------------------------.
   * |      |      | s-tab| tab  | home |           | pgup  | s-tab|  ↑   | tab  |      |
   * |------+------+------+------+------|           |-------+------+------+------+------|
   * |      |      | g-~  | g-`  | end  |           | pgdn  |   ←  |  ↓   |  →   |      |
   * |------+------+------+------+------|           |-------+------+------+------+------|
   * |      |      | ctr  | ctr  |      |           |       | emacs| emacs|      |      |
   * |      |      | s-tab| tab  |      |           |       | scrl↓| scrl↑|      |      |
   * `----------------------------------'           `-----------------------------------'
   */
  [_NAV] = LAYOUT( \
      ____, ____, S(KC_TAB),         KC_TAB,         KC_HOME,     KC_PGUP, S(KC_TAB), KC_UP,   KC_TAB,  KC_LGUI, \
      ____, ____, LGUI(S(KC_GRAVE)), LGUI(KC_GRAVE), KC_END,      KC_PGDN, KC_LEFT,   KC_DOWN, KC_RGHT, ____, \
      ____, ____, LCTL(S(KC_TAB)),   LCTL(KC_TAB),   ____,        ____, ____,   ____, ____, ____, \
      ____, ____, ____,     ____, ____, ____ \
       ),

















  /* layer 3 special gui/command functions
     window functions, spectacle app combinations
     cmd tab window switcher
     importantly, this layer lets x,c,v, and n,w, etc. passthrough for common GUI commands of the OS
   */
  [_MACROS] = LAYOUT( \
     ____, ____,  ____, ____, ____,     ____, ____, ____, LALT(KC_LEFT), LALT(KC_RGHT), \
     ____, ____,  ____, ____, ____,     ____, ____, ____, LCTL(KC_LEFT), LCTL(KC_RGHT), \
     ____, ____,  ____, ____, ____,     ____, LALT(KC_F), ____, LSFT(LCTL(KC_LEFT)), LSFT(LCTL(KC_RGHT)), \
     ____, KC_TAB, S(KC_TAB),     ____, ____, ____                                \
      ),











  /* layer 4 numpad
  */
  [_NUMPAD] = LAYOUT( \
     ____, ____,  ____, ____, ____,     ____, KC_7, KC_8, KC_9, ____, \
     ____, ____,  ____, ____, ____,     ____, KC_4, KC_5, KC_6, ____, \
     ____, ____,  ____, ____, ____,     ____, KC_1, KC_2, KC_3, ____,
     ____, ____, ____,      KC_0, ____, ____  \
       )





};

