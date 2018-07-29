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

const int N = 65536*2;
const int mod = 1000000000 + 7;
int cover[N<<2],Xor[N<<2];
bool vis[N];
//0/1���� 
void upxor(int root){
	if(cover[root]!=-1) cover[root]^=1;//��ʾ�����������ͬʱת��
	else Xor[root]^=1;
}

void pushdown(int root){
	if(cover[root]!=-1){
		cover[root<<1]=cover[root<<1|1]=cover[root];
		Xor[root<<1]=Xor[root<<1|1]=0;//����ȫ��������ԭ����ת�����κ�������
		cover[root]=-1;
	}
	if(Xor[root]){//��ʾ�õ�ת���˵��Ǻ���δת��
		upxor(root<<1);
		upxor(root<<1|1);
		Xor[root]=0;
	}
}

void update(int ql,int qr,char op,int l,int r,int root){
	if(ql<=l&&qr>=r){
		if(op=='U') cover[root]=1,Xor[root]=0;//�� 
		if(op=='D') cover[root]=Xor[root]=0;//���� 
		if(op=='S'||op=='C') upxor(root);//�����ԳƲ� 
		return ;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,op,lson);
	else if(op=='I'||op=='C'){
		Xor[root<<1]=cover[root<<1]=0;
	}
	if(qr>mid) update(ql,qr,op,rson);
	else if(op=='I'||op=='C'){
		Xor[root<<1|1]=cover[root<<1|1]=0;
	}
}

void query(int l,int r,int root){
	if(cover[root]==1){
		for(int i=l;i<=r;i++){
			vis[i]=1;
		}
		return ;
	}
	else if(cover[root]==0) return ;
	if(l==r) return ;
	pushdown(root);
	int mid=(l+r)>>1;
	query(lson);
	query(rson);
}

int main(){
	cover[1]=Xor[1]=0;
	char op,l,r;
	int a,b;
	while(~scanf("%c %c%d,%d%c",&op,&l,&a,&b,&r)){
		a<<=1,b<<=1;
		if(l=='(') a++;
		if(r==')') b--;
		if(a>b){
			if(op=='C'||op=='I'){
				cover[1]=Xor[1]=0;
			}
		}
		else update(a,b,op,0,N,1);
		getchar();
		
	}
	query(0,N,1);
	bool flag=0;
	int s=-1,e;
	for(int i=0;i<=N;i++){
		if(vis[i]){
			if(s==-1) s=i;
			e=i;
		}
		else{
			//Sleep(100);
			if(s!=-1){
				if(flag) printf(" ");
				flag=1;
				printf("%c%d,%d%c",s&1?'(':'[',s>>1,(e+1)>>1,e&1?')':']');
				s=-1;
			}
		}
	}
	if(!flag) puts("empty set");
	return 0;
}
