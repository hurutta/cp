#include <bits/stdc++.h>
using namespace std;
#define INF 200005
 
//-------------------------------------------------------------------------------------------------------------------
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "  "; err(++it, args...);cout << endl; }
//-------------------------------------------------------------------------------------------------------------------
 
int a[INF];
long long tree[INF*3];
 
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
 
long long query(int node,int b,int e,int ll,int rr)
{
    if(rr<b || ll>e) return INT_MAX;
    if(ll<=b && e<=rr) return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,ll,rr);
    int p2=query(right,mid+1,e,ll,rr);
    return min(p1,p2);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

}
