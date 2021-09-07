#include <iostream>
using namespace std;
int fib(int n)
{
    int pre = 0;
    int cur = 1;
    int sum = 0;
    for(int i=2;i<n;i++)
    {
        sum = pre + cur;
        pre = cur;
        cur = sum;
    }
    return sum;
}

int main()
{
    int num = 8;
    int ret = fib(num);
    cout<<ret<<endl;
}