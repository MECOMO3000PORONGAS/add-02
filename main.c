#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    printf("ADC Example, measuring GPIO27\n");

    adc_init();
    adc_gpio_init(27);
    adc_select_input(1);

    while (1) {
        const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();
        float tension = result * conversion_factor;
        float temperatura =  tension*1/0.01;
        printf("Raw value: 0x%03x, voltage: %.2f V\n, temperatura total: %.2f °C/n", result, tension, temperatura );
        sleep_ms(500);
    }
}
