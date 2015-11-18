#pragma once
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


void enemys_alive();
void events();
void enemys_movement();
void player_died();