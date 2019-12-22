#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ll long long
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vector<int> ve[100005],ans;
int vis[100005],fl=1,cnt;
map<int,int> ma;

void dfs(int x) {
	if(ma[x]) fl=0;
	if(vis[x]) return;
	vis[x] = 1;

	ma[x] = 1;
	for(int i=0;i<ve[x].size();i++)
		dfs(ve[x][i]);
	ma[x] = 0;

	ans.pb(x);
}

int main() {
	int i,j,k,l,n,m;
	cin>>n>>m;
	for(i=0;i<m;i++) {
		cin>>j>>k;
		j--,k--;
		ve[j].pb(-k);
	}
	for(i=0;i<n;i++) {
		sort(ve[i].begin(),ve[i].end());
		for(j=0;j<ve[i].size();j++)
			ve[i][j]*=-1;
	}
	for(i=n-1;i>=0;i--)
		dfs(i);
	if(fl) {
		for(i=n-1;i>=0;i--)
			cout<<ans[i]+1<<" ";
		cout<<endl;
	}
	else
		cout<<"Sandro fails.\n";
	return 0;
}

