#include "shutdown.h"


static void vm_shutdown_func(struct VM_TYPE vm, int type)
{
    /* Shutdown VM by writing a word to given ports. */
    if (type == vm.QEMU)
        outw(0xB004, 0x2000);
    
    else if (type == vm.BOCHS)
        outw(0x604, 0x2000);
    
    else if (type == vm.VBOX)
        outw(0x4004, 0x3400);
}

void shutdownVM(int VM) {
    /* Init struct and set vm values */
    struct VM_TYPE vm_;
    vm_.QEMU = __QEMU__;
    vm_.BOCHS = __BOCHS__;
    vm_.VBOX = __VBOX__;
    
    /* Parse VM type */
    switch(VM)
    {
        case vm_.QEMU:
            PrintString("Shutting down QEMU.");
            vm_shutdown_func(vm_, __QEMU__);
            break;
        
        case vm_.BOCHS:
            PrintString("Shutting down BOCHS.");
            vm_shutdown_func(vm_, __BOCHS__);
            break;
        
        case vm_.VBOX:
            PrintString("Shutting down Virtual Box.");
            vm_shutdown_func(vm_, __VBOX__);
            break;
            
        default:
            PrintString("Unrecognized VM - Cannot shutdown OS");
            #ifdef DEBUG //Optional - I think it adds a little flair
            PrintString(IntegerToString(VM)); //strcat("Param passed was: ", paramPassed)
            #endif
            break;
    }
    
    
}
