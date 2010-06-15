#include<cstdio>
#include<cmath>
#include"smallhash.h"
using namespace std;

void defactor(const int N)
{
    int n = N;
    while (n > 1)
    {
        int upto = (int) sqrt(n);
        int d = 2;
        for (; d <= upto ; ++d)
        {
            if (0 == (n % d))
            {
                printf("%d ",d);
                n /= d;
                break;
            }
        }
        
        if (d > upto)
        {
            // currently n is prime.
            printf("%d ",n);
            n = 1;
        }
    }

    printf("\n");
}

int main()
{
    int T = 0;
    scanf("%d",&T);

    int N1,N2,U,L;
    while(T--)
    {
        scanf("%d %d",&N1,&N2);
        U = (N1 >= N2) ? N1 : N2;
        L = (N1 >= N2) ? N2 : N1;
    }
#if 0
    defactor(45);
    defactor(37);
    defactor(49);
    defactor(1024);
#endif
}


