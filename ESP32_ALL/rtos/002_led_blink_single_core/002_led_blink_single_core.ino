//configuring using only one core
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static const int ledpin=LED_BUILTIN;

void toggleled_1(void *parameter){
  while(1){
    digitalWrite(ledpin,HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS);
    digitalWrite(ledpin,LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}
void toggleled_2(void *parameter){
  while(1){
    digitalWrite(ledpin,HIGH);
    vTaskDelay(323/portTICK_PERIOD_MS);
    digitalWrite(ledpin,LOW);
    vTaskDelay(323/portTICK_PERIOD_MS);
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleled_1,  // Function to be called
              "Toggle 1",   // Name of task
              1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
              NULL,         // Parameter to pass to function
              1,            // Task priority (0 to configMAX_PRIORITIES - 1)
              NULL,         // Task handle
              app_cpu);     // Run on one core for demo purposes (ESP32 only)


   xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
              toggleled_2,  // Function to be called
              "Toggle 1",   // Name of task
              1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
              NULL,         // Parameter to pass to function
              1,            // Task priority (0 to configMAX_PRIORITIES - 1)
              NULL,         // Task handle
              app_cpu);     // Run on one core for demo purposes (ESP32 only)

}

void loop() {
  // put your main code here, to run repeatedly:

}