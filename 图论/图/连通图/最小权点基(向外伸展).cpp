#include<set>
#include<map>
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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int head[N],len;
int dfn[N],low[N],dfs_num;//dfn表示遍历深度，low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号
int color[N],col_num;//染色 
int stack[N],vis[N],top;//栈和栈指针
int val[N],cost[N],ind[N];
int ans1,ans2; 

struct EdgeNode{
	int from,to,next;
}edge[N];

void add(int i,int j){
	edge[len].from=i;
	edge[len].to=j;
	edge[len].next=head[i];
	head[i]=len++;
} 

void init(int n){
	mem(ind,0),mem(vis,0),mem(dfn,0),mem(low,0),mem(head,-1),len=ans1=ans2=top=col_num=dfs_num=0;
	for(int i=1;i<=n;i++){
		cost[i]=MAX_INT;
	}
}

void tarjan(int x){
	dfn[x]=++dfs_num;
	low[x]=dfs_num;
	vis[x]=1;//是否在栈中
	stack[++top]=x;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int temp=edge[i].to;
		if(!dfn[temp]){
			tarjan(temp);
			low[x]=min(low[x],low[temp]);
		}
		else if(vis[temp]){
			low[x]=min(dfn[temp],low[x]);
		}
	} 
	if(dfn[x]==low[x]){//构成强连通分量 
		vis[x]=0;
		//染色 
		color[x]=++col_num; 
		while(stack[top]!=x){//退栈 
			color[stack[top]]=col_num;
			vis[stack[top]]=0;
			top--; 
		}
		top--;
	}
}

void solve(int n){
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	//计算入度并缩点 
	for(int i=0;i<len;i++){
		if(color[edge[i].from]!=color[edge[i].to]){
			ind[color[edge[i].to]]++;
		}
	}
	//计算每个强连通分量的最小点权值 
	for(int i=1;i<=n;i++){
		if(cost[color[i]]>val[i]){
			cost[color[i]]=val[i];
		}
	} 
	for(int i=1;i<=col_num;i++){
		//若入度为0，则加入最小权值 
		if(ind[i]==0){
			ans1++;
			ans2+=cost[i];
		}
	} 
}

int main(){
	int n,m,u,v;
	while(~scanf("%d%d",&n,&m)){
		init(n);
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		solve(n);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
/*
debug
6 8
1 1 1 1 1 1
1 3
3 5
5 6
4 6
3 4
4 1
2 4
1 2
*/
