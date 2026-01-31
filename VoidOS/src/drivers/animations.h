#ifndef ANIMATIONS_H
#define ANIMATIONS_H



void firstAnimation(){
int x = 6;
int y = 5;

clearScreen();
kprint(" .sSSS s.    .sSSSSs.    SSSSS .sSSSSs.         .sSSSSs.    .sSSSSs.",RED,x,y++ );
kprint(" SSSSS SSSs. SSSSSSSSSs. SSSSS SSSSSSSSSs.      SSSSSSSSSs. SSSSSSSSSs.",RED,x,y++ );
kprint(" S SSS SSSSS S SSS SSSSS S SSS S SSS SSSSS      S SSS SSSSS S SSS SSSS'",RED,x,y++ );
kprint(" S  SS SSSSS S  SS SSSSS S  SS S  SS SSSSS      S  SS SSSSS S  SS",RED,x,y++      );
kprint(" S..SS SSSSS S..SS SSSSS S..SS S..SS SSSSS      S..SS SSSSS `SSSSsSSSa.",RED,x,y++ );
kprint("  S::S SSSS  S:::S SSSSS S:::S S:::S SSSSS      S:::S SSSSS .sSSS SSSSS",RED,x,y++ );
kprint("   S;S SSS   S;;;S SSSSS S;;;S S;;;S SSSSS      S;;;S SSSSS S;;;S SSSSS",RED,x,y++ );
kprint("    SS SS    S%%%S SSSSS S%%%S S%%%S SSSS'      S%%%S SSSSS S%%%S SSSSS",RED,x,y++ );
kprint("     SsS     SSSSSsSSSSS SSSSS SSSSSsS;:'       SSSSSsSSSSS SSSSSsSSSSS",RED,x,y++ );
kprint(" [*]PRECIONE ENTER PARA INICIAR:                                      ",GREEN,x,y++ );


}











#endif