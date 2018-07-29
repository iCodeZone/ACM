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

const int N = 30 + 5;
const int mod = 1000000000 + 7;
int n,ans,cnt1,cnt2,cnt;

struct node{
	double x,y;
}p1[N],p2[N];

double cross(node a,node b,node c,node d){
	double a1=(c.x-a.x)*(d.y-a.y)-(c.y-a.y)*(d.x-a.x);
	double a2=(c.x-b.x)*(d.y-b.y)-(c.y-b.y)*(d.x-b.x);
	return a1*a2;
}

int main(){
	while(~scanf("%d",&n)){
		node aim;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&p1[i].x,&p1[i].y,&p2[i].x,&p2[i].y);
		}
		n++,p1[n].x=0,p1[n].y=0,p2[n].x=100,p2[n].y=0;
		n++,p1[n].x=100,p1[n].y=0,p2[n].x=100,p2[n].y=100;
		n++,p1[n].x=100,p1[n].y=100,p2[n].x=0,p2[n].y=100;
		n++,p1[n].x=0,p1[n].y=100,p2[n].x=0,p2[n].y=0;
		scanf("%lf%lf",&aim.x,&aim.y);
		ans=MAX_INT;
		for(int i=1;i<=n;i++){
			cnt1=1,cnt2=1;
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				if(cross(p1[i],aim,p1[j],p2[j])<0){
					cnt1++;
				}
				if(cross(p2[i],aim,p1[j],p2[j])<0){
					cnt2++;
				}
			}
			cnt=min(cnt1,cnt2);
			ans=min(cnt,ans);
		}
		printf("Number of doors = %d\n",ans);
	}
	return 0;
}
