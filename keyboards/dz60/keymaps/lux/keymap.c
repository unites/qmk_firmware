#include QMK_KEYBOARD_H

#define ADJUST MO(_ADJUST)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOD MO(_MOD)

enum dz60_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _CMD,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_DEL,  KC_BSPC,
        KC_TAB,         KC_Q,       KC_W,        KC_E,      KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   KC_BSLS,
        KC_LCTL,        KC_A,       KC_S,        KC_D,      KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_NO,      KC_Z,        KC_X,      KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SFTENT, KC_NO,
        KC_LCTL,        KC_LGUI,    KC_LALT,     LOWER,     RAISE,      KC_SPC,     KC_LEAD,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT),

    [_LOWER] = LAYOUT(
        KC_GRV,         KC_F1,      KC_F2,       KC_F3,     KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    _______,  _______,
        _______,        KC_ESC,     KC_UP,       KC_ENT,    KC_BSPC,    KC_DEL,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,     _______,    _______,   _______,
        _______,        KC_LEFT,    KC_DOWN,     KC_RIGHT,  _______,    KC_TAB,     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    _______,    _______,
        _______,        _______,    KC_MUTE,     KC_VOLD,   KC_VOLU,    KC_PSTE,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_MPRV,    KC_MNXT,    KC_MPLY,    _______,   _______,
        _______,        _______,    _______,     _______,   _______,    _______,    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MUTE),

    [_RAISE] = LAYOUT(
        KC_ESC,         RGB_M_P,    RGB_M_B,     RGB_M_R,   RGB_M_SW,   RGB_M_SN,   RGB_M_K,    RGB_M_G,    RGB_RMOD,   RGB_MOD,    RGB_TOG,    RGB_SAD,    RGB_SAI,   DEBUG,  RESET,
        ADJUST,         KC_ESC,     _______,     KC_ENT,    KC_BSPC,    KC_DEL,     KC_NLCK,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS,    KC_PAST,    _______,   _______,
        _______,        KC_MUTE,    KC_VOLD,     KC_VOLU,   KC_FIND,    KC_TAB,     KC_PDOT,    KC_P4,      KC_P5,      KC_P6,      KC_PMNS,    KC_PSLS,    KC_PENT,
        _______,        _______,    KC_MPLY,     KC_MPRV,   KC_MNXT,    _______,    KC_P0,      KC_P1,      KC_P2,      KC_P3,      KC_PEQL,    _______,    _______,   _______,
        _______,        _______,    _______,     _______,   _______,    _______,    _______,    RGB_VAD,    RGB_HUD,    RGB_HUI,    RGB_VAI),

    [_ADJUST] = LAYOUT(
        _______,        KC_F1,      KC_F2,       KC_F3,     KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,   _______,  _______,
        _______,        KC_F13,     KC_F14,      KC_F15,    KC_F16,     KC_F17,     KC_F18,     KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,     KC_F24,   _______,
        _______,        KC_MENU,    KC_PSCR,     KC_SLCK,   KC_PAUS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,        _______,    _______,     _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,
        _______,        _______,    _______,     _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______),
};


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Find
    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING(SS_LCTL("f"));
    }

    // Cut
    SEQ_ONE_KEY(KC_X) {
      // Anything you can do in a macro.
      SEND_STRING(SS_LCTL("x"));
    }

    // Copy
    SEQ_ONE_KEY(KC_C) {
      // Anything you can do in a macro.
      SEND_STRING(SS_LCTL("c"));
    }

    // Select All and copy
    SEQ_TWO_KEYS(KC_A, KC_S) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }

    // Paste
    SEQ_ONE_KEY(KC_V) {
      // Anything you can do in a macro.
      SEND_STRING(SS_LCTL("v"));
    }

    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }

    SEQ_TWO_KEYS(KC_A, KC_A) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
