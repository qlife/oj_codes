#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#if 0
bool checkBaseLegal(int base,const char *val)
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
#endif 

int main()
{
    int base1,base2;
    char input[12];
    while (3 == scanf("%s %d %d",input,&base1,&base2))
    {
        
        string val(input);
        long long ll = 0;
        for (int i = 0 ; i < val.size() ; ++i)
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
            printf("%7s\n","0");
            continue;
        }
       
        string val2;
        while ( ll > 0 )
        {
            int digit = ll % base2;
            char ch = (digit > 9) ? 'A' + (digit - 10) : '0' + digit;
            val2.push_back(ch);
            ll -= digit;
            ll /= base2;
        }

        if (7 < val2.size()) 
        {
            printf("%7s\n","ERROR");
            continue;
        }

        string val3(val2.size(),'\0');
        reverse_copy(val2.begin(),val2.end(),val3.begin());
        printf("%7s\n",val3.c_str());
        

    }
    return 0;
}
