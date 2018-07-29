#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<bitset>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define d(a) cout<<a<<endl
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 100 + 5;
const int mod = 1000000000 + 7;
const LL INF = 1<<27;
const double eps = 1e-8;
LL mp[N][N],dis[N][N];
int n,m;

void Floyd(){
	LL ans=INF;
	for(int k=1;k<=n;k++){
		//��С���ж�
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=min(dis[i][j]+mp[j][k]+mp[k][i],ans);
			}
		} 
		//���¾��� 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	if(ans<INF){
		printf("%d\n",ans);
	}
	else{
		puts("NO");
	}
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				mp[i][j]=dis[i][j]=INF; 
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			if(mp[u][v]>w){
				mp[u][v]=mp[v][u]=w;
				dis[u][v]=dis[v][u]=w;
			}
		}
		Floyd();
	}
	return 0;
}
