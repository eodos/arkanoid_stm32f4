#ifndef PADDLE_MOVEMENT_H
#define PADDLE_MOVEMENT_H

#include "structures.h"

#define avg_win 5

typedef struct
{
	float x;
	float y;
	float z;
}Accdata;

void update_paddle_position(paddle_t *paddle, uint32_t sensibility);

#endif /* PADDLE_MOVEMENT_H */