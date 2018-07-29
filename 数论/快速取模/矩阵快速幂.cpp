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

const int N = 3;
const int mod = 1000000000 + 7;

struct node{
	int m[N][N];
};

node Mul(node a,node b){
	node c;
	mem(c.m,0);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a.m[i][j]){
				for(int k=0;k<N;k++){
					c.m[i][k]=(c.m[i][k]+(a.m[i][j]*b.m[j][k])%mod+mod)%mod;
				}
			}
		}
	}
	return c;
} 

node quickmod(node a,int b){
	node res;
	mem(res.m,0);
	for(int i=0;i<N;i++){
		res.m[i][i]=1;
	}
	while(b){
		if(b&1){
			res=Mul(res,a);
		}
		a=Mul(a,a);
		b>>=1;
	}
	return res;
}

int main(){
	return 0;
}
