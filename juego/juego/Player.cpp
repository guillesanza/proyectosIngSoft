#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include "Player.h"


void events() {

	if (_kbhit() && player_status) {
		switch (_getch()) {
			case 'a':
				if (player > 0) {
					player--;
				}break;

			case 'd':
				if (player < scene - 1) {
					player++;
				}break;

			case 'q':
				if (!shootLeft_status && !shootRight_status) {
					shootLeft_pos = player - 1;
					shootLeft_status = true;
				}break;

			case 'e':
				if (!shootLeft_status && !shootRight_status) {
					shootRight_pos = player + 1;
					shootRight_status = true;
					shootRight_firstTime = true;
				}break;
		}
	}

}



void player_died() {
	printf_s(",_;__,_;__,_,_:___,,_,_::__,,_;__,_GAME OVER,_;__,_,_:___,,_,_::__,,_;__,_,_;__");
	printf_s("\n\n    Survived time: %d seconds                 Enemys killed: %d            ", int(time*(0.1)), score);
}
