#pragma once

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

typedef hsv_t (*reactive_f)(hsv_t hsv, uint16_t offset);

bool effect_runner_reactive(effect_params_t* params, reactive_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        rgb_t    rgb    = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, offset));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

void set_underglow_on(void)
{
    hsv_t hsv = rgb_matrix_config.hsv;
    rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
    for(uint8_t i = RGB_UNDERGLOW_INDEX_START; i < RGB_UNDERGLOW_INDEX_COUNT; ++i)
    {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

bool effect_runner_reactive_with_underglow(effect_params_t* params, reactive_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    set_underglow_on();

    return effect_runner_reactive(params, effect_func);
}
#endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
