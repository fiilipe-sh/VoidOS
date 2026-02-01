# Configurações de Compilação
CC = gcc
CXX = g++
AS = nasm
LD = ld

# Flags
CFLAGS = -m32 -ffreestanding -O2 -nostdlib
CXXFLAGS = -m32 -Isrc -ffreestanding -O2 -fno-exceptions -fno-rtti
LDFLAGS = -m32 -T $(LINKER_SCRIPT) -ffreestanding -O2 -nostdlib

# Arquivos e Pastas
KERNEL_BIN = voidos.bin
ISO_NAME = voidos.iso
ISO_DIR = iso_root

# Tenta encontrar o linker.ld em locais comuns
LINKER_SCRIPT := $(shell find . -name linker.ld | head -n 1)

# Lista de Objetos
OBJS = boot.o kernel.o keyboard.o vga.o timer.o

# Alvo padrão
all: $(ISO_NAME)

# Regra para criar a ISO
$(ISO_NAME): $(KERNEL_BIN)
	@echo "--- Criando estrutura da ISO ---"
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(KERNEL_BIN) $(ISO_DIR)/boot/$(KERNEL_BIN)
	@echo 'set timeout=0' > $(ISO_DIR)/boot/grub/grub.cfg
	@echo 'set default=0' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo 'menuentry "VoidOS" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '	multiboot /boot/$(KERNEL_BIN)' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '	boot' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '}' >> $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO_NAME) $(ISO_DIR)
	@echo "--- ISO Criada com Sucesso: $(ISO_NAME) ---"

# Regra para linkar o Kernel
$(KERNEL_BIN): $(OBJS)
	$(CC) -m32 -T $(LINKER_SCRIPT) -ffreestanding -O2 -nostdlib -o $@ $(OBJS) -lgcc

# --- REGRAS DE COMPILAÇÃO ---

# Procura o boot.asm ou boot.s automaticamente
boot.o:
	@if [ -f src/boot.asm ]; then $(AS) -f elf32 src/boot.asm -o boot.o; \
	elif [ -f boot.asm ]; then $(AS) -f elf32 boot.asm -o boot.o; \
	elif [ -f src/boot.s ]; then $(AS) -f elf32 src/boot.s -o boot.o; \
	elif [ -f boot.s ]; then $(AS) -f elf32 boot.s -o boot.o; \
	else echo "ERRO: Arquivo de boot nao encontrado!"; exit 1; fi

kernel.o: src/kernel.cpp
	$(CXX) $(CXXFLAGS) -c src/kernel.cpp -o kernel.o

keyboard.o: src/drivers/keyboard.cpp
	$(CXX) $(CXXFLAGS) -c src/drivers/keyboard.cpp -o keyboard.o

vga.o: src/drivers/vga.cpp
	$(CXX) $(CXXFLAGS) -c src/drivers/vga.cpp -o vga.o

timer.o: src/drivers/timer.cpp
	g++ -m32 -Isrc -ffreestanding -O2 -fno-exceptions -fno-rtti -c src/drivers/timer.cpp -o timer.o

# Comandos Úteis
run: $(ISO_NAME)
	qemu-system-i386 -cdrom $(ISO_NAME)

clean:
	rm -rf *.o $(KERNEL_BIN) $(ISO_NAME) $(ISO_DIR)