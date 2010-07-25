#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
 
 
int LCS(char s1 [] , int s1_length, char s2 [], int s2_length)
{
    int array[s1_length+1][s2_length+1];
    memset(array, 0, sizeof(array));

    for (int i = 0; i < s1_length; i++)
        for (int j = 0; j < s2_length; j++)
            if (s1[i] == s2[j])
                array[i+1][j+1] = array[i][j] + 1;
            else
                array[i+1][j+1] = max(array[i][j+1], array[i+1][j]);
 
    return array[s1_length][s2_length];
}

int main()
{
    char s1[1024],s2[1024];
    size_t l1,l2;
    int s1_len=0,s2_len=0;

    while (!feof(stdin))
    {
        getline(&s1,&l1,stdin);
        getline(&s2,&l2,stdin);

        s1_len = strlen(s1);
        s2_len = strlen(s2);

        s1[s1_len - 1] = '\0';
        s2[s2_len - 1] = '\0';

        s1_len = strlen(s1);
        s2_len = strlen(s2);

#ifndef ONLINE_JUDGE
        printf("%s %s %d %d\n",s1,s2,s1_len,s2_len);
#endif


        int lcs_len = LCS(s1,s1_len,s2,s2_len);
        printf("%d\n",lcs_len);

    }
    return 0;
}

