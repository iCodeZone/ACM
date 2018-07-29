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

const int N = 50 + 5;
const int mod = 1000000000 + 7;
int s[N],top;

struct point{
	double x,y;
	int num;
};

point list[N];
point cmppoint;
//叉积 
double cross(point p0,point p1,point p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//距离 
double dis(point p1,point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
//极角排序函数，角度相同则距离小的在前面 
bool cmp(point p1,point p2){
	double temp=cross(cmppoint,p1,p2);
	if(temp>0) return 1;
	else if(temp==0&&dis(list[0],p1)<dis(list[0],p2)) return 1;
	else return 0;
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%lf%lf",&list[i].num,&list[i].x,&list[i].y);
			if(list[i].y<list[0].y||(list[i].y==list[0].y&&list[i].x<list[0].x)){
				swap(list[0],list[i]);
			}
		}
		for(int i=1;i<=n;i++){
			cmppoint=list[i-1];
			sort(list+i,list+n,cmp);
		}
		printf("%d",n);
		for(int i=0;i<n;i++){
			printf(" %d",list[i].num);
		}
		puts("");
	}
	return 0;
}
