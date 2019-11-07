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
#define L_CMD MO(_CMD)
#define L_MOD MO(_MOD)
#define SPACEM LT(_MOD, KC_SPC)
#define SPACEC LT(_CMD, KC_SPC)

enum dz60_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _CMD,
  _MOD,
  _ADJUST
};

enum dz60_codes {
  BASE,
  LOWER,
  RAISE,
  CMD,
  MOD,
  ADJUST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_NO,  KC_BSPC,
        KC_TAB,         KC_Q,       KC_W,        KC_E,      KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   KC_BSLS,
        MO(_RAISE),     KC_A,       KC_S,        KC_D,      KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_NO,      KC_Z,        KC_X,      KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,   KC_NO,
        KC_LCTL,        KC_LGUI,    KC_LALT,     KC_SPC,    KC_SPC,     KC_SPC,     KC_RALT,    MO(_LOWER), MO(_RAISE), MO(_MOD),   MO(_LOWER)),

    [_LOWER] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_TRNS,  KC_BSPC,
        KC_GRV,         KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_LBRC,    KC_RBRC,   KC_BSLS,
        KC_TILD,        KC_EXLM,    KC_AT,       KC_HASH,   KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),


    [_RAISE] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_TRNS,  KC_BSPC,
        KC_TRNS,        RGB_TOG,    RGB_MOD,     RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        BL_DEC,     BL_TOGG,     BL_INC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),


    [_MOD] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_TRNS,  KC_BSPC,
        KC_TRNS,        RGB_TOG,    RGB_MOD,     RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        BL_DEC,     BL_TOGG,     BL_INC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

    [_ADJUST] = LAYOUT(
        KC_GESC,        KC_1,       KC_2,        KC_3,      KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,    KC_TRNS,  KC_BSPC,
        KC_TRNS,        RGB_TOG,    RGB_MOD,     RGB_HUI,   RGB_HUD,    RGB_SAI,    RGB_SAD,    RGB_VAI,    RGB_VAD,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
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