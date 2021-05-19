#include <queue>
#include <vector>
#include <cassert>

int main() {
    std::deque<int> deq{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int*> vec2{};
    for (auto& elem : deq) {
        vec2.push_back(&elem);
    }
    *(vec2[0]) = 5;
    std::queue<int> que(deq);
    assert(deq[0] == 5);
    //this fails, because queue makes copies of all the elements, 
    //and no way we can get the reference or pointer to them
    assert(que.front() == 5);

}
