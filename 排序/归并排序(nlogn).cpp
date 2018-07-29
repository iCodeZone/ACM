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
int temp[N],num=0;

void Merge(int a[],int left,int mid,int right){
	//i开始为左半部分最左边，j为右半部分最左边，temp数组从0开始存数 
	int i=left,j=mid+1,cnt=0,length=right-left;
	while(i<=mid&&j<=right){
		if(a[i]>a[j]){//左边比右边大 
			temp[cnt++]=a[j++];
			num+=mid-i+1;//从i到mid都是比a[j]大 
		}
		else{
			temp[cnt++]=a[i++];
		} 
	} 
	while(i<=mid){
		temp[cnt++]=a[i++];
	}
	while(j<=right){
		temp[cnt++]=a[j++];
	}
	for(int k=0;k<=length;k++){//最后赋值到原数组 
		a[left+k]=temp[k];
	}
}

void mergesort(int a[],int left,int right){
	if(left<right){
		int mid=(left+right)>>1;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		Merge(a,left,mid,right); 
	}
}

int main(){
	int n,a[N];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}
