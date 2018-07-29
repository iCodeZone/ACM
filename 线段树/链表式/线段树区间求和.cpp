#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>

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
#define LL_MAX 9223372036854775807i64
#define LL_MIN (-9223372036854775807i64-1)
using namespace std;

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
int arr[N];
int ans;

struct node{
    int l,r;//区间[l,r]
    int add;//区间的延时标记
    int sum,maxn,minn;
}tree[N<<2];//一定要开到4倍多的空间

void pushdown(int root){
    if(tree[root].add != 0){
    	//若为修改，则+=改为= 
        tree[root<<1].sum += (tree[root<<1].r-tree[root<<1].l+1)*tree[root].add;
        tree[root<<1|1].sum +=(tree[root<<1|1].r-tree[root<<1|1].l+1)*tree[root].add;
        tree[root<<1].add += tree[root].add;
        tree[root<<1|1].add += tree[root].add;
        tree[root].add = 0;
    }
}

void build(int l,int r,int root){
    tree[root].l = l;
    tree[root].r = r;
    tree[root].add = 0;//刚开始一定要清0
    if(l == r){
		tree[root].sum = arr[l];
        return ;
    }
    else{
    	int mid = (l+r)>>1;
	    build(l,mid,root<<1);
	    build(mid+1,r,root<<1|1);
	    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
	    return ;
    }
}

void updata(int l,int r,int root,int val){
	if(tree[root].l>r || tree[root].r<l){
		return ;
	}
    if(l <= tree[root].l && r >= tree[root].r){
        tree[root].sum += (tree[root].r-tree[root].l+1)*val;
        tree[root].add += val;//延时标记
        return ;
    }
    pushdown(root);
    updata(l,r,root<<1,val);
    updata(l,r,root<<1|1,val);
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    return ;
}
void query(int l,int r,int root){
	if(tree[root].l>r || tree[root].r<l){
		return ;
	}
    if(l <= tree[root].l && r >= tree[root].r){
    	ans+=tree[root].sum;
        return ;
    }
    pushdown(root);
    query(l,r,root<<1);
    query(l,r,root<<1|1);
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    return ;
}
int main()
{
    int n,m,q,x,y;
    int num;
    char op;
    while(~scanf("%d%d",&n,&m)){
    	for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		build(1,n,1);
		while(m--){
			getchar();
			scanf("%c",&op);
			if(op=='Q'){
				ans=0;
				scanf("%d%d",&x,&y);
				query(x,y,1);
				printf("%d\n",ans);
			}
			else{
				scanf("%d%d%d",&x,&y,&num);
				updata(x,y,1,num);
			}
		}
    }
    return 0;
}
