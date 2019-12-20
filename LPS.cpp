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
int main() {
	int i,j,k,l,n,m,p[200005]={0},cen,rig,mir;
	string c,s;
	cin>>n>>c;
	s += "$";
	for(i=0;i<n;i++) {
		s += "@";
		s += c[i];
	}
	s += '@';
	s += "#";
	cen = rig = 1;
	int ma = 0;
	for(i=1;i<s.size()-1;i++) {
		mir = 2*cen-i;
		if(i<rig)
			p[i] = min(p[mir],rig-i);
		while(s[i+1+p[i]] == s[i-1-p[i]])
			p[i]++;
		if(i+p[i]>rig) {
			rig = i+p[i];
			cen = i;
		}
		ma = max(ma,p[i]);
	}
	cout<<ma<<endl;
	return 0;
}

