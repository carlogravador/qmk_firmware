#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "gpio.h"
#include "config.h"

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
// Define the custom keycode
enum custom_keycodes
{
    RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE = SAFE_RANGE,
    RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE_SIMPLE,
    RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE_MULTIWIDE,
    RGB_SET_EFFECT_MATRIX_TYPING_HEATMAP,
    RGB_SET_EFFECT_MATRIX_CYCLE_UP_DOWN,
    RGB_PLAY_ANIMATION_SLIDESHOW,
    KEYCODE_VIM_NEXT_TAB,
    KEYCODE_VIM_PREV_TAB,
    KEYCODE_TMUX_NEXT_TAB,
    KEYCODE_TMUX_PREV_TAB,
    KEYCODE_TMUX_VI_MODE,
};

// RGB MODE EFFECTS KEYCODES
#define RM_EFF1     RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE
#define RM_EFF2     RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE_SIMPLE
#define RM_EFF3     RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define RM_EFF4     RGB_SET_EFFECT_MATRIX_TYPING_HEATMAP
#define RM_EFF5     RGB_SET_EFFECT_MATRIX_CYCLE_UP_DOWN
#define RM_ANWT     RGB_PLAY_ANIMATION_SLIDESHOW

// VIM KEYCODES
#define KC_VNTB     KEYCODE_VIM_NEXT_TAB
#define KC_VPTB     KEYCODE_VIM_PREV_TAB

// TMUX KEYCODES
#define KC_TNTB     KEYCODE_TMUX_NEXT_TAB
#define KC_TPTB     KEYCODE_TMUX_PREV_TAB
#define KC_TVMO     KEYCODE_TMUX_VI_MODE

// TMUX KEYCODES

// Define the unwanted modes (to be skipped)
#define IS_UNWANTED_MODE(mode) ((mode) == RGB_MATRIX_NONE || \
                                (mode) == RGB_MATRIX_SOLID_COLOR || \
                                (mode) == RGB_MATRIX_GRADIENT_UP_DOWN || \
                                (mode) == RGB_MATRIX_GRADIENT_LEFT_RIGHT || \
                                (mode) == RGB_MATRIX_TYPING_HEATMAP || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_SIMPLE || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_SIMPLE_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_WIDE || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_WIDE_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_CROSS || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_CROSS_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_MULTICROSS || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_MULTICROSS_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_NEXUS || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_NEXUS_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS || \
                                (mode) == RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SPLASH || \
                                (mode) == RGB_MATRIX_SPLASH_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_MULTISPLASH || \
                                (mode) == RGB_MATRIX_MULTISPLASH_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_SPLASH || \
                                (mode) == RGB_MATRIX_SOLID_SPLASH_WITH_UNDERGLOW || \
                                (mode) == RGB_MATRIX_SOLID_MULTISPLASH || \
                                (mode) == RGB_MATRIX_SOLID_MULTISPLASH_WITH_UNDERGLOW)

enum layers
{
    _DEFAULT = 0,
    _RAISE,
    _RGB_EFFECT
};

// Timer variable to track inactivity
static bool idle = false;
static uint32_t inactivity_timer = 0;
static uint32_t change_animation_timer = 0;
static bool rgb_play_animation_slideshow = false;

