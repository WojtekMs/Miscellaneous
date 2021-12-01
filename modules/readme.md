# C++ Modules
Modules are a broad subject, however this example focuses on the simplest use case: import standard header.
Standard library headers are 'importabale' headers which mean that they can be compiled automatically as a module and then they can be imported to your source code instead of included. This provides a major compilation speed up even in the simplest case: "Hello world". This example allows you to observe compilation speed up.

## Example requirements
In order to run this example you must have:
- Unix Makefiles
- Bash
- C++ compiler that supports module header compilation (GCC 11, MSVC 19.28, Clang >8)


## Example execution
In order to observe the speed up run:
- make main (notice the time)
- make main2 (notice the time)

As you could see main compiles 3x faster than main2! What is the difference?  
```cpp
// main2.cpp
#include <iostream>
...
```

```cpp
// main.cpp
import "iostream";
...
```

Preprocessor directive include copies entire file into your source code and the compiler must compile all that code (iostream is very long header). When you are using import "iostream"; you do not copy the content of iostream but you only use the BMI (binary module interface) file which is produced after module compilation. You only compile the module once and then you can always use it almost "for free". 
