/****************************************************************************** 
 * 
 *  Module      : GPIO Interrupt
 *  Description : Interrupt GPIO for PF0, when button on. 
 *  Tool        : Keil ARM  
 *  Chip        : TM4C123GH6PM
 *  History     : 19/02/2014
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
//#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
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
  
/* -- ConfigSystem --------------------------------------------------- 
 * 
 * Description  :  Configure System Clock
 * Parameters   : None
 * Return       : None
 */
  void ConfigSystem(void)
{
	// Configure System Clock at 20MHz, using PLL
	SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
}



/* -- ConfigPort --------------------------------------------------- 
 * 
 * Description  :  Configure Control Pin
 * Parameters   : None
 * Return       : None
 */
void ConfigPort(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);		//Enable GPIO Peripheral
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2);	//Configure PE1 as output
}
/* -- Interrupt_PORTF --------------------------------------------------- 
 * 
 * Description  :  Configure System Clock
 * Parameters   : None
 * Return       : None
 */
void Interrupt_PORTF(void){
	GPIOIntClear(GPIO_PORTF_BASE,GPIO_PIN_4);
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1);
}
/****************************************************************************** 
 * MAIN 
 *****************************************************************************/
//__ Chuong trinh chinh 
  
int main (void) 
{ 
  ConfigSystem(); // Config Clock System
	ConfigPort();   // Config Port F output
	
	// Config PF4 to set interrupt.
	
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_4);
	GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_BOTH_EDGES);
	GPIOIntEnable(GPIO_PORTF_BASE,GPIO_PIN_4);
	GPIOIntRegister(GPIO_PORTF_BASE,Interrupt_PORTF);
  IntMasterEnable();
	
	while(1);
	
} 
  
/****************************************************************************** 
 * END OF standard_form.c 
 *****************************************************************************/
