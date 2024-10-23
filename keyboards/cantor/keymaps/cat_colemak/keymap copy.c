// Copyright 2023 Jepi Humet (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#include "keymap_spanish.h"


/* Tap-Hold keycodes */
#define KC_LOWER LT(1, KC_ENT) /* Tap for Enter, Hold for LOWER layer */
#define KC_RAISE LT(2, KC_ENT) /* Tap for Space, Hold for RAISE layer */

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_QUOTES,
    TD_AA,
    TD_NN,
    TD_CC,
    TD_SS,
    TD_DOT,
    TD_ALT_JUMP
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
    // Tap once for RIGHT ALT, twice for ADJUST LAYER
    [TD_ALT_JUMP] = ACTION_TAP_DANCE_LAYER_MOVE(KC_RALT, 3)
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
        KC_ESC,         KC_A,        KC_S,      KC_D,        KC_T,          KC_D,                       KC_H,        KC_N,          KC_E,        KC_I,        KC_O,           KC_LBRC,
        KC_TAB,         KC_Q,        KC_W,      KC_F,        KC_P,          KC_G,                       KC_J,        KC_L,          KC_U,        KC_Y,        KC_QUOT,        KC_BSPC,
        KC_LSFT,        KC_Z,        KC_X,      KC_C,        KC_V,          KC_B,                       KC_K,        KC_M,          KC_PCMM,     KC_PDOT,     KC_QUOT,        KC_RSFT,
                                                KC_LCTL,     LT(1,KC_ENT),  KC_LGUI,                    KC_SPC,      LT(2,KC_ENT),  KC_RALT
    ),
    [1] = LAYOUT_split_3x6_3(
        KC_TAB,    KC_GRV,      LSFT(KC_EQL),    LSFT(KC_MINS), RALT(KC_QUOT),    RALT(KC_BSLS),            KC_EQL,     KC_7,    KC_8,    KC_9,    KC_0,        KC_TRNS,
        KC_ESC,    KC_LCBR,     KC_EQL,          KC_EXLM,       RALT(KC_LBRC),    RALT(KC_EQL),             KC_PMNS,    KC_4,    KC_5,    KC_6,    KC_PAST,     KC_PSLS,
        KC_LSFT,   KC_NUBS,     KC_COMM,         KC_DOT,        KC_ASTR,          KC_LPRN,                  KC_PPLS,    KC_1,    KC_2,    KC_3,    KC_PDOT,     KC_TRNS,
                                                 KC_TRNS,       KC_NO,            KC_TRNS,                  KC_TRNS,    TO(3),   KC_TRNS
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                            KC_TRNS,    TO(3),      KC_TRNS,            KC_TRNS,    KC_NO,      KC_TRNS
    ),
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS,      KC_BRIU,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_MUTE,      KC_F9,      KC_F10,      KC_F11,      KC_F12,      KC_TRNS,
        KC_TRNS,      KC_BRID,      KC_MRWD,      KC_MFFD,      KC_MPLY,      KC_TRNS,              KC_VOLU,      KC_F5,      KC_F6,       KC_F7,       KC_F8,       KC_TRNS,
        KC_TRNS,      KC_CUT,       KC_COPY,      KC_PSTE,      KC_FIND,      KC_TRNS,              KC_VOLD,      KC_F1,      KC_F2,       KC_F3,       KC_F4,       KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,              KC_TRNS,      KC_TRNS,    KC_TRNS
    )

/*
      //------------------------------------------------------------------------------------                 -----------------------------------------------------------------------------------------
        KC_TAB,             ES_Q,       ES_W,       ES_F,           ES_P,       ES_G,                         ES_J,     ES_L,        ES_U,           ES_Y,        TD(TD_QUOTES),   KC_BSPC,
      //------------------------------------------------------------------------------------                 -----------------------------------------------------------------------------------------
        TD(TD_ESC_CAPS),    TD(TD_AA),  ES_R,       TD(TD_SS),      ES_T,       ES_D,                         ES_H,     TD(TD_NN),   ES_E,           ES_I,        ES_O,            ES_GRV,
      //------------------------------------------------------------------------------------                 -----------------------------------------------------------------------------------------
        LSFT_T(ES_LABK),    ES_Z,       ES_X,       TD(TD_CC),      ES_V,       ES_B,                         ES_K,     ES_M,        ES_COMM,        TD(TD_DOT),  ES_MINS,         RSFT_T(ES_ACUT),
      //------------------------------------------------------------------------------------                 -----------------------------------------------------------------------------------------
                            KC_LCTL,            KC_LOWER,           MT(MOD_LGUI,   KC_SPC),                   KC_SPC,   KC_RAISE,    TD(TD_ALT_JUMP)
      //------------------------------------------------------------------------------------                 -----------------------------------------------------------------------------------------
        ),
*/
     /*
      * ┌───┬───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┬───┐
      * │`~ │ 1 │ 2 │ 3 │ 4 │ 5 │              │ 6 │ 7 │ 8 │ 9 │ 0 │Bsp│
      * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
      * │   │ ! │ @ │ # │ $ │ % │              │ ^ │ & │ * │ ( │ ) │ | │
      * ├───┼───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┼───┤
      * │Sft│+= │ -_│ + │ { │ } │              │ [ │ ] │ ; │ : │ \ │   │
      * └───┴───┴───┴───┴───┴───┘              └───┴───┴───┴───┴───┴───┘
      *           ┌─────────┐                       ┌─────┐
      *           │ MLCKSCN ├─────┐           ┌─────┤TO(3)│
      *           └─────────┤TO(0)├───┐   ┌───┤TO(2)├─────┘
      *                     └─────┤ < │   │ > ├─────┘
      *                           └───┘   └───┘
      */
/*    [1] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_TRNS, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_LSFT, KC_EQL,   KC_MINS,  KC_PLUS,  KC_LCBR,  KC_RCBR,                KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RSFT,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                     _______,  _______,  _______,                _______, _______,_______
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
    [2] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_MSTP, KC_MPLY,    KC_MPRV,   KC_MNXT,  KC_NO,    KC_CAPS,            KC_PGDN,      KC_PGUP,    KC_INS,      KC_PSCR,    KC_NO,    KC_BSPC,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,   KC_HOME,    KC_END,    C(KC_C),    C(KC_V),   KC_NO,           KC_LEFT,    KC_DOWN,   KC_UP,    KC_RGHT,    KC_DEL,   KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_TAB,  KC_UNDO,    KC_CUT,    KC_COPY,  KC_PASTE, KC_APP,             KC_VOLD,    KC_VOLU,   KC_MUTE,    KC_NO,      KC_NO,  KC_RSFT,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                            _______, _______,_______,            _______, _______,_______
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    ),
     [3] = LAYOUT_split_3x6_3(
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,
      //------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
      //------------------------------------------------------------------         ---------------------------------------------------------------------------------
        KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
                                     TO(0), TO(0), TO(0),                           TO(0), TO(0), TO(0)
      //--------------------------------------------------------------         ---------------------------------------------------------------------------------
    )*/
};
