#ifndef PDOS_H_INCLUDED
#define PDOS_H_INCLUDED
#include "pTres.h"

void lanzamiento(int& jpTotal, int& pMaximoRonda, int& pMaximoPartida){
    int i, j, select = 3, tiradasDeLanzamiento[3][6];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 6; j++){
            tiradasDeLanzamiento[i][j] = 1+rand()%6;
            tirarDados(tiradasDeLanzamiento[i][j], j+1, i);
        }
    }
    selectorDeConserva(select);

    calculoDePuntos(tiradasDeLanzamiento[select], jpTotal, pMaximoRonda, pMaximoPartida);
    rlutil::locate(84, 28); std::cout << "Toca un boton para continuar...";
    rlutil::anykey();
}

//FUNCION PARA MOSTRAR LA PANTALLA DE FIN DE JUEGO UNA VEZ QUE SE LLEGA O PASA LOS 500
void pantallaFJuego(int jpTotal){
    rlutil::cls();
    for(int i = 45; i <= 75; i++){
        for(int j = 10; j <= 20; j++){
            if(i == 45 || i == 75){
                rlutil::locate(i,j);std::cout << (char)186;
            } else if(j == 10 || j == 20) {
                rlutil::locate(i,j);std::cout << (char)205;
            }
        }
    }
    rlutil::locate(45, 10); std::cout << (char)201;
    rlutil::locate(75, 10); std::cout << (char)187;
    rlutil::locate(45, 20); std::cout << (char)200;
    rlutil::locate(75, 20); std::cout << (char)188;

    rlutil::locate(55,14);std::cout << "¡GANASTE!";
    rlutil::locate(51,15);std::cout << "PUNTAJE TOTAL: " << jpTotal;
    rlutil::anykey();
}

void sRondaCartel(std::string jNombres[], int pCant, int nRonda, int jpTotal[]){
    int i, j;
    rlutil::cls();

    std::string marcoDeRonda[21][55];
    for(i = 0; i < 21; i++){
        for(j = 0; j < 55; j++){
            if(i == 0 || i == 20){
                marcoDeRonda[i][j] = (char)205;
            } else if (j == 0 || j == 54){
                marcoDeRonda[i][j] = (char)186;
            } else {
                marcoDeRonda[i][j] = " ";
            }
        }
    }
    marcoDeRonda[0][0] = (char)201;
    marcoDeRonda[0][54] = (char)187;
    marcoDeRonda[20][0] = (char)200;
    marcoDeRonda[20][54] = (char)188;

    for(i = 0; i < 21; i++){
        rlutil::locate(30,5+i);
        for(j = 0; j < 55; j++){
            std::cout << marcoDeRonda[i][j];
        }
    }
    rlutil::locate(53, 8); std::cout << "Ronda" << (char)167 << nRonda;
    for(int i = 0; i < pCant; i++){
        rlutil::locate(33 + (i/5)*30, 11 + (i%5)*2); std::cout << jNombres[i] << ": " << jpTotal[i] << " puntos";
    }
    rlutil::locate(33, 23); std::cout << "Presione una tecla para continuar...";
    rlutil::anykey();
}

#endif // PDOS_H_INCLUDED
