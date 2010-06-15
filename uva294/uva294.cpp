#include<cstdio>
#include<cmath>
#include<vector>
#include"smallhash.h"
using namespace std;

void defactor(const int N,MyIntHash *H)
{
    int n = N;
    int count = 0;
    while (n > 1)
    {
        int upto = (int) sqrt(n);
        int d = 2;
        for (; d <= upto ; ++d)
        {
            if (0 == (n % d))
            {
                n /= d;
                if (H->isContainedKey(d))
                {
                    count = H->get(d);
                    H->set(d,count+1);
                }
                else
                    H->set(d,1);
                break;
            }
        }
        
        if (d > upto)
        {
            if (H->isContainedKey(n))
            {
                count = H->get(n);
                H->set(n,count+1);
            }
            else
                H->set(n,1);
            n = 1;
        }
    }
}
void search(int U,int L)
{
    // $Between 1 and 10, 6 has a maximum of 4 divisors.

    int num = U - L + 1;
    MyIntHash *hash = NULL;

    int maxNumber = -1 , maxFactorsCount = -1;
    for (int i = 0 ; i < num ; ++i)
    {
        hash = new MyIntHash();
        defactor(L+i,hash);
        int tmp = hash->factorsCount();
        if (maxFactorsCount < tmp)
        {
            maxFactorsCount = tmp;
            maxNumber = L + i;
        }

        delete hash;
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,maxNumber,maxFactorsCount);
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

        search(U,L);
    }
}


