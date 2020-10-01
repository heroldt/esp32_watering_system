#include "mqtt.h"
#include "mqtt_client.h"
#include "esp_log.h"

#define MQTT_HOSTNAME	CONFIG_MQTT_HOSTNAME

static const char *TAG = "MQTT";
static esp_mqtt_client_handle_t client;

void mqtt_init(void)
{
	const esp_mqtt_client_config_t mqtt_cfg = {
	    .uri = MQTT_HOSTNAME,
	    // .user_context = (void *)your_context
	};
	client = esp_mqtt_client_init(&mqtt_cfg);
	//esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, client);
	esp_mqtt_client_start(client);
}

void mqtt_publish(const char* topic, const char* data, int len)
{
	esp_mqtt_client_publish(client, topic, data, len, 0,0);
}
