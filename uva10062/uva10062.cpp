// Acc 2010 Jul 29
//
// It's tricky. Consider the following situtations.
//  a) A blank line in inputs.
//  b) Last line of ouput isn't blank line.
//  c) When there are two or more characters in the same frequency,
//     the one with highter ASCII code goes first.
//
//  Finally , there WILL be some characters in input out of the range [32,127].
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct 
{
    int n;
    unsigned char c;
} info;

static int 
cmpinfo(const void* p1, const void* p2)
{
    const info *tp1 = (const info *) p1;
    const info *tp2 = (const info *) p2;

    if (tp1->n == tp2->n)
    {
        if (tp1->c > tp2->c)
            return -1;
        else 
            return 1;
    }
    else if (tp1->n < tp2->n)
        return -1;
    else if (tp1->n > tp2->n)
        return 1;
}

int main()
{
    char buf[1024];
    int num_testcase = 0;

    while(gets(buf))
    {
        num_testcase ++;
        if (num_testcase > 1)
            printf("\n");
        info count[256];
        for (int i = 0 ; i < 256; ++i)
        {
            count[i].n = 0;
            count[i].c = (unsigned char) i;
        }
           
        int len = strlen(buf);
        for (int i = 0 ; i < len ; ++i)
            count[buf[i]].n += 1;

        qsort(count,256,sizeof(info),cmpinfo);

        for (int j = 0 ; j < 256; ++j)
        {
            if (0 != count[j].n && (count[j].c > 31 || count[j].c < 128))
                printf("%d %d\n",count[j].c,count[j].n);
        }

    }
    return 0;
}
