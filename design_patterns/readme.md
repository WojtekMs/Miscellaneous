# Design Patterns

Design patterns are solutions to concrete problems (known problems) related to software design. Knowledge of these solutions makes collaborating with other developers easier by just sharing the name of the design pattern as a solution to encountered problem. Design patterns can vary in complexity - for example you can just add traffic lights to control crossing or you can build entire infrastructure (viaduct) to make sure that pedestrians pass safely. The easiest and the least complex patterns are called 'idioms'. For example in C++ there is erase/remove idiom that is used to efficiently erase multiple elements from `std::vector` (which can be replaced by `std::erase_if` in C++20). There are also architectural patterns which are the most abstract, high level patterns that can be implemented any programming language.

They can be divided into 3 categories:
- structural (they define rules how to correctly compose software entities)
- behavioral (they define the right APIs, they manage inter object communication)
- creational (they can be used to easily create new object and re-use code)

## Warnings
- do not over-use them (use the right pattern in the right spot, sometimes much simpler code is enough)

## Structural
- composite
- adapter
- facade

### Composite

It is very useful pattern if you would like to handle entire group of objects in the exact same way as a single object. Example of such approach is filesystem: you dont really care when you want to move file or directory, you want to move entire object or group of objects. Another example can be computer graphics (moving windows, you want to move entire group of pixels by just saying `window->move`)

It is based on a common interface for both single object and collection of objects. You define 'component' and 'collection'. 'collection' inherits after 'component' and contains list of 'components'. Additionally, you implement concrete leaf classes that represent single objects which also inherit after 'component'. Now you can add both single object and collection of objects into the root collection and perform operations defined in the interface that will be applied to all children of the root collection (this is how widgets work in GUI frameworks). 'collection' delegates tasks to 'component's. 

### Adapter

It is useful pattern if you have a 3rd party library or some code that you cant change and it's API is just not compatible with other ready components in the system. This can happen if you try to integrate code from multiple projects for example. This can be difference in primitive types or some small difference in data representation. In order to connect those 2 parts of the system without modifying already written code you can use 'Adapter' pattern, which will be the glue code between them. It can transform one data representaion into another or it can swap between different data types.

### Facade

It is useful pattern to simplify and limit exposed API to the external client. Very often IT systems are complex, a lot of functions must be called, there are dependencies and functions must be called in the right order. In such case when you want to trigger set of complex actions but you do not want to bother the client with all these things you implement a 'Facade' which exposes small, easy to use BUT not flexible interface. 'Facade' handles all the complex details to deliver the expected result of the exposed method. 'Facade' can aggregate other sotware entities or have links to other facades in order to perform the desired call.


## Behavioral
- state
- command
- observer
- visitor
- chain of responsibility (good to implement exception like management)


### State

This pattern is based on the notion that in any moment there is only limited number of possible states. If you see that your program should behave differently based on it's current state and there is a lot of states and the code gets messy with a lot of if statement then you probably can use State pattern. Using this pattern you implement each state as a concrete implementation of the class interface. Then the original class delegates all it's tasks to the current state. Current state after performing the right action transfers to another state. States should easily access internal variables of the original class. This way it is easier to delegate responsibilities for each state into seperate class and if you need another state you just implement another concrete class. However, this can cause file explosion, because each State is implemented in a seperate file as a seperate class.

This is useful when there is a lot of states in the system and behavior of concrete states can change. This can be overkill in situations when there is barely couple of states that do not really change.


### Command

This pattern is extracting particular action or behavior into an object instance. Thanks to this approach command executor can easily change executed commands, it is easy to add new commands which are executed all the same, commands can be more powerful by keeping state or adding additional functionality like help or undo operations. You must implement some mechanism that will create command objects that are passed to the executor. 

### Observer

This pattern is useful when there are a lot of objects that are interested in the change of state of a single particular object. It allows to implement subscription mechanism which notifies all observers about state change of observed subject. Observers ('subscribers') must subscribe themselves to the observed 'subject' and observed subject exposes `notify` method that passes information about change of state to all observers. It is important that all observers must implement the same interface so subject can easily update them.


## Creational
- factory method
- clone (prototype)

### Factory Method

If you expect multiple types (classes) of the same genre (interface) the safest way is to use factory method in your client code, in case you need to change the concrete type you use or if you need to add another one client code doesnt change and you only add new class to work with the already implemented code

You declare single abstract method that will be used to create classes of the same interface. Each implementation overrides this abstract method and creates the right type.

### Clone

If some higher level module depends on abstraction (according to the 'D' rule - dependency inversion) and you would like to implement copy oferation for this module you have no clue what concrete implementation is currently used in the object. In order to copy higher level module without regard to any concrete implementation you need to define an abstract way to copy your abstraction. Clone is the answer - abstraction must provide `copy` method which returns abstract type. Then, all concrete implementations of this abstraction will return concrete types. Then, the higher level module only calls `copy` method defined in the abstract interface and it works for all concrete implementations.

It is quite similar to 'factory method', the difference is that the abstract interface contains the `copy` method, instead of delegating this method to another entity.
