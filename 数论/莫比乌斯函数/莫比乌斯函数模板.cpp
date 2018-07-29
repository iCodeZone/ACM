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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
int mu[N],prime[N],cnt;
bool vis[N];

void getMu(){//普通筛法O(nlogn)
	mem(mu,0);
	for(int i=1;i<N;i++){
		int target=(i==1)?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i){
			mu[j]+=delta;
		}
	}
}

void Init(){//线性筛O(n) 
	mem(mu,0),mem(prime,0),mem(vis,0);
	mu[1]=1,cnt=0;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt&&i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]) mu[i*prime[j]]=-mu[i];
			else{
				mu[i*prime[j]]=0;
				break;
			}
		}
	}
}

int main(){
	getMu();
	Init();
	return 0;
}

