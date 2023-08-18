# Bitnine AGE Interview

Repo contains answers to Bitnine AGE interview questions.

## Requirements
1. Conan package manager installed and in path. 
```bash
    pip install conan
```
2. Build-essential group tools installed including cmake and ninja.
```bash
    sudo <manager> install build-essential cmake
```

## Testing

```bash
    mkdir build && cd build; 
    cmake ../ -DCMAKE_BUILD_TYPE=Release; 
    cmake --build . ; 
    ./Quiz1; 
    ./Quiz2; 
```

## Questions

1. Quiz 1
```c
typedef struct Node
{ 
    TypeTag type; 
} Node;
typedef enum TypeTag {
... 
}
```
Using this structure, please write a function that returns fibonacci sequence based on the following arithmetic operations (+, -, *, /) and conditions. The fibonacci function should be implemented using Dynamic Programming.
```c
main()
{ 
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4); 
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(SUB))(sub, NULL);
    calc(add);
    calc(mul); 
    calc(sub);
    calc(fibo)
}
Output 
add : 16 
mul : 20
sub : -4
fibo : 2 
```
2. Implement the following piecewise recurrence relation in the 3 different ways.
   § Explain the differences (advantages, disadvantages) between the 3. 
The Problem
```html
F(n) = F(n-3) + F(n -2) where F(0) = 0, F(1) = 1, and F(2) = 2.
```
Assume that n will be less than or equal to the maximum integer value and non-negative

