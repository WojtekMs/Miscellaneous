#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_array_v<T>, std::remove_extent_t<T>>
onlyArrays(T& arg) {
    return arg[0];
}
//remove_extent_t<T> gdy typ T jest typem tablicowym zostanie zwrocony typ elementow tablicy,
//gdy typ T nie jest typem tablicowym to zostanie zwrocony typ T
//w sytuacji gdy T jest tablicowa wielowymiarowa, zostanie usuniety jedynie pierwszy wymiar tablicy

template <typename arrayType,
int arraySize = std::extent_v<arrayType>>
void func(arrayType& array) {
    std::cout << arraySize << '\n';
}

template <typename arrayType,
int arrayDimensions = std::rank_v<arrayType>>
void dimensions(arrayType& array) {
    std::cout << arrayDimensions << '\n';
}

template <typename T, 
          std::enable_if_t<std::is_array_v<T>, int> = 0>
void placeHolder() {}
          //komenda enable_if rozwienie sie do typu int, 
          //gdy typ T bedzie typem tablicowym, 
          //przypisujemy do int = 0, aby nie trzeba bylo przekazywac zadnej bezsensownej wartosci do szablonu
          //w sytuacji gdy typ T nie bedzie typem tablicowym to instantacja szablonu zostanie przerwana
          //oznacza to, ze nie bedzie mozna wywolac danej f-cji gdy typ T nie bedzie typem tablicowym!

int main() {
    // std::cout << std::is_array<int>::value << '\n';
    // std::cout << std::is_array<int[]>::value << '\n';
    int a = 5;
    int tab[] = {1,2,3};
    int tab2[sizeof(tab) / sizeof(int)];
    int tab3[3]{};
    int tab4[1];
    a = onlyArrays(tab4);
    // std::cout << a << '\n';
    func(tab3);
    dimensions(tab3);
}
