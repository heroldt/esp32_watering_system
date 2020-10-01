idf_component_register(SRCS "moisture.c" "mqtt.c" "dht22.c"
                  INCLUDE_DIRS "." REQUIRES mqtt)
                  