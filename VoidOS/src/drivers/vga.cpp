#ifndef VGA_H
#define VGA_H

// 1. Definir tipos básicos primeiro
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

// 2. Definir constantes
#define BLACK 0x0F

// 3. Declarar variáveis (extern significa "existe em outro lugar")
extern int terminal_column;
extern int terminal_row;
extern uint8_t terminal_color;

// 4. Apenas as "assinaturas" das funções (terminam em ;)
void put_char(char c, char color, int x, int y);
void clearScreen();
void terminalInteractive(char character);
void kprint(const char* data);
#endif