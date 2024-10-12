/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum {
  TD_Q,
  TD_W,
  TD_E,
  TD_R,
  TD_T,
  TD_Y,
  TD_U,
  TD_I,
  TD_O,
  TD_P,
};

void td_vnum_on_each(tap_dance_state_t *state, void *user_data) {
    uint8_t current_mods = get_mods();
    uint16_t keycode = (uint16_t)(uintptr_t)user_data; // 获取按键码

    if (current_mods == MOD_BIT_LGUI || current_mods == MOD_BIT_RGUI) {
        // 如果只按下了左边或右边的 CMD，则不 reset（等待 Tap Dance 触发）
    } else {
        // 发送按键本体的 keycode，并且 reset Tap Dance
        tap_code(keycode);
        reset_tap_dance(state);
    }
}


void td_vnum_finished(tap_dance_state_t *state, void *user_data) {
    uint8_t current_mods = get_mods();
    uint16_t keycode = (uint16_t)(uintptr_t)user_data; // 获取按键码

    uint16_t numcode = 0;
    if (current_mods == MOD_BIT_LGUI || current_mods == MOD_BIT_RGUI) {
        switch (keycode) {
            case KC_Q: numcode = KC_1; break;
            case KC_W: numcode = KC_2; break;
            case KC_E: numcode = KC_3; break;
            case KC_R: numcode = KC_4; break;
            case KC_T: numcode = KC_5; break;
            case KC_Y: numcode = KC_6; break;
            case KC_U: numcode = KC_7; break;
            case KC_I: numcode = KC_8; break;
            case KC_O: numcode = KC_9; break;
            case KC_P: numcode = KC_0; break;
        }

        if (state->count == 1) {
            // 单击，发送 CMD + 数字
            tap_code16(G(numcode));
        } else if (state->count == 2) {
            // 双击，发送 CMD + 原始按键
            tap_code16(G(keycode));
        }
        reset_tap_dance(state);
    }

}

#define EASY_ACTION_TAP_DANCE_FN(each_fn, user_fn, custom_data) { .fn = {each_fn, user_fn, NULL, NULL}, .user_data = custom_data, }

// 注册 Tap Dance 动作
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_Q),
    [TD_W] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_W),
    [TD_E] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_E),
    [TD_R] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_R),
    [TD_T] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_T),
    [TD_Y] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_Y),
    [TD_U] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_U),
    [TD_I] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_I),
    [TD_O] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_O),
    [TD_P] = EASY_ACTION_TAP_DANCE_FN(td_vnum_on_each, td_vnum_finished, (void *)KC_P),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_FREE);
    return state;
}

#ifdef KEY_OVERRIDE_ENABLE
// Shift + Backspace = Del
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// CMD + Esc = CMD+`
const key_override_t macos_switch_window_override = ko_make_basic(MOD_MASK_GUI, LT(2,KC_ESC), G(KC_GRV));
// Ctrl + Esc = `
const key_override_t grave_key_override = ko_make_basic(MOD_MASK_CTRL, LT(2,KC_ESC), KC_GRV);
// Shift + Esc = ~
const key_override_t wave_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(2,KC_ESC), S(KC_GRV));

const key_override_t *key_overrides[] = {
    &delete_key_override,
    &macos_switch_window_override,
    &grave_key_override,
    &wave_key_override,
};
#endif // KEY_OVERRIDE_ENABLE

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_left_brkt[] = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_right_brkt[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_layer_two[] = {QK_SPACE_CADET_RIGHT_SHIFT_PARENTHESIS_CLOSE, TG(1), COMBO_END};
const uint16_t PROGMEM combo_layer_three[] = {QK_SPACE_CADET_RIGHT_SHIFT_PARENTHESIS_CLOSE, LT(3,KC_ENT), COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_layer_two, MO(2)),
    COMBO(combo_layer_three, TG(3)),
    COMBO(combo_left_brkt, KC_LBRC),
    COMBO(combo_right_brkt, KC_RBRC),
};
#endif // COMBO_ENABLE

#ifdef OLED_ENABLE
#include "lib/oledkit/oledkit.h"
void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif // OLED_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap layers
  [0] = LAYOUT_universal(
    LT(2, KC_ESC)  , TD(TD_Q)    , TD(TD_W) , TD(TD_E)         , TD(TD_R) , TD(TD_T) ,                 TD(TD_Y) , TD(TD_U)     , TD(TD_I)        , TD(TD_O) , TD(TD_P) , KC_BSPC      ,
    LCTL_T(KC_TAB) , KC_A        , KC_S     , KC_D             , KC_F     , KC_G     ,                 KC_H     , KC_J         , KC_K            , KC_L     , KC_SCLN  , LT(3,KC_ENT) ,
    SC_LSPO        , KC_Z        , KC_X     , KC_C             , KC_V     , KC_B     ,                 KC_N     , KC_M         , KC_COMM         , KC_DOT   , KC_SLSH  , SC_RSPC      ,
                     KC_LEFT_ALT , KC_LCMD  , LT(1, KC_SPACE)  , XXXXXXX  , XXXXXXX  ,                 XXXXXXX  , KC_BACKSLASH , RCTL_T(KC_LNG2) , KC_RALT  , TG(1)
  ),

  [1] = LAYOUT_universal(
    _______ ,  KC_1    , KC_2     , KC_3    , KC_4     , KC_5         ,                                KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSPC ,
    _______ ,  XXXXXXX , KC_HOME  , KC_UP   , KC_END   , KC_PAGE_UP   ,                                XXXXXXX  , XXXXXXX  , KC_MINUS , KC_EQUAL , KC_QUOTE , _______ ,
    _______ ,  XXXXXXX , KC_LEFT  , KC_DOWN , KC_RGHT  , KC_PAGE_DOWN ,                                XXXXXXX  , XXXXXXX  , _______  , _______  , _______  , _______ ,
               _______ , _______  , _______ , _______  , _______      ,                                XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______
  ),

  [2] = LAYOUT_universal(
    KC_F1    , KC_F2             , KC_F3           , KC_F4   , KC_F5   , KC_F6   ,                     KC_F7   , KC_F8    , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
    _______  , KC_KB_VOLUME_DOWN , KC_KB_VOLUME_UP , KC_UP   , XXXXXXX , XXXXXXX ,                     KC_BRMU , KC_BTN1  , KC_BTN2 , XXXXXXX , XXXXXXX , _______ ,
    _______  , XXXXXXX           , KC_LEFT         , KC_DOWN , KC_RGHT , XXXXXXX ,                     KC_BRMD , XXXXXXX  , XXXXXXX , XXXXXXX , _______ , _______ ,
               _______           , _______         , _______ , _______ , _______ ,                     XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX , _______
  ),

  // [3] = LAYOUT_universal(
  //   RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
  //   RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
  //   RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
  //                 QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  // ),
};
// clang-format on

void keyboard_post_init_user(void) {

#ifdef CONSOLE_ENABLE
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
#endif // CONSOLE_ENABLE

#ifdef POINTING_DEVICE_ENABLE
    set_auto_mouse_enable(true);
#endif // POINTING_DEVICE_ENABLE

    keyball_set_cpi(0x15);
}

