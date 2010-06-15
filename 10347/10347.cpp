//http://video.yahoo.com/watch/6361313/16500564
// the most important testcases is 180 degree case! Try 
//  1 1 2
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    const double eps = 1e-10;
    double a,b,c;
    while (3 == scanf("%lf %lf %lf",&a,&b,&c))
    {
        double s,result;
        a = 2 * a / 3;
        b = 2 * b / 3;
        c = 2 * c / 3;
        s = (a + b + c) / 2;

        if  ((a >= b+c) || (b >= a+c) || (c >= a+b)) 
        {
            if (! ((a == b) && (b == c) && (c == a)))
                result = (double) -1;
            else
                goto solve;
        }
        else if ((a < eps) || (b < eps) || (c < eps))
        {
            result = (double) -1;
        }
        else
        {
solve:
            result = 3 * sqrt(s * (s - a) * (s - b) * (s - c));
        }

        if (! (s > eps))
            result = (double) -1;

        printf("%.3lf\n",result);
    }
    return 0;
}
