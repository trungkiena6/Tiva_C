/****************************************************************************** 
 * 
 *  Module      : Make Timer with Interrupt
 *  Description : Timer Interrupt
 *  Tool        : Keil ARM  
 *  Chip        : TM4C123GH6PM
 *  History     : 20/02/2014
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
#include "inc/hw_ints.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

  
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
  
/* -- Timer_Interrupt() --------------------------------------------------- 
 * 
 * Description  :  Timer Interrupt
 * Parameters   :  None
 * Return       :  None
 */
  void Timer_Interrupt(void){
		long Pin;
		TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
		Pin = GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_1);
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
		
		// Configure Timer
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
		
		TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC);
		TimerLoadSet(TIMER0_BASE,TIMER_A,SysCtlClockGet());
		TimerIntRegister(TIMER0_BASE,TIMER_A, &Timer_Interrupt);
		IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
		TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
		TimerEnable(TIMER0_BASE, TIMER_A);
		while(1);
		
} 
  
/****************************************************************************** 
 * END OF standard_form.c 
 *****************************************************************************/
