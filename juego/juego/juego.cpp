// juego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <conio.h>

int scene = 60;

int pos = 0;
int time = 0;

int enemyLeft = -1;
int enemyRight = scene + 1;
int player = 25;
bool player_status = true;
bool enemyLeft_status = false;
bool enemyRight_status = false;
bool shootLeft_status = false;
bool shootRight_status = false;
int shootLeft_pos = player;
int shootRight_pos = player;
bool shootRight_firstTime = false;
int score = 0;

void enemys_alive() {

	if (time % 10 == 0) {//init enemy tipe1
		switch (rand() % 2 + 1) {
		case 1:
			if (!enemyLeft_status) {
				enemyLeft_status = true;
				enemyLeft = 0;
			}
			break;
		case 2:
			if (!enemyRight_status) {
				enemyRight_status = true;
				enemyRight = scene + 1;
			}
			break;
		}
	}
}
void events() {

	if (_kbhit() && player_status) {
		switch (_getch()) {
		case 'a': if (player > 0){
						player--;
				  }break;

		case 'd': if (player < scene - 1) {
						player++;
				  }break;

		case 'q': if (!shootLeft_status && !shootRight_status) {
					shootLeft_pos = player - 1;
					shootLeft_status = true;
				  }break;

		case 'e': if (!shootLeft_status && !shootRight_status) {
					shootRight_pos = player + 1;
					shootRight_status = true;
					shootRight_firstTime = true;
				  }
		}
	}



}
void enemys_movement() {
	if (enemyLeft_status)//Enemy movement
		enemyLeft++;
	if (enemyRight_status)//Enemy movement
		enemyRight--;
}
void background() {
	
	if (pos % 9 == 0)//Fondo de escenario
		printf_s("w");
	else if (pos % 5 == 0)//Fondo de escenario
		printf_s("v");
	else
		printf_s("_");
}
void draw_game() {

	for (pos = 0; pos < scene; pos++)
	{
		//--------- DRAW

		if ((enemyLeft) >= player || (enemyRight) == player) {//Player die
			printf_s("X");
			enemyLeft_status = false;
			enemyRight_status = false;
			enemyLeft = -1;
			enemyRight = -1;
			player_status = false;

		}
		else if (enemyLeft >= shootLeft_pos) {//Kill enemy left
			printf_s("*");
			enemyLeft_status = false;
			enemyLeft = -1;
			shootLeft_pos = player;
			shootLeft_status = false;
			score++;

		}
		else if (enemyRight == shootRight_pos) {//Kill enemy right
			printf_s("*");
			enemyRight_status = false;
			enemyRight = -1;
			shootRight_pos = player;
			shootRight_status = false;
			score++;

		}
		else if (enemyLeft == pos) {//Enemy left
			printf_s("H");

		}
		else if (enemyRight == pos) {//Enemy right
			printf_s("H");

		}
		else if (player == pos) {//Player
			printf_s("8");

		}
		else if (shootLeft_status && shootLeft_pos > 0 && pos == shootLeft_pos) {//Left  shoot
			shootLeft_pos--;
			printf_s("-");

		}
		else if (shootRight_status && shootRight_pos < scene && pos == shootRight_pos && shootRight_firstTime) {//Right  shoot
			shootRight_pos++;
			printf_s("-");
			shootRight_firstTime = false;

		}
		else
			background();
			
			

		if (pos == scene - 1) shootRight_firstTime = true;
		if (shootLeft_pos <= 0) shootLeft_status = false;
		if (shootRight_pos >= scene) shootRight_status = false;
		//if (enemyLeft >= scene)	enemyLeft = -1;




	}


}
void player_died() {
	printf_s(",_;__,_;__,_,_:___,,_,_::__,,_;__,_GAME OVER,_;__,_,_:___,,_,_::__,,_;__,_,_;__");
	printf_s("\n\n    Survived time: %d seconds                 Enemys killed: %d            ", int(time*(0.1)), score);
}


int main()
{
	
		printf_s("\n\n\n\n\n\n\n\n");
		
		while(player_status){

			enemys_alive();
			enemys_movement();
			draw_game();
			events();
		
			Sleep(100);
			time++;
			printf_s("  Score:%d", score);
			printf_s("\r");
		}
		player_died();
		getchar();
	
	return 0;
}

