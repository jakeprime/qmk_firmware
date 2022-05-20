RGB_MATRIX_EFFECT(jake_heatmap)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool jake_heatmap(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  HSV hsv = rgb_matrix_get_hsv();
  RGB rgb = hsv_to_rgb(hsv);
  for (uint8_t i = led_min; i < led_max; i++) {
    if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    } else {
      rgb_matrix_set_color(i, 0, 0, 0);
    }
  }
  return led_max < DRIVER_LED_TOTAL;
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
