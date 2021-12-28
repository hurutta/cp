#include <bits/stdc++.h>
using namespace std;
#define INF 300005
 
//=================================================================================================================
#define error(args...) { cerr << __LINE__ << ": "; string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args), cerr << "\n"; }
void err(istream_iterator<string> it) {} template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "  "; err(++it, args...); }
//================================================================================================================= 

const int LIM=300005;

struct st
{
    int a,b;
};

st all[LIM];

bool cmp(st a,st b)
{
    if(a.a==b.a) return a.b<b.b;
    return a.a>b.a;
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //in.tie(NULL);
    int n;
    cin >> n;
    for(int k=0;k<n;k++)
    {
        st aa;
        cin >> aa.a >> aa.b;
        all[k]=aa;
    }
    sort(all,all+n,cmp);
    for(int k=0;k<n;k++)
    {
        error(all[k].a,all[k].b);
    }
}
