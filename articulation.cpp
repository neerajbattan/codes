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
int vis[10004],articulation[10004],cnt,up_edge[10004];
vector<int> ve[10004];

void dfs(int x,int par) {
	int children=0;
	cnt++;
	vis[x] = up_edge[x] = cnt;
	for(int i=0;i<ve[x].size();i++)
		if(ve[x][i]!=par)
			if(vis[ve[x][i]]==0) {
				dfs(ve[x][i],x);
				if(up_edge[ve[x][i]] >= vis[x] && par!=-1)
					articulation[x] = 1;
				up_edge[x] = min(up_edge[x],up_edge[ve[x][i]]);
				children++;
			}
			else
				up_edge[x] = min(up_edge[x],vis[ve[x][i]]);
	if(par==-1)
		if(children>1)
			articulation[x] = 1;
}

int main() {
	while(1) {
		int i,j,k,l,n,m;
		cin>>n>>m;
		cnt=0;
		if(n==0&&m==0)
			break;
		for(i=0;i<n;i++)
			ve[i].clear();
		memset(vis,0,sizeof(vis));
		memset(articulation,0,sizeof(articulation));
		for(i=0;i<m;i++) {
			cin>>j>>k;
			j--,k--;
			ve[j].pb(k);
			ve[k].pb(j);
		}
		for(i=0;i<n;i++)
			if(!vis[i])
				dfs(i,-1);
		int ans=0;
		for(i=0;i<n;i++)
			ans += articulation[i];
		cout<<ans<<endl;
	}
	return 0;
}

