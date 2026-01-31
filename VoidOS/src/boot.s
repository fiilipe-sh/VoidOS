; --- CONFIGURAÇÃO MULTIBOOT ---
MB_ALIGN     equ  1 << 0            ; Alinha módulos em páginas de 4KB
MB_MEMINFO   equ  1 << 1            ; Fornece mapa de memória
MB_FLAGS     equ  MB_ALIGN | MB_MEMINFO
MB_MAGIC     equ  0x1BADB002        ; Número mágico que o GRUB/QEMU procura
MB_CHECKSUM  equ -(MB_MAGIC + MB_FLAGS)

section .multiboot
align 4
    dd MB_MAGIC
    dd MB_FLAGS
    dd MB_CHECKSUM

; --- RESERVA DE MEMÓRIA (STACK) ---
section .bss
align 16
stack_bottom:
    resb 16384 ; Reserva 16KB para a pilha do C++
stack_top:

; --- PONTO DE ENTRADA DO SISTEMA ---
section .text
global _start

_start:
    ; 1. Configura o ponteiro da pilha (ESP)
    mov esp, stack_top

    ; 2. Chama a sua função principal no kernel.cpp
    extern kernel_main
    call kernel_main

    ; 3. Caso o kernel retorne, trava o PC num loop infinito
    cli
.hang:
    hlt
    jmp .hang