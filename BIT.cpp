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

ll n;
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
		update(bit,i+1,ar[i]);
}

int main() {
	ll i,j,k,l,m,ar[100005],bit[100005]={0};
	cin>>n;
	for(i=0;i<n;i++)
		cin>>ar[i];
	create_bit(bit,ar);
	int q;
	cin>>q;
	while(q--) {
		cin>>j>>k>>l;
		if(j==0)
			cout<<sum(bit,l)-sum(bit,k-1)<<endl;
		else
			update(bit,k,l);
	}
	return 0;
}

