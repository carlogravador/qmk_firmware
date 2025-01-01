// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(NEW_YEAR_COUNTDOWN)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static uint32_t new_year_animation_timer = 0;
static int8_t countdown_start = 10;

// e.g: A simple effect, self-contained within a single method
static bool NEW_YEAR_COUNTDOWN(effect_params_t* params)
{

    if (params->init)
    {
        rgb_matrix_set_color_all(RGB_OFF);
        countdown_start = 10;
    }
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if(new_year_animation_timer == 0)
    {
        new_year_animation_timer = timer_read32();
    }
    else if(timer_elapsed32(new_year_animation_timer) > 1000)
    {
        // turn off all first
        rgb_matrix_set_color_all(RGB_OFF);

        new_year_animation_timer = 0;
        switch(countdown_start)
        {
            case 9:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);

                }
            }
            break;
            // 8
            case 8:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(16, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 7:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 6:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(16, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 5:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 4:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 3:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 2:
            {
                if(is_keyboard_left())
                {
                    // rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(16, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 1:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(17, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(18, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(22, 0xff, 0x00, 0x00);
                }
            }
            break;
            case 0:
            {
                if(is_keyboard_left())
                {
                    rgb_matrix_set_color(11, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(12, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(13, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(24, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(25, 0xff, 0x00, 0x00);
                }
                else
                {
                    rgb_matrix_set_color(15, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(16, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(21, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(28, 0xff, 0x00, 0x00);
                    rgb_matrix_set_color(29, 0xff, 0x00, 0x00);
                }

            }
            break;
            case -1:
                rgblight_mode_noeeprom(RGB_MATRIX_DUAL_BEACON);
            break;

        }
        --countdown_start;
    }
    else
    {
        return false;
    }


    // for (uint8_t i = led_min; i < led_max; i+=2)
    // {
    //     rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
    //     // rgb_matrix_set_color(i, 0, 0, 0);
    // }
    return rgb_matrix_check_finished_leds(led_max);
}



#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
