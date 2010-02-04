#include<cstdio>
#include<cmath>

const double PI = 3.141592653589;

int main()
{
    int iR,N;
    while (2 == scanf("%d %d",&iR,&N))
    {
        if (N == 1)
        {
            printf("%.10lf %.10lf %.10lf\n",(double) iR,0.0,0.0);
            continue;
        }

        double R,r,theta,sine;
        double R_minus_r;
        R = iR;
        theta = PI / (double) N;
        sine = sin(theta);
        r = R * sine / (1.0 + sine);
        R_minus_r = R - r;


        double I , tri_area , t;
        t = sqrt (R_minus_r * R_minus_r - r * r);
        I = (r * t * N) - (r * r * PI * (N - 2) / 2);

        double E,bigCircleArea, smallCircleArea;
        bigCircleArea = R * R * PI;
        smallCircleArea = r * r * PI;

        E = bigCircleArea - (N * smallCircleArea) - I;

        printf("%.10lf %.10lf %.10lf\n",r,I,E);
    }
    return 0;
}
