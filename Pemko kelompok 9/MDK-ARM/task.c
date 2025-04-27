#include "task.h"
#include "sensor.h"
#include "Display.h"

osThreadId readPMTaskHandle;
osThreadId readMQTaskHandle;
osThreadId displayTaskHandle;

void StartReadPMTask(void const * argument) {
    start_pm_uart_interrupt(); // inisialisasi UART
    for(;;) {
        osDelay(500);
    }
}

void StartReadMQTask(void const * argument) {
    for(;;) {
        read_mq135();
        osDelay(1000);
    }
}

void StartDisplayTask(void const * argument) {
    lcd_display_init();
    for(;;) {
        update_lcd_display();
        update_led_status();
        osDelay(1000);
    }
}

void create_tasks(void) {
    osThreadDef(readPMTask, StartReadPMTask, osPriorityLow, 0, 128);
    readPMTaskHandle = osThreadCreate(osThread(readPMTask), NULL);

    osThreadDef(readMQTask, StartReadMQTask, osPriorityLow, 0, 128);
    readMQTaskHandle = osThreadCreate(osThread(readMQTask), NULL);

    osThreadDef(displayTask, StartDisplayTask, osPriorityNormal, 0, 128);
    displayTaskHandle = osThreadCreate(osThread(displayTask), NULL);
}
