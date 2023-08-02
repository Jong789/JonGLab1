// The program failed to run and the green LED flashed SOS 
//

/*  ++ MbedOS Error Info ++
Error Status: 0x80010133 Code: 307 Module: 1
Error Message: Mutex: 0x200015FC, Not allowed in ISR context
Location: 0x8009351
Error Value: 0x200015FC
Current Thread: main Id: 0x20001DB4 Entry: 0x8006923 StackSize: 0x1000 StackMem: 0x20000580 SP: 0x2009FF54 
For more info, visit: https://mbed.com/s/error?error=0x80010133&tgt=B_L4S5I_IOT01A
-- MbedOS Error Info --
*/
// 0x200015FC is SRAM1 memory location of where error is occuring due to printf statement



#include "mbed.h"
// JonGLab1

// main() runs in its own thread in the OS
InterruptIn button(PC_13);

void button_interrupt(){
    printf("Button pressed \r\n");
}

int main()
{
    button.fall(&button_interrupt);
    while (true) {

    }
}

