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

#define MOVEL LALT(LCTL(KC_LEFT))
#define MOVER LALT(LCTL(KC_RIGHT))
#define VIEWD LCTL(KC_TAB)

#define S_Z LCTL(KC_Z)
#define S_X LCTL(KC_X)
#define S_C LCTL(KC_C)
#define S_V LCTL(KC_V)
#define S_A LCTL(KC_A)
#define S_S LCTL(KC_S)
#define S_D LCTL(KC_D)
#define S_F LCTL(KC_F)
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

// // Alt Tab Super
// bool is_alt_tab_active = false;
// uint16_t alt_tab_timer = 0;

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _GAME,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _GTIME,
  _CMD,
  _MOD,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  ALT_TAB
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GTIME MO(_GTIME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  ESCMOD,   KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_GAME] = LAYOUT_planck_grid(
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
  KC_BSPC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  ESCMOD,   L_CMD,   KC_LALT, KC_LCTL, GTIME,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_COLEMAK] = LAYOUT_planck_grid(
  KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,  \
  KC_BSPC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
  ESCMOD,   KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

[_DVORAK] = LAYOUT_planck_grid(
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,     KC_BSLS,  \
  KC_BSPC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,     KC_SLSH, \
  KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,     KC_SFTENT,  \
  ESCMOD,   KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT  \
),

[_LOWER] = LAYOUT_planck_grid(
  KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, VIEWD,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,  \
  KC_ESC,  KC_ESC,  KC_BSPC, KC_DEL,  KC_ENT,  MOVER,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,  \
  KC_VOLD, KC_LCBR, KC_RCBR, KC_EQL,  KC_MINS, MOVEL,   KC_PSCR, KC_SLCK, KC_PAUS, KC_INS,  KC_MPLY, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  \
),

[_RAISE] = LAYOUT_planck_grid(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    _______,  \
  KC_TILD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______,  KC_LCBR, KC_RCBR, KC_EQL,  KC_MINS, KC_BSPC,  KC_ENT,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, _______, \
  _______,  _______, _______, _______, _______, _______,  _______,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
),

[_GTIME] = LAYOUT_planck_grid(
  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,  \
  KC_ESC,   KC_5,    KC_6,    KC_7,    KC_8,    KC_VOLU,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, _______, _______,  \
  _______,  KC_9,    KC_0,    KC_EQL,  KC_MINS, KC_VOLD,  KC_PSCR,  KC_SLCK, KC_PAUS, KC_INS,  KC_MPLY, _______, \
  _______,  _______, _______, _______, _______, _______,  _______,  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  \
),


[_MOD] = LAYOUT_planck_grid( \
  KC_ESC,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_NLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_BSPC,  \
  _______,  KC_F5,   KC_F6,   KC_F7,    KC_F8,   GAME,    KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_NUBS,  \
  _______,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   QWERTY,  KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_ENT, \
  _______,  _______, _______, _______,  _______, _______, _______, KC_P0,   KC_HOME, KC_PGDN, KC_PGUP, KC_END  \
),

[_CMD] = LAYOUT_planck_grid( \
  _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,   _______,  \
  _______, S_GUI,   KC_DEL,  KC_BSPC, KC_ENT,  _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,  _______,  \
  _______, _______, _______,   _______,    _______,   _______,    KC_PSCR, KC_SLCK, KC_PAUS, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT  \
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______,  _______,  _______,  KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAME,     COLEMAK,  DVORAK,   _______,  
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______,  _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, BL_OFF,   BL_DEC,   BL_INC,   BL_ON
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// // Super Alt tab --------

// if (is_alt_tab_active) {
//     if (timer_elapsed(alt_tab_timer) > 1000) {
//       unregister_code(KC_LALT);
//       is_alt_tab_active = false;
//     }
//   }

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case ALT_TAB:
    //       if (record->event.pressed) {
    //         if (!is_alt_tab_active) {
    //           is_alt_tab_active = true;
    //           register_code(KC_LALT);
    //         } 
    //         alt_tab_timer = timer_read();
    //         register_code(KC_TAB);
    //       } else {
    //         unregister_code(KC_TAB);
    //       }
    //       break;
    case QWERTY:
      if (record->event.pressed) {
        // print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
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
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

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

