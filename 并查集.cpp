//²¢²é¼¯
#include <iostream>
using namespace std;

const int N=1000005;
int F[N];

int Find(int x){
	return (x==F[x])?x:(F[x]=Find(F[x]));
}

void unite(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x!=y) F[x]=y;
}

int main(){
	
	return 0;
} 
