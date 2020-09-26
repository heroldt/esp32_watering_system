#ifndef MQTT_H_
#define MQTT_H_

void mqtt_init(void);

void mqtt_publish(const char* topic, const char* data, int len);

#endif
