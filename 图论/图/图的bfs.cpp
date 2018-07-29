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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int head[N],len;
bool vis[N];

struct EdgeNode{
	int to,next,w;
}edge[N*N];

void add(int i,int j,int w){
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
} 

void init(){
	mem(vis,0),mem(head,-1),len=0;
}

void bfs(int x){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int i=q.front();q.pop();
		vis[i]=1;
		for(int k=head[i];k!=-1;k=edge[k].next){
			if(!vis[edge[k].to]){
				q.push(edge[k].to);
			}
		}
	}
}

int main(){
	int n,m,u,v,w;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		bfs(1);
	}
	return 0;
}
/*
debug
8 12
5 8 29
6 1 12
8 3 11
1 2 4
3 1 22
4 3 17
7 4 25
6 5 9
8 7 7
1 6 9
3 2 19
6 7 4
*/
