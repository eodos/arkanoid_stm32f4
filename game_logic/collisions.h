#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "structures.h"

void check_collisions_paddle(ball_t *ball, paddle_t *paddle);
uint32_t check_collisions_limits(ball_t *ball);
void check_collisions_blocks(ball_t *ball, brick_t **bricks, uint32_t *score, uint32_t *n_bricks_active);
uint32_t check_collisions(ball_t *ball, paddle_t *paddle, brick_t **bricks, uint32_t *score, uint32_t *n_bricks_active);

#endif /* COLLISIONS_H */