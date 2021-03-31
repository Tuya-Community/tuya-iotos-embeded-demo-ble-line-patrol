#ifndef LINE_PATROL_H_
#define LINE_PATROL_H_

#include "tuya_ble_common.h"
#include "tuya_ble_log.h"

#define SENSOR_PIN		GPIO_PB4
#define DARK_COLOR		1
#define LIGHT_COLOR 	0

void line_patrol_init(void);
void line_patrol_fun(void);

#endif
