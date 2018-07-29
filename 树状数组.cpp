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
#include<climits>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
int tree[N];

int lowbit(int x){
	return x&-x;
} 

void add(int k,int num){
	while(k<=N){
		tree[k]+=num;
		k+=k&-k;
	}
}

int read(int k){
	int sum=0;
	while(k){
		sum+=tree[k];
		k-=k&-k;
	}
	return sum;
}

int main() {
	return 0;
}

