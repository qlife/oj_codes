#include<cstdio>

int main()
{
    int n , m;
    int fieldCount = 0;
    while (2 == scanf("%d %d",&n,&m))
    {
        if ((n == 0) && (m == 0)) 
            break;
        
        fieldCount ++;
        if (fieldCount > 1)
            printf("\n");
        char field[100][100];
        for (int t=0 ; t < n ; ++t)
        {
            scanf("%s",field[t]);
        }

        printf("Field #%d:\n",fieldCount);
        for (int i=0 ; i<n ; ++i)
        {
            for (int j=0 ; j<m ; ++j)
            {
               if (field[i][j] != '*')
               { 
                   int tile = 0;
                   
                   if (i !=  0 && j != 0)
                       tile += (field[i-1][j-1] == '*') ? 1 : 0; 

                   if (i != 0)
                       tile += (field[i-1][j] == '*') ? 1 : 0;

                   if (i != 0 && j != (m - 1))
                       tile += (field[i-1][j+1] == '*') ? 1 : 0;

                   if (j != 0)
                       tile += (field[i][j-1] == '*') ? 1 : 0;

                   if (j != (m - 1))
                       tile += (field[i][j+1] == '*') ? 1 : 0;

                   if (i != (n - 1) && j != 0)
                       tile += (field[i+1][j-1] == '*') ? 1 : 0;

                   if (i != (n - 1))
                       tile += (field[i+1][j] == '*') ? 1 : 0;

                   if (i != (n - 1) && j != (m - 1))
                       tile += (field[i+1][j+1] == '*') ? 1 : 0;

                   printf("%d",tile);
               }
               else
                   printf("%c",'*');
            }
            printf("\n");
        }
    }
    return 0;
}
