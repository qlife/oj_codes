#include<iostream>
#include"smallhash.h"

using namespace std;

int main()
{
    MyIntHash H;

    for (int i = 0 ; i < 10 ; ++i)
        H.set(i,1);

    cout << H.isContainedKey(7) << endl;
    cout << H.isContainedKey(3) << endl;

    cout << H.get(8) << endl;
    H.set(8,15);
    cout << H.get(8) << endl;

    for (int i = 4 ; i < 20; i += MyIntHash::BUCKET_SIZE)
    {
        H.set(i,12);
        cout << H.get(i) << endl;
    }

    H.PrinttoString();

    return 0;
}
