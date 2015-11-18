// juego.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <conio.h>

#include "Game.h"
#include "Render.h"
#include "Enemy.h"
#include "Player.h"







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

