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
    bool first_line = true;

    while(cin.getline(buf,1024) && *buf)
    {
        if (first_line)
            first_line = false;
        else
            printf("\n");

        info count[128];
        for (int i = 0 ; i < 128 ; ++i)
        {
            count[i].n = 0;
            count[i].c = (unsigned char) i;
        }
           
        int len = strlen(buf);
        for (int i = 0 ; i < len ; ++i)
            count[buf[i]].n += 1;

        qsort(count,128,sizeof(info),cmpinfo);

        for (int j = 0 ; j < 128 ; ++j)
        {
            if (0 != count[j].n)
                printf("%d %d\n",count[j].c,count[j].n);
        }
    }
    return 0;
}
