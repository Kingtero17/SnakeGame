#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <stdio.h>

// Colores ANSI
#define COLOR_ROJO     "\x1b[31m"
#define COLOR_VERDE    "\x1b[32m"
#define COLOR_AMARILLO "\x1b[33m"
#define CP_AZUL        "\x1b[34m"
#define CP_CIAN        "\x1b[36m"
#define COLOR_RESET    "\x1b[0m"

// Declarando funciones interfaz.
void gotoxy(int x, int y);
void ocultar_cursor();
void limpiar_pantalla();
void pintar_marco();
void menu_inicio();
void menu_controles();
void menu_pausa();
void menu_game_over();
void menu_post_puntaje();
void pantalla_final();

// Funcion gotoxy (ANSI)
void gotoxy(int x, int y){
    printf("\033[%d;%dH", y, x);
}

// Ocultar cursor (ANSI)
void ocultar_cursor(){
    printf("\033[?25l");
}

// Limpiar pantalla (ANSI)
void limpiar_pantalla(){
    printf("\033[2J\033[H");
}

#ifdef _WIN32
    // FUNCIÓN PARA WINDOWS
    void pintar_marco() {
        // Lineas horizontales (Código 205: ═)
        for(int i = 2; i < 118; i++) {
            gotoxy(i, 2);  printf("%c", 205);
            gotoxy(i, 28); printf("%c", 205);
        }
        // Lineas verticales (Código 186: ║)
        for(int i = 2; i < 29; i++) {
            gotoxy(2, i);   printf("%c", 186);
            gotoxy(117, i); printf("%c", 186);
        }
        // Esquinas (201: ╔, 187: ╗, 200: ╚, 188: ╝)
        gotoxy(2, 2);    printf("%c", 201);
        gotoxy(117, 2);  printf("%c", 187);
        gotoxy(2, 28);   printf("%c", 200);
        gotoxy(117, 28); printf("%c", 188);
    }
#else
    // FUNCIÓN PARA LINUX (Usa secuencias UTF-8)
    void pintar_marco() {
        for(int i = 2; i < 118; i++) {
            gotoxy(i, 2);  printf("═");
            gotoxy(i, 28); printf("═");
        }
        for(int i = 2; i < 29; i++) {
            gotoxy(2, i);   printf("║");
            gotoxy(117, i); printf("║");
        }
        gotoxy(2, 2);    printf("╔");
        gotoxy(117, 2);  printf("╗");
        gotoxy(2, 28);   printf("╚");
        gotoxy(117, 28); printf("╝");
    }
#endif


void menu_inicio(){
    limpiar_pantalla();
    pintar_marco();

    const char* portada[21] = {
    "        aaaaaaaaaaaa  aa         aa      aaaa      aa       aa aaaaaaaaaaaa                                   ",
    "                  aa  aaa        aa    aaaaaaaa    aa    aa    aa                                             ",
    "                  aa  aa  aa     aa  aaaaaaaaaaaa  a  aa       aa                                             ",
    "        aaaaaaaaaaaa  aa   aaa   aa aaaaaaaaaaaaaa aa          aaaaaaaaaaaa                                   ",
    "        aa            aa     aa  aa  aaaaaaaaaaaa  a aa        aa                                             ",
    "        aa            aa        aaa    aaaaaaaa    aa   aa     aa                                             ",
    "        aaaaaaaaaaaa  aa         aa      aaaa      aa      aa  aaaaaaaaaaaa                                   ",
    "                                     **        **                              -PRESIONE 1 PARA JUGAR.        ",
    "                                     ****    ****             ************     -PRESIONE 2 PARA VER PUNTAJES  ",
    "                                     ** ****** **             ************     -PRESIONE 3 PARA VER CONTROLES ",
    "     ********************************************             ************     -PRESIONE ESC PARA SALIR.      ",
    "     ********************************************             ************                                    ",
    "     ********************************************             ************                                    ",
    "     ********************************************             ************                                    ",
    "     ************                                             ************                                    ",
    "     ************            *********************************************                                    ",
    "     ************            *********************************************                                    ",
    "     ************            *********************************************                                    ",
    "     *********************************************************************                                    ",
    "     *************************************                                                                    ",
    "     *************************************                                                                    ",

    };

    for(int i = 0 ; i < 21; i++){
        gotoxy(5, i + 5); 
        printf("%s", portada[i]);
    }
}


void menu_controles() {
    limpiar_pantalla();
    pintar_marco();

    int a = 33;
    gotoxy(a, 6);  printf(COLOR_AMARILLO "  ____ _____   _  ___ ______ _____    __    ____ ____ " COLOR_RESET);
    gotoxy(a, 7);  printf(COLOR_AMARILLO " / __// __  \\ / \\/  //_  __/ / __/   / /   / __// __/ " COLOR_RESET);
    gotoxy(a, 8);  printf(COLOR_AMARILLO "/ /_ / /_ / // \\/  /  / / / / / o \\ / /__ / _/_ \\ \\  " COLOR_RESET);
    gotoxy(a, 9);  printf(COLOR_AMARILLO "\\___/\\_____//_/ \\_/  /_/ /_/\\_\\___//____/ \\___//___/ " COLOR_RESET);

    // Controles
    int b = 45;
    gotoxy(b, 12); printf("ARRIBA:    [ W ]  o  [ ^ ]");
    gotoxy(b, 13); printf("ABAJO:     [ S ]  o  [ v ]");
    gotoxy(b, 14); printf("IZQUIERDA: [ A ]  o  [ < ]");
    gotoxy(b, 15);      printf("DERECHA:   [ D ]  o  [ > ]");

    gotoxy(b, 17); printf(COLOR_ROJO "PAUSA:     [ 3 ]" COLOR_RESET);
    gotoxy(b, 18); printf(COLOR_ROJO "SALIR:     [ ESC ]" COLOR_RESET);

    gotoxy(38, 22); printf("PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU...");
}

