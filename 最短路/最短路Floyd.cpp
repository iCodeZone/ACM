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
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
int dis[N][N],path[N][N],n;

void Floyd(int a[][N])
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			path[i][j]=-1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]>a[i][k]+a[k][j]){
					a[i][j]=a[i][k]+a[k][j];
					path[i][j]=k;
				}
			}
		}
	}
} 

int main(){ 
	return 0;
}
