# Emplace Back
This example checks whether emplace_back method calls copy constructor.

## Result

1. std::vector<T,U>::emplace_back tries to call move constructor of class T. 
2. However, in case when move constructor is not available copy constructor is called instead in it's place.
