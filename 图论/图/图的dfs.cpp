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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int head[N];
bool vis[N];

struct EdgeNode{
	int to,next,w;
}edge[N];

void add(int k){
	int i,j,w;
	scanf("%d%d%d",&i,&j,&w);
	edge[k].to=j;
	edge[k].w=w;
	edge[k].next=head[i];
	head[i]=k;
} 

void dfs(int x){
	vis[x]=1;
	printf("%d\n",x);
	for(int i=head[x];i!=-1;i=edge[i].next){
		//...
		if(!vis[edge[i].to]){
			dfs(edge[i].to);
		}
	}
}

int main(){
	int n;
	cin>>n;
	mem(head,-1);
	for(int i=1;i<=n;i++){
		add(i);
	}
	mem(vis,0);
	dfs(1);
	return 0;
}
/*
debug
12
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
