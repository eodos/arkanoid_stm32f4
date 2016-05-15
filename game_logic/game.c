#include "game.h"
#include "structures.h"
#include "collisions.h"
#include "init.h"
#include "draw.h"
#include "tft_lcd.h"
#include "paddle_movement.h"
#include "touch_management.h"

void update_game(void)
{
	static paddle_t *paddle;
  	static ball_t *ball;
  	static brick_t *bricks[N_BRICKS];

  	static uint32_t game_over = 0;
	static uint32_t initialize = 1;
	static uint32_t reset = 0;
	static uint32_t waiting_to_start = 0;

	static uint32_t score = 0;
	static uint32_t sensibility = 1;

	static uint32_t n_bricks_active = N_BRICKS;

	/* Check sensibility control input */
	check_sensibility_control_input(&sensibility);

	if (initialize)
	{  
		/* Allocate the structs, and jump to reset */
  		init_game(&ball, &paddle, bricks);
  		reset = 1;
  		initialize = 0;
	}

	else if (reset)
	{
		/* Clear the screen, initialize the values of the struct and draw the game */
		LCD_Clear(BLACK);
		reset_game(ball, paddle, bricks);
		score = 0;
		n_bricks_active = N_BRICKS;
		reset = 0;
		waiting_to_start = 1;
		draw_all_game(ball, paddle, bricks, score, sensibility);
	}

	else if (waiting_to_start)
	{
		if (check_start_game())	waiting_to_start = 0;
	}

	else
	{
		/* Erase ball and paddle */
		draw_ball_paddle(ball, paddle, BLACK);

		/* Update position of the ball */
		ball->x += ball->vx;
		ball->y += ball->vy;

		/* Update position of the paddle */
		update_paddle_position(paddle, sensibility);

		/* Check collisions */
		game_over = check_collisions(ball, paddle, bricks, &score, &n_bricks_active);

		if (game_over)
		{
			wait(1);
			reset = 1;
			game_over = 0;
		}

		/* Detect if all the blocks have been destroyed */
		if (n_bricks_active == 0)
		{
			draw_win_screen();
			wait(1);
			reset = 1;
		}

		/* Draw the game */
		draw_ball_paddle(ball, paddle, GREEN);
	}
}