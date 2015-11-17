// juego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int main()
{
	
	int scene = 60;
	int player = 25;
	bool estado_bala_izq = false;
	bool estado_bala_der = false;
	int pos_bala_izq = player;
	int pos_bala_der = player;
	bool first = false;
	printf_s("\n\n\n\n\n\n\n\n");


	while (true) {

		for ( int pos = 0; pos < scene; pos++)
		{
			if (pos == player)
				printf_s("8");
			else if (estado_bala_izq && pos_bala_izq > 0 && pos== pos_bala_izq) {
					pos_bala_izq--;
					printf_s("-");
			}else if (estado_bala_der && pos_bala_der < scene && pos== pos_bala_der && first) {
					pos_bala_der++;
					printf_s("-");
					first = false;
			}else if (pos % 7 == 0)//Fondo de escenario
					printf_s(";");
				else
					printf_s(",");

			if (pos == scene - 1) first = true;
			if (pos_bala_izq <= 0) estado_bala_izq = false;
			if (pos_bala_der >= scene) estado_bala_der = false;
		}
		
		if (_kbhit()) {
			switch(_getch()){
				case 'a': if (player > 0) 
							player--;
						  break;

				case 'd': if(player<scene-1) 
							player++;
						  break;

				case 'q': if (!estado_bala_izq) {
							pos_bala_izq = player - 1;
							estado_bala_izq = true;
						  }break;

				case 'e': if (!estado_bala_der) {
							pos_bala_der = player + 1;
							estado_bala_der = true;
							first = true;
						  }
			}
		}
		Sleep(100);
		printf_s("\r");
	}
	return 0;
}

