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
int head[N],len,n,m;
int dis[N],cnt[N],temp;//temp�����и��ߺ� 
bool vis[N];

struct node{
	int to,next,w;
}edge[N];

void add(int i,int j,int w){
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
} 

void init(){
	mem(head,-1),len=temp=0;
}
//���Լ�һ������Դ�� 
bool SPFA(int s,int n,int head[],node edge[],int dis[]){
	//vis����Ƿ��ڶ����� 
	mem(vis,0),mem(cnt,0);
	for(int i=0;i<=n;i++){
		dis[i]=MAX_INT;
	}
	dis[s]=0;
	queue<int> q;
	q.push(s);vis[s]=1;cnt[s]=1;
	while(!q.empty()){
		//��ͷԪ�س��ӣ������������ 
		int x=q.front();q.pop();vis[x]=0;
		for(int k=head[x];k!=-1;k=edge[k].next){
			int y=edge[k].to;
			if(dis[x]+edge[k].w<dis[y]){
				dis[y]=dis[x]+edge[k].w;//�ɳ�
				if(!vis[y]){//��y���ڶ��� 
					vis[y]=1;//��� 
					cnt[y]++;//ͳ�ƴ���
					q.push(y);
					if(cnt[y]>n||dis[y]<temp)//������Ӵ�������˵���и��� 
						return 0; 
				} 
			}
		} 
	}
	return 1; 
}

int main(){
	int u,v,w,ans,pos;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
			if(w<0) temp+=w;
		}
		if(!SPFA(1,n,head,edge,dis)){
			puts("���ڸ���"); 
		}
		else{
			ans=dis[2],pos=2;
			for(int i=3;i<=n;i++){
				if(ans>dis[i]){
					ans=dis[i];
					pos=i;
				}
			} 
			printf("%d %d\n",pos,ans);
		}
	}
	return 0;
}
/*
debug
3 2
1 2 1
1 3 -1
*/
