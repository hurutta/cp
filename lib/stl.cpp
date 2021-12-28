#include <bits/stdc++.h>
using namespace std;
#define INF 2000006
#define MOD 1000000007

int main()
{
	  //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   	
    vector<int>a;
    a.push_back(20);
    a.push_back(10);
    a.push_back(30);
    a.push_back(40);
    a.push_back(15);
    a.push_back(30);


    cout << *max_element(a.begin(),a.end()) << endl;
    cout << accumulate(a.begin(),a.end(),0) << endl;        //summation of whole vector
    cout << count(a.begin(),a.end(),30) << endl;            //occurance count

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());             //make sorted vector set
    for(auto x:a) cout << x << " ";
    cout << "  -  " << a.size() << endl;

    next_permutation(a.begin(),a.end());

    for(auto x:a) cout << x << " ";
    cout << "  -  " << a.size() << endl;

    prev_permutation(a.begin(),a.end());

    for(auto x:a) cout << x << " ";
    cout << "  -  " << a.size() << endl;
}
