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
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 10000 + 5;
const int mod = 1000000000 + 7;
int li[N],ri[N],t,n,cnt,m;
int x[N<<2],col[N<<4],ans;
bool vis[N<<2];

void pushdown(int root){
	if(col[root]!=-1){
		col[root<<1]=col[root<<1|1]=col[root];
		col[root]=-1;
	}
}

void update(int ql,int qr,int nl,int nr,int num,int root){
	if(ql<=nl&&qr>=nr){
		col[root]=num;
		return ;
	}
	pushdown(root);
	int mid=(nl+nr)>>1;
	if(ql<=mid){
		update(ql,qr,nl,mid,num,root<<1);
	}
	if(qr>mid){
		update(ql,qr,mid+1,nr,num,root<<1|1);
	}
}

void query(int ql,int qr,int nl,int nr,int root){
	if(col[root]!=-1){
		if(!vis[col[root]]){
			ans++;
			vis[col[root]]=1;
		}
		col[root]=-1;
		return ;
	}
	if(nl==nr) return ;
	pushdown(root);
	int mid=(nl+nr)>>1;
	if(ql<=mid){
		query(ql,qr,nl,mid,root<<1);
	}
	if(qr>mid){
		query(ql,qr,mid+1,nr,root<<1|1);
	}
}

int Search(int num,int l,int r){
	while(l<r){
		int mid=(l+r)>>1;
		if(x[mid]==num){
			return mid;
		}
		else if(x[mid]>num){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}

int main(){
	scanf("%d",&t);
	while(t--){
		mem(col,-1),mem(vis,0),cnt=1,ans=0,m=2;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&li[i],&ri[i]);
			x[cnt++]=li[i];
			x[cnt++]=ri[i];//ÀëÉ¢»¯ 
		}
		sort(x+1,x+cnt);
		for(int i=2;i<cnt;i++){
			if(x[i]!=x[i-1]){
				x[m++]=x[i];
			}
		}
		cnt=m;
		for(int i=2;i<m;i++){
			if((x[i]-x[i-1])>1){
				x[cnt++]=x[i]-1;
			}
		}
		sort(x+1,x+cnt);
		for(int i=1;i<=n;i++){
			int l=Search(li[i],1,cnt-1);
			int r=Search(ri[i],1,cnt-1);
			//cout<<l<<" "<<r<<endl;
			update(l,r,1,cnt-1,i,1);
		}
		query(1,cnt-1,1,cnt-1,1);
		printf("%d\n",ans);
	} 
	return 0;
}

