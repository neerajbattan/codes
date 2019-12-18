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

int n,bit[26][100005];

void update(int bi,int ind,int val) {//ind is 1 indexed
	while(ind<=n) {
		bit[bi][ind] += val;
		ind += ind&(-ind);
	}
}

int sum(int bi,int ind) {//ind is 1 indexed
	int su=0;
	while(ind) {
		su += bit[bi][ind];
		ind -= ind&(-ind);
	}
	return su;
}

int main() {
	int i,j,k,l,m,q;
	string s;
	char c;
	cin>>n>>q>>s;
	for(i=0;i<n;i++)
		update(s[i]-'a',i+1,1);
	while(q--) {
		cin>>j>>k;
		if(j==1) {
			cin>>c;
			update(s[k-1]-'a',k,-1);
			s[k-1] = c;
			update(s[k-1]-'a',k,1);
		}
		else {
			cin>>l;
			int ans=0;
			for(j=0;j<26;j++)
				if((sum(j,l)-sum(j,k-1))%2)
					ans++;
			if(ans>1)
				cout<<"no\n";
			else
				cout<<"yes\n";
		}
	}
	return 0;
}

