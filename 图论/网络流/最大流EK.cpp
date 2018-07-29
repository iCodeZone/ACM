#include<set>
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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;

int map[N][N],pre[N],n,m;

bool EK_BFS(int start,int end){
	queue<int> q;
	bool vis[N];
	mem(vis,0),mem(pre,-1);
	q.push(start);
	vis[start]=1;
	while(!q.empty()){
		int e=q.front();q.pop();
		if(e==end) return 1;
		for(int i=1;i<=n;i++){
			if(map[e][i]&&!vis[i]){//边容量不为零，且增广点未标记 
				vis[i]=1;
				pre[i]=e;//记录前驱
				q.push(i); 
			}
		}
	}
	return 0;
}

int EK_Max_Flow(int start,int end){
	int u,temp,ans=0;//初始化最大流为0
	while(EK_BFS(start,end)){//当增广成功 
		temp=MAX_INT;
		u=end;
		//寻找瓶颈边 
		while(pre[u]!=-1){
			temp=min(temp,map[pre[u]][u]);
			u=pre[u];
		} 
		ans+=temp;//累加进最大流
		u=end;
		//修改路径上的边容量 
		while(pre[u]!=-1){
			map[pre[u]][u]-=temp;
			map[u][pre[u]]+=temp;
			u=pre[u];
		} 
	} 
	return ans;
}

int main(){
	int u,v,w; 
	while(~scanf("%d%d",&n,&m)){
		mem(map,0);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			map[u][v]+=w;
		}
		scanf("%d%d",&u,&v);
		printf("%d\n",EK_Max_Flow(u,v));
	}
	return 0;
}
/*
debug
4 5
1 2 1
2 4 1
1 3 1
3 4 1
2 3 1
1 4
*/
