#ifndef DRAW_H
#define DRAW_H

#include "structures.h"

void draw_all_game(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t score, uint32_t sensibility);
void draw_ball_paddle(ball_t *ball, paddle_t *paddle, uint16_t color);
void erase_brick(brick_t *brick);
void draw_score(uint32_t score);
void draw_win_screen(void);
void draw_sensibility(uint32_t sensibility);

#endif /* DRAW_H */