#ifndef STRUCTURES_H
#define STRUCTURES_H

#define LEFT_LIMIT 		0
#define RIGHT_LIMIT		200
#define LOWER_LIMIT	0
#define UPPER_LIMIT		400

#define BRICK_LENGTH	5
#define BRICK_HEIGHT	3

typedef struct {
	bool active = 1;
	uint32_t x;
	uint32_t y;
} brick_t;

typedef struct {
	uint32_t x;
	uint32_t y;
	uint32_t height = 3; // Distance from the center of mass to the lower / upper limit of the brick
	uint32_t length = 5; // Distance from the center of mass to the left / right limit of the brick
} paddle_t;

typedef struct {
	uint32_t x;
	uint32_t y;
	uint32_t vx;
	uint32_t vy;
	uint32_t radius = 3;
} ball_t;

#endif /* STRUCTURES_H */