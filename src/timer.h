#ifndef TIMER_H
#define TIMER_H

#include <util/delay.h>

static inline void delay_ms(unsigned int ms) {
	while (ms--) {
		_delay_ms(1);
	}
}

#endif
