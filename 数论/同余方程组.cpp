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
#include<ctime>

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

const int N = 1000000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;

LL exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL r=exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return r;
} 
//�й�ʣ�ඨ��  r[]�������  a[]����������ʵĳ���
/*��ģ���������ʣ����ǿ������й�ʣ�ඨ�����⡣ 
���������ȿ����������̣�
x��r1(moda1)
x��r2(moda2)
���ǿ���д��:
x+y1a1=r1
x-y2a2=r2

����ã�y1a1+y2a2=r1-r2Ҳ����ax+by=m����ʽ�� 
���ǿ�������չŷ����½�ġ� 
��gcd(a,b)/|m��ô���̾��޽⣬ֱ�����-1�� 
�������ǿ��Խ����ʽ��y1���ش��õ�һ���ؽ�x0=r1-y1a1�� 
ͨ�����д��x=x0+k*lcm(a1,a2)Ҳ����x��x0(mod lcm(a1,a2))�� 
�������Ǿͽ��������̺ϲ�Ϊ��һ�����ظ��������ϲ��������������ܽ�n������ȫ���ϲ���������չŷ���µý�����ͺ��ˡ�
*/
LL solve(LL a[],LL r[],int n){
	LL M=a[1],R=r[1],x,y,d,temp;
	for(int i=2;i<=n;i++){
		d=exgcd(M,a[i],x,y);
		if((R-r[i])%d!=0) return -1;//�޽� 
		temp=a[i]/d;  
        x=(R-r[i])/d*x;//�ؽ�x1��  
        x=(x%temp+temp)%temp;  
		R-=x*M;//�ؽ�x0���µ�������
		M=M/d*a[i];////�µ�ģ����
		R%=M;
	}
	return R==0?M:(R%M+M)%M;//����ȫΪ0���򷵻�lcm 
}

LL a[N],r[N];

int main(){
	int n,t,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&r[i]);
		}
		printf("Case %d: %lld\n",++cas,solve(a,r,n));
	}
	return 0;
}

