#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream file1;
	int count=0,i,e=0,flag=0,flagc=0;
	file1.open("file1.txt");
	string a;
	while(e!=1)
	{
		getline(file1,a);
		for(i=0;i<a.length();i++)
		{
			if(a[i]==' ')
			continue;
			else if(a[i]=='/' && a[i+1]=='/' && flag==0)
			i=a.length();
			else if(flag==1 && a[i]=='*' && a[i+1]=='/')
			{
				flag=0;
				i=i+1;
			}
			else if(flag==0 && a[i]=='/' && a[i+1]=='*')
			{
				flag=1;
				i=i+1;
			}
			else if(flagc==0 && flag==0)
			{
				flagc=1;
				count++;
			}
		}
		flagc=0;
		e=file1.eof();
	}
	cout<<count;
	return 0;
}
