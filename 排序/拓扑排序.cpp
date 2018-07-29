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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
int indeg[N],ans[N],n,k;//保存入度和拓扑后的答案 
bool mp[N][N];//保存有向图 
bool flag;

void topo(){
	k=1,flag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(indeg[j]==0){
				indeg[j]=-1;
				ans[k++]=j;
				for(int k=1;k<=n;k++){
					if(mp[j][k]){
						indeg[k]--;
					}
				}
				break;
			}
			if(j>=n){
				flag=0;
				return ;
			}
		}
	}
} 

int main(){
	return 0;
}

