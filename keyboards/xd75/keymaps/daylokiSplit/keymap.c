/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1
#define _LW 2
#define _MS 3
#define _UP 4
#define _GHERKIN 5
#define _TEST 6
#define _RAND 7
#define _NUM 8

#define ALTF4 LALT(KC_F4)

 //Tap Dance Declarations
enum {
    YOUR_TAPDANCE_1 = 0,
    BACK_DANCE=1,
    // ..., the rest of your tap dances
};
 
 //Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // simple tap dance
    [YOUR_TAPDANCE_1] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, LALT(KC_F4)), // replace with your keyco.des
    [BACK_DANCE] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT,LALT(KC_LEFT)),
    // complex tap dance function (to specify what happens when key is pressed 3+ times, for example). See https://docs.qmk.fm/tap_dance.html for how to define
    // [YOUR_TAPDANCE_2] = ACTION_TAP_DANCE_FN(your_function_name),
};



/**
 * Randomness
 */ 
static uint16_t keystroke;
static bool shift_pressed;

static int lower = (int) KC_A;
static int upper = (int) KC_Z;

uint16_t random_keycode(void) {
  return lower + (rand() % (upper - lower + 1));
};

enum custom_keycodes {
  RND_KEY = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case RND_KEY:
      if (record->event.pressed) {
        keystroke = random_keycode();
        if (rand() % 2 > 0) {
          shift_pressed = 1;
          register_code(KC_LSHIFT);
        }
        register_code(keystroke);
      } else {
        if (shift_pressed > 0) {
          unregister_code(KC_LSHIFT);
        }
        unregister_code(keystroke);
      }
      return false;
    default:
        return true;
  }
  return true;
}
/****************************************************************************/



 
 //In Layer declaration, add tap dance item in place of a key code

// [_BLANK] = { /* FUNCTION */
//   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   },
//   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
//   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
//   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
//   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,},
//  },


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_F2,    KC_F3,            KC_F4,   KC_F5,  KC_F6,    _______, _______, _______,   KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   },
  { KC_ESC,  KC_Q,    KC_W,             KC_E,    KC_R,    KC_T,   RGB_RMOD, RGB_TOG, RGB_MOD,    KC_Y,      KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,   },
  { KC_TAB,  KC_A,    LT(_NUM,KC_S),    KC_D,    KC_F,    KC_G,    RGB_HUD, RGB_TOG, RGB_HUI,    KC_H,      KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,   },
  { KC_LSFT, KC_Z,    KC_X,             KC_C,    KC_V,    KC_B,    RGB_SAD, _______, RGB_SAI,    KC_N,      KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, },
  { KC_LCTL, MO(_FN), KC_LGUI,       KC_LALT, MO(_LW),  KC_SPC,    RGB_VAD, _______, RGB_VAI, KC_BSPC,   MO(_UP), MO(_MS), KC_LEFT, KC_DOWN, KC_RGHT, },
 },      


 [_FN] = { /* FUNCTION */
  {   KC_F1, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,   },
  { _______, _______, _______, _______, _______, _______, _______, KC_INSERT, _______, _______, _______, _______, _______, _______, _______,  },
  { _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_SLCK,   KC_CAPS, KC_NLCK, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,   },
  { _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,  },
  { _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_VOLD, RESET  },
 },


[_NUM] = { /* FUNCTION */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   },
  { _______, _______, _______, KC_PERC, KC_CIRC, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, },
  { _______, _______, _______, KC_MINS, KC_PLUS,  KC_EQL, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, },
  { _______, _______, _______, KC_PSLS, KC_ASTR,  KC_EQL, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_COMM, KC_ASTR, XXXXXXX,},
 },



[_MS] = { /* MOUSE */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, _______, KC_WH_U, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R,},
 },

[_UP] = { /* FUNCTION */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, },
  { _______, _______, KC_EXLM, KC_AMPR, KC_PIPE, _______, _______, _______, _______, _______, KC_DQUO, KC_QUOT, KC_GRAVE, _______, _______, },
  { _______, _______, _______, KC_EQUAL,KC_RABK, _______, _______, _______, _______,  KC_EQL, KC_PLUS, KC_MINS,  KC_ASTR, KC_PSLS, _______, },
  { _______, _______,   KC_AT, KC_HASH,  KC_DLR, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, },
 },

 [_GHERKIN] = { /* FUNCTION */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
  { _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______, _______, _______,  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,},
 },

 [_TEST] = { /* Test layer crazy crazy stuff */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RND_KEY,   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,},
 },

  [_RAND] = { /* Test layer crazy crazy stuff */
  { RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY,},
  { RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY,},
  { RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY,},
  { KC_LSFT, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY,},
  { RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY, RND_KEY,},
 },

 
 [_LW] = { /* FUNCTION */
  {     _______,       KC_F1,   KC_F2,   KC_F3,   ALTF4,   KC_F5, _______, _______, _______, _______, _______, _______,  _______, _______, _______,   },
  {LALT(KC_TAB),     KC_BSPC, _______,   KC_UP, _______,  KC_DEL, _______, _______, _______,  KC_EQL, KC_ASTR, KC_PSLS, KC_LPRN, KC_RPRN, _______,  },
  {     _______,     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, _______, _______, _______,  KC_EQL, KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR, KC_DQUO,   },
  {     _______,     _______, _______,  KC_APP, _______, _______, _______, _______, _______, _______, KC_UNDS, _______, KC_LBRC, KC_RBRC, KC_BSLS,  },
  {     _______,     _______, _______, RGB_TOG, _______, RGB_MOD, _______, _______, _______, KC_LCTL, KC_LSFT, KC_PDOT, _______, _______, _______, },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
