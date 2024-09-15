#include <stdio.h>

int fibonacci (int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
    printf("The result of fib(5) is: %d\n", fibonacci(5));
}

// return               fib(4)                    +               fib(3)
// return {fib(3)          +        fib(2)}       +   {   fib(2)       +       fib(1)}
// return {(fib(2) + fib(1)) + (fib(1) + fib(0))} + {(fib(1) + fib(0)) +         1}
// return {((fib(1) + fib(0)) + 1) + (1 +0)     } + {   1    +    0    +         1}
// return {    1    +   0     + 1  +  1 +0      } + {   1    +    0    +         1} = 5

// fib(5) is called // it needs fib(4) and fib(3)
    // fib(4) is called by fib(5) // it needs fib(3) and fib(2)
        // fib(3) is called by fib(4) // it needs fib(2) and fib(1)
            // fib(2) is called by fib(3) // it needs fib(1) and fib(0)
                // fib(1) called by fib(2) is a base case returns 1
                // fib(0) called by fib(2) is a base case returns 0
                // fib(2) is 1 + 0 = 1
            // fib(1) called by fib(3) is a base case returns 1
            // fib(3) is 1 + 1 = 2
        // fib(2) is called by fib(4) // it needs fib(1) and fib(0)
            // fib(1) called by fib(2) is a base case returns 1
            // fib(0) called by fib(2) is a base case returns 0
            // fib(2) is 1 + 0 = 1
        // fib(4) is 2 + 1 = 3
    // fib(3) is called by fib(5) // it needs fib(2) and fib(1)
        // fib(2) is called by fib(3) // it needs fib(1) and fib(0)
            // fib(1) called by fib(2) is a base case returns 1
            // fib(0) called by fib(2) is a base case returns 0
            // fib(2) is 1 + 0 = 1
        // fib(1) called by fib(3) is a base case returns 1
            // fib(3) is 1 + 1 = 2
            // fib(5) is 3 + 2 = 5 
