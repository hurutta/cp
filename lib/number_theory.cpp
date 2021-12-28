#include <bits/stdc++.h>
using namespace std;
#define INF 1000
#define INF2 200000

//======================================================
//============= N U M B E R - T H E O R Y ==============
//======================================================

vector<int>prime;
void seive(int limit)
{
	bool vis[limit+5]={false};
	for(int i=4;i<=limit;i=i+2) vis[i]=true;
	for(int i=3;i*i<=limit;i=i+2)
	{
		if(vis[i]==false)
		{
			for(int k=i*i;k<=limit;k=k+i+i) vis[k]=true;
		}
	}
	for(int i=2;i<=limit;i++) if(!vis[i]) prime.push_back(i);
}

//=========== A L L - D I V I S O R S ==================

vector<int>divisors[INF];
void div(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j=j+i)
		{
			divisors[j].push_back(i);
		}
	}
}

int divisor(int n)
{
	int val=sqrt(n)+1;
	int sum=1;
	for(int i=0;prime[i]<val;i++)
	{
		if(n%prime[i]==0)
		{
			int count=0;
			while(n%prime[i]==0)
			{
				n=n/prime[i];
				count++;
			}
			sum=sum*(count+1);
		}
	}
	if(n>1) sum=sum*(1+1);
	return sum;
}

//=========== B I G M O D ===== binary exp. ============= 

const int MOD=1000000007;
long long bm(long long base,long long pow)
{
	if(pow==0) return 1LL;
	if(pow%2==0)
	{
		long long now=bm(base,pow/2);
		return ((now%MOD)*(now%MOD))%MOD;
	}
	return ((base%MOD)*(bm(base,pow-1)%MOD))%MOD;
}

//=========== INV MOD ====  (a/b)%m =====================

long long invmod(int a,int b)
{
	long long tmp=((a%MOD)*(bm(b,MOD-2)%MOD))%MOD;
	return tmp;
}

//=========== INV MOD ==== (a^-1)%m =====================

long long invmod(int a)
{
	long long tmp=(bm(a,MOD-2))%MOD;
	return tmp;
}

//=========== nCr MOD ==== nCr = fact(n) / (fact(r) * fact(n-r))
//================================= will pre-calculate factorial

long long fact[LIM];

void factorial()
{
	fact[0]=1LL;
	int n=LIM-2;
    for(int i=1;i<=n;i++)
    {
        fact[i]=(fac[i-1]*i)%MOD;
    }
}

long long nCr(long long n,int r, int p)
{
    if(n<r) return 0LL;
    if(r==0) return 1LL;
    long long ncr=(((fact[n]*invmod(fact[r]))%MOD)*invmod(fact[n-r]))%MOD;
    return ncr;
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

}
