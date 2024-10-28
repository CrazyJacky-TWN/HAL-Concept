/**
 * @file hal_max96853.c
 * @brief MAX96853 HAL driver.
 *
 * @copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */
#include "hal_max96853.h"

/* Function Delcarations */
STATIC void HAL_Max96853_Open(void);
STATIC char *HAL_Max96853_getName(void);

/* Global Variable Delcarations */
STATIC hw_max96853_t gDevMax96853 =
{
	.common.name = "MAX96853",
	.common.id = DEV_MAX96853,	/* const value */
	.common.version_major = VER_MAJOR,	/* const value */
	.common.version_minor = VER_MINOR,	/* const value */
	.common.getName = HAL_Max96853_getName,
	.open = HAL_Max96853_Open,
};

STATIC char *HAL_Max96853_getName(void)
{
	return gDevMax96853.common.name;
}


STATIC void HAL_Max96853_Open(void)
{
	printf("HAL_Max96853_Open\n");

	printf("ID:%d\r\n", gDevMax96853.common.id);
	printf("Ver:%d.%d\r\n", gDevMax96853.common.version_major, gDevMax96853.common.version_minor);
}


/* Global Functions */
hw_max96853_t * getMax96853(void)
{
	return &gDevMax96853;
}

