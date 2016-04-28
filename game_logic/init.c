#include "structures.h"

void init_game(ball_t *ball, paddle_t *paddle, brick_t **bricks)
{
	paddle->x = RIGHT_LIMIT/2;
	paddle->y = 50;
	paddle->height = 3;
	paddle->length = 5;

	ball->radius = 3;
	ball->x = paddle->x + ball->radius;
	ball->y = paddle->y;
	ball->vx = 5;
	ball->vy = 5;

	uint32_t brick_y = 200;
	uint32_t brick_x = 5;
	uint32_t i = 0;
	for(i=0; i< N_BRICKS; i++)
	{
		bricks[i]->active = 1;
		bricks[i]->height = 3;
		bricks[i]->length = 5;
		bricks[i]->y = brick_y;
		bricks[i]->x = brick_x;
		brick_x += bricks[i]->length * 2 + 1;
		if(brick_x + bricks[i]->length > RIGHT_LIMIT)
		{
			brick_x = 5;
			brick_y += bricks[i]->height * 2;
		}
	}
}