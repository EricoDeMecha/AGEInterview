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
## Difference between three implementation of the piece-wise recurrence relation
1. Recursive Approach
In the recursive approach, the sequence is defined using a recursive formula where each term is expressed in terms of previous terms. This aligns with the concept of mathematical recurrence relations, which are equations that express terms of a sequence using previous terms.
#### Advantages
- Reflects the inherent nature of recurrence relations in mathematics.
 - Intuitive understanding of how terms relate to each other.
- Simple to implement and follow the mathematical definition.
#### Disadvantages
- Can lead to redundant calculations due to repeated subproblem evaluations, which increases computational complexity.
- Tends to be less efficient for larger values of n due to the exponential growth of recursive calls.

2. Iterative Approach
The iterative approach leverages the concept of dynamic programming, where the sequence is built up iteratively by solving subproblems and using their solutions to compute the next terms. This method aligns with the principle of breaking down a complex problem into smaller, manageable subproblems.
#### Advantages
- Avoids redundant calculations through efficient reuse of previously computed values.
- Better suited for larger values of n due to its polynomial time complexity.
- Explicitly showcases the tabular structure of dynamic programming.
#### Disadvantages
- Requires more code and a clear understanding of how to set up the iterative loop and update the table of values.

3. Memoization Approach
- The memoization approach combines the recursive nature of the problem with the efficiency of dynamic programming. It involves solving the problem using a recursive approach but avoids redundant calculations by storing already computed values in a memoization array.
#### Advantages
- Retains the simplicity of the recursive approach while mitigating its redundancy.
- Leverages the advantages of dynamic programming to reduce complexity.
- Particularly useful when you want to adapt a recursive solution to be more efficient.
#### Disadvantages
- Requires additional memory for storing the memoization array.
- While memory usage is typically less than for an explicit dynamic programming table, it's not negligible.

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

