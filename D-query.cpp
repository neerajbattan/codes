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

int n,bit[30004];

void update(int ind,int val) {//ind is 1 indexed
	while(ind<=n) {
		bit[ind] += val;
		ind += ind&(-ind);
	}
}

int sum(int ind) {//ind is 1 indexed
	int su=0;
	while(ind) {
		su += bit[ind];
		ind -= ind&(-ind);
	}
	return su;
}

int main() {
	int i,j,k,l,m,q,ar[30004],ans[200005];
	int en=0;
	vector<pair<pair<int,int>,int> > qu;
	map<int,int> ma;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>ar[i];
	cin>>q;
	for(i=0;i<q;i++) {
		cin>>j>>k;
		qu.pb(mp(mp(k,j),i));
	}
	sort(qu.begin(),qu.end());

	for(i=0;i<qu.size();i++) {
		while(en<qu[i].f.f) {
			if(ma[ar[en]])
				update(ma[ar[en]],-1);
			ma[ar[en]] = en+1;
			update(ma[ar[en]],1);
			en++;
		}
		ans[qu[i].s] = sum(qu[i].f.f)-sum(qu[i].f.s-1);
	}
	for(i=0;i<q;i++)
		cout<<ans[i]<<endl;
	return 0;
}

