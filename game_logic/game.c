#include "structures.h"
#include "collisions.h"
#include "init.h"
#include "draw.h"

void update_game(void)
{
	static paddle_t *paddle;
  	static ball_t *ball;
  	static brick_t *bricks[N_BRICKS];

	static uint32_t initialize = 1;
	if (initialize)
	{  
  		init_game(&ball, &paddle, bricks);
  		initialize = 0;
	}

	else
	{
		/* Testing */
		ball->x += ball->vx;
		ball->y += ball->vy;
	}

	draw_game(ball, paddle, bricks);
}