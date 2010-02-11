/** 
 * 2010 / 02 / 11 AC
 * Checking this problem on http://www.algorithmist.com/index.php/UVa_488 
 * before try to solve it.
 * 
 * Testing data is also from the aboving page.
 */
#include<cstdio>

char waveform[10][100] = 
{"1\n","1\n22\n1\n","1\n22\n333\n22\n1\n","1\n22\n333\n4444\n333\n22\n1\n",
    "1\n22\n333\n4444\n55555\n4444\n333\n22\n1\n",
    "1\n22\n333\n4444\n55555\n666666\n55555\n4444\n333\n22\n1\n",
    "1\n22\n333\n4444\n55555\n666666\n7777777\n666666\n55555\n4444\n333\n22\n1\n",
    "1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n",
    "1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n999999999\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n"};



int main()
{
    int t;
    bool head = false;
    scanf("%d",&t);
    while (t--)
    {
        int amplitude,frequency;
        scanf("%d",&amplitude);
        scanf("%d",&frequency);

        for (int f = 0 ; f < frequency ; ++f)
        {
            if (head)
            {
                printf("\n");
            }
            head = true;
            printf("%s",waveform[amplitude-1]);
        }

    }
    return 0;
}
