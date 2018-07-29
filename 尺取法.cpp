int a[N];
int l=0,r=0,vla=0;
while(r没有越界){
	if(val+a[r]<=key){//加上a[r]是否满足条件 
		val+=a[r];
		r++;//更新右端点，满足条件的区间为[l,r) 
	}
	else{
		val-=a[l];
		l++;//左端点左移 
	} 
} 
