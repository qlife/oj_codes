#include<cstdio>

using namespace std;

class Pair
{
    public:
        int key;
        int value;

        Pair *next;

        Pair(const int K, const int V);
        void PrinttoString();
};

class MyIntHash 
{
    public:
        static const int BUCKET_SIZE = 256;
        MyIntHash();        
        ~MyIntHash();
        bool isContainedKey(const int K);
        int  get(const int K);
        void set(const Pair P);
        void set(const int K , const int V);
        void PrinttoString();
        int factorsCount();
    private:
        Pair * _data[BUCKET_SIZE];
};
