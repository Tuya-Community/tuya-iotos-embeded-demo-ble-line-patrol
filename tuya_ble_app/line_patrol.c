#include "line_patrol.h"

#define 	TIME_MS		1000
#define		BUF_LEN		(sizeof(DP_buf) / sizeof(DP_buf[0]))

unsigned long sys_time = 0;
uint8_t DP_buf[4] = {0x65, 0x04, 0x01, 0x00}; //{DP_ID, DP_type, DP_len, DP_data}

void line_patrol_init(void)
{
    gpio_set_func(SENSOR_PIN, AS_GPIO);
    gpio_set_input_en(SENSOR_PIN, 1);
}

void line_patrol_fun(void)
{
	if(!clock_time_exceed(sys_time, 1000 * TIME_MS)){
		return;
	}
	sys_time = clock_time();

	if(gpio_read(SENSOR_PIN) == FALSE) {
		DP_buf[3] = LIGHT_COLOR;
		TUYA_APP_LOG_INFO("light_color");
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);		//light -> low level -> light color
	} else {
		DP_buf[3] = DARK_COLOR;
		TUYA_APP_LOG_INFO("dark_color");
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);		//put out -> high level -> dark color
	}

}
