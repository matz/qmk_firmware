#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define QWERTY 0
#define LOWER 1
#define RAISE 2
#define MEDIA 3
#define MIRROR 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// for MacOS
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,--------------------------------------------, ,------------------------------------------,
   * | Tab   |   Q  |   W  |   E  |   R   |   T   | |   Y   |   U  |   I  |   O  |   P  |  BS  |
   * |-------+------+------+------+-------+-------| |-------+------+------+------+------+------|
   * |Esc/Ctl| A/Md |   S  |   D  |   F   |   G   | |   H   |   J  |   K  |   L  |;:/Md |'"/Ctl|
   * |-------+------+------+------+-------+-------| |-------+------+------+------+------+------|
   * | SHIFT |   Z  |   X  |   C  |   V   |   B   | |   N   |   M  |  ,<  |  .>  |  /?  |  \|  |
   * |-------+------+------+------+-------+-------| |-------+------+------+------+------+------|
   * |Mirror | HOME | END  | Exec | Raise |Ent/Low| | Sp/Sft| Raise|Lower |HENKAN|MUHENK|Ent/Mr|
   * `--------------------------------------------' `------------------------------------------'
   */
  [QWERTY] = KEYMAP( \
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,                  KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSPC, \
    CTL_T(KC_ESC),LT(MEDIA,KC_A),KC_S,KC_D,KC_F,KC_G, KC_H,KC_J,KC_K,KC_L,LT(MEDIA,KC_SCLN),CTL_T(KC_QUOT), \
    KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,                 KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_INT3, \
    MO(MIRROR),KC_HOME,KC_END,KC_MHEN,MO(RAISE),LT(LOWER,KC_ENT), \
                                     LT(RAISE,KC_SPC),MO(LOWER),MO(RAISE),KC_HENK,KC_KANA,LT(MIRROR,KC_ENT) \
  ),

  /* Lower 
   * ,-----------------------------------------, ,-----------------------------------------,
   * |   1  |   2  |   3  |   4  |   5  |   6  | |   7  |   8  |   9  |   0  |  -/_ | =/+  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |   !  |   @  |   #  |   $  |   %  |   ^  | |   &  |   *  |   (  |   )  |   [  |  ]   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |   \  |   |  |   `  |   ~  | |   `  |  ~   |   {  |   }  |   ~  |  ~`  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      | Exec |      |      | |      |      |      |HENKAN|MUHENK|      |
   * `-----------------------------------------' `-----------------------------------------'
   */
  [LOWER] = KEYMAP( \
    KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,                 KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,\
    KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,  KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC, \
    _______,_______,KC_INT3,LSFT(KC_INT3),KC_BSLS,LSFT(KC_BSLS),
                                           KC_BSLS,LSFT(KC_BSLS),KC_LCBR,KC_RCBR,LSFT(KC_BSLS),KC_BSLS,\
    _______,_______,_______,_______,_______,_______,  _______,_______,_______,_______,_______,_______  \
  ),

  /* Raise 
   * ,-----------------------------------------, ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  Q   |  V   |  -   |  =   |   \  |  BS  |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | | PGDN | PGUP | HOME | END  |   [  |  ]   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |  F2  |  F5  |  F6  |  F7  |  F8  |  F9  | | LEFT | DOWN |  '   |  "   |   `  |  ~   |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |Reset |      |      |      |      |      | |      |      |      |      |      | PGUP |
   * `-----------------------------------------' `-----------------------------------------'
   */

  [RAISE] = KEYMAP( \
    KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,    KC_Q,   KC_V,   KC_MINS, KC_EQL,  KC_INT3, KC_BSPC, \
    KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12, KC_PGDN, KC_PGUP, KC_HOME, KC_END, KC_LBRC, KC_RBRC, \
    KC_F2,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,    KC_LEFT,KC_DOWN,KC_QUOT,LSFT(KC_QUOT), KC_BSLS, LSFT(KC_BSLS), \
    RESET,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,KC_PGUP \
  ),

  /* Media 
   * ,-----------------------------------------, ,-----------------------------------------.
   * |      |      | WhUp | MsUp | WhDn |      | |  End | PgDn |  Up  | PgUp | Home |      |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |Reset |      | MsLf | MsDn | MsRg |      | |      | Left | Down | Right|      |Reset |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |      |      | | Prev |StpPly| Next |Mute  |VolDn |VolUp |
   * |------+------+------+------+------+------| |------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1| |      |      |      |      |      |      |
   * `-----------------------------------------' `-----------------------------------------'
   */
 
  [MEDIA] = KEYMAP( \
    _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, KC_Q,    KC_PGDN, KC_UP,   KC_PGUP,  KC_HOME,  KC_END, \
    RESET,   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,  RESET,   \
    _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU, \
    _______, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, KC_BTN1, KC_BTN2, KC_BTN3,  _______,  _______ \
  ),

  
  [MIRROR] = KEYMAP( \
    KC_BSPC,KC_P,KC_O,KC_I,KC_U,KC_Y,                      KC_T,KC_R,KC_E,KC_W,KC_Q,KC_TAB,  \
    CTL_T(KC_QUOT),LT(MEDIA,KC_SCLN),KC_L,KC_K,KC_J,KC_H,  KC_G,KC_F,KC_D,KC_S,LT(MEDIA,KC_A),CTL_T(KC_ESC), \
    SFT_T(KC_NUHS),KC_SLSH,KC_DOT,KC_COMM,KC_M,KC_N,       KC_B,KC_V,KC_C,KC_X,KC_Z,KC_LSFT, \
    _______,KC_KANA,KC_HENK,MO(LOWER),MO(RAISE),SFT_T(KC_SPC),\
                                                    LT(LOWER,KC_ENT),MO(RAISE),KC_LGUI,KC_END,KC_HOME,_______ \
  ),
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
