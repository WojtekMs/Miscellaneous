#include <type_traits>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <iomanip>
#include <iostream>

int main() {
    std::cout << std::boolalpha;
    std::cout << "vector is aggregate: " << std::is_aggregate_v<std::vector<int>> << '\n';
    std::cout << "list is aggregate: " << std::is_aggregate_v<std::list<int>> << '\n';
    std::cout << "deque is aggregate: " << std::is_aggregate_v<std::deque<int>> << '\n';
    std::cout << "map is aggregate: " << std::is_aggregate_v<std::map<int, int>> << '\n';
    std::cout << "set is aggregate: " << std::is_aggregate_v<std::set<int>> << '\n';

    std::cout << "vector is compound: " << std::is_compound_v<std::vector<int>> << '\n';
}
