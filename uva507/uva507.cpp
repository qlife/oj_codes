#include<cstdio>
using namespace std;

int main()
{
    int testCases;

    scanf("%d",&testCases);
    for(int routeNo = 1 ; routeNo < testCases + 1 ; ++routeNo)
    {
        int s[20000];
        int routeLen,nParts,sum = 0;
        int begin = 0,end = 0;
        int maxSum = 0 , maxBegin = 0, maxEnd = 0;

        scanf("%d",&routeLen);
        nParts = routeLen - 1;
        for(int i = 0 ; i < nParts ; ++i)
            scanf("%d",&(s[i]));
        
        // Now select [0,1] , sum = s[0]
        maxSum = sum = s[0];
        maxBegin = begin = 0; 
        maxEnd = end = 1;

        for (int j = 1; j < nParts ; ++j)
        {
            if (sum < 0)
            {
                sum = s[j];
                begin = j;
                end = j+1;
            }
            else
            {
                sum += s[j];
                end++;
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                maxBegin = begin;
                maxEnd = end;
            }
            else if (sum == maxSum)
            {
                if ((maxEnd - maxBegin) < (end - begin))
                {
                    maxBegin = begin;
                    maxEnd = end;
                }
            }
        }
        if (maxSum <= 0)
            printf("Route %d has no nice parts\n",routeNo);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",routeNo,maxBegin+1,maxEnd+1);


    }
    return 0;
}
