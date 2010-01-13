// A TLE version.
#include<cstdio>

int main()
{
    long n; int m;
    while (2 == scanf("%ld %d",&n,&m))
    {
        unsigned long modulo = 1;
        for (int j = 1 ; j < m  ; ++j)
        {
            modulo = modulo | (1 << j);
        }
        unsigned long a , b , c;
        a = 0 ; 
        b = 1 ;
        c = 1 ;

        if (n < 2)
        {
            switch (n)
            {
                case 0:
                    printf("%ld\n",a % modulo);
                    break;
                case 1:
                    printf("%ld\n",b % modulo);
                    break;
            }
            continue;
        }

        for (unsigned long i = 2 ; i <= n ; ++i)
        {
            c = (a + b) & modulo;
            a = b ; 
            b = c ;
        }

        printf("%ld\n",c);
    }
    return 0;
}
