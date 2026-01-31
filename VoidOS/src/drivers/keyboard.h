#ifndef KEYBOARD_H
#define KEYBOARD_H 

#include <stdint.h>

// Lê o código bruto enviado pelo hardware (Scancode)
uint8_t get_scan_code();

// Converte o Scancode em uma letra que humanos entendem (ASCII)
char keyboard_get_char();

// Pausa o sistema até que uma tecla específica seja pressionada (ex: Enter)
void wait_for_key(char target);








#endif