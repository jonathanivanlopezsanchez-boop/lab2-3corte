#ifndef LCD_H
#define LCD_H

#include <xc.h>
#include <stdint.h>

/*
 * Frecuencia del oscilador para __delay_ms/__delay_us.
 * Puedes sobreescribirla desde el proyecto antes de incluir este archivo.
 */
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000UL
#endif

/*
 * Pines de control LCD.
 * Ajusta estos macros según tu conexión física.
 */
#define LCD_RS RD0
#define LCD_EN RD1

/*
 * Comandos útiles del controlador HD44780.
 */
#define LCD_CMD_CLEAR            0x01u
#define LCD_CMD_HOME             0x02u
#define LCD_CMD_DISPLAY_ON       0x0Cu
#define LCD_CMD_DISPLAY_OFF      0x08u
#define LCD_CMD_ENTRY_MODE       0x06u
#define LCD_CMD_FUNCTION_SET_4B  0x28u

/*
 * API pública.
 * Nota: LCD_SetCursor(row, col) usa índices en corchetes: row[0..1], col[0..15].
 */
void LCD_Init(void);
void LCD_Command(uint8_t cmd);
void LCD_Char(uint8_t data);
void LCD_String(const char str[]);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);

#endif /* LCD_H */
