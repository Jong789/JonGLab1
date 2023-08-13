/* The printf function does not work within the void button_interrupt function 
 The printf function works when you put it into the main part of the program.
 This is because printf function is non re-entrant and its behaviour is modified when called from the 
 Interrupt Service Routine.
 A flag variable is created to signify whether the button is pressed or not pressed
 The printf in the while loop will keep printing "Button pressed" unless the flag is reset to zero
 after the printf statement */

#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn button(PC_13); 

char flag0 = 0;  // create a flag variable

void fall_interrupt(){
    flag0 = 1;  // this means that when interrupt is triggered the value of flag becomes 1
}

int main()
{
    button.fall(&fall_interrupt);
  
    while (true) {
        if(flag0 == 1)
                printf("Button is pressed \r\n");
                flag0=0; //This resets the flag
        ThisThread::sleep_for(50);
        }
    }


