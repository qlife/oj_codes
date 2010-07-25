// AC 2010/01/11 
// Now the numbers of testcases is huge and so I use this evil trick.
// My "Normal" implementation recived TLE :-(
// Checkout wikipedia for Carmachael Numbers.
#include<cstdio>

using namespace std;

int main()
{
    long CarmachaelNumbers[15] = {561, 1105, 1729,
        2465, 2821, 6601, 8911, 10585, 15841,
        29341, 41041, 46657, 52633, 62745, 63973};

    long n;
    while(1 == scanf("%ld",&n))
    {
        if (0 == n) break;
        bool flag = false;
        for (int i = 0 ; i < 15 ; ++i)
        {
            if (n == CarmachaelNumbers[i])
                flag = true;
        }

        if (flag)
            printf("The number %ld is a Carmichael number.\n",n);
        else
            printf("%ld is normal.\n",n);
    }
    return 0;
}
