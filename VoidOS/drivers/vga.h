#ifndef VGA.H
#define VGA.H


// Definições de cores
enum Color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	WHITE = 15,
};

int terminal_row = WHITE;
int terminal_column = WHITE;
uint8_t terminal_color = BLACK;




void kprint(const char* data){
	for(int i = 0; data[0] != '\n'; i++){
		terminalInteractive(data[i]);
	}
}


void terminalInteractive(char character ){
// Se for um caractere de nova linha (\n), apenas pulamos a linha
	if(character == '\n'){
		terminal_column = 0;
		terminal_row++;
	}else{
		// Usa a sua lógica original do index, mas com as variáveis globais
		put_char(character,terminal_color,terminal_column,terminal_row);
		terminal_column++;
	
	// Se chegar no fim da linha (coluna 80), pula para a próxima
	if(terminal_column >= 80){
		terminal_column = 0;
		terminal_row++;
	}

	}
	// Se chegar no fim da tela (linha 25), precisamos de Scroll (limpar ou subir
	if(terminal_row >= 25){
		clearScreen();
		terminal_row;
	}
	
}
	


// Função para colocar um caractere em uma posição específica (x, y)
void put_char(char c, char color, int x, int y){
	volatile char* video_memory = (char*)0xB8000;
	// Cálculo: Cada linha tem 80 caracteres, cada caractere tem 2 bytes
	int index = (y * 80 + x) * 2;
	video_memory[index] = c;
	video_memory[index + 1] = color;
}

//Função percorre todos os bytes deixando eles limpos e com cor preta 
void clearScreen(){
	for(int y = 0; y < 25; y++){
		for(int x = 0; y < 80; x++){
			put_char(" ",BLACK,x,y);
		}
	}
}









#endif