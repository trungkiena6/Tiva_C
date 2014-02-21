/****************************************************************************** 
 * 
 *  Module      : UART Module, Use Library
 *  Description : UART
 *  Tool        : Keil ARM  
 *  Chip        : TM4C123GH6PM
 *  History     : 21/02/2014
 *  Version     : 1.0 
 * 
 *  Author      : BUI TRUNG KIEN.
 *  Notes       : 
 * 
 *****************************************************************************/
  
/****************************************************************************** 
 * IMPORT 
 *****************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"


#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "Uart_lib.h"
  
/****************************************************************************** 
 * EXTERN 
 *****************************************************************************/
/*__Khai bao cac ham, bien da ton tai trong file C khac, vi du: 
extern void Exit(void); */
  
/****************************************************************************** 
 * GLOBAL VARIABLE 
 *****************************************************************************/
/*__Khoi tao bien toan cuc */
UARTType UART_Init;
  
/****************************************************************************** 
 * ROUTINES 
 *****************************************************************************/
/*__Cac chuong trinh con viet o day */
  
/* -- UART_Config --------------------------------------------------- 
 * 
 * Description  : Configure UART use Library
 * Parameters   : None
 * Return       : None
 */
void UART_Config(void){
		UART_Init.PortName = UART0;
		UART_Init.BaudRate = 115200;
		UART_Init.DataBits = 8;
		UART_Init.Parity = None;
		UART_Init.StopBits = 1;
		ConfigUART(&UART_Init);
}
/****************************************************************************** 
 * MAIN 
 *****************************************************************************/
//__ Chuong trinh chinh 
  
int main (void) 
{ 
		unsigned long i;
		// Set the clock
		SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
		UART_Config();
		
		while(1){
		for (i = 0;i<=10;i++)
		{	
			/*
			In library, you have UARTPuts and UARTPutn. With UARTPuts: you can send a string. Such as: "Hello World"
			And UARTPutn: you send a numberic
			*/
			UARTPutn(UART0_BASE,i);
			SysCtlDelay(SysCtlClockGet()/3);
			UARTPuts(UART0_BASE,"\r");
		}
		}	
    
} 
  
/****************************************************************************** 
 * END OF standard_form.c 
 *****************************************************************************/
