#include "hal_data.h"

#include "control_board.h"

volatile uint8_t count_10ms;
volatile uint8_t count_sec;
volatile uint8_t timer_flag;

void SysTick_Handler(void)
{
	count_10ms++;
	if (count_10ms >= 10) {
		count_10ms = 0;
		timer_flag = 1;
		/*LED3 = ~LED3;*/
	}

}

void process_10ms(void)
{
	count_sec++;
	if (count_sec >= 100) {
		count_sec = 0;
		LED1 = ~LED1;
	}
}

int main(void)
{
	timer_flag = 0;
	count_10ms = 0;
	count_sec = 0;

	SysTick_Config(48000);	/* SystemCoreClock 48MHz/1000*/
	
	for (;;) {
		if (timer_flag) {
			timer_flag = 0;
			process_10ms();
			/*LED2 = ~LED2;*/
		}
	}

	return 0;
}
