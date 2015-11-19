#pragma once
extern int time;
extern int scene;
extern int player;
extern bool player_status;

extern int shootLeft_pos;
extern bool shootLeft_status;

extern int shootRight_pos;
extern bool shootRight_status;
extern bool shootRight_firstTime;
extern int score;

void background();
void draw_game();