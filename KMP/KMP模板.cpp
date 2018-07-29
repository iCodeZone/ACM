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
int ans,next[N]; 

void GetNext(char *p){
	int plen,k,j;
	plen=strlen(p),k=-1,j=0;
	mem(next,0),next[0]=-1; 
	while(j<plen){
		//p[k]表示前缀，p[j]表示后缀
		if(k==-1||p[j]==p[k]){
			++k,++j;
			if(p[j]!=p[k]){
				next[j]=k;
			}
			else{
				//因为不能出现p[j]==p[next[j]],所以当出现时需要继续递归,k=next[k]=next[next[k]]
				next[j]=next[k];
			}
		} 
		else{
			k=next[k];
		}
	}
}

int KMP(char* s,char* p){
	GetNext(p);
	int i,j,slen,plen;
	i=0,j=0;
	slen=strlen(s),plen=strlen(p);
	while(i<slen&&j<plen){
		//如果j=-1,或者当前字符匹配成功,都令i++,j++
		if(j==-1||s[i]==p[j]){
			i++,j++;
		}
		else{
			//如果j != -1,且当前字符匹配失败,则令 i 不变,j=next[j]
            //next[j]即为j所对应的next值
            j=next[j];
		}
		//找有几组满足的 
		if(j==plen){
			ans++;
			j=next[j];
		}
	}
	if(j==plen){ 
		return i-j;//最后一个位置 
	}
	else{
		return -1;
	}
}

int main(){
	return 0;
}

