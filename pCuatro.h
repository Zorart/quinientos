#ifndef PCUATRO_H_INCLUDED
#define PCUATRO_H_INCLUDED

void dadosConservados(int dConservados, int cantCons){
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

    switch(dConservados){
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
        if(dConservados != 0){
            rlutil::locate(5 + (cantCons-1)*12, 24 + i);
            for(j = 0; j < 9; j++){
                std::cout << dado[i][j];
            }
        } else if(dConservados == 0){
            rlutil::locate(5 + (cantCons-1)*12, 24 + i);
            for(j = 0; j < 9; j++){
                std::cout << dado[i][j];
            }
        }
    }
}

#endif // PCUATRO_H_INCLUDED
