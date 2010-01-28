// I wrote this program after I peeked the solution of Sagit. 
// He generously posted some AC code on his site.
// Sagit's ACM Code:  http://www.tcgs.tc.edu.tw/~sagit/acm/
#include<cstdio>
const int num = 5842;
int ugly[num+1];

int main()
{
    int n;
    ugly[0] = 1;

    for (int i = 1 ; i < num; ++i)
    {
        int u2,u3,u5,u7;

        for (u7 = 0 ; u7 < i && (ugly[u7] * 7) <= ugly[i-1]; ++u7)
            ;
        for (u5 = u7 ; u5 < i && (ugly[u5] * 5) <= ugly[i-1]; ++u5)
            ;
        for (u3 = u5 ; u3 < i && (ugly[u3] * 3) <= ugly[i-1]; ++u3)
            ;
        for (u2 = u3 ; u2 < i && (ugly[u2] * 2) <= ugly[i-1]; ++u2)
            ;

        ugly[i] = ugly[u2] * 2;
        if (ugly[u3] * 3 < ugly[i]) ugly[i] = ugly[u3] * 3;
        if (ugly[u5] * 5 < ugly[i]) ugly[i] = ugly[u5] * 5;
        if (ugly[u7] * 7 < ugly[i]) ugly[i] = ugly[u7] * 7;
    }

    while(1 == scanf("%d",&n))
    {
        if (n == 0) break;

        if ((n % 100 - n % 10) == 10)
            printf("The %dth humble number is %d.\n",n,ugly[n-1]);
        else 
        {
            switch ( n % 10 )
            {
                case 1:
                    printf("The %dst humble number is %d.\n",n,ugly[n-1]); break;
                case 2:
                    printf("The %dnd humble number is %d.\n",n,ugly[n-1]); break;
                case 3:
                    printf("The %drd humble number is %d.\n",n,ugly[n-1]); break;
                default:
                    printf("The %dth humble number is %d.\n",n,ugly[n-1]); break;

            }
        }
    }
    return 0;
}
