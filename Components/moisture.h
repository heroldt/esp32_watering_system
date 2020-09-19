/*
 * Moisture.h
 *
 *  Created on: Jun 11, 2020
 *      Author: Thomas Herold
 */

#ifndef MOISTURE_H_
#define MOISTURE_H_

#include <stdint.h>

typedef enum{
	MOISTURE_ERROR_OK,
	MOISTURE_ERROR_UKNOWN
}moisture_error_t;

moisture_error_t moisture_get_raw_value(uint8_t * value);

moisture_error_t moisture_get_percent(uint8_t * value);

#endif /* MOISTURE_H_ */
