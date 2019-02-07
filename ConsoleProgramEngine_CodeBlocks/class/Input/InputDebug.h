#ifndef INPUTDEBUG_H
#define INPUTDEBUG_H
#define I_DBG 1
#if I_DBG
    #include <iostream>
    #define _PF_ __PRETTY_FUNCTION__
    #define $I_MSG(msg) std::cout << msg;
    #define $I_CODE(code) code
#else
     #define _PF_ ""
     #define $IDBG(msg)
     #define $IDBGCODE(code)
#endif // I_DBG
#endif // INPUTDEBUG_H
