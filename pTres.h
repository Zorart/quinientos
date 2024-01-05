#ifndef PTRES_H_INCLUDED
#define PTRES_H_INCLUDED

//FUNCION PARA MOSTRAR LOS DADOS QUE POSTERIORMENTE SE VAN A SELECCIONAR
void tirarDados(int nDado, float nTirada, int nLanzamiento){
    int i, j;
    std::string dado[5][9];
    for(i=0;i<5;i++){
        for(j=0;j<9;j++){
            if(i == 0 || i == 4){
                dado[i][j] = (char)196;
            } else if(j == 0 || j == 8) {
                dado[i][j] = (char)179;
            } else {
                dado[i][j] = " ";
            }
        }
    }
    dado[0][0] = (char)218;
    dado[0][8] = (char)191;
    dado[4][0] = (char)192;
    dado[4][8] = (char)217;

    switch(nDado){
        case 0:
            for(i=0; i<5; i++){
                for(j=0; j<9; j++){
                    dado[i][j] = " ";
                }
            }
        break;
        case 1:
            dado[2][4] = (char)254;
        break;
        case 2:
            dado[1][2] = dado[3][6] = (char)254;
        break;
        case 3:
            dado[1][2] = dado[2][4] = dado[3][6] = (char)254;
        break;
        case 4:
            dado[1][2] = dado[1][6] = dado[3][2] = dado[3][6] = (char)254;
        break;
        case 5:
            dado[1][2] = dado[1][6] = dado[3][2] = dado[3][6] = dado[2][4] = (char)254;
        break;
        case 6:
            dado[1][2] = dado[1][6] = dado[2][2] = dado[2][6] = dado[3][2] = dado[3][6] = (char)254;
        break;
    }

    for(i = 0; i < 5; i++){
        //EN EL CIELO Y LA TIERRA SOY EL UNICO QUE MERECE VENERACION
        rlutil::locate(6 + nLanzamiento*24 + (round((nTirada/2)-0.01) - floor((nTirada/2)-0.01))*10, 9 + (floor((nTirada/2)-0.01))*6 + i);
        for(j = 0; j < 9; j++){
            std::cout << dado[i][j];
        }
    }
}

//FUNCION PARA MOSTRAR LOS DADOS CONSERVADOS
void dadosConservados(int tiradasDeLanzamiento, float nTirada){
    int i, j;
    std::string dado[5][9];

    //FOR DEDICADO A LA CONSTRUCCION DE LOS BORDES DEL DADO
    for(i=0;i<5;i++){
        for(j=0;j<9;j++){
            if(i == 0 || i == 4){
                dado[i][j] = (char)196;
            } else if(j == 0 || j == 8) {
                dado[i][j] = (char)179;
            } else {
                dado[i][j] = " ";
            }
        }
    }
    dado[0][0] = (char)218;
    dado[0][8] = (char)191;
    dado[4][0] = (char)192;
    dado[4][8] = (char)217;

    switch(tiradasDeLanzamiento){
    case 0:
        for(i=0; i<5; i++){
            for(j=0; j<9; j++){
                dado[i][j] = " ";
            }
        }
    break;
    case 1:
        dado[2][4] = (char)254;
    break;
    case 2:
        dado[1][2] = dado[3][6] = (char)254;
    break;
    case 3:
        dado[1][2] = dado[2][4] = dado[3][6] = (char)254;
    break;
    case 4:
        dado[1][2] = dado[1][6] = dado[3][2] = dado[3][6] = (char)254;
    break;
    case 5:
        dado[1][2] = dado[1][6] = dado[3][2] = dado[3][6] = dado[2][4] = (char)254;
    break;
    case 6:
        dado[1][2] = dado[1][6] = dado[2][2] = dado[2][6] = dado[3][2] = dado[3][6] = (char)254;
    break;
    }

    for(i = 0; i < 5; i++){
        rlutil::locate(83 + (round((nTirada/2)-0.01) - floor((nTirada/2)-0.01))*20, 9 + (floor((nTirada/2)-0.01))*6 + i);
        for(j = 0; j < 9; j++){
            std::cout << dado[i][j];
        }
    }
}

