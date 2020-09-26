#include "moisture.h"
#include "esp_log.h"

static const char* TAG = "Moisture";

moisture_error_t moisture_get_raw_value(const adc1_channel_t channel, uint16_t * value)
{
	int adc_raw_val = 0;

	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(channel,ADC_ATTEN_DB_11);
	adc_raw_val = adc1_get_raw(channel);
	if(adc_raw_val < 0)
	{
		ESP_LOGE(TAG,"ADC channel %d read failed.",channel);
		return MOISTURE_ERROR_ADC;
	}
	ESP_LOGI(TAG,"ADC channel %d raw value %u",channel,adc_raw_val);
	*value = (uint16_t)adc_raw_val;

	return MOISTURE_ERROR_OK;
}

moisture_error_t moisture_get_percent(uint16_t * value)
{
	return MOISTURE_ERROR_OK;
}
