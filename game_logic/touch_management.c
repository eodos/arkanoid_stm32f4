#include "touch.h"

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

#if 0
    Convert_Pos();

    if ((Pen_Point.X0>180) && (Pen_Point.X0<210) && ( Pen_Point.Y0>304) && ( Pen_Point.Y0<320))
    {
      LCD_Clear(LCD_COLOR_MAGENTA);
      LCD_SetBackColor(GREEN);
      LCD_SetTextColor(CYAN);
      LCD_StringLine(215,300,"SIL");
      LCD_StringLine(172,300,"YENI");
      goto DON ;
    }

    if ((Pen_Point.X0>220) && (Pen_Point.X0<239) && (Pen_Point.Y0>304)&&(Pen_Point.Y0<320))
    {

      LCD_Clear(RED);
      LCD_BackLight(100);

      LCD_SetBackColor(GREEN);
      LCD_SetTextColor(CYAN);
      LCD_StringLine(215,300,"SIL");
      LCD_StringLine(172,300,"YENI");

      goto DON;
    }

    if ((Pen_Point.X0>0) && (Pen_Point.Y0>0))
    {
      Pixel(Pen_Point.X0,Pen_Point.Y0,YELLOW);
      Pixel(Pen_Point.X0,Pen_Point.Y0+1,YELLOW);
      Pixel(Pen_Point.X0+1,Pen_Point.Y0,YELLOW);
      Pixel(Pen_Point.X0+1,Pen_Point.Y0+1,YELLOW);
    }
#endif
