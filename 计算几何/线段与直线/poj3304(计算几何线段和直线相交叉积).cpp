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

const int N = 100 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int t,n;
bool flag;

struct node{
	double x,y;
}s[N],e[N];

double judge(node a,node b,node c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

bool solve(node a,node b){
	if(abs(a.x-b.x)<eps&&abs(a.y-b.y)<eps){
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(judge(a,b,s[i])*judge(a,b,e[i])>eps){
			return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&s[i].x,&s[i].y,&e[i].x,&e[i].y);
		}
		if(n==1){
			flag=1;
		}
		for(int i=1;i<=n&&!flag;i++){
			for(int j=i+1;j<=n&&!flag;j++){
				if(solve(s[i],s[j])) flag=1;
				if(solve(s[i],e[j])) flag=1;
				if(solve(e[i],s[j])) flag=1;
				if(solve(e[i],e[j])) flag=1;
			}
		} 
		if(flag){
			puts("Yes!");
		}
		else{
			puts("No!");
		}
	}
	return 0;
}
