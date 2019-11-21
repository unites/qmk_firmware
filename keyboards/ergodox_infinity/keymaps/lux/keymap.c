#include QMK_KEYBOARD_H
#include "version.h"

// #define BASE 0 // default layer
// #define SYMB 1 // symbols
// #define MDIA 2 // media keys
// #define CMD 3 // media keys
// #define GALT 4 // media keys

enum custom_layers {
  _BASE, // can always be here
  _SYMB,
  _MDIA,
  _CMD,
  _MOD,
  _SWTC,
  _GALT,
  _FKEY,
  _NUMP
};

enum custom_keycodes {
  BASE = SAFE_RANGE, // can always be here
  SYMB,
  MDIA,
  CMD,
  MOD,
  SWTC,
  GALT,
  FKEY,
  NUMP,
  EPRM,
  VRSN,
  RGB_SLD

};

#define L_SYMB MO(_SYMB)
#define L_CMD MO(_CMD)
#define L_MOD MO(_MOD)
#define L_SWTC MO(_SWTC)
#define L_FKEY MO(_FKEY)
#define L_NUMP MO(_NUMP)

#define SWAPL LCTL(LGUI(KC_LEFT))
#define SWAPR LCTL(LGUI(KC_RIGHT))
#define S_GUI LGUI(KC_TAB)

#define L_ESC LT(_MOD, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,     KC_3,       KC_4,     KC_5,   KC_ESC,
        KC_TAB,         KC_Q,         KC_W,     KC_E,       KC_R,     KC_T,   L_FKEY,
        L_CMD,          KC_A,         KC_S,     KC_D,       KC_F,     KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,       KC_V,     KC_B,   L_NUMP,
        L_ESC,          KC_LGUI,      KC_LALT,  KC_LCTL,    L_SYMB,
                                                            KC_DEL,   KC_ENT,
                                                                      L_FKEY,
                                                KC_SPC,     KC_BSPC,  L_MOD,
        // right hand
        KC_ESC,      KC_6,   KC_7,      KC_8,     KC_9,     KC_0,     KC_DEL,
        L_FKEY,      KC_Y,   KC_U,      KC_I,     KC_O,     KC_P,     KC_BSLS,
                     KC_H,   KC_J,      KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        L_NUMP,      KC_N,   KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_SFTENT,
                             L_SYMB,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,
        KC_RALT,     KC_RCTRL,
        L_FKEY,
        L_MOD,       KC_BSPC, KC_SPC
    ),
[_GALT] = LAYOUT_ergodox(  
        // left hand
        KC_GRV,         KC_1,         KC_2,       KC_3,     KC_4,     KC_5,     KC_ESC,
        KC_TAB,         KC_Q,         KC_W,       KC_E,     KC_R,     KC_T,     KC_HOME,
        KC_LCTL,        KC_A,         KC_S,       KC_D,     KC_F,     KC_G,
        KC_LSFT,        KC_Z,         KC_X,       KC_C,     KC_V,     KC_B,     KC_END,
        L_ESC,          L_CMD,        KC_LALT,    KC_LCTL,  SH_MON,
                                                                      KC_DEL,   KC_ENT,
                                                                                KC_PGUP,
                                                            KC_SPC,   KC_BSPC,  KC_PGDN,
        // right hand
        KC_ESC,      KC_6,    KC_7,      KC_8,     KC_9,    KC_0,     KC_DEL,
        KC_HOME,     KC_Y,    KC_U,      KC_I,     KC_O,    KC_P,     KC_BSLS,
                     KC_H,    KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
        KC_END,      KC_N,    KC_M,      KC_COMM,  KC_DOT,  KC_SLSH,  KC_SFTENT,
                              L_SWTC,    KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT,
        KC_RALT,     KC_RCTRL,
        KC_HOME,
        KC_END,      KC_BSPC, KC_SPC
    ),

