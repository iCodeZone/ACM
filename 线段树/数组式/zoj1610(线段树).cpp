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

const int N = 8000 + 5;
const int mod = 1000000000 + 7;
int n,col[N<<4],num[N],last,x,y,val;

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
	if(nl==nr) return ;
	pushdown(root);
	int mid=(nl+nr)>>1;
	if(ql<=mid){
		update(ql,qr,nl,mid,num,root<<1);
	}
	if(qr>mid){
		update(ql,qr,mid+1,nr,num,root<<1|1);
	}
}

void query(int ql,int qr,int root){
	if(ql==qr){
		if(col[root]!=-1&&col[root]!=last)
			num[col[root]]++;
		last=col[root];
		return ; 
	}
	pushdown(root);
	int mid=(ql+qr)>>1;
	query(ql,mid,root<<1);
	query(mid+1,qr,root<<1|1);
}

int main(){
	while(~scanf("%d",&n)){
		mem(num,0),mem(col,-1);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&val);
			update(x+1,y,1,8000,val,1);
		}
		last=-1;
		query(1,8000,1);
		for(int i=0;i<=8000;i++){
			if(num[i]){
				printf("%d %d\n",i,num[i]);
			}
		}
		puts("");
	}
	return 0;
}
