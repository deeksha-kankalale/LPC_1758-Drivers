#include "FreeRTOS.h"
#include "task.h"
#include "uart0_min.h"

void vTaskOneCode(void *p)
{
    while(1)
    {
        uart0_puts("1a2a3a4a5a6a7a8a9");
        vTaskDelay(100); // This sleeps the task for 100ms (because 1 RTOS tick = 1 millisecond)
    }
}

// Create another task and run this code in a while(1) loop
void vTaskTwoCode(void *p)
{
    while(1)
    {
        uart0_puts("1b2b3b4b5b6b7b8b9");
        vTaskDelay(100);
    }
}



// You can comment out the sample code of lpc1758_freertos project and run this code instead
int main(int argc, char const *argv[])
{
    /// This "stack" memory is enough for each task to run properly
    const uint32_t STACK_SIZE = 1024;

  
  
    xTaskCreate(vTaskTwoCode,(const char*)"TaskTwo",STACK_BYTES(2048), 0, 1, 0);
    xTaskCreate(vTaskOneCode,(const char*)"TaskOne",STACK_BYTES(2048), 0, 1, 0);


  
    vTaskStartScheduler();

    return 0;
}
