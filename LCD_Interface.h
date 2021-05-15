#ifndef _LCD_INTERFACE_H_

#define _LCD_INTERFACE_H_


void LCD_VidSendData(u8 Copy_u8Data);
void LCD_VidSendCommand(u8 Copy_u8Command);
void LCD_VidInit(void);
void LCD_VidSendString(u8 *u8String);
void LCD_VidSendNumber(s32 Copy_s32Number);
void LCD_vidSetPosition(u8 Copy_u8Row, u8 Copy_u8Col);


#endif
