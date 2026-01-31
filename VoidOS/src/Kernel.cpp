#include "drivers/vga.h"
#include "drivers/keyboard.h"
#include "drivers/animations.h"






extern "C" void kernel_main(){
	firstAnimation();
	while(keyboard_get_char() != '\n');
	
	
	clearScreen();
   kprint("VoidOS$> ", GREEN, 0, 0);
    terminal_row = 1; // Começa a digitar na linha de baixo
	
	
while(1) {
        char c = keyboard_get_char(); // Pega a tecla do nosso driver
        
        if (c != 0) { // Se alguma tecla foi pressionada
            terminalInteractive(c); // Mostra na tela e cuida das linhas/colunas
        }
        
        // Pequeno delay ou halt para não fritar o processador no emulador
        asm volatile("hlt"); 
    }
	
	
	
	

}
