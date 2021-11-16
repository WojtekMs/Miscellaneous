template <typename T>
struct Widget
{
  void print(T&&);
};

template <typename T>
void Widget<T>::print(T&& obj) {}  // rvalue reference; at the moment print gets called the T is well known

int main()
{
  int a;
  Widget<int> w;
  w.print(5);  // rvalue reference
//   w.print(a);  // error
}
