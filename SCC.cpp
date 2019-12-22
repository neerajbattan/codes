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
vector<ll> ve[100005],ve1[100005];
vector<ll> stack_;
ll ar[100005],vis[100005],vis1[100005],ans[100005],mii,an1=0,an2=1,mo=1e9+7;
map<ll,ll> ma;
 
void dfs(ll x) {
	if(vis[x]) return;
	vis[x] = 1;
	for(ll i=0;i<ve[x].size();i++)
		dfs(ve[x][i]);
	stack_.pb(x);
}
 
void dfs1(ll x) {
	if(vis1[x]) return;
	vis1[x] = 1;
	mii = min(mii,ar[x]);
	ma[ar[x]]++;
	for(ll i=0;i<ve1[x].size();i++)
		dfs1(ve1[x][i]);
}
 
int main() {
	ll i,j,k,l,n,m;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>ar[i];
	cin>>m;
	for(i=0;i<m;i++) {
		cin>>j>>k;
		ve[j].pb(k);
		ve1[k].pb(j);
	}
	for(i=1;i<=n;i++)
		dfs(i);
	for(i=n-1;i>=0;i--)
		if(!vis1[stack_[i]]) {
			mii = 2e9;
			ma.clear();
			dfs1(stack_[i]);
			an1 += mii;
			an2 = (an2*ma[mii])%mo;
		}
	cout<<an1<<" "<<an2<<endl;
	return 0;
}
