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
int head[N],ans[N],num,len;
bool vis[2*N];

struct EdgeNode{
	int to,next;
}edge[2*N];

void add(int i,int j){
	edge[len].to=j;
	edge[len].next=head[i];
	head[i]=len++;
} 

void dfs(int now){
	for(int k=head[now];k!=-1;k=edge[k].next){
		if(!vis[k]){
			vis[k]=1; 
			vis[k^1]=1;//有向图不要这一句 
			dfs(edge[k].to);
			ans[num++]=edge[k].to;
		}
	}
}

int main(){
	int n,u,v;
	cin>>n;
	mem(head,-1),mem(edge,0),mem(vis,0),num=0,len=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(2);
	for(int i=0;i<num;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
