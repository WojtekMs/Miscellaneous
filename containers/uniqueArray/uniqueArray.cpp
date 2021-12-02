#include <iostream>
#include <memory>
#include <type_traits>

namespace cs
{
template <typename T>
class unique_ptr
{
  T* data_{};
  bool isArray{false};

 public:
  unique_ptr() = default;

  template <std::enable_if_t<!std::is_array_v<T>, int> = 0>
  unique_ptr(T* data): data_(data)
  {
  }

  template <std::enable_if_t<std::is_array_v<T>, int> = 0>
  unique_ptr(T** data): data_(data)
  {
      
  }
  bool getIsArray() const { return isArray; }
};
};  // namespace cs

int main()
{
  //   std::unique_ptr<int[]> uniqueArray{new int[5]{1, 2, 3, 4, 5}};
  //   std::cout << unique[3] << '\n';

  //   std::unique_ptr<int> unique{new int{3}};
//   cs::unique_ptr<int> regularUnique{new int{5}};
//   std::cout << std::boolalpha << regularUnique.getIsArray() << '\n';

  cs::unique_ptr<int[]> arrayUnique(new int[5]{});
  std::cout << std::boolalpha << arrayUnique.getIsArray() << '\n';
}
