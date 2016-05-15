#include "collisions.h"
#include "draw.h"

void check_collisions_paddle(ball_t *ball, paddle_t *paddle) {
	/* Check collision with the paddle only if the ball is moving to the bottom of the screen */
	if ((ball->vy > 0) &&
		(ball->y + ball->radius + ball->vy >= paddle->y - paddle->height) &&
		(ball->y + ball->radius + ball->vy <= paddle->y + paddle->height) &&
		(ball->x >= paddle->x - paddle->length) &&
		(ball->x <= paddle->x + paddle->length))
	{
		ball->vy = -ball->vy;
	}
}

/* This function detects collisions with the game limits. If the ball hits the lower limit,
 * it will return -1. In any other case it will return 0. */
uint32_t check_collisions_limits(ball_t *ball) {
	if(ball->x - ball->radius + ball->vx <= LEFT_LIMIT)
		/* Collision with left border, change x velocity */
		ball->vx = -ball->vx;
	else if(ball->x + ball->radius + ball->vx >= RIGHT_LIMIT)
		/* Collision with right border, change x velocity */
		ball->vx = -ball->vx;
	else if(ball->y - ball->radius + ball->vy <= UPPER_LIMIT)
		/* Collision with upper border, change y velocity */
		ball->vy = -ball->vy;
	else if(ball->y + ball->radius + ball->vy >= LOWER_LIMIT)
	{
		/* Collision with lower limit, return 1 */
		ball->vx = 0;
		ball->vy = 0;
		return 1;
	}
		
	return 0;
}

void check_collisions_blocks(ball_t *ball, brick_t **bricks, uint32_t *score, uint32_t *n_bricks_active) {
	uint32_t i;
	for(i=0; i<N_BRICKS; i++)
	{
		if(bricks[i]->active)
		{
			if((ball->x + ball->vx + ball->radius >= bricks[i]->x - bricks[i]->length) &&
				((ball->x + ball->vx - ball->radius <= bricks[i]->x + bricks[i]->length)) &&
				((ball->y + ball->vy + ball->radius >= bricks[i]->y - bricks[i]->height)) &&
				((ball->y + ball->vy - ball->radius <= bricks[i]->y + bricks[i]->height)))
			{
				if((ball->y <= bricks[i]->y - bricks[i]->length) ||
					(ball->y >= bricks[i]->y + bricks[i]->length))
				{
					ball->vx = -ball->vx;
				}
				else
				{
					ball->vy = -ball->vy;
				}

				bricks[i]->active = 0;
				*n_bricks_active--;
				erase_brick(bricks[i]);
				*score += 10;
				draw_score(*score);
				break;
			}
		}
	}
}

uint32_t check_collisions(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t *score, uint32_t *n_bricks_active) {
	check_collisions_paddle(ball, paddle);
	uint32_t end = 0;
	end = check_collisions_limits(ball);
	check_collisions_blocks(ball, bricks, score, n_bricks_active);
	return end;
}