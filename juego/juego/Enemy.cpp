#include "stdafx.h"
#include <windows.h>
#include "Enemy.h"

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

void enemys_movement() {
	if (enemyLeft_status)//Enemy movement
		enemyLeft++;
	if (enemyRight_status)//Enemy movement
		enemyRight--;
}

