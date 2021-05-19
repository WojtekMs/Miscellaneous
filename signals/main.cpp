#include <csignal>
#include <iostream>
int main() {
    //sends signal to itself
    //return value of this program after receiving SIGTERM is 143;
    //seems that it's not connected
    std::cout << SIGTERM << '\n';
    std::raise(SIGTERM);    
}
