#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>
#include "config.h"

typedef enum {
	IIC_MAX96853,
	IIC_EEPROM,
	IIC_DEV_MAXNUM
} iic_device_list;

/* for application use, don't use iic_device_list directly */
#define SERIALIZER	IIC_MAX96853



typedef struct hw_device_t {
	/* device information */
	char *name;
	const uint16_t id;
	const uint16_t version_major;
	const uint16_t version_minor;
	
	/* device common methods */
	void (*close)();		/**< Close device */
	char *(*getName)();		/**< Get device name */
} hw_device_t;



#endif
/* EOF */
