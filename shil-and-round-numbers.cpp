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

void create_bit(ll bit[],ll ar[]) {
	for(ll i=0;i<n;i++)
		if(isround(ar[i]))
			update(bit,i+1,1);
}

int main() {
	ll i,j,k,l,m,ar[200005],bit[200005]={0};
	int q;
	cin>>n>>q;
	for(i=0;i<n;i++)
		cin>>ar[i];
	create_bit(bit,ar);
	while(q--) {
		cin>>j>>k>>l;
		if(j==1)
			cout<<sum(bit,l)-sum(bit,k-1)<<endl;
		else {
			if(isround(ar[k-1]))
				update(bit,k,-1);
			ar[k-1] = l;
			if(isround(ar[k-1]))
				update(bit,k,1);
		}
	}
	return 0;
}

