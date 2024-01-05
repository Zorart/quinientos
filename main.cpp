#include <time.h>
#include <math.h>
#include "rlutil.h"
#include "pUno.h"

int main(){
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::cls();
    rlutil::hidecursor();
    std::string spNombre;
    int op = 5, x = 0;

        for(int i = 2; i <= 119; i++){
            for(int j = 1; j <= 17 ; j++){
                if(i == 2 || i == 119){
                   rlutil::locate(i,j+1); std::cout << (char)186;
                } else if(j == 2){
                    rlutil::locate(i,1); std::cout << (char)205;
                } else if(j == 17){
                    rlutil::locate(i,19); std::cout << (char)205;
                }
            }
        }
        rlutil::locate(54, 9);std::cout << "QUINIENTOS";

        rlutil::locate(9,25); std::cout << "SINGLEPLAYER";
        rlutil::locate(39,25); std::cout << "MULTIPLAYER";
        rlutil::locate(70,25); std::cout << "HIGHSCORE";
        rlutil::locate(103,25); std::cout << "EXIT";

    do{
        rlutil::locate(15 + x*30, 24); std::cout << "V" << std::endl;

        int key = rlutil::getkey();

        switch(key){
            case 16:
                rlutil::locate(15 + x*30, 24); std::cout << " " << std::endl;
                x--;
                if(x < 0){
                    x = 3;
                }
            break;
            case 17:
                rlutil::locate(15 + x*30, 24); std::cout << " " << std::endl;
                x++;
                if(x > 3){
                    x = 0;
                }
            break;

            case 1:
                op = x+1;
            break;
        }

    }while(op == 5);
    inicio(op);
}
