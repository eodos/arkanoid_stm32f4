#include "structures.h"
#include <stdlib.h>

void reset_game(ball_t *ball, paddle_t *paddle, brick_t **bricks)
{
	uint32_t i;

	uint32_t brick_y = 100;
	uint32_t brick_x = BRICK_LENGTH + 15;

	paddle->x = RIGHT_LIMIT/2;
	paddle->y = 270;
	paddle->height = PADDLE_HEIGHT;
	paddle->length = PADDLE_LENGTH;

	ball->radius = 3;
	ball->x = paddle->x;
	ball->y = paddle->y - paddle->height - ball->radius - 1;
	ball->vx = -3;
	ball->vy = -3;

	for(i=0; i< N_BRICKS; i++)
	{
		bricks[i]->active = 1;
		bricks[i]->height = BRICK_HEIGHT;
		bricks[i]->length = BRICK_LENGTH;
		bricks[i]->y = brick_y;
		bricks[i]->x = brick_x;
		brick_x += bricks[i]->length * 2 + 5;
		if(brick_x + bricks[i]->length > RIGHT_LIMIT - 15)
		{
			brick_x = BRICK_LENGTH + 15;
			brick_y -= bricks[i]->height * 2 + 2;
		}
	}

}

void init_game(ball_t **ball, paddle_t **paddle, brick_t **bricks)
{
	/* Allocate the structures */
	*paddle = malloc(sizeof(paddle_t));
	*ball = malloc(sizeof(ball_t));

	uint32_t i = 0;

	for(i=0; i< N_BRICKS; i++)
	{
		bricks[i] = malloc(sizeof(brick_t));
	}
}

float get_time();

void wait(uint32_t sec)
{
	float n;
	n = get_time() + sec;
	while(get_time() < n);
}