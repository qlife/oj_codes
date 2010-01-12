// AC 2010/01/12
//  1. Beware of 0.
//  2. conversation from big base to small base will make number longer,
//     prepare for memory.
#include<cstdio>
#include<cstring>
#include<cctype>

const int MAX_INPUT_LEN = 13;
// FFFFFFFFFF in base 16 to base 2 need such length.
const int MAX_CONV_LEN = 41;
bool checkBaseLegal(int base,char *val)
{
    int len = strlen(val);
    char upChar ;
    if (base > 10)
    {
        upChar = 'A' + (base - 11);
        for (int i = 0; i < len ; ++i)
        {
            if (!(isdigit(val[i]) || 
                  (val[i] >= 'A' && val[i] <= upChar)))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        upChar = '0' + (base - 1);
        for (int i = 0 ; i < len ; ++i)
        {
            if (!(val[i] >= '0' && val[i] <= upChar))
                return false;
        }
        return true;
    }
}

int main()
{
    int base1,base2;
    char val[MAX_INPUT_LEN];
    while (3 == scanf("%d %d %s",&base1,&base2,val))
    {
        if (!checkBaseLegal(base1,val))
        {
            printf("%s is an illegal base %d number\n",val,base1);
        }
        else
        {
            int len = strlen(val);
            long long ll = 0;
            for (int i = 0 ; i < len; ++i)
            {
                ll *= base1;
                if (isdigit(val[i]))
                {
                    ll += (val[i] - '0');
                }
                else
                {
                    ll += (val[i] - 'A' + 10);
                }
            }

            if (ll == 0)
            {
                printf("%s base %d = %d base %d\n",val,base1,0,base2);
                continue;
            }

            //printf("%s base %d = %lld base 10\n",val,base1,ll);
            //I've encounter strange pointer assignment problem here.
            //Because I have not allocated enough memory space for val2,
            //during the following while loop a accidently modified the content of val[],
            //and I have not noticed that information.
            //I should always test the extremely case : 16 2 FFFFFFFFFF,
            //the longest case, and I'll notice some of output is cutted.
           
            char val2[MAX_CONV_LEN],val3[MAX_CONV_LEN];
            char *p = val2;
            while ( ll > 0 )
            {
                int digit = ll % base2;
                *p = (digit > 9) ? 'A' + (digit - 10) : '0' + digit;
                p++;
                ll -= digit;
                ll /= base2;
            }
            *p = '\0';


            char *p2 = val3;
            for (int k = strlen(val2) - 1 ; k >= 0 ; k--)
            {
                *p2 = val2[k];
                p2 ++;
            }
            *p2 = '\0';

            printf("%s base %d = %s base %d\n",val,base1,val3,base2);
        }

    }
    return 0;
}
