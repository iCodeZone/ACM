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

int main(){
	int n;
	double x1,x2,x3,x4,y1,y2,y3,y4,x,y;
	scanf("%d",&n);
	puts("INTERSECTING LINES OUTPUT");
	while(n--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if((y2-y1)*(x3-x4)==(x2-x1)*(y3-y4)){
			if((y3-y1)*(x2-x4)==(x3-x1)*(y2-y4)&&(y4-y1)*(x3-x2)==(x4-x1)*(y3-y2)){
				puts("LINE");
			}
			else{
				puts("NONE");
			}
		}
		else{
			double k1=(y2-y1)/(x2-x1),k2=(y4-y3)/(x4-x3);
			x=(y3-k2*x3-y1+k1*x1)/(k1-k2);
			if(x1==x2){
				x=x1;
				y=k2*(x-x3)+y3;
			}
			else if(x3==x4){
				x=x3;
				y=k1*(x-x1)+y1;
			}
			else{
				y=k1*(x-x1)+y1;
			}
			printf("POINT %.2f %.2f\n",x,y);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
