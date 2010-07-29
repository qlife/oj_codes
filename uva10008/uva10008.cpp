#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<iostream>

typedef struct {
    char c;
    int n;
} alpha;
using namespace std;


static int pCmp (const void * p1, const void *p2) 
{
    const alpha * lhs = (const alpha *) p1;
    const alpha * rhs = (const alpha *) p2;

    if (lhs->n == rhs->n)
    {
        if (lhs->c < rhs->c)
            return -1;
        else
            return 1;
    } else if (lhs->n > rhs->n)
        return -1;
    else if (lhs->n < rhs->n)
        return 1;
}

int main()
{
    alpha info [26];
    for (int i = 0 ; i < 26 ; ++i)
    {
        info[i].c = 'A' + i;
        info[i].n = 0;
    }

    char buf[1024];
    int testCases;
    fgets(buf,1024,stdin);
    sscanf(buf,"%d",&testCases);

    while(testCases--)
    {
        char c;
        while ('\n' != (c = fgetc(stdin)))
        {
            if (isalpha(c))
                info[toupper(c) - 'A'].n += 1;
        }
    }

    qsort(info,26,sizeof(alpha),pCmp);
    for (int i = 0 ; i < 26 ; ++i)
    {
        if (info[i].n > 0)
            printf("%c %d\n",info[i].c,info[i].n);
    }

    return 0;
}
