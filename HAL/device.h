#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

typedef enum {
	DEV_MAX96853,
	DEV_EEPROM,
	DEV_MAXNUM
} hw_device_list;


typedef struct hw_device_t {
	/* device information */
	char *name;
	const uint16_t id;
	const uint16_t version_major;
	const uint16_t version_minor;
	
	/* device methods */
	void (*close)();		/**< Close device */
	char *(*getName)();		/**< Get device name */
	void (*read)(char *buf, int len);						/**< Read data from device without setting reg. */
	void (*readRegBuffer)(int reg, char *buf, int len);		/**< Read data from device with indcated reg. */
	unsigned char (*readRegByte)(int reg);					/**< Read single byte from device with indcated reg. */
	void (*write)(char *buf, int len);						/**< Write data to device without setting reg. */
	void (*writeRegBuffer)(int reg, char *buf, int len);	/**< Write data to device with indcated reg. */
	void (*writeRegByte)(int reg, unsigned char val);		/**< Write single byte to device with indcated reg. */
} hw_device_t;

#endif
/* EOF */
