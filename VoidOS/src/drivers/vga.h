#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define BLACK  0x00
#define BLUE   0x01
#define GREEN  0x02
#define CYAN   0x03
#define RED    0x04
#define MAGENTA 0x05
#define BROWN  0x06
#define WHITE  0x07
#define GRAY   0x08
#define LIGHT_GREEN 0x0A
#define YELLOW 0x0E


#define BLACK 0x07  // Define a cor (0x07 é cinza claro no fundo preto)

// Use 'static' para que essas variáveis fiquem presas apenas aos arquivos que incluírem este header
static int terminal_column = 0;
static int terminal_row = 0;
static uint8_t terminal_color = BLACK;

void put_char(char c, char color, int x, int y) {
    volatile char* video_memory = (char*)0xB8000;
    int index = (y * 80 + x) * 2;
    video_memory[index] = c;
    video_memory[index + 1] = color;
}

void clearScreen() {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            put_char(' ', BLACK, x, y);
        }
    }
    terminal_column = 0;
    terminal_row = 0;
}

void terminalInteractive(char character) {
    if (character == '\n') {
        terminal_column = 0;
        terminal_row++;
    } else {
        put_char(character, terminal_color, terminal_column, terminal_row);
        terminal_column++;
    }
    
    // Proteção simples para não sair da tela
    if (terminal_column >= 80) {
        terminal_column = 0;
        terminal_row++;
    }
}

void kprint(const char* data, char color, int x, int y) {
    terminal_column = x;
    terminal_row = y;
    terminal_color = color;
    for (int i = 0; data[i] != '\0'; i++) {
        terminalInteractive(data[i]);
    }
}

#endif