#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ssd1306.h"

#define SLEEPTIME 25

void setup_gpios(void);

int main() {
  stdio_init_all();
  setup_gpios();


  ssd1306_t display;
  display.external_vcc = false;
  ssd1306_init(&display, 128, 64, 0x3C, i2c0);
  ssd1306_clear(&display);

  ssd1306_draw_square(&display, 10, 10, 20, 20);
  ssd1306_draw_char(&display, 30, 30, 1, 'A');
  ssd1306_draw_char(&display, 40, 30, 1, 'A');
  ssd1306_draw_char(&display, 50, 30, 1, 'R');
  ssd1306_draw_char(&display, 60, 30, 1, 'O');
  ssd1306_draw_char(&display, 70, 30, 1, 'N');
    ssd1306_show(&display);//Moatrar cuadrado en la pantalla
    sleep_ms(SLEEPTIME);
    ssd1306_clear(&display);
}

void setup_gpios(void) {
  i2c_init(i2c0, 100000);
  gpio_set_function(0, GPIO_FUNC_I2C);
  gpio_set_function(1, GPIO_FUNC_I2C);
  gpio_pull_up(0);
  gpio_pull_up(1);
}
