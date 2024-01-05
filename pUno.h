#ifndef PUNO_H_INCLUDED
#define PUNO_H_INCLUDED
#include "pDos.h"

void iJuego(std::string jNombres[], int pCant){
    srand(time(NULL));
    int nRonda = 0, jpTotal[pCant] = {0}, pMaximoRonda = 0, pMaximoPartida = 0;

    do{
        nRonda++;

        for(int i = 0; i < pCant; i++){
            rlutil::cls();

            int rDigitos = 0;
            if(nRonda >= 100){
                while(nRonda > 9){nRonda/=10; rDigitos++;}
                rDigitos/= 2;
            }

            rlutil::locate(17 - (jNombres[i].size()/2), 2); std::cout << "TURNO DE " << jNombres[i];
            rlutil::locate(55 - rDigitos, 2); std::cout << "RONDA N" << (char)167 << nRonda;
            rlutil::locate(85, 2); std::cout <<"PUNTAJE TOTAL: " << jpTotal[i] << " PUNTOS";
            rlutil::locate(40, 2); std::cout << (char)186;
            rlutil::locate(78, 2); std::cout << (char)186;

            for(int j = 1; j <= 114; j++){
                rlutil::locate(2 + j, 6); std::cout << (char)205;
                rlutil::locate(2 + j, 3); std::cout << (char)205;
                if(j > 6 && j < 30) {
                    rlutil::locate(78, j); std::cout << (char)186;
                }
            }

            rlutil::locate(40, 3); std::cout << (char)202;
            rlutil::locate(78, 3); std::cout << (char)202;
            rlutil::locate(78, 6); std::cout << (char)203;

            rlutil::locate(4,5); std::cout << "MAXIMO PUNTAJE DE LA RONDA: " << pMaximoRonda << " PUNTOS" << std::endl;

            //FUNCION DE LANZAR DADOS
            lanzamiento(jpTotal[i], pMaximoRonda, pMaximoPartida);

            if(pMaximoPartida >= 500){break;}
        }

        if(pCant >= 2 && pMaximoPartida < 500){
            sRondaCartel(jNombres, pCant, nRonda, jpTotal);
        }
    }while(pMaximoPartida < 500);
    pantallaFJuego(pMaximoPartida);
}

void inicio(int num){
    switch(num){
        case 1:{
            std::string jNombres[1];
            rlutil::cls();
            rlutil::locate(30,15);std::cout << "Ingrese el nombre del jugador: ";
            getline(std::cin, jNombres[0]);
            iJuego(jNombres, 1);
        }
        break;

        case 2:{
            rlutil::cls();
            int key = 0, pCant = 2;

            rlutil::locate(30,15); std::cout << "Seleccione cantidad de jugadores: ";

            do{
                rlutil::locate(65,15); std::cout << pCant;
                key = rlutil::getkey();

                switch(key){
                    case 14:
                        pCant++;
                        if(pCant > 10){
                            pCant = 10;
                        }
                    break;

                    case 15:
                        rlutil::locate(66,10); std::cout << " " << std::endl;
                        pCant--;
                        if(pCant < 2){
                            pCant = 2;
                        }
                    break;

                    case 1:
                        rlutil::cls();
                        std::string jNombres[pCant];
                        for(int i = 0; i < pCant ; i++){
                            rlutil::cls();
                            rlutil::locate(30, 15); std::cout << "INGRESE EL NOMBRE DEL JUGADOR " << i+1 << ": ";
                            getline(std::cin, jNombres[i]);
                        }
                        iJuego(jNombres, pCant);
                    break;
                }
            }while(key != 1);
        }
        break;

        case 3:
            rlutil::locate(1,25);std::cout << "Te la quedo debiendo maestro" << std::endl;
        break;
        case 4:
            exit(EXIT_FAILURE);
        break;
    }
}

#endif // PUNO_H_INCLUDED
