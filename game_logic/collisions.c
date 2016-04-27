
void check_collisions(ball_t *ball, paddle_t paddle, brick_t *bricks, uint32_t n_bricks) {

}

void check_collisions_paddle(ball_t *ball, paddle_t paddle) {
	if (ball->y + ball->radius < paddle->y + paddle->heigth)
		ball->vy = -ball->vx;
}

/* This function detects collisions with the game limits. If the ball hits the lower limit,
 * it will return -1. In any other case it will return 0. */
int32_t check_collisions_limits(ball_t *ball) {
	if(ball.x - ball.radius < LEFT_LIMIT)
		/* Collision with left border, change x velocity */
		ball.vx = -ball.vx;
	else if(ball.x + ball.radius > RIGHT_LIMIT)
		/* Collision with right border, change x velocity */
		ball.vx = -ball.vx;
	else if(ball.y + ball.radius > UPPER_LIMIT)
		/* Collision with upper border, change y velocity */
		ball.vy = -ball.vy;
	else if(ball.y - ball.radius < LOWER_LIMIT)
		/* Collision with lower limit, return -1 */
		return -1;
	return 0;
}

void check_collisions_blocks(ball_t *ball, brick_t *bricks, uint32_t n_bricks) {
	uint32_t i;
	for(i=0; i<n_bricks; i++)
	{
		if(bricks[i].active)
		{
			/* Left side collision */
			if((ball.x + ball.radius > bricks[i].x - BRICK_LENGTH) && (ball.y + radius > ) && ()) // TODO
			{
				bricks[i].active = 0;
				ball.vx = -ball.vx;
			}
			else if()
			{

			}
			else if()
			{

			}

		}
	}
}