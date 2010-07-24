#include<cstdio>
#include<cstring>
using namespace std;

int H[10001];

int main()
{
    memset(H,0,sizeof(H));

    int l,h,r,maxR = -1;
    while (3 == scanf("%d %d %d",&l,&h,&r))
    {
        for (int j = l ; j < r ; ++j)
        {
            if (h > H[j]) H[j] = h;
        }

        if (r > maxR)
            maxR = r;

    }

    for (int k = 1 ; k <= 10000 ; ++k)
    {
        if (H[k-1] < H[k])
        {
            printf("%d %d",k,H[k]);
            printf(" ");
        }
        else if (H[k-1] > H[k])
        {
            printf("%d %d",k,H[k]);
            if (k != maxR) printf(" ");
        }
    }
    printf("\n");
#ifndef ONLINE_JUDGE
    for (int pp = 0 ; pp <= maxR ; ++pp)
        printf("%d ",H[pp]);
    printf("\n");
    for (int pp = 0 ; pp <= maxR ; ++pp)
        printf("%d ",pp);
    printf("\n");
#endif
}
