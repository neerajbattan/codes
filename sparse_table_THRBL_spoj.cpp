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

int sp_ta[50004][25],n;

void build() {
	for(int j=1;j<25;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			sp_ta[i][j] = max(sp_ta[i][j-1], sp_ta[i+(1<<(j-1))][j-1]);
}

int query(int l, int r) {
	int j=24,ans=-1e9;
	r++;
	while(j>=0 && l<r) {
		if(l+(1<<j)<=r) {
			ans = max(ans, sp_ta[l][j]);
			l += (1<<j);
		}
		j--;
	}
	return ans;
}

int main() {
	int i,j,k,l,m,q,ans=0;
	cin>>n>>q;
	for(i=0;i<n;i++)
		cin>>sp_ta[i][0];
	build();
	while(q--) {
		cin>>j>>k;
		int hi_from=sp_ta[j-1][0];
		int fr=min(j,k), to=max(j,k);
		l = query(fr,to-2);
		if(l<=hi_from)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}

