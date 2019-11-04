/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

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
#define ALTSP LALT(KC_SPACE)
#define ALTE LALT(KC_E)
#define TOG TG(_MOD)

#define ESCMOD LT(_MOD, KC_ESC)
#define ESCCMD LT(_CMD, KC_ESC)
#define L_CMD MO(_CMD)
#define L_MOD MO(_MOD)
#define SPACEM LT(_MOD, KC_SPC)
#define SPACEC LT(_CMD, KC_SPC)

// Alt Tab Super
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum preonic_layers {
  _QWERTY,
  _ALPHA,
  _PIPEHITTER,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _MOD,
  _CMD,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  ALPHA,
  PIPEHITTER,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  MOD,
  BACKLIT,
  ALT_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  ESCMOD,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  KC_LCTL,  KC_LGUI, KC_LALT, L_CMD,   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_ALPHA] = LAYOUT_preonic_grid( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  ESCCMD,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  KC_LCTL,  KC_LGUI, KC_LALT, L_MOD,   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_PIPEHITTER] = LAYOUT_preonic_grid( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  CTRLESC,  KC_LGUI, KC_LALT, L_CMD,   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_COLEMAK] = LAYOUT_preonic_grid( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,  \
  L_MOD,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  KC_LCTL,  KC_LGUI, KC_LALT, L_CMD,   LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_DVORAK] = LAYOUT_preonic_grid( \
  KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV, \
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,     KC_BSPC,  \
  L_MOD,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,     KC_SLSH, \
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,     KC_SFTENT,  \
  KC_LCTL,  KC_LGUI, KC_LALT, L_CMD,   LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_LOWER] = LAYOUT_preonic_grid( \
  KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______,  KC_VOLU, KC_DEL,  KC_BSPC, KC_ENT,  ALT_TAB,  _______,  KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS, \
  _______,  KC_VOLD, KC_MPLY, KC_MPRV, KC_MNXT, ALTE,     _______,  KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, \
  _______,  _______, _______, _______, _______, _______,  _______,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
),

[_RAISE] = LAYOUT_preonic_grid( \
  KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______,  _______, _______, _______, _______, _______,  _______,   KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS, \
  _______,  _______, _______, _______, _______, _______,  _______,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, \
  _______,  _______, _______, _______, _______, _______,  _______,   _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT  \
),

[_MOD] = LAYOUT_preonic_grid( \
  KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_BSPC,  \
  _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PAUS, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_NUBS,  \
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_ENT, \
  _______,  _______, _______, _______, _______, _______, _______, KC_P0,   KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT  \
),

[_CMD] = LAYOUT_preonic_grid( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, SWAPL,   S_GUI,   SWAPR,   S_R,     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,  \
  _______, S_A,     S_S,     S_D,     S_F,     _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,  KC_ENT,  \
  _______, S_Z,     S_X,     S_C,     S_V,     _______, KC_MNXT, KC_MUTE, KC_MPLY, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT  \
),

[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   \
  _______, RESET,   _______, _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,  \
  _______, DEBUG,   MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  ALPHA,   PIPEHITTER, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_PSCR, KC_SLCK, KC_PAUS, KC_INS,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case ALT_TAB:
          if (record->event.pressed) {
            if (!is_alt_tab_active) {
              is_alt_tab_active = true;
              register_code(KC_LALT);
            } 
            alt_tab_timer = timer_read();
            register_code(KC_TAB);
          } else {
            unregister_code(KC_TAB);
          }
          break;
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case ALPHA:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_ALPHA);
          }
          return false;
          break;
        case PIPEHITTER:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_PIPEHITTER);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif

// Super Alt tab --------

if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

// Leader Key values --------


  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING(SS_LCTRL("f"));
    }
    SEQ_ONE_KEY(KC_R) {
      SEND_STRING(SS_LCTRL("r"));
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
  
// Leader Key values END -------
}




bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


// --------------- Combo Keys ---------------

// enum combo_events {
//   C_UNDO,
//   C_CUT,
//   C_COPY,
//   C_PASTE,
//   C_ESC
// };

// const uint16_t PROGMEM cut_combo[] = {KC_A, KC_D, COMBO_END};
// const uint16_t PROGMEM copy_combo[] = {KC_A, KC_F, COMBO_END};
// const uint16_t PROGMEM paste_combo[] = {KC_A, KC_G, COMBO_END};
// const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM undo_combo[] = {KC_A, KC_S, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [C_CUT] = COMBO_ACTION(cut_combo),
//   [C_COPY] = COMBO_ACTION(copy_combo),
//   [C_PASTE] = COMBO_ACTION(paste_combo),
//   [C_ESC] = COMBO_ACTION(esc_combo),
//   [C_UNDO] = COMBO_ACTION(undo_combo),
// };

// void process_combo_event(uint8_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case C_CUT:
//       if (pressed) {
//         tap_code16(LCTL(KC_X));
//       }
//       break;
//     case C_COPY:
//       if (pressed) {
//         tap_code16(LCTL(KC_C));
//       }
//       break;
//     case C_PASTE:
//       if (pressed) {
//         tap_code16(LCTL(KC_V));
//       }
//       break;
//     case C_UNDO:
//       if (pressed) {
//         tap_code16(LCTL(KC_Z));
//       }
//       break;
//     case C_ESC:
//       if (pressed) {
//         tap_code16(KC_ESC);
//       }
//       break;
//   }
// }