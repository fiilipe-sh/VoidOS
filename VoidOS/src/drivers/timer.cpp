#include "timer.h"


void io_wait(){
	// Escreve na porta 0x80 (comumente usada para checkpoints de BIOS)
    // para forçar um pequeno atraso de hardware.
	asm volatile ("outb %%al, $0x80" : : "a"(0));
}


 void sleep(uint32_t loops){ 
	for( volatile uint32_t i = 0; i < loops; ++i){
		io_wait();
	}

	
}