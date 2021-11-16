# Forward Declaration
Po wykonaniu forward declaration mamy do czynienia z 'incomplete type'.

```cpp
class Foo; //forward-declaration of type Foo; Foo is incomplete type
```

## Incomplete Type
Taki 'niepełny typ' posiada swoje ograniczenia w zastosowaniu. Niektóre operacje w języku C++ są dozwolone tylko dla w pełni zdefiniowanych typów.

Oto sytuacje gdy typ T musi być w pełni zdefiniowany:
- definicja lub wywołanie funkcji, która ma typ zwracany T lub argument typu T;
- definicja obiektu typu T;
- deklaracja nie statycznego membera klasy typu T;
- wyrażenie `new` dla obiektu typu T lub tablicy z elementami typu T;
- konwersja lvalue-to-rvalue zastosowana do glvalue typu T;
- jawna lub niejawna konwersja do typu T;
- standardowe rzutowanie, `dynamic_cast` lub `static_cast` do typu `T*` lub `T&`, za wyjątkiem gdy rzutujemy nullptr lub ze wskaźnika typu void;
- wykorzystywanie operatora `.` lub `->` na memberze typu T;
- zastosowanie operatorów `typeid`, `sizeof`, lub `alignof` do typu T;
- zastosowanie operatorów arytmetycznych do `T*`;
- definicja klasy, która dziedziczy po klasie typu T;
- przypisanie do lvalue typu T;
- wyrażenie `catch` dla wyjątku typu `T`, `T&`, lub `T*`. 

## Kiedy występuje Incomplete Type
- typ void 
- nie w pełni zdefiniowane obiekty:
  - klasa zadeklarowana za pomoca forward-declaration
  - [tablica z nieokreslonym rozmiarem](https://en.cppreference.com/w/cpp/language/array#Arrays_of_unknown_bound)
  - tablica z elementami, które są niepełnymi typami
  - typ wyliczeniowy (enum) jeśli został zadeklarowany bez podania wykorzystywanego typu (np char) 
