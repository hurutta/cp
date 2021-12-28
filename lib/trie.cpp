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

struct node
{
    bool endpoint;
    node* next[2+1];
    int counter;
    node()
    {
        counter=0;
        endpoint=false;
        next[0]=NULL;
        next[1]=NULL;
    }
}*root;

void input(string a)
{
    int n=a.size();
    node* current=root;
    for(int i=0;i<n;i++)
    {
        int id=a[i]-'0';
        if(current->next[id]==NULL)
        {
            node* temp2=new node();
            current->next[id]=temp2;
            current=temp2;
            current->counter=1;
        }else
        {
            current=current->next[id];
            current->counter++;
        }
    }
    current->endpoint=true;
}

vector<int>ans;
int sz;
int chk;

void rec(node* temp,int pos)
{
    // if(temp->endpoint==true)
    // {
    //     ans.push_back(temp->strno);
    // }
    if(temp->next[0]==NULL && !chk)
    {
        for(int i=pos+1;i<sz;i++)
        {
            ans.push_back(0);
        }
        chk=1;
        return;
    }
    if(temp->next[1]==NULL && !chk)
    {
        for(int i=pos+1;i<sz;i++)
        {
            ans.push_back(1);
        }
        chk=1;
        return;
    }
    node* nx1=temp->next[0];
    node* nx2=temp->next[1];
    if(nx1->counter<=nx2->counter)
    {
        ans.push_back(0);
        rec(temp->next[0],pos+1);
    }else
    {
        ans.push_back(1);
        rec(temp->next[1],pos+1);
    }
}

void rmv(node* temp,string a,int pos)
{
    if(pos<a.size())
    {
        int id=a[pos]-'0';
        rmv(temp->next[id],a,pos+1);
    }
    if(pos>0)
    {
        temp->counter--;
    }
}

void del(node* temp)
{
    for(int i=0;i<2;i++)
    {
        if(temp->next[i]!=NULL)
        {
            del(temp->next[i]);
        }
    }
    delete(temp);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("input.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int cases;
    cin >> cases;
    for(int i=0;i<cases;i++)
    {
        root=new node();
        int n;
        cin >> n;
        sz=n;
        for(int k=0;k<n;k++)
        {
            string now;
            cin >> now;
            input(now);
        }
        chk=0;
        node* current=root;
        rec(current,-1);
        for(int k=0;k<n;k++)
        {
            cout << ans[k];
        }
        cout << "\n";
        ans.clear();
        del(root);
    }
}

