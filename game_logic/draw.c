#include "structures.h"
#include "tft_lcd.h"

void draw_game(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t score)
{
	LCD_SetTextColor(GREEN);

	/* Draw score  */
	LCD_DrawLine(0, UPPER_LIMIT, RIGHT_LIMIT, LCD_DIR_HORIZONTAL);
	LCD_StringLine(10, 305, (uint8_t *) "SCORE");
	//LCD_StringLine(50, 305, score);
	
	/* Draw ball */
	LCD_DrawFullCircle(ball->x, ball->y, ball->radius);

	/* Draw paddle */
	LCD_DrawRect(paddle->x - paddle->length, paddle->y - paddle->height, paddle->length * 2, paddle->height * 2);

	/* Draw bricks */
	uint32_t i;
	for(i=0; i<N_BRICKS; i++)
		if(bricks[i]->active)
			LCD_DrawRect(bricks[i]->x - bricks[i]->length, bricks[i]->y - bricks[i]->height, bricks[i]->length * 2, bricks[i]->height * 2);
}

void erase_ball_paddle(ball_t *ball, paddle_t *paddle)
{
	LCD_SetTextColor(BLACK);

	/* Erase ball */
	LCD_DrawFullCircle(ball->x, ball->y, ball->radius);

	/* Erase paddle */
	LCD_DrawRect(paddle->x - paddle->length, paddle->y - paddle->height, paddle->length * 2, paddle->height * 2);
}

void erase_brick(brick_t *brick)
{
	LCD_SetTextColor(BLACK);

	/* Erase brick */
	LCD_DrawRect(brick->x - brick->length, brick->y - brick->height, brick->length * 2, brick->height * 2);

}