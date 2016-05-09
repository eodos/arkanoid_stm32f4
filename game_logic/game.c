#include "structures.h"
#include "collisions.h"
#include "init.h"
#include "draw.h"
#include "tft_lcd.h"

void update_game(void)
{
	static paddle_t *paddle;
  	static ball_t *ball;
  	static brick_t *bricks[N_BRICKS];

  	static uint32_t game_over = 0;
	static uint32_t initialize = 1;
	static uint32_t reset = 0;

	if (initialize)
	{  
  		init_game(&ball, &paddle, bricks);
  		reset = 1;
  		initialize = 0;
	}

	if (reset)
	{
		LCD_Clear(BLACK);
		reset_game(ball, paddle, bricks);
		draw_game(ball, paddle, bricks);
		wait(3);
		reset = 0;
	}

	else
	{
		/* Erase ball and paddle */
		erase_ball_paddle(ball, paddle);

		/* Update position of the ball */
		ball->x += ball->vx;
		ball->y += ball->vy;

		/* Check collisions */
		game_over = check_collisions(ball, paddle, bricks, N_BRICKS);

		if (game_over)
		{
			wait(1);
			reset = 1;
			game_over = 0;
		}

		/* Detect if all the blocks have been destroyed */
		/* TODO */

		draw_game(ball, paddle, bricks);
	}
}