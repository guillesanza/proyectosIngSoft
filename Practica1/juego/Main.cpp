// juego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int scene = 60;
int pos = 0;
int player = 25;


int main()
{
	
		printf_s("\n\n\n\n\n\n\n\n");
		
		while(true){

			
			for (pos = 0; pos < scene; pos++)
			{
				if (player == pos) {//Player
					printf_s("8");

				} else {
					printf_s("_");
				}
			}

				//Events
				if (_kbhit()) {
					switch (_getch()) {
					case 'a':
						if (player > 0) {
							player--;
						}break;

					case 'd':
						if (player < scene - 1) {
							player++;
						}break;

				
					}
				}

			printf_s("\r");
		
		}
		
		
		getchar();
	
	return 0;
}

