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

const int N = 2000 + 5;
const int mod = 1000000000 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int head[N],cnt[N],len,n,m;
int dis[N];
bool vis[N],flag;

struct node{
	int to,next,w;
}edge[N*N];

void add(int i,int j,int w){
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
} 

void init(){
	mem(vis,0),mem(head,-1),len=flag=0;
}

void spfa(int u){
	vis[u]=1;
	for(int k=head[u];k!=-1;k=edge[k].next){
		int v=edge[k].to;
		if(dis[v]>dis[u]+edge[k].w){
			dis[v]=dis[u]+edge[k].w;
			if(vis[v]||flag){
				flag=1;
				return;
			}
			spfa(v);
		}
	}
	vis[u]=0;
}

int main(){
	return 0;
}
