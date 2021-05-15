#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include <avr/delay.h>


int main(void)
{
	LCD_VidInit();

	LCD_vidSetPosition(0,8);
	LCD_VidSendString("MOSTAFA");

	while(1)
	{

	}

	return 0;
}
