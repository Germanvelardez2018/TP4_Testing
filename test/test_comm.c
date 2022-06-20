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






void setUp(void)
{
    // Reset elements
  // FFF_RESET_HISTORY;

}

void tearDown(void)
{
}

void test_comm_init(){
    TEST_FAIL_MESSAGE("HOLA");
}





void test_comm_services_init(void){
   // uint32_t  ret =  comm_init();
    uint32_t ret = 0;
   TEST_ASSERT_EQUAL(ret,1);
  // TEST_ASSERT_CALLED_TIMES(1,simo_uart_init);
}

