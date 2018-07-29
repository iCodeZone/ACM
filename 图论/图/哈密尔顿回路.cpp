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
int ans[N];
bool mp[N][N],vis[N];

inline void reverse(int ans[],int s,int t){
	while(s<t){
		swap(ans[s++],ans[t--]);
	}
}

void Hamilton(int ans[],bool mp[][N],int n){
	int s=1,t,cnt=2;
	int i,j;
	mem(vis,0);
	for(i=1;i<=n;i++){
		if(mp[s][i]){
			break;
		}
	}
	t=i;//取任意邻接于s的点t
	vis[s]=vis[t]=1;
	ans[0]=s,ans[1]=t;
	while(true){
		//从t点向外扩展
		while(true){
			for(i=1;i<=n;i++){
				if(mp[t][i]&&!vis[i]){
					ans[cnt++]=t=i;
					vis[i]=1;
					break;
				}
			}
			if(i>n) break;//无法扩展 
		} 
		//将当前序列倒置，s和t互换，从t继续扩展，相当于在原来的序列上从s向外扩展
		reverse(ans,0,cnt-1);
		swap(s,t);
		while(true){
			for(i=1;i<=n;i++){
				if(mp[t][i]&&!vis[i]){
					ans[cnt++]=t=i;
					vis[i]=1;
					break;
				}
			}
			if(i>n) break;
		}
		//如果s和t不相邻
		if(!mp[s][t]){
			//取序列ans中的一点i，使得ans[i]与t相邻，且ans[i+1]与s相邻
			for(i=1;i<cnt-2;i++){
				if(mp[ans[i]][t]&&mp[s][ans[i+1]]){
					break; 
				}
			} 
			i++;
			t=ans[i];
			reverse(ans,i,cnt-1);
		} 
		//如果当前s和t相邻
		if(cnt==n) return ;//如果当前序列中包含n个元素，算法结束
		for(j=1;j<=n;j++){
			if(vis[j]) continue;
			for(i=1;i<cnt-1;i++){
				if(mp[ans[i]][j]){
					break;
				}
			}
		} 
		s=ans[i-1];
		t=j;
		reverse(ans,0,i-1);
		reverse(ans,i,cnt-1);
		ans[cnt++]=j;
		vis[j]=1;
	}
}

int main(){
	int n,m,u,v;
	mem(mp,0),mem(ans,0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			mp[i][j]=mp[j][i]=1;
		}
		mp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		mp[u][v]=mp[v][u]=0;
	}
	Hamilton(ans,mp,n);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" "; 
	}
	puts("");
	return 0;
}
/*
周游世界 
debug
20 30
1 2
1 5
1 8
2 3
3 4
4 5
2 6
5 10
3 14
4 12
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 6
6 7
7 16
9 17
11 18
13 19
15 20
16 17
17 18
18 19
19 20
16 20
*/
