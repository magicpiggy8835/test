#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int n, m, u, v;
int par[maxn], self_xp[maxn], par_xp[maxn];
string sg;

int dsu_find(int x)
{
    if(par[x]==x)return x;
    else {
        par[x]=dsu_find(par[x]);
        return par[x];
    }
}

void dsu_merge(int u,int v)
{
    int x = dsu_find(u);
    int y = dsu_find(v);
    if(x != y){
        par_xp[x] += self_xp[y];
        par[x] = y;
    }
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
        par[i]=i;
        self_xp[i]=0;
        par_xp[i]=0;
   }
   for(int i=1;i<=m;i++){
        cin>>sg;
        if(sg=="join"){
            cin>>u>>v;
            dsu_merge(u,v);
        }
        else if(sg=="add"){
            cin>>u>>v;
            int x = dsu_find(u);
            self_xp[x]+=v;
        }
        else {
            cin>>u;
            v = dsu_find(u);
            int ans = self_xp[v] - par_xp[u];
            if(v!=u)ans+=self_xp[u];
            cout<<ans<<endl;
        }
   }
//   for(int i=1;i<=n;i++){
//        cout<<self_xp[i]<<" ";
//   }cout<<endl;
//   for(int i=1;i<=n;i++){
//        cout<<par_xp[i]<<" ";
//   }cout<<endl;
//   for(int i=1;i<=n;i++){
//        cout<<par[i]<<" ";
//   }
}
