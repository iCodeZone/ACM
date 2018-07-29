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

const int N = 5000 + 5;
const int mod = 1000000000 + 7;
int ans[N],num[N]; 

struct node{
	int x1,x2,y1,y2;
}a[N];

bool cmp(node a,node b){
	if(a.x1<b.x1&&a.x2<b.x2){
		return 1;
	}
	return 0;
}

bool judge(node a,int x,int y){
	int num=(a.x1-x)*(a.y2-y)-(a.x2-x)*(a.y1-y);
	if(num>0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int n,m,x1,x2,y1,y2,cnt,x,y,l,r;
	while(~scanf("%d",&n)&&n){
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		cnt=0,mem(ans,0),mem(num,0);
		a[cnt].x1=x1,a[cnt].y1=y1,a[cnt].x2=x1,a[cnt++].y2=y2;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			a[cnt].x1=x,a[cnt].y1=y1,a[cnt].x2=y,a[cnt++].y2=y2;
		}
		a[cnt].x1=x2,a[cnt].y1=y1,a[cnt].x2=x2,a[cnt++].y2=y2;
		sort(a,a+cnt,cmp);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			l=0,r=n+1;
			while(l<r){
				int mid=(l+r)>>1;
			//	cout<<mid<<endl;
				//ÔÚÓÒ±ß 
				if(judge(a[mid],x,y)){
					l=mid+1;
				} 
				//ÔÚ×ó±ß 
				else{
					r=mid-1;
				}
			}
			if(judge(a[l],x,y)){
				ans[l]++;
			}
			else{
				l--;
				ans[l]++;
			}
		}
		puts("Box");
		for(int i=0;i<=n;i++){
			if(ans[i]){
				num[ans[i]]++;
			}
		}
		for(int i=0;i<=m;i++){
			if(num[i]){
				printf("%d: %d\n",i,num[i]);
			}
		}
	}
	return 0;
}
