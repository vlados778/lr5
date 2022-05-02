#include "mbed.h"

Thread thread;

DigitalOut oled(D7);
InterruptIn ibutton1(BUTTON1);

int i=0;
static auto sleep_time = 100ms;

Ticker toggle_led_ticker;

void pressed()
{
    if (i<2)
    i++;
    else
        i=0;
}

void masseg()
{
while(true)
{
if (i==0)
{
    printf("mode 1 \n");
    ThisThread::sleep_for(500ms);
}
if (i==1)
{
    printf("mode 2 \n");
    ThisThread::sleep_for(500ms);
}
if (i==2)
{
    printf("mode 3 \n");
    ThisThread::sleep_for(500ms);
}
}
}

int main()
{
    ibutton1.rise(&pressed);
    thread.start(masseg);

while(true)
{
    if (i==0)
    {
        oled=!oled;
        ThisThread::sleep_for(100ms);
    }
    if (i==1)
    {   
        oled=!oled;
        ThisThread::sleep_for(500ms);
    }
    if (i==2)
    {
        oled=!oled;
        ThisThread::sleep_for(1000ms);
    }
}
}