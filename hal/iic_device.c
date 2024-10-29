/**
 * @file device.c
 * @brief device list and method
 *
 * @copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#include "device.h"
#include "iic_device.h"


/* Function Delcarations */
STATIC void HAL_Max96853_Close(void);
STATIC char *HAL_Max96853_getName(void);
STATIC void HAL_Max96853_Open(void);
STATIC void HAL_Max96853_Read(uint8_t *buf, uint16_t len);
STATIC int16_t HAL_Max96853_Write(iic_msg_t *pData);

/* Global Variable Delcarations */
STATIC iic_device_t gDevMax96853 =
{
	.common.name = "MAX96853",
	.common.id = IIC_MAX96853,	/* const value */
	.common.version_major = VER_MAJOR,	/* const value */
	.common.version_minor = VER_MINOR,	/* const value */
	.common.close = HAL_Max96853_Close,
	.common.getName = HAL_Max96853_getName,
	.open = HAL_Max96853_Open,
	.read = HAL_Max96853_Read,
	.write = HAL_Max96853_Write,
#if	0 
void (*read)(char *buf, int len);						/**< Read data from device without setting reg. */
void (*readRegBuffer)(int reg, char *buf, int len);		/**< Read data from device with indcated reg. */
unsigned char (*readRegByte)(int reg);					/**< Read single byte from device with indcated reg. */
void (*write)(char *buf, int len);						/**< Write data to device without setting reg. */
void (*writeRegBuffer)(int reg, char *buf, int len);	/**< Write data to device with indcated reg. */
void (*writeRegByte)(int reg, unsigned char val);		/**< Write single byte to device with indcated reg. */
#endif
};

STATIC void HAL_Max96853_Close(void)
{
	/* do nothing */
	printf("Max96853 close\r\n");
}


STATIC char *HAL_Max96853_getName(void)
{
	return gDevMax96853.common.name;
}


STATIC void HAL_Max96853_Open(void)
{
	gDevMax96853.u16SubAddr = MAX96853_ADDR;

		
	printf("HAL_Max96853_Open\n");

	printf("ID:%d\r\n", gDevMax96853.common.id);
	printf("Ver:%d.%d\r\n", gDevMax96853.common.version_major, gDevMax96853.common.version_minor);


	
}

STATIC void HAL_Max96853_Read(uint8_t *buf, uint16_t len)
{
	printf("HAL_Max96853_Read\n");
}

STATIC int16_t HAL_Max96853_Write(iic_msg_t *pData)
{
	printf("Write: SubAddr:%04x, Addr:[%02x][%02x], Value:%02x\r\n",pData->u16Addr, pData->pData[0], pData->pData[1], pData->pData[2]);
	return DEV_OK;
}

STATIC iic_device_t *gIICDevList[IIC_DEV_MAXNUM];


/* Function Delcarations */
int16_t HAL_IIC_Device_Prepare(void)
{
	gIICDevList[IIC_MAX96853] = &gDevMax96853;

	return 1;
}

iic_device_t *HAL_IIC_Device_Find(iic_device_list dev)
{
	iic_device_t *pReturn;

	if( dev < IIC_DEV_MAXNUM )
	{
		/* valid input */
		pReturn = gIICDevList[dev];
	}
	else
	{
		; /* invalid input */
	}
	return pReturn;
}
/* EOF */
