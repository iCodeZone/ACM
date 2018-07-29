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
#define d(a) cout<<a<<endl
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
const double eps = 1e-8;

int nxt[N];
char a[N],b[N];
//符串均从下标0开始
void Getnxt(char *T,int *nxt){
	mem(nxt,0);
	for(int i=1,j=0,len=strlen(T);i<len;i++){
		while(j&&T[i]!=T[j]) j=nxt[j-1];
		if(T[i]==T[j]) j++;
		nxt[i]=j;
	}
}

int KMP(char *S,char *T,int *nxt){
	Getnxt(T,nxt);
	int ans=0,slen=strlen(S),tlen=strlen(T);
	for(int i=0,j=0;i<slen;i++){
		while(j&&S[i]!=T[j]) j=nxt[j-1];
		if(S[i]==T[j]) j++;
		if(j==tlen){
			ans++;
		}
	} 
	return ans;
} 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",a,b);
		printf("%d\n",KMP(a,b,nxt));
	}
	return 0;
}

