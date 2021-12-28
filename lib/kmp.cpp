#include <bits/stdc++.h>
using namespace std;
#define INF 100005

int lps[INF];

void kmp_preprocess(string pattern)
{
	lps[0]=0;
	int mat=0;
	int pos=1;
	while(pos<pattern.size())
	{
		if(pattern[mat]==pattern[pos])
		{
			mat++;
			lps[pos]=mat;
			pos++;
		}else
		{
			if(mat!=0)
			{
				mat=lps[mat-1];
			}else
			{
				lps[pos]=0;
				pos++;
			}
		}
	}
}

vector<int>ans;

void kmp(string a,string pattern)
{
	int i=0;
	int j=0;
	while(i<a.size())
	{
		if(a[i]==pattern[j])
		{
			i++;
			j++;
			if(j==pattern.size())
			{
				ans.push_back(i-pattern.size()+1);
				j=lps[j-1];
			}
		}else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}else
			{
				i++;
			}
		}
	}
}

int main()
{
	int cases;
	cin >> cases;
	while(cases)
	{
		string a,b;
		cin >> a >> b;
		ans.clear();
		for(int i=0;i<b.size()+5;i++) lps[i]=0;
		kmp_preprocess(b);
		kmp(a,b);
		if(ans.size()==0)
		{
			cout << "Not Found\n";
		}else
		{
			cout << ans.size() << "\n";
			for(int i=0;i<ans.size();i++)
			{
				cout << ans[i];
				if(i<ans.size()-1)
				{
					cout << " ";
				}
			}
			cout << "\n";
		}
		cases--;
		if(cases) cout << "\n";
	}
}

/*
abcdabxabcdabc
abcabc abcdabxabcdabc
*
