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

int lps[1000006],n,m;
string pat,txt;
vector<int> ans;

void find_location() {
	int i = 0,j=0;
	while(i<n && j<m) {
		if(txt[i]==pat[j]) {
			i++;
			j++;
		}
		else
			if(j==0)
				i++;
			else
				j = lps[j-1];
		if(j==m) {
			ans.push_back(i-j+1);
			j = lps[j-1];
		}
	}
}

void find_lps() {
	int i=1,j=0;
	while(i<m)
		if(pat[i]==pat[j]) {
			j++;
			lps[i] = j;
			i++;
		}
		else
			if(j==0) {
				lps[i] = 0;
				i++;
			}
			else
				j = lps[j-1];
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int i,j,k,l;
		ans.clear();
		cin>>txt>>pat;
		n = txt.size();
		m = pat.size();
		find_lps();
		find_location();
		if(ans.size()==0)
			cout<<"Not Found\n";
		else {
			cout<<ans.size()<<endl;
			for(i=0;i<ans.size();i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

