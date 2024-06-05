#include "head.h"
#define Item 30

void itemtime(time_t* t) {
	*t += Item;
}

void pause_item(time_t* t) {
	if (*t > 0)
	*t += time(0) - Stop_time;
}