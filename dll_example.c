#include <windows.h>
#include <stdio.h>

typedef void (*bytecode_func)(); 

unsigned char bytecode[] __attribute__((section(".text"))) = {
    0x55, 0x48, 0x89, 0xe5, 0x48, 0x81, 0xec, 0xa0, 0x00, 0x00, 0x00, 0xb8,
    0x60, 0x00, 0x00, 0x00, 0x65, 0x48, 0x8b, 0x00, 0x48, 0x89, 0x45, 0xe8,
    0x48, 0x8b, 0x45, 0xe8, 0x48, 0x8b, 0x40, 0x18, 0x48, 0x8b, 0x40, 0x20,
    0x48, 0x8b, 0x00, 0x48, 0x8b, 0x00, 0x48, 0x8b, 0x40, 0x20, 0x48, 0x89,
    0x45, 0xe0, 0x48, 0x8b, 0x45, 0xe0, 0x48, 0x89, 0x45, 0xd8, 0x48, 0x8b,
    0x45, 0xd8, 0x8b, 0x40, 0x3c, 0x48, 0x63, 0xd0, 0x48, 0x8b, 0x45, 0xe0,
    0x48, 0x01, 0xd0, 0x48, 0x89, 0x45, 0xd0, 0x48, 0x8b, 0x45, 0xd0, 0x8b,
    0x80, 0x88, 0x00, 0x00, 0x00, 0x89, 0xc2, 0x48, 0x8b, 0x45, 0xe0, 0x48,
    0x01, 0xd0, 0x48, 0x89, 0x45, 0xc8, 0x48, 0x8b, 0x45, 0xc8, 0x8b, 0x40,
    0x1c, 0x89, 0xc2, 0x48, 0x8b, 0x45, 0xe0, 0x48, 0x01, 0xd0, 0x48, 0x89,
    0x45, 0xc0, 0x48, 0x8b, 0x45, 0xc8, 0x8b, 0x40, 0x20, 0x89, 0xc2, 0x48,
    0x8b, 0x45, 0xe0, 0x48, 0x01, 0xd0, 0x48, 0x89, 0x45, 0xb8, 0x48, 0x8b,
    0x45, 0xc8, 0x8b, 0x40, 0x24, 0x89, 0xc2, 0x48, 0x8b, 0x45, 0xe0, 0x48,
    0x01, 0xd0, 0x48, 0x89, 0x45, 0xb0, 0x48, 0xc7, 0x45, 0xf8, 0x00, 0x00,
    0x00, 0x00, 0xc7, 0x45, 0xf4, 0x00, 0x00, 0x00, 0x00, 0xe9, 0x8a, 0x00,
    0x00, 0x00, 0x8b, 0x45, 0xf4, 0x48, 0x8d, 0x14, 0x85, 0x00, 0x00, 0x00,
    0x00, 0x48, 0x8b, 0x45, 0xb8, 0x48, 0x01, 0xd0, 0x8b, 0x00, 0x89, 0xc2,
    0x48, 0x8b, 0x45, 0xe0, 0x48, 0x01, 0xd0, 0x48, 0x89, 0x45, 0xa8, 0x48,
    0x8b, 0x45, 0xa8, 0x0f, 0xb6, 0x00, 0x3c, 0x57, 0x75, 0x5a, 0x48, 0x8b,
    0x45, 0xa8, 0x48, 0x83, 0xc0, 0x05, 0x0f, 0xb6, 0x00, 0x3c, 0x43, 0x75,
    0x4b, 0x48, 0x8b, 0x45, 0xa8, 0x48, 0x83, 0xc0, 0x0c, 0x0f, 0xb6, 0x00,
    0x3c, 0x41, 0x75, 0x3c, 0x8b, 0x45, 0xf4, 0x48, 0x8d, 0x14, 0x00, 0x48,
    0x8b, 0x45, 0xb0, 0x48, 0x01, 0xd0, 0x0f, 0xb7, 0x00, 0x0f, 0xb7, 0xc0,
    0x89, 0x45, 0xa4, 0x8b, 0x45, 0xa4, 0x48, 0x8d, 0x14, 0x85, 0x00, 0x00,
    0x00, 0x00, 0x48, 0x8b, 0x45, 0xc0, 0x48, 0x01, 0xd0, 0x8b, 0x00, 0x89,
    0x45, 0xa0, 0x8b, 0x55, 0xa0, 0x48, 0x8b, 0x45, 0xe0, 0x48, 0x01, 0xd0,
    0x48, 0x89, 0x45, 0xf8, 0x83, 0x45, 0xf4, 0x01, 0x48, 0x8b, 0x45, 0xc8,
    0x8b, 0x40, 0x18, 0x3b, 0x45, 0xf4, 0x0f, 0x87, 0x66, 0xff, 0xff, 0xff,
    0x48, 0x83, 0x7d, 0xf8, 0x00, 0x74, 0x63, 0xc6, 0x45, 0x92, 0x48, 0xc6,
    0x45, 0x93, 0x65, 0xc6, 0x45, 0x94, 0x6c, 0xc6, 0x45, 0x95, 0x6c, 0xc6,
    0x45, 0x96, 0x6f, 0xc6, 0x45, 0x97, 0x20, 0xc6, 0x45, 0x98, 0x57, 0xc6,
    0x45, 0x99, 0x6f, 0xc6, 0x45, 0x9a, 0x72, 0xc6, 0x45, 0x9b, 0x6c, 0xc6,
    0x45, 0x9c, 0x64, 0xc6, 0x45, 0x9d, 0x21, 0xc6, 0x45, 0x9e, 0x60, 0x48
};

void function() {
    
}


#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        LPVOID exec_mem = VirtualAlloc(NULL, sizeof(bytecode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (exec_mem) {
            memcpy(exec_mem, bytecode, sizeof(bytecode));
            bytecode_func func = (bytecode_func)exec_mem;
            func();  
            VirtualFree(exec_mem, 0, MEM_RELEASE);  
        }
    }
    return TRUE; 
}
