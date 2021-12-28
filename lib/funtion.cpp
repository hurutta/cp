#include <bits/stdc++.h>
using namespace std;
#define INF 2000006

int ceil2(int a, int b) {return (a+b-1)/b;}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    tuple<int,int,int>tp;
    tp=make_tuple(1,2,3);
    int x,y,z;
    tie(x,y,z)=tp;
    cout << x << y << z << "\n";
}
