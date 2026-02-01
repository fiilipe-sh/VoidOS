#include "drivers/vga.h"
#include "drivers/keyboard.h"
#include "drivers/animations.h"
#include "drivers/timer.h"





extern "C" void kernel_main(){
	firstAnimation();
    while(keyboard_get_char() != '\n');

    clearScreen();
    kprint("VoidOs$>", 0x07, 0, 0);

    int col = 8;
    int row = 0; // Começa na linha 2 para não apagar o título

    while(1) {
        char c = keyboard_get_char();
        
        if (c != 0) {
            char str[2] = {c, '\0'};
            kprint(str, 0x0F, col, row); // 0x0F é branco brilhante
            
            col++; // Move para a próxima coluna
            if (col >= 80) { // Se chegar no fim da linha
                col = 0;
                row++;
            }
        }
    }
}
	
	
	


