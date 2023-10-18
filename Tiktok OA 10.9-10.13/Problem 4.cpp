#include<iostream>
#include <map>
using namespace std;

map<int,long long> pi;

int main()
{
    int n,p=0;
    cin >> n;
    long long sum=0; pi[0]=1;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        p = p^x;
        sum = sum+pi[p];
        pi[p]++;
    }
    printf("%lld",sum);
    return 0;
}