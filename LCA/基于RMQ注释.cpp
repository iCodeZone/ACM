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
int edgenum,head[N];//edgenum:�ߵ����� head:���ֵܽ�� 
int id[N<<1],deep[N<<1],first[N];//id:�������Ӧ�Ľ���� deep:��� first:���ŵ�һ�γ��ֵ�����
int dp[N<<1][30];
int tot;//�������� 

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
	id[++tot]=u;//tot�����Ӧ���Ϊu 
	first[u]=tot;//��һ�γ���u�������tot���� 
	deep[tot]=dep;//����tot��������
	for(int k=head[u];k!=-1;k=e[k].next){
		int v=e[k].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		//���������ʾdfs��Ҫ���ݵ����׽�� 
		deep[++tot]=dep;
		id[tot]=u;
	} 
}

void getst(int n){//RMQǰ�ĳ�ʼ�� 
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
	return deep[ll]<deep[rr]?ll:rr;//������С��ȵ����� 
} 

int lca(int u,int v){
	u=first[u],v=first[v];//����һ�γ������� 
	if(u>v) swap(u,v);
	int res=rmq(u,v);//����С��ȵ�����
	return id[res];//���ض�Ӧ�Ľ�� 
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
		printf("%d %d��LCA:%d\n",u,v,LCA); 
	}
	return 0;
}
