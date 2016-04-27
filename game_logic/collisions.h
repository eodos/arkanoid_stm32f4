#ifndef COLLISIONS_H
#define COLLISIONS_H

void check_collisions(ball_t *ball, paddle_t paddle, brick_t *bricks, uint32_t n_bricks);
void check_collisions_paddle(ball_t *ball, paddle_t paddle);
int32_t check_collisions_limits(ball_t *ball);
void check_collisions_blocks(ball_t *ball, brick_t *bricks, uint32_t n_bricks);

#endif /* COLLISIONS_H */