/*3. Write a OpenMP program to calculate n Fibonacci numbers using tasks. */


#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int x, y;

    if (n < 2)
        return n;

    #pragma omp task shared(x)
    x = fib(n - 1);

    #pragma omp task shared(y)
    y = fib(n - 2);

    #pragma omp taskwait
    return x + y;
}

int main() {
    int n;

    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");

    for (int i = 0; i < n; i++) {
        int result;

        #pragma omp parallel
        {
            #pragma omp single
            {
                result = fib(i);
            }
        }

        printf("%d ", result);
    }

    printf("\n");
    return 0;
}

/*Step 1: Save the Program : Save the code above into a file named fib_tasks.c 
Step 2: Compile with OpenMP: gcc -fopenmp -o fib_tasks fib_tasks.c 
Step 3: Run the Program: ./ fib_tasks.c */

/*Enter number of Fibonacci terms: 9
Fibonacci Series:
0 1 1 2 3 5 8 13 21*/