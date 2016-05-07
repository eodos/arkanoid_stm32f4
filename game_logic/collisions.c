#include "structures.h"


void check_collisions_paddle(ball_t *ball, paddle_t *paddle) {
	if ((ball->y - ball->radius < paddle->y + paddle->height) &&
		(ball->x >= paddle->x - paddle->length) &&
		(ball->x <= paddle->x + paddle->length))
	{
		ball->vy = -ball->vx;
	}
}

/* This function detects collisions with the game limits. If the ball hits the lower limit,
 * it will return -1. In any other case it will return 0. */
uint32_t check_collisions_limits(ball_t *ball) {
	if(ball->x - ball->radius <= LEFT_LIMIT)
		/* Collision with left border, change x velocity */
		ball->vx = -ball->vx;
	else if(ball->x + ball->radius >= RIGHT_LIMIT)
		/* Collision with right border, change x velocity */
		ball->vx = -ball->vx;
	else if(ball->y + ball->radius >= UPPER_LIMIT)
		/* Collision with upper border, change y velocity */
		ball->vy = -ball->vy;
	else if(ball->y - ball->radius <= LOWER_LIMIT)
	{
		/* Collision with lower limit, return 1 */
		ball->vx = 0;
		ball->vy = 0;
		return 1;
	}
		
	return 0;
}

void check_collisions_blocks(ball_t *ball, brick_t **bricks, uint32_t n_bricks) {
	uint32_t i;
	for(i=0; i<n_bricks; i++)
	{
		if(bricks[i]->active)
		{
			/* Left side collision */
			if((ball->x + ball->radius > bricks[i]->x - bricks[i]->length) && 
				(ball->y > bricks[i]->y - bricks[i]->height) && 
				(ball->y < bricks[i]->y + bricks[i]->height))
			{
				bricks[i]->active = 0;
				ball->vx = -ball->vx;
				break;
			}
			else if((ball->x - ball->radius < bricks[i]->x + bricks[i]->length) &&
				(ball->y > bricks[i]->y - bricks[i]->height) && 
				(ball->y < bricks[i]->y + bricks[i]->height))
			{
				bricks[i]->active = 0;
				ball->vx = -ball->vx;
				break;
			}
			else if((ball->y + ball->radius > bricks[i]->y - bricks[i]->height) &&
				(ball->x > bricks[i]->x - bricks[i]->length) &&
				(ball->x < bricks[i]->x + bricks[i]->length))
			{
				bricks[i]->active = 0;
				ball->vy = -ball->vy;
				break;
			}
			else if((ball->y - ball->radius < bricks[i]->y + bricks[i]->height) &&
				(ball->x > bricks[i]->x - bricks[i]->length) &&
				(ball->x < bricks[i]->x + bricks[i]->length))
			{
				bricks[i]->active = 0;
				ball->vy = -ball->vy;
				break;
			}
		}
	}
}

uint32_t check_collisions(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t n_bricks) {
	check_collisions_paddle(ball, paddle);
	uint32_t end = 0;
	end = check_collisions_limits(ball);
	//check_collisions_blocks(ball, bricks, n_bricks);
	return end;
}