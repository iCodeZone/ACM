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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
int s[N],top;

struct point{
	double x,y;
};

point list[N];
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
	double temp=cross(list[0],p1,p2);
	if(temp>0) return 1;
	else if(temp==0&&dis(list[0],p1)<dis(list[0],p2)) return 1;
	else return 0;
}
//输入，并把最左下方的点放在list[0]。并且进行极角排序 
void init(int n){
	int k=0;
	point p0;
	scanf("%lf%lf",&list[0].x,&list[0].y);;
	p0=list[0];
	for(int i=1;i<n;i++){
		scanf("%lf%lf",&list[i].x,&list[i].y);
		if(p0.y>list[i].y||(p0.y==list[i].y&&p0.x>list[i].x)){
			p0=list[i];
			k=i;
		}
	} 
	list[k]=list[0];
	list[0]=p0;
	
	sort(list+1,list+n,cmp);
} 
//Graham算法
void graham(int n){
	if(n==1){top=0;s[0]=0;}
	if(n==2){
		top=1;
		s[0]=0;
		s[1]=1;
	}
	if(n>2){
		for(int i=0;i<=1;i++) s[i]=i;
		top=1;
		
		for(int i=2;i<n;i++){
			while(top>0&&cross(list[s[top-1]],list[s[top]],list[i])<=0) top--;
			top++;
			s[top]=i;
		}
	}
}

int main(){
	return 0;
}
