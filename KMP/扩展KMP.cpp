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
int nxt[N],extand[N];
char a[N],b[N];

void Getnxt(char *T,int *nxt){
	int len=strlen(T),a=0;
	nxt[0]=len;
	while(a<len-1&&T[a]==T[a+1]) a++;
	nxt[1]=a;
	a=1;
	for(int k=2;k<len;k++){
		int p=a+nxt[a]-1,L=nxt[k-a];
		if((k-1)+L>=p){
			int j=(p-k+1)>0?(p-k+1):0;
			while(k+j<len&&T[k+j]==T[j]) j++;
			nxt[k]=j;
			a=k;
		}
		else{
			nxt[k]=L;
		}
	}
}

void GetExtand(char *S,char *T,int *nxt){
	Getnxt(T,nxt);
	int slen=strlen(S),tlen=strlen(T),a=0;
	int MinLen=min(slen,tlen);
	while(a<MinLen&&S[a]==T[a]) a++;
	extand[0]=a;
	a=0;
	for(int k=1;k<slen;k++){
		int p=a+extand[a]-1,L=nxt[k-a];
		if((k-1)+L>=p){
			int j=(p-k+1)>0?(p-k+1):0;
			while(k+j<slen&&j<tlen&&S[k+j]==T[j]) j++;
			extand[k]=j;
			a=k;
		}
		else{
			extand[k]=L;
		}
	}
}

int main(){
	while(~scanf("%s%s",a,b)){
		GetExtand(a,b,nxt);
		for(int i=0;i<strlen(a);i++){
			printf("%d ",extand[i]);
		}
		puts("");
	}
	return 0;
}
