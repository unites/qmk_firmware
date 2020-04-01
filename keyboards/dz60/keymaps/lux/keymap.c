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
  _MOD,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_DEL,  KC_BSPC,
        KC_TAB,         KC_Q,       KC_W,        KC_E,      KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   KC_BSLS,
        KC_LCTL,        KC_A,       KC_S,        KC_D,      KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_NO,      KC_Z,        KC_X,      KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SFTENT, KC_NO,
        KC_LCTL,        KC_LGUI,    KC_LALT,     LOWER,     RAISE,      KC_SPC,     ADJUST,     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT),

    [_LOWER] = LAYOUT(
        KC_TRNS,        KC_F1,      KC_F2,       KC_F3,     KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    KC_TRNS,  KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_UP,       KC_ENT,    KC_BSPC,    KC_DEL,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,     KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_LEFT,    KC_DOWN,     KC_RIGHT,  KC_TRNS,    KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT),

    [_RAISE] = LAYOUT(
        KC_TRNS,        KC_F1,      KC_F2,       KC_F3,     KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    KC_TRNS,  KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_ENT,    KC_BSPC,    KC_DEL,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,     KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_MUTE,    KC_VOLD,     KC_VOLU,   KC_TRNS,    KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_MPLY,    KC_MPRV,     KC_MNXT,   KC_TRNS,    KC_TRNS,    KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT),

    [_MOD] = LAYOUT(
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,        KC_F9,      KC_F10,      KC_F11,    KC_F12,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_F5,      KC_F6,       KC_F7,     KC_F8,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_F1,       KC_F2,     KC_F3,      KC_F4,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

    [_ADJUST] = LAYOUT(
        KC_TRNS,        RGB_TOG,    RGB_MOD,     RGB_HUI,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   DEBUG,  RESET,
        KC_TRNS,        RGB_HUI,    RGB_SAI,     RGB_VAI,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        RGB_HUD,    RGB_SAD,     RGB_VAD,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        BL_DEC,     BL_TOGG,     BL_INC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),
};

