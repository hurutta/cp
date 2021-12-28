#include <bits/stdc++.h>
using namespace std;
#define INF 4000

int query(int pos)
{
	int sum=0;
	while(pos>0)
	{
		sum+=tree[pos];
		pos=pos-(pos&(-pos));
	}
	return sum;
}

void update(int n,int pos,int newval)
{
	while(pos<=n)
	{
		tree[pos]+=newval;
		pos=pos+(pos&(-pos));
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
