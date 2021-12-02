# Universal References

Universal references apply only at the moment when the type is being deduced. This is very important. In case when you have a template class and you have a function declaration, the type is already deduced - at the moment of class instantiation. If you would like to have universal reference in your class member function you have to create a template member function which parameter will be deduced when the function gets called.

```cpp
int a;
auto&& b = a; //universal reference which gets deduced as lvalue reference
```

```cpp
template <typename T>
class Widget {
    void print(T&&);
}

template <typename T>
void Widget<T>::print(T&& obj); // this is rvalue reference; at the moment print gets called the T is well known

int a;
Widget<int> w;
w.print(5); //rvalue reference is okay
w.print(a); //lvalue referens returns error
```
