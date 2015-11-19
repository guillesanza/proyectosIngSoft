#pragma once

extern int scene;
extern int pos;
extern int time;
extern int enemyLeft;
extern int enemyRight;
extern int player;
extern bool player_status;
extern bool enemyLeft_status;
extern bool enemyRight_status;
extern bool shootLeft_status;
extern bool shootRight_status;
extern int shootLeft_pos;
extern int shootRight_pos;
extern bool shootRight_firstTime;
extern int score;

void background();
void draw_game();