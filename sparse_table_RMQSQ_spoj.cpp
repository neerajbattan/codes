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

int sp_ta[100005][25],n;

void build() {
	for(int j=1;j<25;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			sp_ta[i][j] = min(sp_ta[i][j-1], sp_ta[i+(1<<(j-1))][j-1]);
}

int query(int l, int r) {
	int j=24,ans=2e9;
	r++;
	while(l<r) {
		if(l+(1<<j)<=r) {
			ans = min(ans, sp_ta[l][j]);
			l += (1<<j);
		}
		j--;
	}
	return ans;
}

int main() {
	int i,j,k,l,m,q;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>sp_ta[i][0];
	build();
	cin>>q;
	while(q--) {
		cin>>j>>k;
		cout<<query(j,k)<<endl;
	}
	return 0;
}

