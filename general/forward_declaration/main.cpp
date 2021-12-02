#include "B.hpp"
#include "A.hpp"
int main() {
    B b;
    b.print();    
    //at this point we must know complete A type, because here std::default_delete<A> will be called by std::unique_ptr<A> which resides in class B
}