static void refresh_inactivity_timer(void);
static void play_next_rgb_effect(void);
static void start_play_animation_slideshow(void);
static void stop_animation_slideshow(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC, KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC , KC_ENT , MO(1)  , KC_MINS, KC_EQL
    ),
    [_RAISE] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL , KC_DEL ,
        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,                   XXXXXXX, KC_HOME, KC_END , KC_LBRC, KC_RBRC, XXXXXXX,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX ,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TVMO, KC_TPTB, KC_TNTB, KC_VPTB, KC_VNTB, XXXXXXX, MO(2)  ,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RGB_EFFECT] = LAYOUT(
        RM_ANWT, RM_EFF1, RM_EFF2, RM_EFF3, RM_EFF4, RM_EFF5,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TPTB, KC_TNTB, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// Disable MCU LED. It is used as CAPSLOCK indicator instead. See config.h
void keyboard_pre_init_user(void)
{
    gpio_set_pin_output(LED_CAPS_LOCK_PIN);
    gpio_write_pin_high(LED_CAPS_LOCK_PIN);
}

void keyboard_post_init_user(void)
{
    inactivity_timer = timer_read32();
}

// Define what happens when the custom key is pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

#if defined(INACTIVITY_TIMEOUT) && defined(CHANGE_ANIMATION_TIMEOUT)
    if(record->event.pressed)
    {
        refresh_inactivity_timer();

        if(rgb_play_animation_slideshow)
        {
            stop_animation_slideshow();
        }
    }
#endif // defined(INACTIVITY_TIMEOUT) && defined(CHANGE_ANIMATION_TIMEOUT)


    // Add custom behavior for other keycodes if needed
    switch(keycode)
    {
        case RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE:
        {
            if(record->event.pressed)
            {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
            }
            return false;
        }
        case RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE_SIMPLE:
        {
            if(record->event.pressed)
            {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            }
            return false;
        }
        case RGB_SET_EFFECT_MATRIX_SOLID_REACTIVE_MULTIWIDE:
        {
            if(record->event.pressed)
            {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
            }
            return false;
        }

        case RGB_SET_EFFECT_MATRIX_TYPING_HEATMAP:
        {
            if(record->event.pressed)
            {
                rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            }
            return false;
        }
        case RGB_SET_EFFECT_MATRIX_CYCLE_UP_DOWN:
        {
            if(record->event.pressed)
            {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
            }
            return false;
        }
        case RGB_PLAY_ANIMATION_SLIDESHOW:
        {
            if(record->event.pressed)
            {
                start_play_animation_slideshow();
            }
            return false;
        }
        case KEYCODE_VIM_NEXT_TAB:
        {
            if(record->event.pressed)
            {
                // Send 'g' and 't' sequentially
                tap_code(KC_G);
                tap_code(KC_T);
            }
            return false;
        }
        case KEYCODE_VIM_PREV_TAB:
        {
            if(record->event.pressed)
            {
                // Send 'g' and 't' sequentially
                tap_code(KC_G);
                // Send 'Shift + T'
                tap_code16(S(KC_T));
            }
            return false;
        }
        case KEYCODE_TMUX_NEXT_TAB:
        {
            if(record->event.pressed)
            {
                // Send Ctrl-B (equivalent to Escape)
                tap_code16(C(KC_B));  // C() sends Ctrl + key
                // Send 'n'
                tap_code(KC_N);
            }
            return false;
        }
        case KEYCODE_TMUX_PREV_TAB:
        {
            if(record->event.pressed)
            {
                // Send Ctrl-B (equivalent to Escape)
                tap_code16(C(KC_B));  // C() sends Ctrl + key
                // Send 'n'
                tap_code(KC_P);
            }
            return false;
        }
        case KEYCODE_TMUX_VI_MODE:
        {
            if(record->event.pressed)
            {
                // Send Ctrl-B (equivalent to Escape)
                tap_code16(C(KC_B));  // C() sends Ctrl + key
                // Send 'n'
                tap_code(KC_LBRC);
            }
            return false;
        }

        default:
            return true; // Return true to allow normal processing for other keycodes
    }
}

void housekeeping_task_user(void)
{
#if defined(INACTIVITY_TIMEOUT) && defined(CHANGE_ANIMATION_TIMEOUT)
    if(rgb_play_animation_slideshow)
    {
        if(timer_elapsed32(change_animation_timer) > CHANGE_ANIMATION_TIMEOUT)
        {
            play_next_rgb_effect();
            change_animation_timer = timer_read32(); // Reset the timer after the change
        }
    }

    if((!idle) && (timer_elapsed32(inactivity_timer) > INACTIVITY_TIMEOUT))
    {
        idle = true;
        start_play_animation_slideshow();
    }

#endif // define(INACTIVITY_TIMEOUT) && define(CHANGE_ANIMATION_TIMEOUT)
}

static void refresh_inactivity_timer(void)
{
    inactivity_timer = timer_read32();
    if(idle)
    {
        idle = false;
    }
}


static void play_next_rgb_effect(void)
{
    // Start at RGB_MATRIX_CYCLE_UP_DOWN
    static uint8_t current_rgb_mode = RGB_MATRIX_CYCLE_UP_DOWN;
    // Increment the mode index and check if it’s unwanted
    do
    {
        current_rgb_mode = (current_rgb_mode + 1) % RGB_MATRIX_EFFECT_MAX;
    }
    while(IS_UNWANTED_MODE(current_rgb_mode));

    rgb_matrix_mode_noeeprom(current_rgb_mode);
}

static void start_play_animation_slideshow(void)
{
    rgb_play_animation_slideshow = true;
    // force timeout
    change_animation_timer = timer_read32() + CHANGE_ANIMATION_TIMEOUT;
}


static void stop_animation_slideshow(void)
{
    rgb_matrix_reload_from_eeprom();
    rgb_play_animation_slideshow = false;
}


#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

