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

int main()
{
    char *fib[5001];
    char F0[2] = "0"; char F1[2] = "1"; char F2[2] = "1";
    fib[0] = F0; fib[1] = F1; fib[2] = F2;
    int nextToEval = 3;
    int n , lenA,lenB;


    for (int i = 3; i < 5001 ; ++i)
    {
        lenA = strlen(fib[i-1]);
        lenB = strlen(fib[i-2]);

        char *buf = new char[lenA + lenB+1];
        bigAdd(buf,fib[i-1],fib[i-2]);

        fib[i] = buf;
    }

    while (1 == scanf("%d",&n))
    {
        char buf2[MAX_LEN];
        strncpy(buf2,fib[n],MAX_LEN);
        strrev(buf2);
        printf("The Fibonacci number for %d is %s\n",n,buf2);
    }

    for (int i = 3; i < 5001 ; ++i)
        delete [] fib[i];
    return 0;
}
