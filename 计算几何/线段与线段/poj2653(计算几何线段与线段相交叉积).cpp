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
int n;
bool flag,vis[N];

struct node{
	double x[2],y[2];
}a[N];

double cross(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
	double a=(x3-x1)*(y4-y1)-(y3-y1)*(x4-x1); 
	double b=(x3-x2)*(y4-y2)-(y3-y2)*(x4-x2);
	return a*b; 
}

int main(){
	while(~scanf("%d",&n)&&n){
		mem(vis,0);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&a[i].x[1],&a[i].y[1],&a[i].x[2],&a[i].y[2]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(!vis[j]){
					double num1=cross(a[i].x[1],a[i].y[1],a[i].x[2],a[i].y[2],a[j].x[1],a[j].y[1],a[j].x[2],a[j].y[2]);
					double num2=cross(a[j].x[1],a[j].y[1],a[j].x[2],a[j].y[2],a[i].x[1],a[i].y[1],a[i].x[2],a[i].y[2]);
					if(num1<0&&num2<0){
						vis[i]=1;
						break;
					}
				}
			}
		}
		printf("Top sticks: "),flag=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(flag){
					printf("%d",i);
					flag=0;
					continue;
				}
				printf(", %d",i);
			}
		}
		puts(".");
	}
	return 0;
}
