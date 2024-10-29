#include "app/app_serializer.h"
// #include "hal/iic_device.h"




int main() 
{
    HAL_IIC_Device_Prepare();

    Serializer_Init();


    return 0;
}
