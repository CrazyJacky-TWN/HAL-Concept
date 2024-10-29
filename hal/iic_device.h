#ifndef IIC_DEVICE_H
#define IIC_DEVICE_H

#include "device.h"

#define DEV_OK              1   /**< device work correct. */
#define DEV_NOK             -1  /**< device work non okay, and need some error handle. */
#define DEV_NON_VALID_PARA  -2  /**< the input paramenters are in-correct.*/
#define DEV_WRITE_FAIL      -3  /**< i2c writing fail */


#define IIC_MAX_MSG_LEN		10U
#define VER_MAJOR	0
#define	VER_MINOR	1
#define MAX96853_ADDR   0x40U

#if (MCHP_PLATFORM)
typedef enum
{
	SERCOM_0,
	SERCOM_1,
	SERCOM_2,
	SERCOM_3,
	SERCOM_4,
	SERCOM_5,
	SERCOM_MAX,
} sercom_t;
#endif

typedef struct iic_msg_t
{
	uint8_t *pData;
	uint16_t u16Addr;
	uint32_t u32Length;
} iic_msg_t;

typedef struct iic_device_t
{
	hw_device_t common;
	uint16_t u16SubAddr;

#if (MCHP_PLATFORM)
	uint8_t	u8IICBus;
#endif
	/* device methods */
	void (*open)(void);
	void (*read)(uint8_t *buf, uint16_t len);						/**< Read data from device without setting reg. */
	void (*readRegBuffer)(uint16_t reg, uint8_t *buf, uint16_t len);		/**< Read data from device with indcated reg. */
	uint8_t (*readRegByte)(uint16_t reg);					/**< Read single byte from device with indcated reg. */
	int16_t (*write)(iic_msg_t *);						/**< Write data to device without setting reg. */
	void (*writeRegBuffer)(uint16_t reg, uint8_t *buf, uint16_t len);	/**< Write data to device with indcated reg. */
	void (*writeRegByte)(uint16_t reg, uint8_t val);		/**< Write single byte to device with indcated reg. */
} iic_device_t;


/* Function Delcarations */
extern int16_t HAL_IIC_Device_Prepare(void);
extern iic_device_t *HAL_IIC_Device_Find(iic_device_list);


#endif
/* EOF */
