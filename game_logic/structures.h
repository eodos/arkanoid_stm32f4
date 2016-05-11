#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "stm32f4xx.h"

#define LEFT_LIMIT 		0
#define RIGHT_LIMIT		240
#define LOWER_LIMIT		0
#define UPPER_LIMIT		320

#define N_BRICKS		18

#define BRICK_LENGTH	15
#define	BRICK_HEIGHT	7

#define PADDLE_LENGTH	30
#define PADDLE_HEIGHT	5

typedef struct {
	uint8_t active;
	uint32_t x;
	uint32_t y;
	uint32_t length;
	uint32_t height;
} brick_t;

typedef struct {
	uint32_t x;
	uint32_t y;
	uint32_t length; // Distance from the center of mass to the left / right limit of the brick
	uint32_t height; // Distance from the center of mass to the lower / upper limit of the brick
} paddle_t;

typedef struct {
	uint32_t x;
	uint32_t y;
	int32_t vx;
	int32_t vy;
	uint32_t radius;
} ball_t;

#endif /* STRUCTURES_H */