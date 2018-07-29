/*
���κ�������������У�
ͬһǿ��ͨ�����ڵ����ж���
����ͬһ����������������С�
Ҳ����˵��ǿ��ͨ����һ��������ͼ��ĳ��������������
��dfn[x]=low[x] 
*/
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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int n,m,x[N],y[N];
int head[N],len;
int dfn[N],low[N],dfs_num;//dfn��ʾ������ȣ�low(u)Ϊu��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ����
int color[N],col_num,num[N];//Ⱦɫ 
int stack[N],vis[N],top;//ջ��ջָ��

struct EdgeNode{
	int from,to,next,w;
}edge[N*N];

void add(int i,int j,int w){
	edge[len].from=i;
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
} 

void init(){
	mem(vis,0),mem(dfn,0),mem(low,0),mem(head,-1),len=top=col_num=dfs_num=0;
}

void tarjan(int u){
	dfn[u]=low[u]=++dfs_num;
	vis[u]=1;//�Ƿ���ջ��
	stack[++top]=u;
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(dfn[v],low[u]);
		}
	} 
	if(dfn[u]==low[u]){//����ǿ��ͨ���� 
		vis[u]=0;
		//Ⱦɫ 
		color[u]=++col_num;
		num[col_num]=1;
		while(stack[top]!=u){//��ջ 
			color[stack[top]]=col_num;
			num[col_num]++;
			vis[stack[top]]=0;
			top--; 
		}
		top--;
	}
}

void solve(){
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x[i],&y[i],&w);
			add(x[i],y[i],w);
		}
		solve();
		for(int i=1;i<=col_num;i++){
			for(int j=1;j<=n;j++){
				if(color[j]==i){
					cout<<j<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
/*
debug
6 8
1 3
3 5
5 6
4 6
3 4
4 1
2 4
1 2
*/
