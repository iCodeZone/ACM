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

void qsort(int a[],int left,int right)
{
    int t;
    if(left>=right)
    return;
    int temp=a[left];
    int i=left;
    int j=right;
    while(i<j){
        while(a[j]>=temp&&i<j)j--;
        while(a[i]<=temp&&i<j)i++;
        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;
    qsort(a,left,i-1);
    qsort(a,i+1,right);
}
int main(){
    return 0;
}
