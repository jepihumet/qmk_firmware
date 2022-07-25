// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ F │ P │ G │       │ J │ L │ U │ Y │ Ñ |Bsp|
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ R │ S │ T │ D │       │ H │ N │ E │ I │ O │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ K │ M │CMD│ . │ / │ ´ │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │CMD├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(   
        LCTL_T(KC_ESC),
        KC_Q,
        KC_W,
        KC_F,
        KC_P,
        KC_G,
        KC_J,
        KC_L,
        KC_U,
        KC_Y,
        KC_QUOT,
        KC_BSPC,
        KC_TAB,
        KC_A,
        KC_R,
        KC_S,
        KC_T,
        KC_D,
        KC_H,
        KC_N,
        KC_E,
        KC_I,
        KC_O,
        KC_BSLS,
        KC_LSFT,
        KC_Z,
        KC_X,
        KC_C,
        KC_V,
        KC_B,
        KC_K,
        KC_M,
        KC_COMM,
        KC_DOT,
        KC_MINS,
        KC_SCLN,
        KC_LGUI,
        LT(2,KC_SPC),
        KC_BSPC,
        KC_ENT,
        LT(1,KC_SPC),
        KC_RALT
    ),
    [1] = LAYOUT_split_3x6_3(   
        KC_TRNS,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_1,
        KC_2,
        KC_3,
        KC_GRV,
        KC_QUOT,
        KC_EQL,
        KC_TRNS,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_4,
        KC_5,
        KC_6,
        KC_COMM,
        KC_LBRC,
        KC_EQL,
        KC_TRNS,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_7,
        KC_8,
        KC_9,
        KC_0,
        KC_QUOT,
        KC_BSLS,
        KC_TRNS,
        KC_NO,
        KC_TRNS,
        KC_TRNS,
        KC_NO,
        KC_TRNS
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_BRIU,
        KC_F1,
        KC_F2,
        KC_F3,
        KC_F4,
        KC_NO,
        KC_MPRV,
        KC_MUTE,
        KC_UP,
        KC_NO,
        KC_NO,
        KC_PWR,
        KC_BRID,
        KC_F5,
        KC_F6,
        KC_F7,
        KC_F8,
        KC_NO,
        KC_MPLY,
        KC_LEFT,
        KC_DOWN,
        KC_RGHT,
        KC_NO,
        KC_SLEP,
        KC_NO,
        KC_F9,
        KC_F10,
        KC_F11,
        KC_F12,
        KC_NO,
        KC_MNXT,
        KC_VOLD,
        KC_VOLU,
        KC_NO,
        KC_NO,
        KC_WAKE,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO
    )
};

