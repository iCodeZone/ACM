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
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 40000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int head[N],len;
int qhead[N],qlen;
int F[N],ance[N],dis[N];
bool vis[N];

struct EdgeNode{
	int from,to,next;
	int lca,w;
}edge[2*N],qedge[N];

void add(int i,int j,int w){
	edge[len].from=i;
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
} 

void qadd(int i,int j){
	qedge[qlen].from=i;
	qedge[qlen].to=j;
	qedge[qlen].lca=-1;
	qedge[qlen].next=qhead[i];
	qhead[i]=qlen++;
} 

void init(){
	mem(vis,0),mem(head,-1),mem(qhead,-1),len=qlen=0;
}

int Find(int x){
	return F[x]==x?x:F[x]=Find(F[x]);
}

void LCA(int u){
	ance[u]=F[u]=u;
	vis[u]=1;
	for(int k=head[u];k!=-1;k=edge[k].next){
		int temp=edge[k].to;
		if(!vis[temp]){
			dis[temp]=dis[u]+edge[k].w;
			LCA(temp);
			F[temp]=u;
		}
	}
	for(int k=qhead[u];k!=-1;k=qedge[k].next){
		int temp=qedge[k].to;
		if(vis[temp]){
			qedge[k].lca=qedge[k^1].lca=ance[Find(temp)];
		}
	}
}

int main(){
	int n,m,q,u,v,w,ans;
	char x;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d %c",&u,&v,&w,&x);
			add(u,v,w);
			add(v,u,w);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d%d",&u,&v);
			qadd(u,v);
			qadd(v,u);
		}
		dis[1]=0;
		LCA(1);
		for(int i=0;i<q;i++){
			ans=dis[qedge[2*i].from]+dis[qedge[2*i].to]-2*dis[qedge[2*i].lca];
			printf("%d\n",ans);
		}
	}
	return 0;
}
