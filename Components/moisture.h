/*
 * Moisture.h
 *
 *  Created on: Jun 11, 2020
 *      Author: Thomas Herold
 */

#ifndef MOISTURE_H_
#define MOISTURE_H_

#include <stdint.h>
#include <driver/adc.h>

typedef enum{
	MOISTURE_ERROR_OK = 0,
	MOISTURE_ERROR_ADC,
	MOISTURE_ERROR_UKNOWN
}moisture_error_t;

moisture_error_t moisture_get_raw_value(const adc1_channel_t channel, uint16_t * value);

moisture_error_t moisture_get_percent(uint16_t * value);

#endif /* MOISTURE_H_ */
