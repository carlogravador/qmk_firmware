#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS) || defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS)

#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
RGB_MATRIX_EFFECT(SOLID_REACTIVE_CROSS)

#           ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
RGB_MATRIX_EFFECT(SOLID_REACTIVE_CROSS_WITH_UNDERGLOW)
#           endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#        endif

#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTICROSS)

#           ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTICROSS_WITH_UNDERGLOW)
#           endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_CROSS_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist;
    dx              = dx < 0 ? dx * -1 : dx;
    dy              = dy < 0 ? dy * -1 : dy;
    dx              = dx * 16 > 255 ? 255 : dx * 16;
    dy              = dy * 16 > 255 ? 255 : dy * 16;
    effect += dx > dy ? dy : dx;
    if (effect > 255) effect = 255;
#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
#            endif
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

#            ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
bool SOLID_REACTIVE_CROSS(effect_params_t* params) {
    return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &SOLID_REACTIVE_CROSS_math);
}

#                ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
bool SOLID_REACTIVE_CROSS_WITH_UNDERGLOW(effect_params_t* params) {
    return effect_runner_reactive_splash_with_underglow(qsub8(g_last_hit_tracker.count, 1), params, &SOLID_REACTIVE_CROSS_math);
}
#                endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#            endif

#            ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
bool SOLID_REACTIVE_MULTICROSS(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_CROSS_math);
}

#                ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
bool SOLID_REACTIVE_MULTICROSS_WITH_UNDERGLOW(effect_params_t* params) {
    return effect_runner_reactive_splash_with_underglow(0, params, &SOLID_REACTIVE_CROSS_math);
}
#                endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#            endif

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS) || defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
