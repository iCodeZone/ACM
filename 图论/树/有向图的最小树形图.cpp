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
int id[N],vis[N],pre[N],pos;
LL dis[N],INF=1e17;

struct node{
	int u,v,cost;
}edge[N*N];

LL zhuliu(int root,int V,int E){
	LL sum=0;
	while(true){
		for(int i=0;i<V;i++){
			dis[i]=INF;
		}
		//����С��� 
		for(int i=0;i<E;i++){
			int u=edge[i].u,v=edge[i].v;
			if(u!=v&&dis[v]>edge[i].cost){
				dis[v]=edge[i].cost;
				pre[v]=u;
			}
		}
		//ĳ�㲻������ߣ��㷨���� 
		for(int i=0;i<V;i++){
			if(dis[i]==INF&&i!=root){
				return -1;
			}
		}
		int cnt=0;
		mem(id,-1),mem(vis,-1);
		dis[root]=0;
		//�һ� 
		for(int i=0;i<V;i++){
			int v=i;
			sum+=dis[i];
			while(id[v]==-1&&vis[v]!=i&&v!=root){
				vis[v]=i;
				v=pre[v];
			}
			//�ҵ�����ʱ�������� 
			if(id[v]==-1&&v!=root){
				for(int u=pre[v];u!=v;u=pre[u]){
					id[u]=cnt;
				}
				id[v]=cnt++;
			}
		} 
		//���û�л��������ҵ���С����ͼ���㷨���� 
		if(!cnt){
			break;
		}
		//�����µĲ��ڻ���ĵ��� 
		for(int i=0;i<V;i++){
			if(id[i]==-1){
				id[i]=cnt++;
			}
		} 
		//���¾��� 
		for(int i=0;i<E;i++){
			int u=edge[i].u,v=edge[i].v;
			edge[i].u=id[u];
			edge[i].v=id[v];
			if(id[u]!=id[v]){
				edge[i].cost-=dis[v];
			}
		}
		V=cnt;
		root=id[root];
	}
	return sum;
}

int main(){
	return 0;
}
