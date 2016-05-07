#include "structures.h"
#include "tft_lcd.h"

void draw_game(ball_t *ball, paddle_t *paddle, brick_t **bricks)
{
	/* Erase screen */
	LCD_Clear(BLACK);
	
	/* Draw ball */
	LCD_DrawFullCircle(ball->x, ball->y, ball->radius);

	/* Draw paddle */
	LCD_DrawRect(paddle->x - paddle->length, paddle->y - paddle->length, paddle->length * 2, paddle->height * 2);

	/* Draw bricks */
	uint32_t i;
	for(i=0; i<N_BRICKS; i++)
		if(bricks[i]->active)
			LCD_DrawRect(bricks[i]->x - bricks[i]->length, bricks[i]->y - bricks[i]->length, bricks[i]->length * 2, bricks[i]->height * 2);
}