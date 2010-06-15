#include<cstdio>
#include<cstring>
#include"smallhash.h"

using namespace std;

/*
class Pair
{
    public:
        int key;
        int value;

        Pair *next;

        Pair(int K, int V);
};

class MyIntHash 
{
    public:
        MyIntHash();        
        ~MyIntHash();
        bool isContain(int K);
        Pair get(int K,int V);
        void set(Pair P);
    private:
        Pair * _data[BUCKET_SIZE];
};
*/

Pair::Pair(const int K,const int V):key(K),value(V),next(NULL) { }
void Pair::PrinttoString()
{
    printf(" (%d,%d) ",key,value);
}

MyIntHash::MyIntHash()
{
    memset(_data, NULL , sizeof(_data));
}

MyIntHash::~MyIntHash()
{
    int i = 0;
    Pair * ppair = NULL;
    for (int i = 0 ; i < BUCKET_SIZE; ++i)
    {
        if (_data[i] != NULL)
        {
            ppair = _data[i];
            Pair * pdispoal = NULL;
            while (ppair != NULL)
            {
                pdispoal = ppair;
                ppair = ppair->next;
                delete ppair;
            }
        }
    }
}

bool MyIntHash::isContainedKey(const int K)
{
    int L = K % BUCKET_SIZE;
    if (_data[L] == NULL)
        return false;
    else
    {
        Pair *pPair = _data[L];
        while (pPair != NULL)
        {
            if (K == pPair->key)
                return true;
            else
                pPair = pPair->next;
        }
        return false;
    }
}

/*
 * May return NULL;
 * */

int MyIntHash::get(const int K)
{
    int L = K % BUCKET_SIZE;
    Pair * pResult = _data[L];
    if (pResult)
    {
        Pair *pPair = _data[L];
        while (pPair != NULL)
        {
            if (K == pPair->key)
            {
                pResult = pPair;
                break;
            }

            pPair = pPair->next;
        }
    }
    return pResult->value;
}

void MyIntHash::set(const Pair P)
{
    int L = P.key % BUCKET_SIZE;
    Pair *pSearch = _data[L];
    if (pSearch)
    {
        Pair *pTemp = pSearch;
        Pair *pFormer = NULL;
        while (pSearch != NULL)
        {
            if (pSearch->key == P.key)
            {
                break;
            }
            else
            {
                pFormer = pSearch;
                pSearch = pSearch->next;
            }
        }
        
        if (pSearch != NULL)
        {
            pSearch->value = P.value;
        }
        else
        {
            pSearch = new Pair(P.key,P.value);
        }
    }
    else
    {
        Pair *newly = new Pair(P.key,P.value);
        _data[L] = newly;
    }

}
void MyIntHash::set(const int K , const int V)
{
    Pair p = Pair(K,V);
    set(p);
}
void MyIntHash::PrinttoString()
{
    for (int i = 0 ; i < BUCKET_SIZE ; ++i)
    {
        Pair * pResult = _data[i];
        if (pResult)
        {
            Pair *pPair = _data[i];
            while (pPair != NULL)
            {
                pPair->PrinttoString();
                pPair = pPair->next;
            }
        }
    }
    printf("\n");
}

int MyIntHash::factorsCount()
{
    int result = 1;
    for (int i = 0 ; i < BUCKET_SIZE ; ++i)
    {
        Pair * pResult = _data[i];
        if (pResult)
        {
            Pair *pPair = _data[i];
            while (pPair != NULL)
            {
                result *= (pPair->value + 1);
                pPair = pPair->next;
            }
        }
    }
    return result;
}
