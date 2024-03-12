#include<iostream>
#include <math.h>
using namespace std;
class Solution
{ 
public:  
    //泰勒一阶展开：f(x)=f(x0)+f'(x0)(x-x0)=0 ==> x=-f(x0)/f'(x0)  +x0
    // f(x) = y - x^2
    static double Neton(int y,int maxSize)
    {
        double res;
        double x = 3.001;
        int count=0;
        while(maxSize--)
        {
            count++;
            x = -(y-x*x)/(-2*x) + x;
            res = abs(y -x*x);
            if(res < 1e-6)
            {
                
                return x;
            }
        }
        return x;
    }
};




int main()
{
    int len = 100;
    int y = 4;
    cout<<"x = "<< Solution::Neton(y,len)<<endl;
   
}