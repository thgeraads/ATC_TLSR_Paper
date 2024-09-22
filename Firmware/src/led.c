#include <stdint.h>
#include "tl_common.h"
#include "drivers.h"
#include "stack/ble/ble.h"
#include "drivers/8258/flash.h"
#include "led.h"
#include "main.h"
#include "../components/common/string.h"


_attribute_ram_code_ void init_led(void) {
    gpio_setup_up_down_resistor(LED_BLUE, PM_PIN_PULLUP_1M);
    gpio_write(LED_BLUE, 1);
    gpio_set_func(LED_BLUE, AS_GPIO);
    gpio_set_output_en(LED_BLUE, 1);
    gpio_set_input_en(LED_BLUE, 0);

    gpio_write(LED_RED, 1);
    gpio_setup_up_down_resistor(LED_RED, PM_PIN_PULLUP_1M);
    gpio_set_func(LED_RED, AS_GPIO);
    gpio_set_output_en(LED_RED, 1);
    gpio_set_input_en(LED_RED, 0);

    gpio_setup_up_down_resistor(LED_GREEN, PM_PIN_PULLUP_1M);
    gpio_write(LED_GREEN, 1);
    gpio_set_func(LED_GREEN, AS_GPIO);
    gpio_set_output_en(LED_GREEN, 1);
    gpio_set_input_en(LED_GREEN, 0);
}

_attribute_ram_code_ void set_led_color(char *color) {
    if (strcmp(color, "red") == 0) {
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 0);
        gpio_write(LED_GREEN, 1);
    }
    else if (strcmp(color, "green") == 0) {
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 0);
    }
    else if (strcmp(color, "blue") == 0) {
        gpio_write(LED_BLUE, 0);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 1);
    }
    else if (strcmp(color, "yellow") == 0) {
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 0);
        gpio_write(LED_GREEN, 0);
    }
    else if (strcmp(color, "cyan") == 0) {
        gpio_write(LED_BLUE, 0);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 0);
    }
    else if (strcmp(color, "magenta") == 0) {
        gpio_write(LED_BLUE, 0);
        gpio_write(LED_RED, 0);
        gpio_write(LED_GREEN, 1);
    }
    else if (strcmp(color, "white") == 0) {
        gpio_write(LED_BLUE, 0);
        gpio_write(LED_RED, 0);
        gpio_write(LED_GREEN, 0);
    }
    else if (strcmp(color, "off") == 0) {
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 1);
    }
    else {
        gpio_write(LED_BLUE, 1);
        gpio_write(LED_RED, 1);
        gpio_write(LED_GREEN, 1);
    }
}
