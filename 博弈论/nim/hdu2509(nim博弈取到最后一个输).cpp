#include<bits/stdc++.h>
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

int main(){
	int n,ans,num;
	bool flag;
	while(~scanf("%d",&n)){
		ans=0,flag=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			ans^=num;
			if(num>1){
				flag=0;
			}
		}
		if(flag){
			if(n&1){
				puts("No");
			}
			else{
				puts("Yes");
			}
			continue;
		}
		if(ans==0){
			puts("No");
		}
		else{
			puts("Yes");
		}
	}
	return 0;
}
