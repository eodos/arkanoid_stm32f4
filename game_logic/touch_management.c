#include "touch.h"
#include "draw.h"
#include "touch_management.h"

void get_position(void)
{
	Pen_Point.X0 = 0;
	Pen_Point.Y0 = 0;

	Read_Ads7846();
	Pen_Point.X0 = (int)((Pen_Point.Y-103)/7.666666667);
	Pen_Point.Y0 = (int)((Pen_Point.X-104)/5.609375);
	if(Pen_Point.X0>240) Pen_Point.X0=240;
	if(Pen_Point.Y0>320) Pen_Point.X0=320;
}

uint32_t check_start_game(void)
{
	get_position();

	if ((Pen_Point.X0 > 0) && (Pen_Point.Y0 > 120) && (Pen_Point.Y0 < 300))
    	return 1;

    return 0;
}

void check_sensibility_control_input(uint32_t *sensibility)
{
	get_position();

	if ((Pen_Point.Y0 > 0) && (Pen_Point.Y0 < 20))
	{
		if ((Pen_Point.X0 > 150) && (Pen_Point.X0 < 175))
		{
			if (*sensibility > 1)
			{
				*sensibility -= 1;
				draw_sensibility(*sensibility);
			}
		}
		else if ((Pen_Point.X0 > 190) && (Pen_Point.X0 < 215))
		{
			if (*sensibility < 3)
			{
				*sensibility += 1;
				draw_sensibility(*sensibility);
			}
		}
	}
}