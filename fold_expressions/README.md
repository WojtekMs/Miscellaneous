# Fold Expressions

- [Fold Expressions](#fold-expressions)
  - [Syntax](#syntax)
  - [Explanation](#explanation)
  - [Examples](#examples)

Since C++17
They can be used to reduce a parameter pack with binary operator. Example:
```cpp
template<typename ...Args>
double sum(Args... args) {
    return (args + ...);
}
sum(2, 3, 5); //10
```
## Syntax
There is more than one way to fold a parameter pack:
- (pack op ...)
- (... op pack)
- (pack op ... op init) #binary fold
- (init op ... op pack) #binary fold

1-2) unary fold<br />
3-4) binary fold<br />

op - any of 32 binary operators used in C++; in binary fold both operators must be the same (+, -, *, /, %, <<, >>, &&, ||, etc)<br />
pack - expression (unexpanded parameter pack; cannot contain an operator with precedence lower than C-style cast operator [operator precedence](https://en.cppreference.com/w/cpp/language/operator_precedence))<br />
init - expression that does not contain either unexpanded parameter pack or operator with precedence lower than C-style cast operator<br />

**Note**\
Parenthesis are part of the fold expression syntax!

## Explanation
Fold expression expands the expression $E$ as follows:
1. ($E$ op ...) ==> ($E_1$ op ($E_2$ op ($E_3$ op ($E_4$ op $E_5$))))
2. (... op $E$) ==> (((($E_1$ op $E_2$) op $E_3$) op $E_4$) op $E_5$)
3. ($E$ op ... op $I$) ==> ($E_1$ op ($E_2$ op ($E_3$ op ($E_4$ op ($E_5$ op $I$)))))
4. ($I$ op ... op $E$) ==> ((((($I$ op $E_1$) op $E_2$) op $E_3$) op $E_4$) op $E_5$)

This describes situation when there are 5 elements in the pack expansion. It goes as long as there are elements in the fold expression.  

## Examples
1. 
```cpp
//this example is not type safe
//(for example trying to push back "a" will cause compliation failure)
template <typename ValueType, typename ...Values>
void push_back_many(std::vector<ValueType>& vec, Values... values) {
    (vec.push_back(values) , ...);
}
std::vector<int> vec{};
push_back_many(vec, 5, 7, 10, 13, 15); 
// vec{5, 7, 10, 13, 15}
```

2. 
```cpp
//remember what applied to expression??
//it cannot contain operator with precedence lower than C-style cast
//that's why it is obligatory to wrap std::cout << values in ()
//otherwise '<<' would be treated as operator
template <typename ...Values>
void print_many(Values... values) {
    ((std::cout << values) , ...);
}
print_many(5, 7.5, "ab", "ba"); 
// 57.5abba
```

3. 
```cpp
//expression now consists of value and seperator
template <typename ...Values>
void print_many(Values... values) {
    ((std::cout << values << ", ") , ...);
}
print_many(5, 7.5, "ab", "ba"); 
// 5, 7.5, ab, ba, 
```

4. 
```cpp
//above examples were unary folds
//now, it's time for a binary one!
template <typename ...Values>
void print_many(Values... values) {
    (std::cout << ... << values);
}
print_many(5, 7.5, "ab", "ba"); 
// 57.5abba
```

5. 
```cpp
//another binary fold
template <typename ...Values>
long double factorial(Values... values) {
    return (1 * ... * values);
}
factorial(1, 2, 3, 4, 5, 6); 
// 720
```

6. 
```cpp
//unary fold, 
//do you know what is the major difference between 5. and 6.?
template <typename ...Values>
long double factorial(Values... values) {
    return (values * ...);
}
factorial(1, 2, 3, 4, 5, 6); 
// 720
factorial();
// OOPS! compilation error, no init value!!
// in example 5.
// factorial() would result in 1
```
