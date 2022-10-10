#include "lzn_lib.h"

namespace lzn {
    void amx_GetStr(AMX* amx, cell amx_addr, char* dest, int len) {
        cell* addr; // we create a cell-type pointer to store the contents of the address
        amx_GetAddr(amx, amx_addr, &addr); // here we store the contents of the address, in our storage pointer
        amx_GetString(dest, addr, 0, len); // here now, we take the string stored in our variable, and put it in its destination, with the size specified by the function
    }
    
}