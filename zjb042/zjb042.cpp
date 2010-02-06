#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

class person {
public:
    int cook;
    int eat;
} ;

struct gt_person : public binary_function<person, person  , bool> 
{
    bool operator()(person x, person y) const 
    { 
        return x.eat > y.eat; 
    }
};

int main()
{
    
    while(1)
    {

        int testCases;
        int sum = 0;

        scanf("%d",&testCases);
        if (testCases == 0) break;
        vector<person> vec;
        for (int i = 0 ; i < testCases ; ++i)
        {
            person per;
            scanf("%d %d",&(per.cook),&(per.eat));
            vec.push_back(per);
        }
        sort(vec.begin(),vec.end(),gt_person());

        vector<person>::iterator its;
        int cookTime = 0 , max = 0 , leaveTime = 0;
        for (its = vec.begin() ; its != vec.end() ; ++its)
        {
            cookTime += (*its).cook;
            leaveTime = cookTime + (*its).eat;
            if (leaveTime > max) max = leaveTime;
        }

        printf("%d\n",max);
    }
    return 0;
}
