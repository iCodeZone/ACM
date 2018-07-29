/****************************************************************************
��״���� ( Binary Indexed Tree��BIT������������ )

ģ��ʾ�� by ouzheng 2017.2.16

��״����Ļ�����һ�������������ʽ��:C[i]=A[i]+A[i-1]+....+A[i-2^k+1];k����i�Ķ����Ƶ��������0�ĸ��� ���� ����1000��101000��k=3��

���ԣ�
1.�������������±�x��y(x < y)�����x + 2^k = y (k����x�Ķ����Ʊ�ʾ��ĩβ0�ĸ���)����ô����(y, x)Ϊһ�����ϵĸ��ӹ�ϵ������yΪ����㣬xΪ�ӽ�㡣

��Ҫ������
1��add( x,value)(1<=x<=n)		�Ե�i��Ԫ�ص�ֵ����value       O(logn)
2��sum( x )   (1<=x<=n)			ͳ��[1...x]Ԫ��ֵ�ĺ�          O(logn)

Example Array(size = 10):
10 11 25 36 98 456465 21254 8 66 15451 
****************************************************************************/

#include <iostream>
using namespace std;

#define MAX_NUM 500 
#define lowbit(x) (x&(-x))
//lowbit(k)���ǰ�k�Ķ����Ƶĸ�λ1ȫ����գ�ֻ�������λ��1,����10�Ķ�������1010,��lowbit(k)=lowbit(1010)=0010(2����)

void print_Array(int* Array, int printSize, int beginPos = 1);
void add(int x, int value);
int sum(int* Array, int x);

int A[MAX_NUM];
int arraySize;
int BitTree[MAX_NUM];

int main()
{
	cout << "******************************Binary Indexed Tree**************************" << endl << endl;
	cout << "********************************Example Start******************************" << endl << endl;
	cout << "Please input the array size( <=500 ):" << endl;

	cin >> arraySize;
	cout << endl;
	cout << "Please input the array num( <=1000000 ):" << endl;

	for (int i = 1; i <= arraySize; ++i)
	{
		cin >> A[i];
	}

	//print_Array(A, arraySize);

	for (int i = 1; i <= arraySize; ++i)
	{
		BitTree[i] = 0;
		for (int j = i; (j >= (i - lowbit(i)+1)) && (j>=0); j--)
		{
			BitTree[i] += A[j];
		}
	}
	cout << "the Binary Indexed Tree:" << endl;
	print_Array(BitTree, arraySize);

	int Index = 0;
	cout << "Please input the array Sum Index:" << endl;
	cin >> Index;

	cout << "The Sum :" << endl;
	cout << sum(BitTree, Index) << endl;

	int addIndex = 0;
	int addValue = 0;
	cout << "Please input the array add Index:" << endl;
	cin >> addIndex;

	cout << "Please input the array add Value:" << endl;
	cin >> addValue;

	add(addIndex, addValue);

	cout << "Fresh Binary Indexed Tree:" << endl;
	print_Array(BitTree, arraySize);

	cout << "********************************Example End******************************" << endl << endl;

	return 0;
}

void print_Array(int* Array, int printSize, int beginPos)
{
	for (int i = beginPos; i <= printSize; ++i)
	{
		cout << Array[i] << " ";
		if (i % 20 == 19)
			cout << endl;
	}
	cout << endl<<endl;
}

void add(int x, int value)
{//ԭʼ���ݱ仯 ֻ��Ӱ�� x���������״����ֵ
	while (x <= arraySize)
	{
		BitTree[x] += value;
		x += lowbit(x);
	}
}

int sum(int* Array, int x)
{
	int Sum = 0;

	for (int i = x; i; i-= lowbit(i))
	{
		Sum += Array[i];
	}

	return Sum;
}