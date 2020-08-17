#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int b[222222];
int vis[6222];
int a[6666];

vector<ll> S;

void dfs(int u, ll s)
{
	if(vis[u]) return ;
	vis[u]=1;
	s+=b[u];
	S.pb(s);
	dfs(a[u],s);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	ll ans = -ll(1e18);
	for(int i=0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i,0);
		if(S.back()>0&&k>=int(S.size()))
		{
			ll q = k/int(S.size());
			if(q>=1)
			{
				ll mx = -ll(1e18);
				if(q-1>0) mx=0;
				for(int i=0;i<int(S.size());i++)
				{
					mx=max(mx,S[i]);
				}
				ans=max(ans,(q-1)*S.back()+mx);
			}

			{
				int r = k%int(S.size());
				ll mx = 0;
				for(int i=0;i<r;i++)
				{
					mx=max(mx,S[i]);
				}
				ans=max(ans,mx+q*S.back());
			}
		}
		else
		{
			for(int j=1;j<=k;j++)
			{
				if(j-1<S.size()) ans=max(ans,S[j-1]);
				else break;
			}
		}
		S.clear();
	}
	cout<<ans<<'\n';
}
