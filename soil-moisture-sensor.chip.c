// Wokwi Custom Chip - Soil Moisture Sensor for ESP32
// Simulates 0–4095 ADC readings via voltage output

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin;
  float moisture;
} chip_data_t;

void chip_timer_callback(void *data) {
  chip_data_t *chip_data = (chip_data_t*)data;

  // Read simulated value from slider (0–4095)
  float moisture_raw = attr_read(chip_data->moisture);

  // Convert ADC to voltage (ESP32 ADC reference ~3.3V)
  float volts = (moisture_raw / 4095.0) * 5;

  // Output analog voltage
  pin_dac_write(chip_data->pin, volts);

  // Debug
  float moisture_percent = (moisture_raw / 4095.0) * 100.0;
  printf("Soil Moisture: %.0f (ADC), %.2f%%, %.2fV\n", 
          moisture_raw, moisture_percent, volts);
}

void chip_init() {
  chip_data_t *chip_data = (chip_data_t*)malloc(sizeof(chip_data_t));
  
  // Default to mid-range
  chip_data->moisture = attr_init("moisture", 2048.0);

  // Init analog output pin
  chip_data->pin = pin_init("SIG", ANALOG);

  // Timer every 1s
  const timer_config_t config = {
    .callback = chip_timer_callback,
    .user_data = chip_data,
  };

  timer_t timer_id = timer_init(&config);
  timer_start(timer_id, 1000, true);
}
