#include <stdio.h>

void recursiveFunction(int n)
{
    int localVariable = n;

    printf("Recursive function call with n = %d\n", localVariable);

    if (n > 0)
    {
        recursiveFunction(n - 1);
    }
}

int main()
{
    recursiveFunction(10);

    return 0;
}