// SYMBOLS
[_SYMB] = LAYOUT_ergodox(
       // left hand
      _______,       KC_F1,     KC_F2,      KC_F3,    KC_F4,    KC_F5,    _______,
      KC_GRV,        KC_1,      KC_2,       KC_3,     KC_4,     KC_5,     _______,
      KC_TILD,       KC_EXLM,   KC_AT,      KC_HASH,  KC_DLR,   KC_PERC,
      _______,       KC_LCBR,   KC_RCBR,    KC_EQL,   KC_MINS,  KC_BSPC,  _______,
      _______,       _______,   _______,    _______,  _______,
                                            _______,  _______,
                                                      _______,
                                _______,    _______,  _______,
       // right hand
       KC_F12,       KC_F6,     KC_F7,      KC_F8,    KC_F9,    KC_F10,  KC_F11,
       _______,      KC_6,      KC_7,       KC_8,     KC_9,     KC_0,    KC_BSLS,
                     KC_CIRC,   KC_AMPR,    KC_ASTR,  KC_LPRN,  KC_RPRN, KC_PIPE,
       _______,      KC_ENT,    KC_UNDS,    KC_PLUS,  KC_LBRC,  KC_RBRC, _______,
                                _______,    _______,  _______,  _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[_SWTC] = LAYOUT_ergodox(
       // left hand
      _______,   KC_6,      KC_7,       KC_8,       KC_9,       KC_0,     _______,
      _______,   KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,     KC_BSLS,
      _______,   KC_H,      KC_J,       KC_K,       KC_L,       KC_SCLN,
      _______,   KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,  KC_QUOT,
      _______,   _______,   _______,    _______,    _______,  
                                        _______,    _______,
                                                    _______,
                            _______,    _______,    _______,
       // right hand
       _______,   KC_1,       KC_2,     KC_3,       KC_4,       KC_5,     _______,
       _______,   KC_Q,       KC_W,     KC_E,       KC_R,       KC_T,     _______,
                  KC_A,       KC_S,     KC_D,       KC_F,       KC_G,     _______,
       _______,   KC_Z,       KC_X,     KC_C,       KC_V,       KC_B,     _______,
                              _______,  _______,    _______,    _______,  _______,
       _______,   _______,
       _______, 
       _______,   _______,    _______
),

[_FKEY] = LAYOUT_ergodox(
       // left hand
      _______,   KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_HOME,     _______,
      _______,   KC_F5,     KC_F6,      KC_F7,      KC_F8,      KC_PGUP,     _______,
      _______,   KC_F9,     KC_F10,     KC_F11,     KC_F12,     KC_PGDN,
      _______,   KC_PSCR,   KC_SLCK,    KC_SLCK,    KC_INS,     KC_END,      _______,
      _______,   _______,   _______,    _______,    _______,  
                                        _______,    _______,
                                                    _______,
                            _______,    _______,    _______,
       // right hand
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                  _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                              _______,  _______,    _______,    _______,  _______,
       _______,   _______,
       _______, 
       _______,   _______,    _______
),

[_NUMP] = LAYOUT_ergodox(
       // left hand
      KC_NLCK,   _______,   _______,    _______,    _______,    _______,     _______,
      _______,   KC_PAST,   KC_P7,      KC_P8,      KC_P9,      KC_PPLS,     _______,
      _______,   KC_PSLS,   KC_P4,      KC_P5,      KC_P6,      KC_PMNS,
      _______,   KC_P0,     KC_P1,      KC_P2,      KC_P3,      KC_PENT,     _______,
      _______,   _______,   _______,    _______,    _______,  
                                        _______,    _______,
                                                    _______,
                            _______,    _______,    _______,
       // right hand
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                  _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                              _______,  _______,    _______,    _______,  _______,
       _______,   _______,
       _______, 
       _______,   _______,    _______
),

[_CMD] = LAYOUT_ergodox(
       // left hand
      BL_TOGG,   BL_BRTG,   BL_DEC,     BL_INC,     _______,    _______,  _______,
      KC_MUTE,   KC_VOLU,   KC_MPLY,    KC_MPRV,    KC_MNXT,    _______,  _______,
      _______,   KC_VOLD,   KC_BSPC,    KC_DEL,     KC_ENT,     _______,
      _______,   SWAPL,     S_GUI,      SWAPR,      _______,    _______,  _______,
      _______,   _______,   _______,    _______,    _______,  
                                        _______,    _______,
                                                    _______,
                            _______,    _______,    _______,
       // right hand
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                  _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                              _______,  _______,    _______,    _______,  _______,
       _______,   _______,
       _______, 
       _______,   _______,    _______
),

[_MOD] = LAYOUT_ergodox(
       // left hand
      RESET,     BASE,      GALT,       _______,    _______,    _______,  _______,
      _______,   BL_INC,    BL_ON,      _______,     _______,    _______,  _______,
      _______,   BL_DEC,    BL_OFF,    _______,    _______,    _______,
      _______,   BL_TOGG,   _______,    _______,    _______,    _______,  _______,
      _______,   _______,   _______,    _______,    _______,  
                                        _______,    _______,
                                                    _______,
                            _______,    _______,    _______,
       // right hand
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                  _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                              _______,  _______,    _______,    _______,  _______,
       _______,   _______,
       _______, 
       _______,   _______,    _______
),

// MEDIA AND MOUSE
[_MDIA] = LAYOUT_ergodox(
       // left hand
      _______,   _______,   _______,    _______,    _______,    _______,  _______,
      _______,   _______,   _______,    KC_MS_U,    _______,    _______,  _______,
      _______,   _______,   KC_MS_L,    KC_MS_D,    KC_MS_R,    _______,
      _______,   _______,   _______,    _______,    _______,    _______,  _______,
      _______,   _______,   _______,    KC_BTN1,    KC_BTN2,  
                                        _______,    _______,
                                                    _______,
                               _______, _______,     _______,
       // right hand
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                  _______,    _______,  _______,    _______,    _______,  _______,
       _______,   _______,    _______,  _______,    _______,    _______,  _______,
                              _______,  _______,    _______,    _______,  _______,
       _______,   _______,
       _______, 
       _______,   _______, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Layouts
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case GALT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GALT);
      }
      return false;
      break;
    // Stock
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case _SYMB:
            ergodox_right_led_1_on();
            break;
        case _CMD:
            ergodox_right_led_2_on();
            break;
        case _MOD:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }
};


// [_TEMPLATE] = LAYOUT_ergodox(
//        // left hand
//       _______,   _______,   _______,    _______,    _______,    _______,  _______,
//       _______,   _______,   _______,    _______,    _______,    _______,  _______,
//       _______,   _______,   _______,    _______,    _______,    _______,
//       _______,   _______,   _______,    _______,    _______,    _______,  _______,
//       _______,   _______,   _______,    _______,    _______,  
//                                         _______,    _______,
//                                                     _______,
//                                _______, _______,     _______,
//        // right hand
//        _______,   _______,    _______,  _______,    _______,    _______,  _______,
//        _______,   _______,    _______,  _______,    _______,    _______,  _______,
//                   _______,    _______,  _______,    _______,    _______,  _______,
//        _______,   _______,    _______,  _______,    _______,    _______,  _______,
//                               _______,  _______,    _______,    _______,  _______,
//        _______,   _______,
//        _______, 
//        _______,   _______, _______