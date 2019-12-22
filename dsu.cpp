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
int par[100005];

int find_par(int x) {
	if(par[x]==x)
		return x;
	par[x] = find_par(par[x]);
	return par[x];
}

int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int i,j,k,l,n,m,ar[100005];
		cin>>n>>m;
		for(i=1;i<=n;i++) {
			cin>>ar[i];
			par[i] = i;
		}
		for(i=0;i<m;i++) {
			cin>>j>>k;
			if(find_par(j)!=find_par(k))
				par[find_par(j)] = find_par(k);
		}
		int ans[100005];
		for(i=1;i<=n;i++)
			ans[find_par(i)] += ar[i];
		vector<int> ans_ve;
		for(i=1;i<=n;i++)
			if(ans[i])
				ans_ve.pb(ans[i]);
		cout<<"Case "<<tt<<": "<<ans_ve.size()<<endl;
		sort(ans_ve.begin(),ans_ve.end());
		for(i=0;i<ans_ve.size();i++)
			cout<<ans_ve[i]<<" ";
		cout<<endl;
	}
	return 0;
}

