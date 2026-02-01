#include "keyboard.h"

// Tabela de mapeamento (Set 1)
const char keyboardMap[] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

// Variável para evitar repetição infinita enquanto a tecla está segurada
uint8_t last_scancode = 0;

inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

uint8_t get_scan_code() {
    // Verifica se há dados disponíveis (Bit 0 da porta 0x64)
    if (inb(0x64) & 0x01) {
        return inb(0x60);
    }
    return 0;
}

char keyboard_get_char() {
    uint8_t scancode = get_scan_code();

    if (scancode == 0) return 0;

    // Se o scancode for igual ao último, significa que a tecla ainda está pressionada
    // Nós ignoramos para não sair "aaaaaaaaaaaaa" na tela.
    if (scancode == last_scancode) {
        return 0;
    }

    // Se o bit 7 estiver setado (0x80), a tecla foi SOLTADA
    if (scancode & 0x80) {
        last_scancode = 0; // Reseta para permitir pressionar a mesma tecla de novo
        return 0;
    }

    // Se chegou aqui, é um novo "Key Press"
    last_scancode = scancode;

    // Converte para caractere se estiver no mapa
    if (scancode < sizeof(keyboardMap)) {
        return keyboardMap[scancode];
    }

    return 0;
}

void wait_for_key(char target) {
    while (true) {
        char c = keyboard_get_char();
        if (c == target) {
            break;
        }
        // Impede que o loop trave o processador em 100% no host
        asm volatile("pause");
    }
}