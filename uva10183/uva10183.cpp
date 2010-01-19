#include<cstdio>
#include<cstdlib>
#include<cstring>

#define ALPHA_TO_NUM(x) x - '0'
#define NUM_TO_ALPHA(x) x + '0'

const int MAX_LEN = 2048;

void strrev(char *buf)
{

    char *head = buf ;
    char *tail = buf;

    while ((*tail) != '\0') tail ++;
    tail --;
    while (head < tail)
    {
        char temp = (*tail);
        (*tail) = (*head);
        (*head) = temp;
        head ++; tail --;
    }
}
void bigAdd(char *result, char *A, char *B)
{
    char carry = 0;
    char *p = result;
    char *a = A ;
    char *b = B;
    char *cont = NULL;
    while (((*a) != '\0') && ((*b) != '\0'))
    {
        char temp = ALPHA_TO_NUM(*a) + ALPHA_TO_NUM(*b) + carry;
        if (temp > 9)
        {
            temp -= 10;
            carry = 1;
        }
        else
            carry = 0;

        *p = NUM_TO_ALPHA(temp);
        a++; b++; p++;
    }

    if (((*a) == '\0') && ((*b) == '\0'))
    {
        if (carry != 0)
        {
            (*p) = NUM_TO_ALPHA(carry);
            p[1] = '\0';
            return ;
        }
        else
        {
            (*p) = '\0';
            return ;
        }
    }
    else if (((*a) != '\0') && ((*b) == '\0'))
    {
        cont = a;
    }
    else if (((*a) == '\0') && ((*b) != '\0'))
    {
        cont = b;
    }

    while((*cont) != '\0')
    {
        char temp2 = ALPHA_TO_NUM(*cont) + carry;
        if (temp2 > 9)
        {
            temp2 -= 10;
            carry = 1;
        }
        else
            carry = 0;
        *p = NUM_TO_ALPHA(temp2);
        cont++; p++;
    }
    if (carry != 0)
    {
        (*p) = NUM_TO_ALPHA(carry);
        p[1] = '\0';
    }
    else
        (*p) = '\0';
    return ;
}

/* -1 : A < B , 0 : A = B , 1 : A > B*/
int bigCmp(char *A,char *B)
{
    int lenA = strlen(A);
    int lenB = strlen(B);

    if (lenA == lenB)
    {
        for (int i = lenB - 1 ; i >= 0 ; i--)
        {
            if (A[i] < B[i])
                return -1;
            else if (A[i] > B[i])
                return 1;

        }
        return 0;
    }
    else if (lenA < lenB)
    {
        return -1 ;
    }
    else if (lenA > lenB)
    {
        return 1;
    }
}

int main()
{
    char *fib[501];
    char F0[2] = "1"; char F1[2] = "1"; char F2[2] = "2";
    fib[0] = F0; fib[1] = F1; fib[2] = F2;
    int nextToEval = 3;
    int n , lenA,lenB;

    for (int i = 3; i < 501 ; ++i)
    {
        lenA = strlen(fib[i-1]);
        lenB = strlen(fib[i-2]);

        char *buf = new char[lenA + lenB+1];
        bigAdd(buf,fib[i-1],fib[i-2]);
        fib[i] = buf;
    }

    char a[128],b[128];
    int upper,lower;
    upper = lower = 0;
    while (2 == scanf("%s %s",a,b))
    {
        if (0 == strcmp(a,"0") && 0 == strcmp(b,"0"))
            break;
        strrev(a); strrev(b);
        for (int i = 1 ; i < 501 ; ++i)
        {
            int result = bigCmp(a,fib[i]);
            if (result < 1)
            {
                lower = i;
                break;
            }

        }
        for (int j = 1; j < 501 ; ++j)
        {
            int result = bigCmp(b,fib[j]);
            if (result == 0)
            {
                upper = j;
                break;
            }
            else if (result == -1)
            {
                upper = j - 1;
                break;
            }
        }
        
        printf("%d\n", (upper - lower + 1));
    }


    for (int i = 3; i < 501 ; ++i)
        delete [] fib[i];
    return 0;
}
