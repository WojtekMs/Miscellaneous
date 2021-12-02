# C++ 20 News

- [C++ 20 News](#c-20-news)
  - [GCC < 10](#gcc--10)
  - [GCC 10](#gcc-10)
  - [GCC 11](#gcc-11)
## GCC < 10
- init statement in range-for loop
- pack expansion in lambdas
- designated initialization [except for arrays]
- abbreviated function templates (`std::function<auto(auto, auto)>`)
- string suffix/prefix checking
- std::remove_cvref
- `<version>`
- contains() for associative containers
- std::type_identity
- support for char8_t [unicode 8bit]
- std::erase(vec), std::erase_if
- std::lerp, std::midpoint

## GCC 10
- spaceship operator
- defaulting comparison operators
- constexpr dynamic_cast
- coroutines
- parenthesized initialization of aggregates [`A a(1, 2, 3, 4, 5)`]
- constexpr containers
- constinit
- constructor [[nodiscard]] must be called through static_cast
- template argument deduction for aliased templates
- constexpr for `<algorithm>`, `<utility>`
- `<compare>` to support `operator<=>`
- std::span
- new algorithm std::shift
- constexpr swap
- std::ranges namespace with most algorithms
- std::to_array()
- 

## GCC 11
- consteval
- array size deduction in new expression
- modules (partial)
- using enum
- class template argument deduction for aggregates
- converting from T* to bool is considered narrowing
- calendar and timezeon (partially)
- fix for operator>>(char*)
- std::source_location (info about source code; provides function names; line number etc, good for debugging)
