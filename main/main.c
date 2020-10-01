#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "moisture.h"
#include "dht22.h"
#include "mqtt.h"
#include "string.h"

#define ESP_WIFI_SSID   CONFIG_ESP_WIFI_SSID
#define ESP_WIFI_PASS   CONFIG_ESP_WIFI_PASSWORD

const char mqtt_topic[] = "esp32_watering_system/moisture";

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void app_main(void)
{
    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    wifi_config_t sta_config = {
        .sta = {
            .ssid = ESP_WIFI_SSID,
            .password = ESP_WIFI_PASS,
            .bssid_set = false
        }
    };
    ESP_ERROR_CHECK( esp_wifi_set_config(WIFI_IF_STA, &sta_config) );
    ESP_ERROR_CHECK( esp_wifi_start() );
    ESP_ERROR_CHECK( esp_wifi_connect() );

    mqtt_init();

    setDHTgpio( 4 );
    printf( "Starting DHT Task\n\n");


    while (true) {
    	static uint16_t moisture1 = 0;
    	char mqtt_data[128] = "";
    	moisture_get_raw_value(ADC1_CHANNEL_6,&moisture1);
    	readDHT();
    	float dht22_hum = getHumidity();
    	float dht22_temp = getTemperature();
    	sprintf(mqtt_data,"%u,%.1f,%.1f",moisture1,dht22_temp,dht22_hum);
    	mqtt_publish(&mqtt_topic[0], &mqtt_data[0], strlen(mqtt_data));
    	vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

