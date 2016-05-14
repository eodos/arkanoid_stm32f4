#include "stm32f4xx.h"

#include "delay.h"
#include "tft_lcd.h"
#include "touch.h"
#include "accelerometers.h"
#include "timed_tasks.h"
#include "game.h"

static void init_systick();
static void delay_ms(uint32_t n);
static volatile uint32_t msTicks; // counts 1 ms timeTicks

extern u8 gImage_sil[];
//void tft_example(void);
extern unsigned int xxx,yyy;
extern unsigned char flag;

// SysTick Handler (Interrupt Service Routine for the System Tick interrupt)
void SysTick_Handler(void){
  msTicks++;
}

float get_time()
{
  return 0.001*msTicks;
}

// initialize the system tick
void init_systick(void)
{
  SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
    while (1);                                  /* Capture error              */
  }
}

// pause for a specified number (n) of milliseconds
void delay_ms(uint32_t n)
{
  uint32_t msTicks2 = msTicks + n;
  while(msTicks < msTicks2) ;
}

void initialise_monitor_handles();

int main(void)
{
  // initialize
  SystemInit();
  initialise_monitor_handles();
  init_systick();

  /* Initialize the accelerometers */
  init_accelerometers();

  /* Initialize the LCD and Touch modules */
  Delay(0x3FFFFF);
  LCD_Init();
  Delay(0x3FFFFF);
  touch_init();

  /* Clear the LCD, set text color to green and backlight to 100 */
  LCD_Clear(BLACK);
  LCD_SetTextColor(GREEN);
  LCD_SetBackColor(LCD_COLOR_BLACK);
  LCD_BackLight(100);


  /*Read_Ads7846();
  Pen_Point.X0=(int)((Pen_Point.Y-103)/7.7);
  Pen_Point.Y0=(int)((Pen_Point.X-104)/5.56);
  if(Pen_Point.X0>240)
  {
    Pen_Point.X0=240;
  }
  if(Pen_Point.Y0>320)
  {
    Pen_Point.X0=320;
  }*/

  /* Add update_game to the timed_task array */
  add_timed_task(update_game, 0.05);

  while(1)
  {
    /* Check if the timed task function has to be called */
    update();


    /*DON:

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
    }*/
  }
}


/*void tft_example(void)
{
  LCD_StringLine(100,30, "David");
  LCD_StringLine(85,45, "Paul Pena");
  LCD_StringLine(30,80, "NEW YORK UNIVERSITY");
  LCD_StringLine(45,170, "** 3.2' TFT LCD **");
  LCD_StringLine(45,190, "SSD1289 VE XPT2046 ");
}*/

