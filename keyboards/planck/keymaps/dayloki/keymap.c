
#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _NUM,
  _TNUM,
  _SYM,
  _BRAC,
};



#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
	KC_ESC , KC_Q   , KC_W         , KC_E   , KC_R          , KC_T  ,  KC_Y    , KC_U , KC_I   , KC_O   , KC_P   , KC_BSPC,
	KC_TAB , KC_A   , LT(_NUM,KC_S), KC_D   , LT(_BRAC,KC_F), KC_G  ,  KC_H    , KC_J , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
	KC_LSFT, KC_Z   , KC_X         , KC_C   , KC_V          , KC_B  ,  KC_N    , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
	KC_LCTL, MO(_FN), KC_LGUI      , KC_LALT, LOWER         , KC_SPC,  MO(_NUM), RAISE, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
	LALT(KC_TAB), KC_BSPC, _______, KC_UP  , KC_APP , KC_DEL , KC_EQL , KC_F5  , KC_PSLS, KC_LPRN, KC_RPRN, _______,
	_______     , KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , KC_EQL , KC_LCTL, KC_LALT, KC_LCBR, KC_RCBR, KC_DQUO,
	_______     , _______, _______, _______, _______, _______, _______, KC_UNDS, _______, KC_LBRC, KC_RBRC, KC_BSLS,
	_______     , _______, _______, _______, _______, _______, KC_LCTL, KC_LSFT, KC_LSFT, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
_______, _______, KC_EXLM, KC_AMPR , KC_PIPE, _______, _______,   KC_F5,  KC_F12, KC_GRAVE, _______, _______,
_______, _______, _______, KC_EQUAL, KC_RABK, _______,  KC_EQL, KC_DQUO, KC_QUOT, KC_GRAVE, KC_PSLS, _______,
_______, _______,   KC_AT, KC_HASH , KC_DLR , _______, _______, _______, _______,  _______, _______, _______,
_______, _______, _______, _______ , _______, _______, _______, _______, _______,  _______, _______, _______
),



[_SYM] = LAYOUT_planck_grid(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
),

[_BRAC] = LAYOUT_planck_grid(
_______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LPRN, KC_RPRN, _______,  _______, _______,
_______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LCBR, KC_RCBR, KC_LBRC,  KC_RBRC, _______,
_______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, _______,  _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
),

[_NUM] = LAYOUT_planck_grid(
_______, _______  , _______, KC_PERC, KC_CIRC, _______,  KC_EQL, KC_7, KC_8   , KC_9   , KC_PLUS, _______,
_______, MO(_BRAC), _______, KC_MINS, KC_PLUS,  KC_EQL, KC_ASTR, KC_4, KC_5   , KC_6   , KC_COMM, _______,
_______, KC_LSFT  , _______, KC_PSLS, KC_ASTR,  KC_EQL, _______, KC_1, KC_2   , KC_3   , KC_DOT , _______,
_______, _______  , _______, _______, _______, _______, _______, KC_0, KC_PDOT, KC_COMM, KC_ASTR, XXXXXXX
),

[_TNUM] = LAYOUT_planck_grid(
_______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
),

// CK_UP,   _______, _______, 
// CK_TOGG,  MU_TOG,  AU_TOG, 
// CK_DOWN,  MU_MOD,  _______,


[_FN] = LAYOUT_planck_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
_______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    AU_TOG,
  RESET, _______, _______, _______, _______, _______, _______, _______, KC_CAPS, KC_NLCK,  KC_SLCK,  KC_INS,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
)

};


