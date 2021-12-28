#include <bits/stdc++.h>
using namespace std;
#define INF 100005

namespace H
{
    const int nmax=1e6+6;

    const long long MOD=1e9+7;
    const long long x=1e6+3;
    long long power[nmax];
    long long hash[nmax];

    void precalc()
    {
        power[0]=1LL;
        for(int i=1;i<nmax;i++) power[i]=(power[i-1]*x)%MOD;
    }

    void buildHash(string &a)
    {
        hash[0]=a[0];
        for(int i=1;i<a.size();i++)
        {
            hash[i]=((hash[i-1]*x)+a[i])%MOD;
        }
    }

    long long hashVal(int l,int r)
    {
        if(l==0) return hash[r];
        long long ret=(hash[r]-(hash[l-1]*power[r-l+1]))%MOD;  
        if(ret<0) ret+=MOD;
        return ret;
    }
}  

int main()
{
    H::precalc();

    string a;
    cin >> a;
    H::buildHash(a);
    while(1)
    {
        int l,r;
        cin >> l >> r;
        cout << H::hashVal(l,r) << endl;
    }
}
