// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "layers.h"
#include "keycodes.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Macros */
    switch (keycode) {
        case VSCTERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("`")); // Ctrl + ` (to toggle vscode terminal)
            }
            return false;
        case CHNLANG:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("n"))); // Ctrl + Shift + N (to change keyboard layout)
            }
            return false;
        case M_A_OBERT:
            // Key pressed
            if (record->event.pressed){
                SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_A));
            } else {
                // Key released
                clear_keyboard();
            }
            return false;
    }
    return true;
}
