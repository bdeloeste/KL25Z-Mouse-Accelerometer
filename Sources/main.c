/* ###################################################################
**     Filename    : main.c
**     Project     : Mouse
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-11-23, 13:06, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "CS1.h"
#include "USB1.h"
#include "USB0.h"
#include "HIDM1.h"
#include "Tx2.h"
#include "SW1.h"
#include "Inhr1.h"
#include "BitIoLdd1.h"
#include "I2C.h"
#include "IntI2cLdd1.h"
#include "Term1.h"
#include "Inhr2.h"
#include "ASerialLdd1.h"
#include "SW1.h"
#include "derivative.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define RED				(18) //refers to pin PTA5 (see schematic)
#define RED_SHIFT		(1 << 18)
#define GREEN			(19)
#define GREEN_SHIFT		(1 << 19)

#define RED_OFF			(GPIOB_PSOR = RED_SHIFT)
#define RED_ON			(GPIOB_PCOR = RED_SHIFT)
#define RED_TOGGLE		(GPIOB_PTOR = RED_SHIFT)
#define GREEN_OFF		(GPIOB_PSOR = GREEN_SHIFT)
#define GREEN_ON		(GPIOB_PCOR = GREEN_SHIFT)
#define GREEN_TOGGLE	(GPIOB_PTOR = GREEN_SHIFT)

void delay_time(int);
void init_leds();
void red_on();
void red_off();
void green_on();
void green_off();

void APP_Run(void) {
  int cnt=0; /* counter to slow down LED blinking */
  char		buf[32]; 
  word		count;
  
  int16		xAxis;
  int16		yAxis;
  
  int		xValue;
  int		yValue;
  
  I2C_Init();
  I2C_SelectSlave(0x1d);
  buf[0] = 0x2a;
  buf[1] = 0x01;
  I2C_SendBlock(buf, 2, &count);
  
  init_leds();
  for(;;) {
	do
	{
		I2C_SelectSlave(0x1d);
		buf[0] = 0x00;
		I2C_SendBlock(buf, 1, &count);
		I2C_SelectSlave(0x1d);
		I2C_RecvBlock(buf, 7, &count);
	} while (! (buf[0] & 0x08));
	
	xAxis = (buf[1] << 6) | (buf[2] >> 2);
	
	if (xAxis & 0x2000)
	{
		xAxis |= 0xc000;		
	}
	
	yAxis = (buf[3] << 6) | (buf[4] >> 2);
	
	if (yAxis & 0x2000)
	{
		yAxis |= 0xc000;
	}
	
	xValue = xAxis / 100;
	yValue = yAxis / 100;
	
	Term1_CRLF();
	Term1_SetColor(clWhite, clBlack);
	Term1_SendStr("X-value: ");
	Term1_SetColor(clGreen, clBlack);
	Term1_SendNum(xValue);
	Term1_SetColor(clWhite, clBlack);
	Term1_SendStr("   Y-value: ");
	Term1_SetColor(clGreen, clBlack);
	Term1_SendNum(yValue);
	Term1_SendStr("\r");
	delay_time(500);	
    cnt++;
    
    if (HIDM1_App_Task()==ERR_BUSOFF) {
      if ((cnt % 128) ==0) { /* just slow down blinking */
        green_off();
        red_on();
      }
    } else {
      if ((cnt % 128) == 0) { /* just slow down blinking */
        red_off();
        green_on();
      }
      if (SW1_GetVal()== 0) { /* button not pressed */
        delay_time(1000); /* wait for debouncing */
        if (SW1_GetVal()== 0)
        	(void)HIDM1_Move(xValue, yValue); /* move cursor with x-offset and y-offset */
      }
      else {
    	  HIDM1_Send(HIDM1_MOUSE_LEFT, yValue, xValue); /* send left click signal (inverted x and y-offset */
      }
    }
  }
}
void red_on(){
	RED_ON;
}

void red_off(){
	RED_OFF;
}

void green_on() {
	GREEN_ON;
}

void green_off() {
	GREEN_OFF;
}

/********************************************************************/

void delay_time(int number){
  int cnt;
  for(cnt=0;cnt<number;cnt++);
}

 void init_leds()
 	 {
	 
    /* 
	 * Initialize the Red LED (PTB18)
	 */

		/* Turn on clock to PortB module */
		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

		/* Set the PTB18 pin multiplexer to GPIO mode */
		PORTB_PCR18 = PORT_PCR_MUX(1);

		/* Set the initial output state to high */
		GPIOB_PSOR |= RED_SHIFT;

		/* Set the pins direction to output */
		GPIOB_PDDR |= RED_SHIFT;
		
		SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
		
		PORTB_PCR19 |= PORT_PCR_MUX(1);
		
		GPIOB_PSOR |= GREEN_SHIFT;
		
		GPIOB_PDDR |= GREEN_SHIFT;
		
	}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
{

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  APP_Run();

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
