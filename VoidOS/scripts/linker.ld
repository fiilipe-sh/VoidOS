ENTRY(_start)

SECTIONS
{
    /* O Kernel começa em 1MB */
    . = 1M;

    /* Primeiro o código (text) e o cabeçalho Multiboot */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    /* Dados constantes (ReadOnly Data) */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* Dados mutáveis */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* Espaço para a Pilha (Stack) e variáveis globais */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}