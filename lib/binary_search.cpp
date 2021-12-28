#include <bits/stdc++.h>
using namespace std;
#define INF 200005

//=================================================================================================================
#define error(args...) { cerr << __LINE__ << ": "; string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args), cerr << "\n"; }
void err(istream_iterator<string> it) {} template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "  "; err(++it, args...); }
//=================================================================================================================


//when its decreasing ....... again increasing
void bs()
{
	while(low<high)
	{
		long long mid=(high+low)/2;
		long long ms=calc(mid);
		long long ms2=calc(mid+1);
		if(ms<ms2)
		{
			high=mid;
		}else
		{
			low=mid+1;
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

}
