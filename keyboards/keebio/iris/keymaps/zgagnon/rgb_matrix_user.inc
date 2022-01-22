RGB_MATRIX_EFFECT(layer_indicator_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool layer_indicator_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint16_t active_layer =get_highest_layer(layer_state) + 2;
    for(uint16_t i = led_min + 1; i < active_layer; i++){
        rgb_matrix_set_color(i, RGB_BLUE);
    }
    for(uint16_t i = active_layer; i < led_max; i++){
        rgb_matrix_set_color(i, RGB_OFF);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
