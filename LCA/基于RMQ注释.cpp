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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int edgenum,head[N];//edgenum:边的数量 head:存兄弟结点 
int id[N<<1],deep[N<<1],first[N];//id:该坐标对应的结点编号 deep:深度 first:点编号第一次出现的坐标
int dp[N<<1][30];
int tot;//深搜坐标 

struct Edge{
	int v,next;
	Edge(int v=0,int next=0):v(v),next(next){}
}e[N<<1]; 

void init(){
	tot=0,edgenum=0;
	mem(head,-1);
}

void add(int u,int v){
	e[edgenum]=Edge(v,head[u]);
	head[u]=edgenum++;
}

void dfs(int u,int fa,int dep){
	id[++tot]=u;//tot坐标对应结点为u 
	first[u]=tot;//第一次出现u结点是在tot坐标 
	deep[tot]=dep;//更新tot坐标的深度
	for(int k=head[u];k!=-1;k=e[k].next){
		int v=e[k].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		//下面两句表示dfs还要回溯到父亲结点 
		deep[++tot]=dep;
		id[tot]=u;
	} 
}

void getst(int n){//RMQ前的初始化 
	for(int i=1;i<=n;i++){
		dp[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			int ll=dp[i][j-1],rr=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=deep[ll]<deep[rr]?ll:rr;
		}
	} 
} 

int rmq(int l,int r){
	int k=(int)log(r-l+1)/log(2.0);
	int ll=dp[l][k],rr=dp[r-(1<<k)+1][k];
	return deep[ll]<deep[rr]?ll:rr;//返回最小深度的坐标 
} 

int lca(int u,int v){
	u=first[u],v=first[v];//结点第一次出现坐标 
	if(u>v) swap(u,v);
	int res=rmq(u,v);//求最小深度的坐标
	return id[res];//返回对应的结点 
}

int main(){
	int n,q,u,v,LCA;
	init();
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,1,0);
	getst(tot);
	while(q--){
		scanf("%d%d",&u,&v);
		LCA=lca(u,v);
		printf("%d %d的LCA:%d\n",u,v,LCA); 
	}
	return 0;
}
