#include <cstdarg>

//this file was supposed to check how
//va_start
//va_arg
//va_end
//works
//however in order to "unpack" argument you have to satisfy 2 requirements:
//you must have at least 1 concrete argument as first one to start va_list [used by va_arg, initialized by va_start]
//you must explicitly state what type of argument you want to unpack with va_arg [double, int, string]
//better approach is to use recursive variadic template model

void emptyVariadic(...) {

}

int main() {
    emptyVariadic(5, 3, 7, 9, 10);
    
}
