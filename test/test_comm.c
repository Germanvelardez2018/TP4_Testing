/**
 * @file test_comm_services.c
 * @author your name (you@domain.com)
 * @brief  Test Unitario del modulo comm_services (servicios de comunicacion)
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "unity.h"
#include "mock_uart.h"
#include "mock_gpio.h"
#include "mock_delay.h"
#include "mock_debug.h"
#include "comm.h"
#include "string.h"

extern uint8_t __comm_buffer[];   // SIMCOM_BUFFER_ARRAY from comm.c





void test_comm_init();


void setUp(void)
{
    // Reset elements
  // FFF_RESET_HISTORY;
  FFF_RESET_HISTORY();
  RESET_FAKE(simo_uart_init);
  RESET_FAKE(simo_gpio_set);
  RESET_FAKE(simo_gpio_write);
  RESET_FAKE(simo_uart_write);

// HARDWARE DE BAJO NIVEL UART SE INICIA CORRECTSMENTE
  simo_uart_init_fake.return_val = 1;
 


  

}

void tearDown(void)
{
}




/**
 * @brief Funcion a probar: __comm_init()
 * @note  Probamos que la iniciacion de bajo nivel funcione correctamente
 * @return ** void 
 */

void test_comm_init_ll(){
   uint32_t  ret = 0;
   // Modulo comm depende de 
   // enviar comandos por uart
   // Necesito probar que configura el hardware
   // Correctamente antes de cualquier 
   // test sobre la logica de la funcion
   simo_uart_init_fake.return_val = 1;
   ret =   __comm_init();
   TEST_ASSERT_CALLED_TIMES(1,simo_uart_init);
   TEST_ASSERT_CALLED_TIMES(2,simo_gpio_set);
   TEST_ASSERT_CALLED_TIMES(2,simo_gpio_write);
}



/**
 * @brief Funcion a probar: comm_init()
 * @note  Probamos la iniciacion del modulo en alto nivel
 * @return ** void 
 */

void test_comm_init(){
  // simo_uart_init_fake.return_val = 1;
   uint32_t ret = 0;
   ret = comm_init();
   TEST_ASSERT_CALLED_TIMES(1,simo_delay_ms);
   TEST_ASSERT_EQUAL(1,ret);
}


/**
 * @brief Funcion a probar: __comm_write()
 * @note Probamos que retorne 1 cuando llamamos a la funcion 
 * y que se llame a simo_uart_write
 * 
 * @return ** void 
 */
void test_comm_cmd_write_ll(){
    simo_uart_write_fake.return_val = 1;
    uint32_t ret = 0;
    ret = __comm_write("ALGO DISTINTO DE NULL");
    TEST_ASSERT_CALLED_TIMES(1,simo_uart_write);
    TEST_ASSERT_EQUAL(1,ret);
}



/**
 * @brief Funcion a probar: __comm_read()
 * @note Probamos que retorne 1 cuando llamamos a la funcion 
 * y que se llame a simo_uart_read
 * 
 * @return ** void 
 */
void test_comm_cmd_read_ll(){
    simo_uart_read_fake.return_val = 1;
    uint32_t ret = 0;
    ret = __comm_read();
    TEST_ASSERT_CALLED_TIMES(1,simo_uart_read);
    TEST_ASSERT_EQUAL(1,ret);
}



/**
 * @brief Funcion a probar: __comm_check_response()
 * @note Probamos que la funcion falle por parametro NULL 
 * 
 * @return ** void 
 */
void test_comm_check_response_ll_FAIL_1(){
    uint32_t ret = 1;
    ret = __comm_check_response(NULL);
    //DEBE FALLAR CON NULL
    TEST_ASSERT_EQUAL(0,ret);
}


/**
 * @brief Funcion a probar: __comm_check_response()
 * @note Probamos que la funcion falle por
 *  diferencia entre buffer y comando esperado
 * 
 * @return ** void 
 */
void test_comm_check_response_ll_FAIL_2(){
    uint32_t ret = 1;
    #define CMD_RESPONSE    "RESPUESTA"
    #define RESPUESTA_FAIL  "RESPUESTASS"
    strcpy((char*)__comm_buffer,RESPUESTA_FAIL);
    ret = __comm_check_response(CMD_RESPONSE);
    //DEBE FALLAR CON NULL
    TEST_ASSERT_EQUAL(0,ret);
}


/**
 * @brief Funcion a probar: __comm_check_response()
 * @note Probamos que la funcion sea exitosa 
 * con buffer y comando esperado iguales
 * 
 * @return ** void 
 */
void test_comm_check_response_ll(){
    uint32_t ret = 1;
    #define CMD_RESPONSE    "RESPUESTA"
    strcpy((char*)__comm_buffer,CMD_RESPONSE);
    ret = __comm_check_response(CMD_RESPONSE);
    //DEBE FALLAR CON NULL
    TEST_ASSERT_EQUAL(1,ret);
}

