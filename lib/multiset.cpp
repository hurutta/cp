#include <bits/stdc++.h>
using namespace std;
#define INF 300005
 
//=================================================================================================================
#define error(args...) { cerr << __LINE__ << ": "; string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args), cerr << "\n"; }
void err(istream_iterator<string> it) {} template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "  "; err(++it, args...); }
//================================================================================================================= 

const int LIM=200005;
const int MOD=1000000007;

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    multiset<int>st;
        st.insert(25);
        st.insert(25);
        set<int>::iterator it;

    it=st.lower_bound(25);
    int pos = distance( st.begin(), it );
    cout << pos << "\n";
}
