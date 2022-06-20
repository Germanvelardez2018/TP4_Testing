#ifndef __CORE_H__
#define __CORE_H__

  #include <string.h>
  #include <stdint.h>
  #include <stdlib.h>
  #include "stdio.h"


// Enabled key

 // GPIO HARDWARE
 #define SIMO_GPIO_ENA           1
 #define NUM_SIMO_GPIO          40

 // UART HARDWARE
#define SIMO_UART_ENA           1
#define NUM_SIMO_UART           2




       //! Estados del sistema
    typedef enum {
      FSM_UNDEFINED        = 2
    , FSM_WITHOUT_CONFIG   =3         //! Sin configuracion
    , FSM_ON_FIELD         =4      //! Transmicion desde campo
    , FSM_MEMORY_DOWNLOAD  =5    //! Transmicion desde memoria

    } fsm_devices;



  //CORE UART
    #if SIMO_UART_ENA == 1
        typedef enum {
        #if NUM_SIMO_UART >0
            UART_A,
        #endif
        #if NUM_SIMO_UART >1
            UART_B,
        #endif
        #if NUM_SIMO_UART >2
            UART_C
        #endif
        } SIMO_UART;
    #endif




#endif