/* TLE */
#include<cstdio>
#include<set>
using namespace std;

long bigmod(long a,long x,long m)
{
    // Recursively compute a^x mod m in O(lgn) time
    if (x == 0)
        return 1;
    else if ((x % 2) == 0)
    {
        long t = bigmod(a,x/2,m);
        return (t * t) % m;
    }
    else
        return ((a % m) * bigmod(a,x-1,m)) % m;
}

int main()
{
    // Create primes table.
    const int SIZE = 65000;
    int check[SIZE];
    set<long> primes;

    memset(check,false,sizeof(check));
    for (long i=2 ; i<SIZE+1 ; ++i)
    {
        if (!check[i])
        {
            primes.insert(i);
            for (long j=i+i ; j < SIZE ; j += i)
                check[j] = true;
        }
    }

    long n;

    while (1 == scanf("%ld" , &n))
    {
        if (0 == n) break;
        bool flag = true;
        for (long a = 2 ; a < n ; ++a)
        {
            if (a != bigmod(a,n,n))
            {
                flag = false;    
                break;
            }
        }
        if (flag)
        {
            set<long>::iterator its;
            // l passed Fermet test.
            its = primes.find(n);
            if (its == primes.end())
            {
                // l is Carmichael numbers.
                printf("The number %ld is a Carmichael number.\n",n);
            }
            else
            {
                printf("%ld is normal.\n",n);
            }
        }
        else
        {
            printf("%ld is normal.\n",n);
        }
    }
    return 0;
}
