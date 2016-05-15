#include "structures.h"
#include "tft_lcd.h"
#include <stdio.h>

void draw_ball_paddle(ball_t *ball, paddle_t *paddle, uint16_t color)
{
	LCD_SetTextColor(color);

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

void draw_score(uint32_t score)
{
	LCD_SetTextColor(BLACK);
	LCD_DrawFullRect(60, 10, 30, 15);
	LCD_SetTextColor(GREEN);
	char buffer[5];
	sprintf(buffer, "%lu", score);
	LCD_StringLine(60, 10, (uint8_t *) buffer);
}

void draw_win_screen(void)
{
	LCD_SetTextColor(GREEN);
	LCD_StringLine(100, 150, (uint8_t *) "WIN!");
}

void draw_sensibility(uint32_t sensibility)
{
	LCD_SetTextColor(BLACK);
	LCD_DrawFullRect(180, 10, 17, 15);
	LCD_SetTextColor(GREEN);
	char buffer[5];
	sprintf(buffer, "%lu", sensibility);
	LCD_StringLine(180, 10, (uint8_t *) buffer);
}

void draw_all_game(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t score, uint32_t sensibility)
{
	LCD_SetTextColor(GREEN);

	/* Draw score  */
	LCD_StringLine(10, 10, (uint8_t *) "SCORE");
	draw_score(score);
	LCD_DrawLine(0, UPPER_LIMIT, RIGHT_LIMIT, LCD_DIR_HORIZONTAL);

	/* Draw sensibility controls */
	LCD_StringLine(160, 10, (uint8_t *) "-");
	draw_sensibility(sensibility);
	LCD_StringLine(200, 10, (uint8_t *) "+");
	
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