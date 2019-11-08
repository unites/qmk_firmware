#include QMK_KEYBOARD_H

// Custom key definitions
#define SWAPL LCTL(LGUI(KC_LEFT))
#define SWAPR LCTL(LGUI(KC_RIGHT))

#define S_Z LCTL(KC_Z)
#define S_X LCTL(KC_X)
#define S_C LCTL(KC_C)
#define S_V LCTL(KC_V)
#define S_A LCTL(KC_A)
#define S_S LCTL(KC_S)
#define S_D LCTL(KC_D)
#define S_F LCTL(KC_F)
#define S_R LCTL(LSFT(KC_R))
#define S_TAB LALT(KC_TAB)
#define S_GUI LGUI(KC_TAB)
#define S_RE LCTL(KC_R)
#define S_RA LCTL(RSFT(KC_R))
#define CTRLESC CTL_T(KC_ESC)
#define ALTESC ALT_T(KC_ESC)
#define ALTSP LALT(KC_SPACE)
#define ALTE LALT(KC_E)
#define TOG TG(_MOD)

#define ESCMOD LT(_MOD, KC_ESC)
#define ESCCMD LT(_CMD, KC_ESC)
#define SPACEM LT(_MOD, KC_SPC)
#define SPACEC LT(_CMD, KC_SPC)

#define COMMAND MO(_CMD)
#define MODIFY MO(_MOD)


enum dz60_layers {
  _BASE,
  _ALT,
  _LOWER,
  _RAISE,
  _CMD,
  _MOD,
  _ADJUST,
  _NORMSPC
};

enum dz60_codes {
  BASE,
  LOWER,
  RAISE,
  CMD,
  MOD,
  ADJUST,
  ALT,  
  NORMSPC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_DEL,  KC_BSPC,
        KC_TAB,         KC_Q,       KC_W,        KC_E,      KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   KC_BSLS,
        COMMAND,        KC_A,       KC_S,        KC_D,      KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_NO,      KC_Z,        KC_X,      KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SFTENT, KC_NO,
        KC_LCTL,        KC_LGUI,    KC_LALT,     LOWER,     KC_SPC,     KC_SPC,     MO(_MOD),   DEBUG,    KC_DOWN,    KC_UP,      RESET),

    [_ALT] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_DEL,  KC_BSPC,
        KC_TAB,         KC_Q,       KC_W,        KC_E,      KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,    KC_BSPC,   KC_BSLS,
        COMMAND,        KC_A,       KC_S,        KC_D,      KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_NO,      KC_Z,        KC_X,      KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SFTENT, KC_NO,
        KC_LCTL,        KC_LGUI,    KC_LALT,     LOWER,     RAISE,      KC_SPC,     MO(_MOD),   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT),

    [_NORMSPC] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_DEL,  KC_BSPC,
        KC_TAB,         KC_Q,       KC_W,        KC_E,      KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   KC_BSLS,
        COMMAND,        KC_A,       KC_S,        KC_D,      KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_NO,      KC_Z,        KC_X,      KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_SFTENT, KC_NO,
        KC_LCTL,        KC_LGUI,    KC_LALT,     KC_SPC,    LOWER,      KC_SPC,     MO(_MOD),   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT),

    [_LOWER] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_DEL,  KC_BSPC,
        KC_GRV,         KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSLS,    KC_TRNS,   KC_TRNS,
        KC_TILD,        KC_EXLM,    KC_AT,       KC_HASH,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_PIPE,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_LCBR,     KC_RCBR,   KC_EQL,     KC_MINS,    KC_BSPC,    KC_ENT,     KC_UNDS,    KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

    [_CMD] = LAYOUT(
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,        KC_MUTE,    KC_VOLD,     KC_VOLU,   KC_MNXT,    KC_MPRV,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        S_GUI,      KC_DEL,      KC_BSPC,   KC_ENT,     KC_TRNS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    SWAPL,       SWAPR,     ALTE,       S_TAB,      KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_INS,     KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT),

    [_RAISE] = LAYOUT(
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

    [_MOD] = LAYOUT(
        KC_TRNS,        BASE,       ALT,         NORMSPC,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  RESET,
        KC_TRNS,        KC_F9,      KC_F10,      KC_F11,    KC_F12,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   DEBUG,
        KC_TRNS,        KC_F5,      KC_F6,       KC_F7,     KC_F8,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_F1,       KC_F2,     KC_F3,      KC_F4,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

    [_ADJUST] = LAYOUT(
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,  RESET,
        KC_TRNS,        RGB_TOG,    RGB_MOD,     RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   DEBUG,
        KC_TRNS,        BL_DEC,     BL_TOGG,     BL_INC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case BASE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_BASE);
          }
          return false;
          break;
        case ALT:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_ALT);
          }
          return false;
          break;
        case NORMSPC:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NORMSPC);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};