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

const int N = 500000 + 5;
const int mod = 1000000000 + 7;
int n,x,pos[N],cnt[N<<4],temp,t,ans,s;
char name[N][15];
int a[40] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,500001};  
int b[40] = {1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200,1314521};  

void pushup(int root){
	cnt[root]=cnt[root<<1]+cnt[root<<1|1];
}

void build(int l,int r,int root){
	if(l==r){
		cnt[root]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(lson),build(rson);
	pushup(root);
}

int query(int p,int l,int r,int root){
	if(l==r){
		cnt[root]=0;
		return l;
	}
	int mid=(l+r)>>1;
	int ret;
	if(p<=cnt[root<<1]) ret=query(p,lson);
	else ret=query(p-cnt[root<<1],rson);
	pushup(root);
	return ret;
}

int main(){
	while(~scanf("%d%d",&n,&x)){
		for(int i=1;i<=n;i++){
			scanf("%s%d",name[i],&pos[i]);
		}
		for(int i=0;a[i]<=n;i++){
			temp=a[i],ans=b[i];
		}
		build(1,n,1);
		s=n;
		while(temp--){
			s--;
			t=query(x,1,n,1);
			if(s==0){
				break;
			}
			if(pos[t]>=0){
				x=(x+pos[t]-2)%s+1;
			}
			else{
				x=((x+pos[t]-1)%s+s)%s+1;
			}
		}
		printf("%s %d\n",name[t],ans);
	}
	return 0;
}
