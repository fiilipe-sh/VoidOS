
<img width="1024" height="289" alt="Gemini_Generated_Image_9v37yh9v37yh9v37" src="https://github.com/user-attachments/assets/2aeab555-90e1-421d-a0bb-fa451e959ada" />





**A Modular, Multiacthecture OS for Ethical Hacking and Network Analysis.**

VoidOS é um sistema operacional desenvolvido do zero (*From Scratch*), projetado para ser portável entre arquiteturas **x86** e microcontroladores (como **ESP32**). O projeto foca em um ambiente minimalista para ferramentas de segurança, diagnóstico de redes e manipulação de hardware de baixo nível.

---

## 🏗️ Architecture & Design

O sistema utiliza uma **HAL (Hardware Abstraction Layer)** para garantir que as ferramentas de segurança funcionem independentemente do processador.

* **Kernel:** Monolítico minimalista focado em execução de módulos.
* **Drivers:** Implementação nativa de VGA (80x25 text mode) e Keyboard (Port 0x60).
* **Targets:** PCs Legados (BIOS/x86) e Microcontroladores (Xtensa/RISC-V).

---




https://github.com/user-attachments/assets/8d953b58-f6f8-40a7-a1b6-d2ac593f9467




## 📂 Project Structure

```text
VoidOS/
├── src/
│   ├── kernel.cpp          # Ponto de entrada e lógica principal
│   ├── drivers/            # Drivers específicos de hardware
│   │   ├── vga.cpp/h       # Controle de saída de vídeo
│   │   └── keyboard.cpp/h  # Interface de entrada de teclado
│   └── hal/                # Hardware Abstraction Layer
├── include/                # Cabeçalhos globais (stdint, stddef)
└── scripts/                # Scripts de compilação e linker (linker.ld)
```
🛠️ Build and Execution
Prerequisites
Cross-Compiler: i686-elf-gcc / i686-elf-g++

Emulator: QEMU

Assembler: NASM (para o bootloader)

Compilation

# 1. Compilar os fontes
```Bash
i686-elf-g++ -c src/kernel.cpp -o kernel.o -ffreestanding -O2 -Wall
i686-elf-g++ -c src/drivers/vga.cpp -o vga.o -ffreestanding -O2 -Wall
```
# 2. Linkagem
```Bash
i686-elf-gcc -T scripts/linker.ld -o voidos.bin -ffreestanding -O2 -nostdlib kernel.o vga.o -lgcc
```
# 3. Execução
```Bash
qemu-system-i386 -kernel voidos.bin
```