void menu_pausa(){
    gotoxy(56, 7); printf("PAUSE");
    gotoxy(28, 9); printf("SALIR:              Presione ESC para salir.");
    gotoxy(28, 10);printf("REINICIAR PARTIDA:  Presione 1 para reiniciar la partida.");
    gotoxy(28, 11);printf("MENU DE INICIO:     Presione 2 para volver al menu de inicio.");
    gotoxy(28, 12);printf("REANUDAR PARTIDA:   Presione 3 para reanudar la partida.");
}

void menu_game_over(){
    limpiar_pantalla();
    pintar_marco();

    int c = 32; 
    gotoxy(c, 7);  printf(COLOR_ROJO " _________    __  _________   ____ _   ____________ " COLOR_RESET);
    gotoxy(c, 8);  printf(COLOR_ROJO "/ ____/   |  /  |/  / ____/  / __ \\ | / / ____/ __ \\" COLOR_RESET);
    gotoxy(c, 9);  printf(COLOR_ROJO "/ / __/ /| | / /|_/ / __/    / / / / |/ / __/ / /_/ /" COLOR_RESET);
    gotoxy(c, 10); printf(COLOR_ROJO "/ /_/ / ___ |/ /  / / /___   / /_/ /|  / /___/ _, _/ " COLOR_RESET);
    gotoxy(c, 11); printf(COLOR_ROJO "\\____/_/  |_/_/  /_/_____/   \\____/ |_/_____/_/ |_|  " COLOR_RESET);

    int a = 28;
    gotoxy(a, 13);printf("SALIR:              Presione ESC para salir.");
    gotoxy(a, 14);printf("REINICIAR PARTIDA:  Presione 1 para reiniciar la partida.");
    gotoxy(a, 15);printf("GUARDAR RECORD:     Presione 2 para guardar su record.");
    gotoxy(a, 16);printf("MENU DE INICIO:     Presione 3 para volver al menu de inicio.");
}

void menu_post_puntaje(){
    limpiar_pantalla();
    pintar_marco();
    gotoxy(42, 7); printf("ELIGE UNA OPCION PARA CONTINUAR:");
    gotoxy(28, 9); printf("SALIR:              Presione ESC para salir.");
    gotoxy(28, 10);printf("JUGAR DE NUEVO:     Presione 1 para jugar de nuevo.");
    gotoxy(28, 11);printf("MENU DE INICIO:     Presione 2 para volver al menu de inicio.");
}

void pantalla_final(){
    limpiar_pantalla();
    pintar_marco();

int x_centro = 30; 
    int y_ini = 8;

    // Se duplicaron las barras invertidas (\\) para que el compilador no de error
    gotoxy(x_centro, y_ini++); printf(COLOR_VERDE "  _____ _   _    _   _   _ _  __ ____    _____ ___  ____  " COLOR_RESET);
    gotoxy(x_centro, y_ini++); printf(COLOR_VERDE " |_   _| | | |  / \\ | \\ |  ||/ // ___|  |  ___/ _ \\|  _ \\ " COLOR_RESET);
    gotoxy(x_centro, y_ini++); printf(COLOR_VERDE "   | | | |_| | / _ \\|  \\|  |' / \\___ \\  | |_ | | | | |_) |" COLOR_RESET);
    gotoxy(x_centro, y_ini++); printf(COLOR_VERDE "   | | |  _   / ___ \\  |\\  |.  \\___) |  |  _|| |_| |  _ < " COLOR_RESET);
    gotoxy(x_centro, y_ini++); printf(COLOR_VERDE "   |_| |_| |_/_/   \\_\\_| \\_|_|\\_\\____/  |_|   \\___/|_| \\_\\" COLOR_RESET);
    
    // Segunda parte: PLAYING
    gotoxy(x_centro+8, y_ini++); printf(COLOR_AMARILLO "  ____  _        _ __   _____ _   _  ____ " COLOR_RESET);
    gotoxy(x_centro+8, y_ini++); printf(COLOR_AMARILLO " |  _ \\| |      / \\\\ \\ / /_ _| \\ | |/ ___|" COLOR_RESET);
    gotoxy(x_centro+8, y_ini++); printf(COLOR_AMARILLO " | |_) | |     / _ \\\\ V / | ||  \\| | |  _ " COLOR_RESET);
    gotoxy(x_centro+8, y_ini++); printf(COLOR_AMARILLO " |  __/| |___ / ___ \\| |  | || |\\  | |_| |" COLOR_RESET);
    gotoxy(x_centro+8, y_ini++); printf(COLOR_AMARILLO " |_|   |_____/_/   \\_\\_| |___|_| \\_|\\____|" COLOR_RESET);

    gotoxy(50,19);printf("GRACIAS POR JUGAR!");
    gotoxy(39,20);printf("PRESIONE ENTER PARA FINALIZAR EL PROGRAMA.");

    while (getchar() != '\n' && getchar() != EOF);
    getchar(); 
}

#endif // INTERFAZ_H