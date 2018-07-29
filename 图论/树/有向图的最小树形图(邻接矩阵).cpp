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
int mp[N][N];

int zhuliu(int mp[][N],int n,int root){
	bool vis[N];
	bool flag[N];//缩点标记为true，则该点已经被缩掉，否则依然存在
	int pre[N];
	double sum=0;
	int i,j,k;
	for(i=0;i<=n;i++){
		flag[i]=0;
		mp[i][i]=MAX_INT;
	}
	pre[root]=root;
	while(true){
		//求最短弧集合E0 
		for(i=0;i<n;i++){
			if(flag[i]||i==root) continue;
			pre[i]=i; 
			for(j=0;j<n;j++){
				if(!flag[j]&&mp[j][i]<mp[pre[i]][i]){
					pre[i]=j;
				}
			}
			//没有入边，算法结束 
			if(pre[i]==i) return -1;
		}
		//检查E0
		for(i=0;i<n;i++){
			if(flag[i]||i==root) continue;
			//从当前vi开始找环
			mem(vis,0);
			vis[root]=1;
			j=i;//从当前点开始找环 
			do{
				vis[j]=1;
				j=pre[j];
			}while(!vis[j]);
			if(j==root) continue;//没有找到环
			//收缩G中的有向环
			i=j;
			//将整个环的权值保存，累计入原图的最小树形图
			do{
				sum+=mp[pre[j]][j];
				j=pre[j];
			}while(j!=i);
			j=i;
			//对与环上的点有关的边，修改边权
			do{
				for(k=0;k<n;k++){
					if(!flag[k]&&mp[k][j]<MAX_INT&&k!=pre[j]){
						mp[k][j]-=mp[pre[j]][j];
					}
				}
				j=pre[j];
			}while(j!=i);
			//缩点，将整个环缩成i号点，所有与环上的点有关的边转移到点i
			for(j=0;j<n;j++){
				if(j==i) continue;
				for(k=pre[i];k!=i;k=pre[k]){
					if(mp[k][j]<mp[i][j]) mp[i][j]=mp[k][j];
					if(mp[j][k]<mp[j][i]) mp[j][i]=mp[j][k];
				}
			} 
			//标记环上其他的点为被缩掉
			for(j=pre[i];j!=i;j=pre[j]) flag[j]=1;
			//当前环缩点结束，形成新的图G'，跳出继续求G'的最小树形图
			break; 
		} 
		//如果所有的点都被检查且没有环存在，现在的最短弧集合E0就是最小树形图，累计入sum，算法结束
		if(i>=n){
			for(i=0;i<n;i++){
				if(!flag[i]&&i!=root) sum+=mp[pre[i]][i];
			}
			break;
		} 
	}
	return sum;
}

int main(){
	int n,m,u,v,w;
	while(scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				mp[i][j]=mp[j][i]=MAX_INT;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			mp[u][v]=w;
		}
		cout<<zhuliu(mp,n,0)<<endl;
	}
	return 0;
}
/*
debug
7 15
1 2 9
4 1 3
1 5 5
2 3 3
3 2 7
2 4 9
5 4 4
6 5 3
4 3 8
4 6 5
3 6 9
3 7 6
7 3 4
6 7 4
7 6 8
*/
