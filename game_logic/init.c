#include "structures.h"
#include <stdlib.h>

void init_game(ball_t **ball, paddle_t **paddle, brick_t **bricks)
{
	*paddle = malloc(sizeof(paddle_t));
	(*paddle)->x = RIGHT_LIMIT/2;
	(*paddle)->y = 50;
	(*paddle)->height = BRICK_HEIGHT;
	(*paddle)->length = BRICK_LENGTH;

	*ball = malloc(sizeof(ball_t));
	(*ball)->radius = 3;
	(*ball)->x = (*paddle)->x + (*ball)->radius;
	(*ball)->y = (*paddle)->y;
	(*ball)->vx = 5;
	(*ball)->vy = 5;

	uint32_t brick_y = 220;
	uint32_t brick_x = BRICK_LENGTH + 8;
	uint32_t i = 0;
	for(i=0; i< N_BRICKS; i++)
	{
		bricks[i] = malloc(sizeof(brick_t));
		bricks[i]->active = 1;
		bricks[i]->height = BRICK_HEIGHT;
		bricks[i]->length = BRICK_LENGTH;
		bricks[i]->y = brick_y;
		bricks[i]->x = brick_x;
		brick_x += bricks[i]->length * 2 + 2;
		if(brick_x + bricks[i]->length > RIGHT_LIMIT)
		{
			brick_x = BRICK_LENGTH + 8;
			brick_y += bricks[i]->height * 2 + 2;
		}
	}
}