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
int euler[N];
//筛法求欧拉函数 O(n)
void Geteuler(){
	mem(euler,0);
	euler[1]=1;
	for(int i=2;i<N;i++){
		if(!euler[i]){//这里出现的肯定是素数 
			for(int j=i;j<N;j+=i){//更新含有它的数 
				if(!euler[j]) euler[j]=j;//初始化为本身 
				euler[j]=euler[j]/i*(i-1);//先除后乘 
			}
		}
	}
} 

int main(){
	return 0;
}

