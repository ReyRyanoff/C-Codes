#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t;i++)
    {
        int n;
        scanf("%d", &n);
        int rem;
        while(1)
        {
            if(n < 10){
                printf("%d", n);
                break;
            }
            rem = n % 10;
            printf("%d ", rem);
            n/=10;
        }
        printf("\n");

    }

    return 0;
}