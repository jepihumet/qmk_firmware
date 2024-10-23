// Copyright 2023 Jepi Humet (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#include "keymap_spanish.h"


/* Tap-Hold keycodes */
#define ES_LOWER LT(1, ES_ENT) /* Tap for Enter, Hold for LOWER layer */
#define ES_RAISE LT(2, ES_ENT) /* Tap for Space, Hold for RAISE layer */

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_QUOTES,
    TD_AA,
    TD_NN,
    TD_CC,
    TD_SS,
    TD_DOT,
    TD_ALT_JUMP,
    TD_COMM_MINS
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Tap once for Quotes, twice for Double Quotes
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(ES_QUOT, ES_DQUO),
    // Tap once for N, twice for Ñ
    [TD_AA] = ACTION_TAP_DANCE_DOUBLE(ES_A, ES_AT),
    // Tap once for N, twice for Ñ
    [TD_NN] = ACTION_TAP_DANCE_DOUBLE(ES_N, ES_NTIL),
    // Tap once for C, twice for Ç
    [TD_CC] = ACTION_TAP_DANCE_DOUBLE(ES_C, ES_CCED),
    // Tap once for S, twice for $
    [TD_SS] = ACTION_TAP_DANCE_DOUBLE(ES_S, ES_DLR),
    // Tap once for ., twice for ·
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(ES_DOT, ES_BULT),
    // Tap once for , or twice for -
    [TD_COMM_MINS] = ACTION_TAP_DANCE_DOUBLE(ES_COMM, ES_MINS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌─────┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───────┐
      * │ Tab │ Q │ W │ F │ P │ G │           │ J │ L │ U │ Y │'" │   `   │
      * ├─────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
      * │ ESC │A@ │ R │S$ │ T │ D │           │ H │ NÑ│ E │ I │ O │   ´   │
      * ├─────┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───────┤
      * │`/Sft│ Z │ X │CÇ │ V │ B │           │ K │ M │ , │ .·│ - │Bsp/Sft│
      * └─────┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───────┘
      *          ┌────┐                              ┌───┐
      *          │LCTL├───────┐                ┌─────┤Alt│
      *          └────┤ TO(1) ├───────┐    ┌───┤TO(2)├───┘
      *               └───────┤GUI/ENT│    │SPC├─────┘
      *                       └───────┘    └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,             ES_Q,        ES_W,          ES_F,        ES_P,          ES_G,                       ES_J,               ES_L,          ES_U,               ES_Y,        TD(TD_QUOTES),      KC_BSPC,
        TD(TD_ESC_CAPS),    TD(TD_AA),   ES_R,          TD(TD_SS),   ES_T,          ES_D,                       ES_H,               TD(TD_NN),     ES_E,               ES_I,        ES_O,               ES_GRV,
        KC_LSFT,            ES_Z,        ES_X,          TD(TD_CC),   ES_V,          ES_B,                       ES_K,               ES_M,          TD(TD_COMM_MINS),   TD(TD_DOT),  RSFT_T(ES_DIAE),    ES_ACUT,
                                                        KC_LCTL,     LT(1,KC_ENT),  LGUI_T(KC_SPC),             KC_SPC,     LT(2,KC_ENT),  KC_RALT
    ),
    [1] = LAYOUT_split_3x6_3(
        _______,    ES_MORD,     ES_IQUE,         ES_QUES,       ES_LCBR,          ES_RCBR,                  ES_EQL,     ES_7,    ES_8,    ES_9,    ES_0,        _______,
        _______,    ES_CIRC,     ES_IEXL,         ES_EXLM,       ES_LBRC,          ES_RBRC,                  KC_PMNS,    ES_4,    ES_5,    ES_6,    KC_PAST,     KC_PSLS,
        _______,    ES_LABK,     ES_COMM,         ES_DOT,        ES_LPRN,          ES_RPRN,                  KC_PPLS,    ES_1,    ES_2,    ES_3,    KC_PDOT,     _______,
                                                 _______,       KC_NO,            _______,                  _______,    TO(3),   _______
    ),
    [2] = LAYOUT_split_3x6_3(
        _______,    _______,    _______,    _______,    _______,    _______,            KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,            KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,            _______,    _______,    _______,    _______,    _______,    _______,
                                            _______,    TO(3),      _______,            _______,    KC_NO,      _______
    ),
    [3] = LAYOUT_split_3x6_3(
        _______,      KC_BRIU,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_MUTE,      KC_F9,      KC_F10,      KC_F11,      KC_F12,      _______,
        _______,      KC_BRID,      KC_MRWD,      KC_MFFD,      KC_MPLY,      KC_TRNS,              KC_VOLU,      KC_F5,      KC_F6,       KC_F7,       KC_F8,       _______,
        _______,      KC_CUT,       KC_COPY,      KC_PSTE,      KC_FIND,      KC_TRNS,              KC_VOLD,      KC_F1,      KC_F2,       KC_F3,       KC_F4,       _______,
                                                  TO(2),        TO(1),        TO(0),                TO(0),        TO(1),      TO(2)
    )
};
