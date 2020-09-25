#include "moisture.h"

moisture_error_t moisture_get_raw_value(const adc1_channel_t channel, uint16_t * value)
{
	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(channel,ADC_ATTEN_DB_0);
	*value = adc1_get_raw(channel);
	if(*value < 0)
	{
		*value = 0;
		return MOISTURE_ERROR_ADC;
	}

	return MOISTURE_ERROR_OK;
}

moisture_error_t moisture_get_percent(uint16_t * value)
{
	return MOISTURE_ERROR_OK;
}
