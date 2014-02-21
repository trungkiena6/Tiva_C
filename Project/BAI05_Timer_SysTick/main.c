/****************************************************************************** 
 * 
 *  Module      : System Tick Timer
 *  Description : Use System Tick to make a pulse
 *  Tool        : Keil ARM  
 *  Chip        : TM4C123GH6PM
 *  History     : 18/02/2014
 *  Version     : 1.0 
 * 
 *  Author      : BUI TRUNG KIEN.
 *  Notes       : 
 * 
 *****************************************************************************/
  
/****************************************************************************** 
 * IMPORT 
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"

  
/****************************************************************************** 
 * EXTERN 
 *****************************************************************************/
/*__Khai bao cac ham, bien da ton tai trong file C khac, vi du: 
extern void Exit(void); */
  
/****************************************************************************** 
 * GLOBAL VARIABLE 
 *****************************************************************************/
/*__Khoi tao bien toan cuc */
  

  
/****************************************************************************** 
 * ROUTINES 
 *****************************************************************************/
/*__Cac chuong trinh con viet o day */
  
/* -- SystemTick_Handler()- --------------------------------------------------- 
 * 
 * Description  : Use to test System Tick with LED RGB PF1
 * Parameters   : None
 * Return       : None
 */
  void SystemTick_Handler(void)
	{
		long Pin = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_1);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,~Pin);
	}
	/****************************************************************************** 
 * MAIN 
 *****************************************************************************/
//__ Chuong trinh chinh 
  
int main (void) 
{ 
		// Set the clock  
		SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
		// Set output
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1);
   
		// Configure SysTick
		SysTickPeriodSet(SysCtlClockGet());
		SysTickIntEnable();
		SysTickIntRegister(&SystemTick_Handler);
		SysTickEnable();
		
		while(1);
} 
  
/****************************************************************************** 
 * END OF standard_form.c 
 *****************************************************************************/
