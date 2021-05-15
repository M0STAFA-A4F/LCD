#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include <avr/delay.h>


void LCD_VidSendData(u8 Copy_u8Data)
{
	DIO_VidSetPinValue(0,2,1);	// RS = 1 to send data
	DIO_VidSetPinValue(0,1,0);	// RW = 0 to write data
	DIO_VidSetPortValue(2,Copy_u8Data);	// send data
	// enable in bit 2
	DIO_VidSetPinValue(0,0,1);
	_delay_ms(1);
	DIO_VidSetPinValue(0,0,0);
	_delay_ms(1);
}

void LCD_VidSendCommand(u8 Copy_u8Command)
{
	DIO_VidSetPinValue(0,2,0);	// RS = 0 to send command
	DIO_VidSetPinValue(0,1,0);	// RW = 0 to write command
	DIO_VidSetPortValue(2,Copy_u8Command);	// send command
	// enable in bit 2
	DIO_VidSetPinValue(0,0,1);
	_delay_ms(1);
	DIO_VidSetPinValue(0,0,0);
	_delay_ms(1);
}

void LCD_VidInit(void)
{
	DIO_VidSetPortDirection(2,0xff);
	DIO_VidSetPinDirection(0,0,1);
	DIO_VidSetPinDirection(0,1,1);
	DIO_VidSetPinDirection(0,2,1);
	
	_delay_ms(40);
	LCD_VidSendCommand(0b00111000);
	_delay_ms(1);
	LCD_VidSendCommand(0b00001100);
	_delay_ms(1);
	LCD_VidSendCommand(0b00000001);
	_delay_ms(2);
	LCD_VidSendCommand(0b00000111);
}

void LCD_VidSendString(u8 *u8String)
{
	for(u8 i=0; u8String[i]!='\0'; i++)
	{
		LCD_VidSendData(u8String[i]);
	}
}

void LCD_VidSendNumber(s32 Copy_s32Number)
{
	u8 Digits[20];
	u8 DigitsSize = 0;

	if(Copy_s32Number >= 0)
	{
		do{
			Digits[DigitsSize] = (Copy_s32Number%10)+'0';
			DigitsSize++;
		}while(Copy_s32Number/10 > 0);
/*
		while(Copy_u8NumOfDigits > DigitsSize)
		{
			Digits[DigitsSize] = '0';
			DigitsSize++;
		}
*/
		for(u8 i=DigitsSize-1; i>=0; i--)
		{
			LCD_VidSendData(Digits[i]);
		}
	}
	else
	{
		do{
			Digits[DigitsSize] = (Copy_s32Number%10)+'0';
			DigitsSize++;
		}while(Copy_s32Number/10 > 0);
/*
		while(Copy_u8NumOfDigits > DigitsSize)
		{
			Digits[DigitsSize] = '0';
			DigitsSize++;
		}
*/
		Digits[DigitsSize] = '-';
		DigitsSize++;

		for(u8 i=DigitsSize-1; i>=0; i--)
		{
			LCD_VidSendData(Digits[i]);
		}
	}
}

void LCD_vidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{
	if(0 == Copy_u8Row)
	{
		LCD_VidSendCommand(128+Copy_u8Col);
	}
	else if(1 == Copy_u8Row)
	{
		LCD_VidSendCommand(128+64+Copy_u8Col);
	}
}











