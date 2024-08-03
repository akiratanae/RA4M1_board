#include "hal_data.h"

#include "control_board.h"

volatile uint8_t count_10ms;
volatile uint8_t count_sec;
volatile uint8_t timer_flag;

#define INT_PRIORITY_AGT0_INT	8

void agt0_int_isr(void)
{
    R_BSP_IrqStatusClear(AGT0_INT_IRQn);

	count_10ms++;
	if (count_10ms >= 10) {
		count_10ms = 0;
		timer_flag = 1;
		/*LED3 = ~LED3;*/
	}
}

void agt0_init(void)
{
	R_BSP_MODULE_START(FSP_IP_AGT, 0);
	R_BSP_IrqDisable(VECTOR_NUMBER_AGT0_INT);
	R_BSP_IrqStatusClear(VECTOR_NUMBER_AGT0_INT);
	R_BSP_IrqCfg(VECTOR_NUMBER_AGT0_INT, INT_PRIORITY_AGT0_INT, (void *)0);
	R_AGT0->AGT16.AGT = 0x5dbf;
	R_AGT0->AGT16.CTRL.AGTMR1 = 0x00;
	R_BSP_IrqEnable(VECTOR_NUMBER_AGT0_INT);
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
	agt0_init();

	timer_flag = 0;
	count_10ms = 0;
	count_sec = 0;

	/* start timer */
	R_AGT0->AGT16.CTRL.AGTCR_b.TSTART = 1;

	for (;;) {
		if (timer_flag) {
			timer_flag = 0;
			process_10ms();
			/*LED2 = ~LED2;*/
		}
	}

	return 0;
}
