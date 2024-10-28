#ifndef _HAL_MAX96853_H_
#define _HAL_MAX96853_H_

#include "Config.h"
#include "device.h"

#define VER_MAJOR	0
#define	VER_MINOR	1

typedef struct hw_max96853_t
{
	hw_device_t common;
	void (*open)();
} hw_max96853_t;



extern hw_max96853_t * getMax96853(void);


#endif
/* EOF */
