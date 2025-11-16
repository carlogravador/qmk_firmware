# NOTE: These are already enabled by default at the revision level
#ENCODER_ENABLE = yes
#OLED_ENABLE = yes

# RGB Matrix is enabled at the revision level,
# while we use the regular RGB underglow for testing
# RGB_MATRIX_ENABLE = no
# RGBLIGHT_ENABLE = yes
# RGB_MATRIX_CUSTOM_USER = yes

# Enable the LED underglow on reactive effects when the flag is set
EXTRAFLAGS += -D RGB_MATRIX_UNDERGLOW_ENABLED_ON_REACTIVE_EFFECT
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c
