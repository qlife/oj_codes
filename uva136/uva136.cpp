// I wrote this program after I peeked the solution of Sagit. 
// He generously posted some AC code on his site.
// Sagit's ACM Code:  http://www.tcgs.tc.edu.tw/~sagit/acm/
#include<cstdio>
const int num = 1500;
int ugly[num+1];

int min3(int a, int b , int c)
{
    if (a <= b)
        return (b <= c) ? a : ( (a <= c) ? a : c) ;
    else
        return (a <= c) ? b : ( (b <= c) ? b : c) ;
}

int main()
{
    ugly[0] = 1;

    for (int i = 1 ; i < 1500 ; ++i)
    {
        int u2,u3,u5;
        for (u5 = 0 ; u5 < i && (ugly[u5] * 5) <= ugly[i-1]; ++u5)
            ;
        for (u3 = u5 ; u3 < i && (ugly[u3] * 3) <= ugly[i-1]; ++u3)
            ;
        for (u2 = u3 ; u2 < i && (ugly[u2] * 2) <= ugly[i-1]; ++u2)
            ;

        ugly[i] = min3(2 * ugly[u2] , 3 * ugly[u3] , 5 * ugly[u5]);
    }

    printf("The 1500'th ugly number is %d.\n",ugly[1500 - 1]);
    return 0;
}
