#include "keyboard.h"

const char keyboardMap[] = {
	0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};


/* Função Assembly inline para ler uma porta de hardware. 
   Isso é essencial porque C++ puro não consegue acessar portas de I/O sozinho.
*/


inline uint8_t inb(uint16_t port){
	uint8_t ret;
	asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
	
}



// Porta 0x64 é o Status Register. O Bit 0 (0x01) diz se tem tecla esperando
uint8_t get_scan_code(){
	if (inb(0x64) & 1){
		return inb(0x60); // Lê a tecla na porta de dados 0x60
	}
	return 0;
}


char keyboard_get_char(){
	uint8_t scancode = get_scan_code();
	
	// Scancodes < 0x80 significam "Tecla Pressionada"
	if( scancode > 0 && scancode < 0x80){
		return keyboardMap[scancode];
	}
	return 0; 	
}

void wait_for_key(char target){
	while(true){
		char c = keyboard_get_char;
		if(c == target){
			break;
		}
	}
	
	
	
	
	
	
}

