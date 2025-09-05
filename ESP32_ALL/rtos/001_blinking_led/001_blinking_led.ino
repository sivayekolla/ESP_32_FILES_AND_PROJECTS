#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_2 // Replace with your LED's GPIO pin

// Forward declaration of the task function
void led_blink_task(void *pvParameters);

void app_main(void) {
    // Configure the GPIO pin for the LED
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Create the LED blink task
    xTaskCreate(led_blink_task,   // Task function
                "led_blink_task", // Task name
                2048,             // Stack size (in words)
                NULL,             // Task parameters
                5,                // Task priority
                NULL);            // Task handle (optional)
}

void led_blink_task(void *pvParameters) {
    while (1) {
        gpio_set_level(LED_PIN, 1); // Turn LED ON
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second

        gpio_set_level(LED_PIN, 0); // Turn LED OFF
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}
