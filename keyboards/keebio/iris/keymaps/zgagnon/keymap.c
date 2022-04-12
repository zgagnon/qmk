#include QMK_KEYBOARD_H


#define _COLEMAK 0
#define _GAME 1
#define _TTS 2
#define _ANKI 3
#define _LOWER 4
#define _RAISE 5

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  GAME,
  TTS,
  ANKI,
  LOWER,
  RAISE
};

enum dance_moves {
    TD_JET_BRAINS = 0,
    TD_END_STATEMENT = 1,
    TD_LOWER = 2,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_JET_BRAINS] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_ENTER)),
    [TD_END_STATEMENT] = ACTION_TAP_DANCE_DOUBLE(KC_ENTER, LSFT(LGUI(KC_ENTER))),
    [TD_LOWER] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_BRACKET, LOWER)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOTE, KC_SLASH	,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESCAPE, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LBRC	, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   RGB_TOG ,         KC_LCTRL ,  KC_K,    KC_M,    KC_COMMA, KC_DOT, KC_SEMICOLON , LOWER,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LSFT, KC_BSPC,                TD(TD_END_STATEMENT), KC_SPC,   TD(TD_JET_BRAINS)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
[_GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_Q,    KC_W,       KC_E   ,  KC_R ,                            KC_G, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTRL, KC_A,    KC_S,     KC_D,    KC_F,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_T,    KC_LSFT, KC_X,     KC_C,    KC_V,    KC_B,    _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_SPC, KC_ENT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

   [_TTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LALT(KC_LSFT), KC_Q,    KC_W,     KC_E,    KC_R,                            KC_G, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESCAPE, LCTL(KC_C), KC_A,    KC_S,     KC_D,    KC_F,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LCTL(KC_V), KC_X,     KC_C,    KC_V,    KC_B,    _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TAB,  KC_LALT, KC_SPC,                    _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ANKI] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_Q,    KC_W,       KC_E   ,  KC_R ,                            KC_G, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTRL, KC_A,    KC_S,     KC_1,    KC_3,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_T,    KC_LSFT, KC_X,     KC_C,    KC_V,    KC_B,    _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_SPC, KC_ENT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10, KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______,RGB_TOG, RGB_MOD, RGB_HUI, RGB_MODE_PLAIN,    KC_5,                     KC_6,    LGUI(LCTL(KC_LEFT)),    LGUI(LCTL(KC_RIGHT)),    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, LGUI(LALT(KC_LEFT)),   LGUI(LALT(KC_RIGHT)),   KC_P6,   KC_PLUS, KC_BACKSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_RBRC, _______, _______, _______, KC_DOWN, KC_LCBR, RESET,             LGUI(LCTL(KC_A)),KC_RCBR, LGUI(LCTL(LSFT(KC_LEFT))),  LGUI(LCTL(LSFT(KC_RIGHT))),   KC_P3,   LGUI(KC_F2), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  LALT(KC_UP), KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

static int8_t layer_tracker = _COLEMAK;
static int16_t current_mode = RGB_MATRIX_NONE;
static uint32_t game_timer = 0;
static bool timer_running = false;

void matrix_scan_user(void){
  if(timer_running && timer_elapsed32(game_timer) >= 5000){
    timer_running = false;
    rgb_matrix_mode(current_mode);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch(get_highest_layer(state)){
//     case _COLEMAK:
//         for(uint8_t i = 1; i <= 5; i++){
//             rgb_matrix_set_color(i, RGB_BLUE);
//         }
//         rgb_matrix_set_color(1, RGB_YELLOW);
//         break;
//     case _GAME:
//         for(uint8_t i = 1; i <= 5; i++){
//             rgb_matrix_set_color(i, RGB_BLUE);
//         }
//         rgb_matrix_set_color(1, RGB_MAGENTA);
//         rgb_matrix_set_color(2, RGB_MAGENTA);
//     break;
//     case _TTS:
//         for(uint8_t i = 1; i <= 5; i++){
//             rgb_matrix_set_color(i, RGB_BLUE);
//         }
//         rgb_matrix_set_color(1, RGB_GOLDENROD);
//         rgb_matrix_set_color(2, RGB_GOLDENROD);
//         rgb_matrix_set_color(3, RGB_GOLDENROD);
//     default:
//         break;
//     }
//     return state;
// }


bool encoder_update_user(uint8_t index, bool clockwise) {
     if (index == 0) {
         if (IS_LAYER_ON(_LOWER)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else {
            if(!timer_running){
            current_mode = rgb_matrix_get_mode();
            game_timer = timer_read32();
            timer_running = true;
            }

            if (clockwise) {
                if(layer_tracker < _ANKI) {
                    layer_tracker++;
                    layer_on(layer_tracker);
                }
                //  if(layer_tracker == _COLEMAK) {
                //     layer_on(_GAME);
                //     layer_tracker++;
                // } else if (layer_tracker == _GAME) {
                //   layer_on(_TTS);
                //   layer_tracker++;
                // } else {
                //     layer_tracker = _TTS;
                // }
            } else {
                if(layer_tracker > _COLEMAK){
                    layer_off(layer_tracker);
                    layer_tracker--;
                }
                // if (layer_tracker == _TTS) {
                //     layer_off(_TTS);
                //     layer_tracker--;
                // }else if(layer_tracker == _GAME) {
                //     layer_off(_GAME);
                //     layer_tracker--;
                // } else {
                //     layer_tracker = _COLEMAK;
                // }
            }
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_layer_indicator_effect);

        }
    }
    return true;
}
