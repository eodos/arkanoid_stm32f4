#include "stm32f4xx.h"
#include "touch.h"
#include "delay.h"
#include "tft_lcd.h"
#include "accelerometers.h"
#include "timed_tasks.h"
#include "game.h"

static void init_systick();
static volatile uint32_t msTicks; // counts 1 ms timeTicks

extern u8 gImage_sil[];
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

  /* Add update_game to the timed_task array */
  add_timed_task(update_game, 0.05);

  while(1)
  {
    /* Check if the timed task function has to be called */
    update();
  }
}