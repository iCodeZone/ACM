//��С��ʾ�� 
int getMin(int str[], int len)    
{    
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len)
    {  
        if(str[(i+k)%len]==str[(j+k)%len]) k++;
        else{
        	if(str[(i+k)%len]>str[(j+k)%len])
        		i=i+k+1;
        	else
        		j=j+k+1;
        	if(i==j) j++;
        	k=0;
        }
    }
    return min(i,j); 
}
//����ʾ��
int getMax(int str[], int len)    
{    
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len)
    {  
        if(str[(i+k)%len]==str[(j+k)%len]) k++;
        else{
        	if(str[(i+k)%len]<str[(j+k)%len])
        		i=i+k+1;
        	else
        		j=j+k+1;
        	if(i==j) j++;
        	k=0;
        }
    }
    return min(i,j); 
}
