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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int head[N],len;
int pre[N],vis[N],newpos[N],now;

struct EdgeNode{
	int to,next,w;
}edge[N];

void add(int i,int j){
	edge[len].to=j;
	edge[len].next=head[i];
	head[i]=len++;
} 

void dfs(int x){
	newpos[now++]=x;
	for(int k=head[x];k!=-1;k=edge[k].next){
		if(!vis[edge[k].to]){
			vis[edge[k].to]=1;
			pre[edge[k].to]=x;
			dfs(edge[k].to);
		}
	}
}
//最大独立集 
int greedy(int n){
	bool s[N]={0};
	bool set[N]={0};
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		int t=newpos[i];
		if(!s[t]){
			set[t]=1;
			cnt++;
			s[t]=s[pre[t]]=1;
		} 
	}
	return cnt;
}

void init(){
	mem(head,-1),mem(edge,0),len=0;
	mem(vis,0),mem(pre,0),now=0;
}

int main(){
	int n,m,u,v;
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	vis[1]=1;
	pre[1]=1;
	dfs(1);
	cout<<greedy(n)<<endl;
	return 0;
}
/*
debug
5 4
1 2
1 3
3 4
3 5
*/
