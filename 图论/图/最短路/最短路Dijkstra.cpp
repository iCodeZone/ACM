#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
int dis[N],pre[N];
int mp[N][N],n;

void Dijkstra(int a[][N],int s){//起点终点
	bool vis[N];// 判断是否已存入该点到S集合中
	int minn,u;
	for(int i=1;i<=n;i++){
		dis[i]=mp[s][i];
	}
	mem(vis,0);
	dis[s]=0;
	vis[s]=1;
	for(int i=1;i<n;i++){
		minn=MAX_INT;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				u=j;//保存最小点 
				minn=dis[j];
			}
		}
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&a[u][j]<MAX_INT){//未加入集合，且u和j可达 
				if(dis[u]+a[u][j]<dis[j]){
					dis[j]=dis[u]+a[u][j];//更新从v到j的最短路经 
					pre[j]=u;
				}
			}
		}
	} 
}

int main(){
	return 0;
} 
