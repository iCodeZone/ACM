#include<set>
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
int n,cnt,num[N][N];//编号 
double map[N][N],dis[N],ans,x,y;

struct node{
	double x[5],y[5];
	int len;
}a[N];
//距离 
double Dis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
//叉积 
double cross(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
	double a=(x3-x1)*(y4-y1)-(y3-y1)*(x4-x1);
	double b=(x3-x2)*(y4-y2)-(y3-y2)*(x4-x2);
	return a*b;
}
//判断相交 
bool judge(int s,int e,double x1,double y1,double x2,double y2){
	for(int i=s+1;i<=e-1;i++){
		if(cross(x1,y1,x2,y2,a[i].x[1],0,a[i].x[1],a[i].y[1])<1e-10&&cross(a[i].x[1],0,a[i].x[1],a[i].y[1],x1,y1,x2,y2)<1e-10) return 0;
		if(cross(x1,y1,x2,y2,a[i].x[2],a[i].y[2],a[i].x[3],a[i].y[3])<1e-10&&cross(a[i].x[2],a[i].y[2],a[i].x[3],a[i].y[3],x1,y1,x2,y2)<1e-10) return 0;
		if(cross(x1,y1,x2,y2,a[i].x[4],a[i].y[4],a[i].x[4],10)<1e-10&&cross(a[i].x[4],10,a[i].x[4],a[i].y[4],x1,y1,x2,y2)<1e-10) return 0;
	}
	return 1;
}
//最短路 
double Dijk(double a[][N],int s,int e,int n)//起点终点 
{
	bool vis[N];// 判断是否已存入该点到S集合中
	double minn;
	int u;
	for(int i=1;i<=n;i++){
		dis[i]=MAX_INT;
		vis[i]=0;
	}
	dis[s]=0;
	for(int i=1;i<=n;i++){
		minn=MAX_INT;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				u=j;//保存最小点 
				minn=dis[j];
			}
		}
		if(minn==MAX_INT){
			break;
		}
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&a[u][j]<MAX_INT){//未加入集合，且u和j可达 
				if(dis[u]+a[u][j]<dis[j]){
					dis[j]=dis[u]+a[u][j];//更新从v到j的最短路经 
				}
			}
		}
	} 
	return dis[e];
}

int main(){
	while(~scanf("%d",&n)){
		if(n==-1){
			break;
		}
		cnt=1;
		a[0].x[1]=0,a[0].y[1]=5,a[0].len=1;
		a[n+1].x[1]=10,a[n+1].y[1]=5,a[n+1].len=1;
		num[0][1]=1,num[n+1][1]=4*n+2;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				map[i][j]=MAX_INT;
			}
		}
		for(int i=1;i<=n;i++){
			a[i].len=4;
			scanf("%lf",&x);
			for(int j=1;j<=4;j++){
				scanf("%lf",&y);
			//	cout<<y<<endl;
				a[i].x[j]=x,a[i].y[j]=y;
				num[i][j]=++cnt;//编号 
			}
		}
		//建图 
		for(int i=0;i<=n;i++){
			for(int j=1;j<=a[i].len;j++){
				x=a[i].x[j],y=a[i].y[j];
				for(int k=i+1;k<=n+1;k++){
					for(int q=1;q<=a[k].len;q++){
						double x1=a[k].x[q],y1=a[k].y[q];
						if(judge(i,k,x,y,x1,y1)){
							int a=num[i][j],b=num[k][q];//读取编号 
							map[a][b]=Dis(x,y,x1,y1);
						}
					}
				}
			}
		}
		ans=Dijk(map,1,4*n+2,4*n+2);
		printf("%.2f\n",ans);
	}
	return 0;
}
