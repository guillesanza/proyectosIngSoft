#include "stdafx.h"
#include "Render.h"
int wheater = 0;

void background() {

	if (pos % 10 == 0) {//Fondo de escenario

		switch (wheater){
			case 0:
				printf_s("|");
				break;
			case 1:
				printf_s("v");
				break;
			case 2:
				printf_s(";");
				break;
			case 3:
				printf_s(",");
				break;
			case 4:
				printf_s(",");
				break;
			default:
				printf_s("_");
				break;
			}

	
		
		if (wheater == 5)
			wheater = 0;

	}else
		printf_s("_");

}

void draw_game() {

	for (pos = 0; pos < scene; pos++)
	{
		if ((enemyLeft)+1 >= player || (enemyRight) == player) {//Player die
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



		if (pos == scene - 1) 
			shootRight_firstTime = true;
		
		if (shootLeft_pos <= 0) 
			shootLeft_status = false;
		
		if (shootRight_pos >= scene) 
			shootRight_status = false;
		




	}

	//if (time % 2 == 0)
		wheater++;

}

