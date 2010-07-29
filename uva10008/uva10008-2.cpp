#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef struct {
    char c;
    int n;
} alpha;

 struct pCmp : public binary_function<alpha, alpha, bool> {
     bool operator() (alpha lhs, alpha rhs)
     {
        if (lhs.n == rhs.n)
        {
            if (lhs.c < rhs.c)
                return true;
            else
                return false;
        } else if (lhs.n > rhs.n)
            return true;
        else if (lhs.n < rhs.n)
            return false;
     }
 };
            

int main()
{
    vector<alpha> info(26);

    for (int i = 0 ; i < 26 ; ++i)
    {
        info.at(i).c = 'A' + i;
        info.at(i).n = 0;
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
                info.at(toupper(c) - 'A').n += 1;
        }
    }

    sort(info.begin(),info.end(), pCmp());
    for (int i = 0 ; i < 26 ; ++i)
    {
        if (info[i].n > 0)
            printf("%c %d\n",info[i].c,info[i].n);
    }

    return 0;
}
