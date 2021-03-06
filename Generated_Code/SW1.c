/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SW1.c
**     Project     : microProject
**     Processor   : MKL25Z128VLK4
**     Component   : Switch
**     Version     : Component 01.007, Driver 01.08, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-12-03, 09:23, # CodeGen: 2
**     Abstract    :
**          This bean provide service of user switch devices.
**          The returned value 'TRUE' correspond to '1-2' pins 
**          connected ('ON' state of the switch). The value 'FALSE' 
**          correspond to '2-3' pins connected ('OFF' state of the switch).
**     Settings    :
**          Switch SW1 is connected to PTA20/RESET_b pin
**     Contents    :
**         GetVal     - bool SW1_GetVal(void);
**         ConnectPin - void SW1_ConnectPin(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file SW1.c
** @version 01.08
** @brief
**          This bean provide service of user switch devices.
**          The returned value 'TRUE' correspond to '1-2' pins 
**          connected ('ON' state of the switch). The value 'FALSE' 
**          correspond to '2-3' pins connected ('OFF' state of the switch).
*/         
/*!
**  @addtogroup SW1_module SW1 module documentation
**  @{
*/         

/* MODULE SW1. */

#include "SW1.h"

/*
** ===================================================================
**     Method      :  SW1_GetVal (component Switch)
**     Description :
**         Return actual status of the switch
**     Parameters  : None
**     Returns     :
**         ---             - Current switch status
**                           TRUE  - '2-3' pins are connected (or the
**                           button is pressed)
**                           FALSE - '1-2' pins are connected (or the
**                           button is released)
** ===================================================================
*/
bool SW1_GetVal(void)
{
  Inhr1_ConnectPin();
  return (!(Inhr1_GetVal()));
}
/*
** ===================================================================
**     Method      :  SW1_ConnectPin (component Switch)
**     Description :
**         This method reconnects selected pin in this bean. This
**         method is available only for CPU derivatives and
**         peripherals that support runtime pin sharing with other
**         internal on-chip peripherals.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void SW1_ConnectPin(void)
  ** This method is implemented as macro
*/

/* END SW1. */

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
