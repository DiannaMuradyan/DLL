#ifndef SHELLCODE_DLL_H
#define SHELLCODE_DLL_H

#ifdef _WIN32
    #ifdef SHELLCODE_DLL_EXPORTS
        #define DLL_EXPORT __declspec(dllexport)  
    #else
        #define DLL_EXPORT __declspec(dllimport)  
    #endif
#else
    #define DLL_EXPORT
#endif


DLL_EXPORT void function();


#endif // SHELLCODE_DLL_H
