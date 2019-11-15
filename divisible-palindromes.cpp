#include<iostream>
using namespace std;

int palin(int x[], int length)
{
	int back=31-length+1,front=31;
	int count=length/2;
	while(count--)
	{
		if(x[front]!=x[back])
		return 0;
		else
		{
			front--;
			back++;
		}
	}
	return 1;
}
int leng(int *p)
{
	int count2=0;
	for(int i=0;i<32;i++)
	{
		if(*p!=0)
		break;
		else
		count2++;
		p++;
	}
	return count2;
}
int main()
{	
	int a[32]={0},i,len,count=0;
	a[31]=9;
	a[30]=1;
	a[24]=1;
	do
	{
		len=32-leng(a);
		if(palin(a,len))
		{
			/*for(i=31-len+1;i<32;i++)
			cout<<a[i];
			cout<<endl;*/
			count++;
		}
			a[31]+=9;
			for(int i=31;i>0;i--)
			{
				if(a[i]>=10)
				{
					a[i-1]+=a[i]/10;
					a[i]%=10;
				}	
			}
			a[30]+=1;
			for(int i=30;i>0;i--)
			{
				if(a[i]>=10)
				{
					a[i-1]+=a[i]/10;
					a[i]%=10;
				}	
			}
			a[24]+=1;
			for(int i=24;i>0;i--)
			{
				if(a[i]>=10)
				{
					a[i-1]+=a[i]/10;
					a[i]%=10;
				}	
			}
	}while(a[0]!=1);
	cout<<count;
	return 0;
}
