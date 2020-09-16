#pragma once

#include "../../IO.cpp"
#include "../../TextPrint.cpp"

/* Macro constants that just make it a bit clearer to see what VM is being shutdown */
#define __QEMU__ 0
#define __BOCHS__ 1
#define __VBOX__ 2

struct VM_TYPE {
    int QEMU,
    int BOCHS,
    int VBOX
};

void shutdownVM(int VM);
