#include <cassert>
#include <cstdlib>

int main()
{
  int nominator = 13;
  int denominator = 5;
  const auto res = std::div(nominator, denominator);
  assert(res.quot == 2);
  assert(res.rem == 3);
  assert(nominator == 13);
  assert(denominator == 5);

  const std::div_t res2 = std::div(13, 10);
  assert(res2.quot == 1);
  assert(res2.rem == 3);

  const auto res3 = std::div(127, 10);
  assert(res3.quot == 12);
  assert(res3.rem == 7);
}
