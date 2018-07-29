#include<bits/stdc++.h>
#define debug cout<<"aaa"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
//num数组表示该区间是否都是同一个数，如果是num就等于这个数，否则等于-1
//maxn表示区间最大值
//add表示该区间是否可以纯色化（变成一个数）。
int num[N<<2],maxn[N<<2],add[N<<2];

int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
} 

void pushup(int rt){
	if(num[rt<<1]==num[rt<<1|1]){
		num[rt]=num[rt<<1];
	}
	else{
		num[rt]=-1;
	}
	maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
}

void pushdown(int rt){
	if(add[rt]!=-1){
		add[ls]=add[rs]=add[rt];  
        maxn[ls]=maxn[rs]=maxn[rt];  
        num[ls]=num[rs]=num[rt];  
        add[rt]=-1;  
    }  
}

void build(int l,int r,int rt){
	add[rt]=-1;
	if(l==r){
		scanf("%d",&num[rt]);
		maxn[rt]=num[rt];
		return ;
	}
	int mid=(l+r)>>1;
	build(lson),build(rson);
	pushup(rt); 
}

void update(int x,int ql,int qr,int l,int r,int rt){
	if(ql<=l&&qr>=r){
		add[rt]=num[rt]=maxn[rt]=x;
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(ql<=mid) update(x,ql,qr,lson);
	if(qr>mid) update(x,ql,qr,rson);
	pushup(rt); 
}

void change(int x,int ql,int qr,int l,int r,int rt){
	if(ql<=l&&qr>=r&&num[rt]>x){
		add[rt]=num[rt]=maxn[rt]=gcd(num[rt],x);
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(ql<=mid&&maxn[ls]>x) change(x,ql,qr,lson);
	if(qr>mid&&maxn[rs]>x) change(x,ql,qr,rson);
	pushup(rt); 
}

void query(int l,int r,int rt){
	if(l==r){
		printf("%d ",num[rt]);
		return ;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	query(lson);
	query(rson);
}

int main(){
	int t,n,x,l,r,op,q;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		build(1,n,1);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d%d%d",&op,&l,&r,&x);
			if(op==2){
				change(x,l,r,1,n,1);
			}
			else{
				update(x,l,r,1,n,1);
			}
		}
		query(1,n,1);
		puts("");
	}
}
