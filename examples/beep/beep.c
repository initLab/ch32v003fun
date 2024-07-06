#include "ch32v003fun.h"
#include <stdio.h>
#include "notes.h"

int main()
{
	SystemInit();

	funGpioInitC();
	funPinMode(PC4, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP);

	size_t index = 0;
	uint32_t last_time = SysTick->CNT;

	while (1)
	{
		uint32_t half_period_duration = notes[index][0];

		if (half_period_duration) {
			funDigitalWrite(PC4, FUN_HIGH);
			DelaySysTick(half_period_duration);
			funDigitalWrite(PC4, FUN_LOW);
			DelaySysTick(half_period_duration);
		}

		uint32_t note_duration = notes[index][1];

		if ((SysTick->CNT - last_time) > note_duration) {
			index++;

			if (index >= NUM_NOTES) {
				index = 0;
			}

			last_time = SysTick->CNT;
		}
	}
}
