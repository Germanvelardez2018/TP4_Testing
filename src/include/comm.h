/**
 * @file comm.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef __COMM_H_
#define __COMM_H_


#include "core.h"



uint32_t __comm_debug_write(uint8_t* buff);


uint32_t __comm_debug_write_raw(uint8_t buff, uint32_t len);


uint32_t  __comm_init();


void __comm_deinit();


uint8_t* __comm_get_buffer();


uint32_t __comm_read(void);


uint32_t __comm_write_with_ch_end(char* buff,uint8_t ch_end );


uint32_t __comm_write_raw(uint8_t* buff,uint8_t byte);


uint32_t __comm_write(uint8_t* buff);


uint32_t __comm_check_response(char* response);


uint32_t __comm_cmd_send_raw(char* cmd_string, char* exp_response,char ch_end );


uint32_t __comm_cmd_send(uint8_t* cmd_string, uint8_t* exp_response);


uint32_t __comm_cmd_send_with_ch_end(char* cmd_string, uint8_t* exp_response,uint8_t ch_end);

//------------------estas funciones antes eran static, se modificaron para simplificar el uso de Ceedling


/**
 * @brief Inicio el hardware necesario para manejar acelerometro (I2C)
 * 
 * @return ** void 
 */
uint32_t comm_init(void);


/**
 * @brief Desactivar el hardware
 * 
 * @return ** void 
 */
void comm_deinit();



/**
 * @brief Reset la configuracion
 * 
 * @return ** void 
 */
void comm_reset();


/**
 * @brief Revisar disponibilidad del sensor
 * 
 * @return ** uint32_t 
 */
uint32_t  comm_check(void);



/**
 * @brief Poner en modo sleep el sensor
 * 
 * @param sleep 
 * @return ** void 
 */
uint32_t comm_sleep();



uint32_t comm_version(void);


/**
 * @brief 
 * 
 * @return ** void 
 */
uint32_t comm_resume();



uint32_t comm_config_irq(uint8_t value );

uint32_t comm_send_mesage(char* sms, char* cellphone);




uint8_t* comm_get_buffer();


uint32_t comm_get_signal();


uint32_t comm_set_echo(uint8_t echo_on);





uint32_t comm_set_pwr_gps(uint32_t gps_on);

uint32_t comm_get_gps_info();

uint32_t comm_get_operator(void);



uint32_t comm_get_apn(void);


uint32_t comm_open_apn(void);


uint32_t comm_config_mqtt(uint8_t* url, uint8_t* user, uint8_t* password, uint8_t* qos);


uint32_t comm_mqtt_publish(char* topic, char* payload, uint8_t len_payload);


#endif