#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ll long long
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll n;

ll isround(ll x) {
	if(x<0) return 0;
	ll st=x%10,en;
	while(x) {
		en = x;
		x/=10;
	}
	if(en==st) return 1;
	return 0;
}

void update(ll bit[],ll ind,ll val) {//ind is 1 indexed
	while(ind<=n) {
		bit[ind] += val;
		ind += ind&(-ind);
	}
}

ll sum(ll bit[],ll ind) {//ind is 1 indexed
	ll su=0;
	while(ind) {
		su += bit[ind];
		ind -= ind&(-ind);
	}
	return su;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll i,j,k,l,m,bit[200005]={0};
		cin>>n;
		vector<pair<ll,ll> > ar;
		for(i=0;i<n;i++) {
			cin>>j;
			ar.pb(mp(j,i+1));
		}
		sort(ar.begin(),ar.end());
		ll ans=0;
		for(i=n-1;i>=0;i--) {
			update(bit,ar[i].s,1);
			ans += sum(bit,ar[i].s-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

