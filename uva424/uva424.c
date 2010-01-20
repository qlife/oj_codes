#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define ALPHA_TO_NUM(x) (x - '0')
#define NUM_TO_ALPHA(x) (x + '0')

const int MAX_LEN = 256;

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
    char sum[MAX_LEN],buf[MAX_LEN];
    int j;
    memset(sum,'\0',sizeof(sum));
    while (1 == scanf("%s",buf))
    {
        char dest[MAX_LEN];
        if (0 == strcmp(buf,"0")) break;
        strrev(buf);
        bigAdd(dest,buf,sum);
        strncpy(sum,dest,strlen(dest));
    }

    strrev(sum);
    printf("%s\n",sum);

    return 0;
}
