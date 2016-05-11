#ifndef DRAW_H
#define DRAW_H

void draw_game(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t score);
void erase_ball_paddle(ball_t *ball, paddle_t *paddle);
void erase_brick(brick_t *brick);

#endif /* DRAW_H */