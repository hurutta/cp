#include <bits/stdc++.h>
using namespace std;
#define INF 300005
 
//=================================================================================================================
#define error(args...) { cerr << __LINE__ << ": "; string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args), cerr << "\n"; }
void err(istream_iterator<string> it) {} template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "  "; err(++it, args...); }
//================================================================================================================= 

const int LIM=100005;
const int MOD=1000000007;

struct st
{
    long long maxx,sum,llsum,rrsum;
};

int n;
long long a[INF];
st tree[INF*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].maxx=a[b];
        tree[node].sum=a[b];
        tree[node].llsum=a[b];
        tree[node].rrsum=a[b];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    st lnode=tree[left];
    st rnode=tree[right];
    tree[node].sum=lnode.sum+rnode.sum;
    tree[node].llsum=max(lnode.llsum,lnode.sum+rnode.llsum);
    tree[node].rrsum=max(rnode.rrsum,rnode.sum+lnode.rrsum);
    tree[node].maxx=max(lnode.maxx,rnode.maxx);
    tree[node].maxx=max({tree[node].maxx,tree[node].sum,tree[node].llsum,tree[node].rrsum,lnode.rrsum+rnode.llsum});
}

st query(int node,int b,int e,int ll,int rr)
{
    //error(ll,rr);
    if(rr<b || ll>e)
    {
        st tmp;
        tmp.maxx=LLONG_MIN;
        return tmp;
    }
    if(ll<=b && e<=rr) return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    st lnode=query(left,b,mid,ll,rr);
    st rnode=query(right,mid+1,e,ll,rr);
    if(lnode.maxx==LLONG_MIN) return rnode;
    if(rnode.maxx==LLONG_MIN) return lnode;
    
    st nownode;
    nownode.sum=lnode.sum+rnode.sum;
    nownode.llsum=max(lnode.llsum,lnode.sum+rnode.llsum);
    nownode.rrsum=max(rnode.rrsum,rnode.sum+lnode.rrsum);
    nownode.maxx=max(lnode.maxx,rnode.maxx);
    nownode.maxx=max({nownode.maxx,nownode.sum,nownode.llsum,nownode.rrsum,lnode.rrsum+rnode.llsum});
    return nownode;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for(int i=0;i<cases;i++)
    {
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        init(1,1,n);
        
        st aa=query(1,1,n,1,n-1);
        st bb=query(1,1,n,2,n);
        long long ans=max(aa.maxx,bb.maxx);
        if(ans>=tree[1].sum)
        {
            cout << "NO" << "\n";
        }else
        {
            cout << "YES" << "\n";
        }
    }
