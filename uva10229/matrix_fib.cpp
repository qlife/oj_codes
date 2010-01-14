#include<cstdio>

void matrix_fib(unsigned long n, unsigned long *x,
        unsigned long *y, unsigned long *z, unsigned long *w)
{
    if (n == 1)
    {
        *x = 1; *y = 1;
        *z = 1; *w = 0;
        return ;
    }
    else if (1 == (n % 2))
    {
        unsigned long tempX , tempY;
        unsigned long a,b,c,d;
        matrix_fib(n-1,&a,&b,&c,&d);
        tempX = a + c ; 
        tempY = b + d ;
        *z = a ; *w = b;
        *x = tempX;
        *y = tempY;
        return ;
    }
    else if (0 == (n % 2))
    {
        unsigned long a,b,c,d;
        unsigned long aa,ab,ac,bc,bd,cd,dd;
        matrix_fib(n/2,&a,&b,&c,&d);
        aa = a*a;
        ab = a*b;
        ac = a*c;
        bc = b*c;
        bd = b*d;
        cd = c*d;
        dd = d*d;
        *x = aa + bc;
        *y = ab + bd;
        *z = ac + cd;
        *w = bc + dd;
        return ;
    }
}

int main()
{
    unsigned long x,y,z,w;
    unsigned long n = 0;
    for (n = 2000000000 ; n < 2000000008 ; ++n)
    {
        matrix_fib(n,&x,&y,&z,&w);
        printf("Fib(%lu) = %lu\n",n,y);
    }
    return 0;
}
