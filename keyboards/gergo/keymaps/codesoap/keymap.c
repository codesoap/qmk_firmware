#include QMK_KEYBOARD_H

#define IGNORE_MOD_TAP_INTERRUPT
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

enum custom_keycodes {
  M1_STRING = SAFE_RANGE,
  M2_URL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                  ,-------------------------------------------.
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |                  |   Y  |   U  |   I  |   O  |  P   |  | \   |
 * |--------+------+------+------+------+------|------.    .------|------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |  D   |   F  |   G  |O(GUI)|    |O(CTL)|   H  |   J  |   K  |   L  | ; :  |  ' "   |
 * |--------+------+------+------+------+------|------|    |------|------+------+------+------+------+--------|
 * |  BKSP  |   Z  |   X  |   C  |   V  |   B  |O(ALT)|    |      |   N  |   M  | ,  < | . >  | /  ? | altgr  |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *                    .----------.   .------------.            .----------.   .----------.
 *                    | alt/del  |   | SUPER/BKSP |            | ctl/Space|   |  LShift  |
 *                    '----------'   '------------'            `----------.   '----------'
 *                                        ,-------.            ,-------.
 *                                        | MMB   |            |  :    |
 *                                 ,------|-------|            |-------|------.
 *                                 | SYMB | TO(   |            | TO(   | NUMB |
 *                                 |  Esc | DFLT) |            | NUMB) | Enter|
 *                                 |      |       |            |       |      |
 *                                 `--------------'            `--------------'
 */
[BASE] = LAYOUT_gergo(
KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                                    KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSLS,
KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, OSM(MOD_LGUI),                      OSM(MOD_LCTL), KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
KC_BSPC, KC_Z, KC_X, KC_C, KC_V, KC_B, OSM(MOD_LALT), KC_BTN3,   KC_COLON, KC_TRNS,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ALGR_T(KC_DEL),
   ALT_T(KC_DEL), LGUI_T(KC_BSPC), LT(SYMB, KC_ESC), TO(BASE),   TO(NUMB), LT(NUMB, KC_ENT), CTL_T(KC_SPC), KC_LSFT
),

/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                  ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                  |   ^  |  &   |  *   |      |      |  VolUp |
 * |--------+------+------+------+------+------|------.    .------|------+------+------+------+------+--------|
 * |        |      |      |  {   |  }   |  `   |  M1  |    |      |   (  |  -   |  _   |  +   |      |  VolDn |
 * |--------+------+------+------+------+------|------|    |------|------+------+------+------+------+--------|
 * |        |  `   |  ~   |  [   |  ]   |  ~   |  M2  |    |      |   )  |  =   | Prev |Pl/Pau| Next |  Mute  |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *                              .------.   .------.            .------.   .-----.
 *                              |      |   |      |            |      |   |     |
 *                              '------'   '------'            `------.   '-----'
 *                                        ,-------.            ,-------.
 *                                        |       |            |       |
 *                                 ,------|-------|            |-------|------.
 *                                 |      |       |            |       |      |
 *                                 |      |       |            |       |      |
 *                                 |      |       |            |       |      |
 *                                 `--------------'            `--------------'
 */
[SYMB] = LAYOUT_gergo(
KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                         KC_CIRC, KC_AMPR, KC_ASTR,       KC_TRNS, KC_TRNS, KC__VOLUP,
KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_GRV,  M1_STRING,                    KC_TRNS,  KC_LPRN, KC_MINS, KC_UNDERSCORE, KC_PLUS, KC_TRNS, KC__VOLDOWN,
KC_TRNS, KC_GRV,  KC_TILD, KC_LBRC, KC_RBRC, KC_EQL,  M2_URL,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_RPRN, KC_EQL,  KC_TRNS,       KC_TRNS, KC_TRNS, KC__MUTE,
                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                  ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                  |  6   |  7   |  8   |  9   |  0   | PgUp   |
 * |--------+------+------+------+------+------|------.    .------|------+------+------+------+------+--------|
 * |        |      |      | BTN2 | BTN1 | BTN3 |      |    | Home | LEFT | DOWN |  UP  | RIGHT| End  | PgDn   |
 * |--------+------+------+------+------+------|------|    |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |    |      | MLFT | MDWN | MUP  | MRGHT|      |        |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *                              .------.   .------.            .------.   .-----.
 *                              |      |   |      |            |      |   |     |
 *                              '------'   '------'            `------.   '-----'
 *                                        ,-------.            ,-------.
 *                                        |       |            |       |
 *                                 ,------|-------|            |-------|------.
 *                                 |      |       |            |       |      |
 *                                 |      |       |            |       |      |
 *                                 |      |       |            |       |      |
 *                                 `--------------'            `--------------'
 */
[NUMB] = LAYOUT_gergo(
KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGUP,
KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS,                    KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  KC_PGDN,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

/* Keymap template
 *
 * ,-------------------------------------------.                  ,-------------------------------------------.
 * |        |      |      |      |      |      |                  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.    .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |    |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|    |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |    |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *                              .------.   .------.            .------.   .-----.
 *                              |      |   |      |            |      |   |     |
 *                              '------'   '------'            `------.   '-----'
 *                                        ,-------.            ,-------.
 *                                        |       |            |       |
 *                                 ,------|-------|            |-------|------.
 *                                 |      |       |            |       |      |
 *                                 |      |       |            |       |      |
 *                                 |      |       |            |       |      |
 *                                 `--------------'            `--------------'
[SYMB] = LAYOUT_gergo(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 */

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    biton32(layer_state);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M1_STRING:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("Hi!" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKBEST is released
      }
      break;

    case M2_URL:
      if (record->event.pressed) {
          SEND_STRING("https://ddg.gg" SS_TAP(X_ENTER));
      }
      break;

  }
  return true;
};
