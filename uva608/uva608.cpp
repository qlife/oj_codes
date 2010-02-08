#include<cstdio>
#include<cstring>
#include<cctype>

int main()
{
    int testCases;
    scanf("%d",&testCases);
    while(testCases--)
    {
        // -1 mean a lighter coin , 1 mean a heavier coin , 0 stands for normal
        int assumption[12];
        // If left[0][11] = 1 means in round 1 , L is placed on left balance.
        int left[3][12],right[3][12];
        // up -> -1 , even -> 0 , down -> 1
        int result[3];

        for (int i = 0 ; i < 3 ; ++i)
            for(int j = 0 ; j < 12 ; ++j)
            {
                left[i][j] = 0; right[i][j] = 0;
            }

        for (int i = 0 ; i < 3 ; ++i)
        {
            char input[8];
            scanf("%s",input);
            for (int j = 0 ; j < strlen(input) ; ++j)
                left[i][input[j] - 'A'] = 1;

            scanf("%s",input);
            for (int j = 0 ; j < strlen(input) ; ++j)
                right[i][input[j] - 'A'] = 1;

            scanf("%s",input);
            for (int j = 0 ; j < strlen(input) ; ++j) 
                input[j] = (char) tolower((char) input[j]);

            if (0 == strcmp("even",input))
                result[i] = 0;
            else if (0 == strcmp("up",input))
                result[i] = -1;
            else if (0 == strcmp("down",input))
                result[i] = 1;

#ifndef ONLINE_JUDGE
            for (int k = 0 ; k < 12 ; ++k)
                fprintf(stderr,"%d ",left[i][k]);
            fprintf(stderr," | ");
            for (int k = 0 ; k < 12 ; ++k)
                fprintf(stderr,"%d ",right[i][k]);
            fprintf(stderr," | ");
            fprintf(stderr,"%d\n",result[i]);
#endif
        }

        for (int k = 0 ; k < 12 ; ++k)
        {
            for (int t = 0 ; t < 12 ; ++t) assumption[t] = 0;
            assumption[k] = 1;
#ifndef ONLINE_JUDGE
            fprintf(stderr,"========= Set %d = %d ==========\n",k,assumption[k]);
            for (int t = 0 ; t < 12 ; ++t) 
                fprintf(stderr,"%d ",assumption[t]);
            fprintf(stderr,"\n");
#endif
            bool flag[3],gotAnswer = false;

            flag[0] = false; flag[1] = false; flag[2] = false;
            for (int i = 0 ; i < 3 ; ++i)
            {
                int lval = 0 , rval = 0;
                for (int j = 0 ; j < 12 ; ++j)
                {
                    if (left[i][j]) 
                        lval += assumption[j];
                    if (right[i][j])
                        rval += assumption[j];
                }

                if (result[i] == -1)
                    flag[i] = (lval > rval);
                else if (result[i] == 0)
                    flag[i] = (lval == rval);
                else if (result[i] == 1)
                    flag[i] = (lval < rval);
#ifndef ONLINE_JUDGE
                fprintf(stderr,"%d(%d): %d %d \n",i,result[i],lval,rval);
#endif
            }

            if (flag[0] && flag[1] && flag[2])
            {
                // no need to eval light part
                printf("%c is the counterfeit coin and it is heavy.\n",k + 'A');
                break;
            }
            else
            {
                flag[0] = false; flag[1] = false; flag[2] = false;
                assumption[k] = -1;
#ifndef ONLINE_JUDGE
                fprintf(stderr,"========= Set %d = %d ==========\n",k,assumption[k]);
                for (int t = 0 ; t < 12 ; ++t) 
                    fprintf(stderr,"%d ",assumption[t]);
                fprintf(stderr,"\n");
#endif

                for (int i = 0 ; i < 3 ; ++i)
                {
                    int lval = 0 , rval = 0; 
                    for (int j = 0 ; j < 12 ; ++j)
                    {
                        if (left[i][j]) 
                            lval += assumption[j];
                        if (right[i][j])
                            rval += assumption[j];
                    }

                    if (result[i] == -1)
                        flag[i] = lval > rval;
                    else if (result[i] == 0)
                        flag[i] = lval == rval;
                    else if (result[i] == 1)
                        flag[i] = lval < rval;
#ifndef ONLINE_JUDGE
                    fprintf(stderr,"%d(%d): %d %d \n",i,result[i],lval,rval);
#endif
                }
                
            }

            if (flag[0] && flag[1] && flag[2])
            {
                printf("%c is the counterfeit coin and it is light.\n",k + 'A');
                break;
            }
        }
    }
    return 0;
}
