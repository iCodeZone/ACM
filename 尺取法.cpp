int a[N];
int l=0,r=0,vla=0;
while(rû��Խ��){
	if(val+a[r]<=key){//����a[r]�Ƿ��������� 
		val+=a[r];
		r++;//�����Ҷ˵㣬��������������Ϊ[l,r) 
	}
	else{
		val-=a[l];
		l++;//��˵����� 
	} 
} 
