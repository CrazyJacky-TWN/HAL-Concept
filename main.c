#include "HAL/hal_max96853.h"




int main() 
{
    hw_max96853_t *pMax96853 = getMax96853();
    

    pMax96853->open();
    printf("%s\r\n", pMax96853->common.getName());

    return 0;
}
