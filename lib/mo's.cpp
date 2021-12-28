#include <bits/stdc++.h>
using namespace std;
#define INF 100005

int a[INF];
int length;

struct Query
{
    int index,L,R;
    bool operator <(const Query &next) const
    {
        int mypos=L/length;
        int nextpos=next.L/length;
        if(mypos==nextpos) //both are on same block
        {
            return R<next.R;
        }
        return mypos<nextpos;
    }
}query[INF];

int freq[INF];
int current;

void add(int pos)
{
    int num=a[pos];
    freq[num]++;
    if(freq[num]==1) current++;
}

void rmv(int pos)
{
    int num=a[pos];
    freq[num]--;
    if(freq[num]==0) current--;
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int cases;
    scanf("%d",&cases);
    for(int i=1;i<=cases;i++)
    {
    	int n,q;
	    scanf("%d%d",&n,&q);
	    length=sqrt(n);
	    for(int k=0;k<n;k++) scanf("%d",&a[k]);
	    for(int k=0;k<q;k++)
	    {
	        int aa,bb;
	        scanf("%d%d",&aa,&bb);
	        aa--;
	        bb--;
	        query[k].L=aa;
	        query[k].R=bb;
	        query[k].index=k;
	    }
	    sort(query,query+q);
	    int L=0;
	    int R=-1;
	    int ans[INF]={0};
	    current=0;
	    memset(freq,0,sizeof(freq));
	    printf("Case %d:\n",i);
	    for(int k=0;k<q;k++)
	    {
	        while(R<query[k].R) add(++R);
	        while(L<query[k].L) rmv(L++);
	        while(R>query[k].R) rmv(R--);
	        while(L>query[k].L) add(--L);
	        ans[query[k].index]=current;
	    }
	    for(int k=0;k<q;k++)
	    {
	    	printf("%d\n",ans[k]);
	    }
    }
}

//reference - lightoj - 118
