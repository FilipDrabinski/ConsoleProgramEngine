#ifndef INPUT_DEBUG_MODE_H
    #define INPUT_DEBUG_MODE_H

    #define INPUT_DEBUG_MODE 1
    #if INPUT_DEBUG_MODE
        #include <iostream>
        #define $I_MSG(msg) std::cout << msg ;
        #define _PF_ __PRETTY_FUNCTION__
        #define _END_I_MSG_ "\n------------------------------------------------------------------------------\n"
    #else
        #define $I_MSG(msg)
        #define _PF_ ""
        #define _END_I_MSG_ ""
    #endif // INPUT_DEBUG_MODE
#endif // INPUT_DEBUG_MODE_H
