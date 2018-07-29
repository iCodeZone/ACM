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

const int N = 1000000 + 5;
const int mod = 1000000000 + 7;
int euler[N],t,n,num,cas=0;
LL ans;

void Geteuler(){
	mem(euler,0);
	euler[1]=1;
	for(int i=2;i<=N;i++){
		if(!euler[i]){
			for(int j=i;j<=N;j+=i){
				if(!euler[j]) euler[j]=j,
				euler[j]=euler[j]/i*(i-1);
			}
		}
	}
}

int main(){
	Geteuler();
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			if(num==1){
				ans+=2;
				continue;
			}
			for(int j=num;;j++)
				if(euler[j]>=num){
					ans+=j;
					break;
				}
		}
		printf("Case %d: %lld Xukha\n",++cas,ans);
	}
	return 0;
}
