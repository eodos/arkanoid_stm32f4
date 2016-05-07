#ifndef INIT_H
#define INIT_H

void reset_game(ball_t *ball, paddle_t *paddle, brick_t **bricks);
void init_game(ball_t **ball, paddle_t **paddle, brick_t **bricks);
void wait(uint32_t sec);

#endif /* INIT_H */