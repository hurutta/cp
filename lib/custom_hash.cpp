#include <bits/stdc++.h>
using namespace std;
#define INF 100005

//==============================================================
const int  p=31;
const long long MOD=1000000009;
long long p_pow[INF];

void calc_p_pow()
{
    int n=INF; //string length
    p_pow[0]=1LL;
    for(int i=1;i<n;i++)  p_pow[i]=(p_pow[i-1]*p)%MOD;
}

long long calc_hash(string a)
{
    long long hash=0LL;
    for(int i=0;i<a.size();i++)
    {
         hash=(hash+((a[i]-'a'+1)*p_pow[i]))%MOD;
    }
    return hash;
}
//===============================================================
//      C U S T O M - H A S H - F U N C T I O N =================
//===============================================================
//    unordered_map<int,int,custom_hash>mp;
//    unordered_set<int,int,custom_hash>st;  
//    only for unordered_
//===============================================================       
struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//===============================================================
//      custom hash function for unordered_map pair hashing
//      unordered_map<pair<int,int>,int,custom_hash_pair>mp;
//===============================================================
        
struct custom_hash_pair 
{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&p) const
    {
        auto hash1=hash<T1>{}(p.first);
        auto hash2=hash<T2>{}(p.second);
        return hash1^hash2;
    }
};

//===============================================================


int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    calc_p_pow();
    string a;
    cin >> a;
    long long val=calc_hash(a);
	cout << val << endl;
}
