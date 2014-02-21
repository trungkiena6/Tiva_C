/****************************************************************************** 
 * 
 *  Module      : GPIO
 *  Description : Blink a Led on PF3 
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
//#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

  
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
  
/* --  --------------------------------------------------- 
 * 
 * Description  : 
 * Parameters   : 
 * Return       : 
 */
  
/****************************************************************************** 
 * MAIN 
 *****************************************************************************/
//__ Chuong trinh chinh 
  
int main (void) 
{ 
	 //unsigned char PinStatus = 0;
   SysCtlClockSet(SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
    		        SYSCTL_SYSDIV_2_5  );
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
   GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_3);
	 while (1){

//	 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0x00);
//	 SysCtlDelay(SysCtlClockGet()/3);

		 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,GPIO_PIN_3);
	   SysCtlDelay(SysCtlClockGet()/3);
	 }
} 
  
/****************************************************************************** 
 * END OF standard_form.c 
 *****************************************************************************/