//FUNCION PARA SELECCIONAR LOS DADOS A CONSERVAR
void selectorDeConserva(int& select){
    int i, j, key;
    std::string marcoSelector[21][25], marcoDeBorrado[21][25];
    rlutil::locate(3,29); std::cout << "Selecciona una combinacion de dados...";
    for(i = 0; i < 21; i++){
        for(j = 0; j < 25; j++){
            if(i == 0 || i == 20){
                marcoSelector[i][j] = (char)196;
                marcoDeBorrado[i][j] = " ";
            } else if (j == 0 || j == 24){
                marcoSelector[i][j] = (char)179;
                marcoDeBorrado[i][j] = " ";
            }
        }
    }
    marcoSelector[0][0] = (char)218;
    marcoSelector[0][24] = (char)191;
    marcoSelector[20][0] = (char)192;
    marcoSelector[20][24] = (char)217;

    int x = 0;
    while(select==3){

        for(i = 0; i < 21; i++){
            rlutil::locate(3 + 24*x, 7+i);
            for(j = 0; j < 25; j++){
                if(j == 24){rlutil::locate(27 + 24*x, 7+i);}
                std::cout << marcoSelector[i][j];
            }
        }

        key = rlutil::getkey();

        for(i = 0; i < 21; i++){
            rlutil::locate(3 + 24*x, 7+i);
            for(j = 0; j < 25; j++){
                if(j == 24){rlutil::locate(27 + 24*x, 7+i);}
                std::cout << marcoDeBorrado[i][j];
            }
        }

        switch(key){
            case 16:
                x--;
                if(x < 0){x = 2;}
            break;
            case 17:
                x++;
                if(x > 2){x = 0;}
            break;
            case 1:
                select = x;
            break;
        }
    };
    for(i = 0; i <= 37; i++){rlutil::locate(3+i,29); std::cout << " ";}
}

//FUNCION USADA PARA CALCULAR LOS DADOS CONSERVADOS
void calculoDePuntos(int tiradasDeLanzamiento[], int& jpTotal, int& pMaximoRonda, int& pMaximoPartida){
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (tiradasDeLanzamiento[j] > tiradasDeLanzamiento[j + 1]) {
                int temp = tiradasDeLanzamiento[j];
                tiradasDeLanzamiento[j] = tiradasDeLanzamiento[j + 1];
                tiradasDeLanzamiento[j + 1] = temp;
            }
        }
    }

    bool todosIguales = true;
    for(int i = 1; i < 6; i++) {
        if(tiradasDeLanzamiento[i] != tiradasDeLanzamiento[i - 1]) {
            todosIguales = false;
            break;
        }
    }
    if(todosIguales) {
        if(tiradasDeLanzamiento[0] != 6){
            jpTotal += tiradasDeLanzamiento[0]*50;
            rlutil::locate(84, 9); std::cout << "Sexteto " << tiradasDeLanzamiento[0] << "!";
            rlutil::locate(92, 11); std::cout << "+" << tiradasDeLanzamiento[0]*50 << " puntos";
            if(pMaximoRonda < tiradasDeLanzamiento[0]*50){pMaximoRonda = tiradasDeLanzamiento[0]*50;}
        } else {
            rlutil::locate(84, 9); std::cout << "Sexteto " << tiradasDeLanzamiento[0] << "...";
            rlutil::locate(92, 11); std::cout << "-" << jpTotal << " Puntos";
            jpTotal = 0;
        }
    } else {
        int contador = 1;
        int maxRepetido = tiradasDeLanzamiento[0];
        int maxContador = 1;

        for(int i = 1; i < 6; i++) {
            if(tiradasDeLanzamiento[i] == tiradasDeLanzamiento[i - 1]) {
                contador++;
                if(contador > maxContador) {
                    maxContador = contador;
                    maxRepetido = tiradasDeLanzamiento[i];
                } else if (contador == maxContador && tiradasDeLanzamiento[i] > maxRepetido) {
                    maxRepetido = tiradasDeLanzamiento[i];
                }
            } else {
                contador = 1;
            }
        }

        if(maxContador >= 3){
            jpTotal += maxRepetido*10;
            rlutil::locate(93, 9); std::cout << "Triada " << maxRepetido << "!";
            rlutil::locate(92, 11); std::cout << "+" << maxRepetido*10 << " puntos";
            if(pMaximoRonda < maxRepetido*10){pMaximoRonda = maxRepetido*10;}
        } else {
            bool contieneTodos = true;
            for(int i = 0; i < 6; i++){
                if(tiradasDeLanzamiento[i] != i + 1){
                    contieneTodos = false;
                    break;
                }
            }

            if(contieneTodos){
                jpTotal = 500;
                rlutil::locate(93, 9); std::cout << "Escalera!";
                rlutil::locate(89, 11); std::cout << "Ganas la partida!";
                if(pMaximoRonda < 500){pMaximoRonda = 500;}
            } else {
                int vAux = 0;
                for(int i = 0; i < 6; i++){
                    vAux += tiradasDeLanzamiento[i];
                }
                jpTotal += vAux;
                rlutil::locate(88, 9); std::cout << "Sin combinaciones :(";
                rlutil::locate(92, 11); std::cout << "+" << vAux << " puntos";
                if(pMaximoRonda < vAux){pMaximoRonda = vAux;}
            }
        }
    }

    if(pMaximoPartida < jpTotal){pMaximoPartida = jpTotal;}
}

#endif // PTRES_H_INCLUDED
