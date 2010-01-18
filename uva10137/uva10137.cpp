#include<cstdio>

int main()
{
    int people = 0;
    while (1 == scanf("%d",&people))
    {
        if (people == 0)
            break;
        unsigned long cost[1000];
        for (int i = 0 ; i < people ; ++i)
        {
            unsigned long c1,c2;
            scanf("%ld.%d",&c1,&c2);
            cost[i] = c1 * 100 + c2;
        }

        unsigned long amount = 0 , avg = 0;
        unsigned long negDiff = 0 , posDiff = 0;
        for (int j = 0 ; j < people ; ++j)
            amount += cost[j];
        avg = amount / people;

        for (int k = 0 ; k < people ; ++k)
        {
            if (cost[k] < avg)
                negDiff += (avg - cost[k]);
            else 
                posDiff += (cost[k] - avg);
        }

        unsigned long biggerDiff = (negDiff < posDiff) ? negDiff : posDiff;
        printf("$%ld.%0.2d\n",biggerDiff / 100, biggerDiff % 100);
    }
}
