#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int x = 1; x < 201; x++)
    {
        if(x % 5 == 0 && x % 7 == 0)
        {
            printf("\nFooBar");
            continue;
        }
        else if(x % 5 == 0)
        {
            printf("\nFoo");
        }
        else if(x % 7 == 0)
        {
            printf("\nBar");
        }
        else
        {
            printf("\n%d",x);
        }

    }
    return 0;
}
