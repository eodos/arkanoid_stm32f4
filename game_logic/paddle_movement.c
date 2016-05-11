#include "paddle_movement.h"

#include "stm32f4xx.h"
#include "accelerometers.h"
#include <math.h>

static Accdata buffer[avg_win];
static Accdata Avg;
static int i = 0;

Accdata calc_average(Accdata *circular_buffer)
{
    Accdata temp;
    temp.x = 0;
    temp.y = 0;
    temp.z = 0;

    for (int j = 0; j < 5; j++)
    {
        temp.x += circular_buffer[j].x;
        temp.y += circular_buffer[j].y;
        temp.z += circular_buffer[j].z;
    }

    temp.x = temp.x/5;
    temp.y = temp.y/5;
    temp.z = temp.z/5;
    return (temp);
}

void calc_pitch_roll(float acc_x, float acc_y, float acc_z, float *pitch, float *roll)
{
    *roll = (180.0/M_PI)*atan2(acc_y, acc_z);
    *pitch = (180.0/M_PI)*atan2(-acc_x, sqrt(acc_y*acc_y+acc_z*acc_z));
}

void crop(paddle_t *paddle)
{
    /* Check if the position of the paddle is in the limits */
    if (paddle->x > RIGHT_LIMIT - PADDLE_LENGTH - 1) paddle->x = RIGHT_LIMIT - PADDLE_LENGTH - 1;
    if (paddle->x < LEFT_LIMIT + PADDLE_LENGTH + 1)  paddle->x = LEFT_LIMIT + PADDLE_LENGTH + 1;
}
void update_paddle_position(paddle_t *paddle)
{
    float a[3];
    float pitch, roll;

    /* Read accelerometers and store in the buffer */
    read_accelerometers(a);
    buffer[i].x = a[0]; buffer[i].y = a[1]; buffer[i].z = a[2]; 
    i++;
    if (i > 4) i = 0;

    /* Compute the average value of the buffer */
    Avg = calc_average(buffer);

    /* Compute pitch and roll */
    calc_pitch_roll(Avg.x, Avg.y, Avg.z, &pitch, &roll);

    /* Compute the paddle position increment */
    float increment = (pitch * pitch * pitch / 7000);

    /* Update paddle position */
    paddle->x -= increment;

    /* Make sure the paddle position is in the limits */
    crop(paddle);
}
