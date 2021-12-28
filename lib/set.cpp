#include <bits/stdc++.h>
using namespace std;
#define INF 1000
#define INF2 200000

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	set<int>st;
	st.insert(20);	
	st.insert(10);	
	st.insert(40);	
	st.insert(30);
	set<int>::iterator it;

	it=st.lower_bound(20);		//it will indicate that position and will start iterating from there
								//that poisition can't be access get as index, its pointer
	vector<int>aa;
	for(;it!=st.end();it++)
	{
		cout << *it << endl;
		aa.push_back(*it);
	}
	
	for(int i=0;i<aa.size();i++)
	{
		cout << st.size() << endl;
		st.erase(aa[i]);
	}
}
