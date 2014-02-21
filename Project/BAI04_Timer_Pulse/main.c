/****************************************************************************** 
 * 
 *  Module      : Test PWM Pulse
 *  Description : Make a PWM 50%
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
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

  
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
  
/* -- Timer_Interrupt --------------------------------------------------- 
 * 
 * Description  : Interrupt for Timer when flag = 1;
 * Parameters   : None
 * Return       : None
 */
  void Timer_Interrupt(void){
		
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
	
	// Configure PF1 as T0CCP1
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	
	GPIOPinConfigure(GPIO_PB6_T0CCP0);
	GPIOPinTypeTimer(GPIO_PORTB_BASE,GPIO_PIN_6);
	
	// Configure Timer
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	
	TimerConfigure(TIMER0_BASE,TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM);
	TimerLoadSet(TIMER0_BASE,TIMER_A,SysCtlClockGet());
	TimerMatchSet(TIMER0_BASE,TIMER_A,SysCtlClockGet()/2);
	TimerControlLevel(TIMER0_BASE,TIMER_A,false);
	TimerEnable(TIMER0_BASE,TIMER_A);
	
} 
  
/****************************************************************************** 
 * END OF standard_form.c 
 *****************************************************************************/
