#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
int n,cnt=0;//cnt is to keep the track of vis
int is_root[200005],vis_size[200005],vis_root[200005],cur_size[200005];
vector<int> old_tr[200005],new_tr[200005];


int find_root(int x,int par,int si) {
    for(int i=0;i<old_tr[x].size();i++)
        if(!is_root[ old_tr[x][i] ] && old_tr[x][i]!=par && cur_size[ old_tr[x][i] ] > si/2)
            return find_root(old_tr[x][i],x,si);
    return x;
}

int find_size(int x) {
    if(vis_size[x]==cnt || is_root[x]) return 0;
    vis_size[x] = cnt;
    int si=0;
    for(int i=0;i<old_tr[x].size();i++)
        si += find_size(old_tr[x][i]);
    cur_size[x] = si+1;
    return cur_size[x];
}

int create_tree(int x) {
    cnt++;
    int si = find_size(x);
    int ro = find_root(x,-1,si);
    is_root[ro] = 1;
    for(int i=0;i<old_tr[ro].size();i++)
        if(!is_root[old_tr[ro][i]]) {
            int ro_sub = create_tree(old_tr[ro][i]);
            new_tr[ro].pb(ro_sub);
            new_tr[ro_sub].pb(ro);
        }
    return ro;
}

int main() {
    int i,j,k,l,m;
    cin>>n;
    for(i=0;i<n-1;i++) {
        cin>>j>>k;
        old_tr[j].pb(k);
        old_tr[k].pb(j);
    }
    create_tree(1);
    for(i=1;i<=n;i++) {
        cout<<i<<"  ";
        for(j=0;j<new_tr[i].size();j++)
            cout<<new_tr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
