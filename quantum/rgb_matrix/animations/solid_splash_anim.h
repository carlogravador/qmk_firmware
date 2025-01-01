#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_SOLID_SPLASH) || defined(ENABLE_RGB_MATRIX_SOLID_MULTISPLASH)

#        ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
RGB_MATRIX_EFFECT(SOLID_SPLASH)

#           ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
RGB_MATRIX_EFFECT(SOLID_SPLASH_WITH_UNDERGLOW)
#           endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#        endif

#        ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
RGB_MATRIX_EFFECT(SOLID_MULTISPLASH)

#           ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
RGB_MATRIX_EFFECT(SOLID_MULTISPLASH_WITH_UNDERGLOW)
#           endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

hsv_t SOLID_SPLASH_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

#            ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
bool SOLID_SPLASH(effect_params_t* params) {
    return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &SOLID_SPLASH_math);
}

#                ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
bool SOLID_SPLASH_WITH_UNDERGLOW(effect_params_t* params) {
    return effect_runner_reactive_splash_with_underglow(qsub8(g_last_hit_tracker.count, 1), params, &SOLID_SPLASH_math);
}
#                endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#            endif

#            ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
bool SOLID_MULTISPLASH(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_SPLASH_math);
}

#                ifdef RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
bool SOLID_MULTISPLASH_WITH_UNDERGLOW(effect_params_t* params) {
    return effect_runner_reactive_splash_with_underglow(0, params, &SOLID_SPLASH_math);
}
#                endif // RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT

#            endif

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_SPLASH) && !defined(ENABLE_RGB_MATRIX_MULTISPLASH)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
