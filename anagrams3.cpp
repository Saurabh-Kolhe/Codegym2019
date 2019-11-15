#include<iostream>
#include<fstream>
using namespace std;
struct anagram
{
	string word;
	int pos;
}a[338882],b[338882],t;

int check(string s)
{
	int total=0,i;
	for(i=0;i<s.length();i++)
	total+=s[i];
	return total;
}
int main()
{
	fstream file2,filen;
	file2.open("file2.txt");
	//filen.open("filen.txt");
	int i,n=338882,j,k,total,len;
	string *s;
	for(i=0;i<n;i++)
	{
		getline(file2,a[i].word);
		b[i].word=a[i].word;
		a[i].pos=b[i].pos=i;
	}
	//cout<<"records scanned!"<<endl;
	//**********************
	for(i=0;i<n;i++)
	{
		for(j=0;j<a[i].word.length()-1;j++)
			{
				for(k=0;k<a[i].word.length()-1;k++)
				{
					if(a[i].word[k]>a[i].word[k+1])
					{
						int temp=a[i].word[k];
						a[i].word[k]=a[i].word[k+1];
						a[i].word[k+1]=temp;
					}
				}
			}
	}
	//cout<<"each word sorted!"<<endl;
	//********************
	for(i=0;i<n-1;i++)
	{
		cout<<i<<endl;
		for(j=0;j<n-1;j++)
		{
			if(a[j].word[0]>a[j+1].word[0])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	//cout<<"all words sorted!"<<endl;
	for(i=0;i<n;i++)
	{
		if(total!=check(b[a[i].pos].word) || len!=b[a[i].pos].word.length())
		{
			cout<<endl;
			cout<<b[a[i].pos].word;
			total=check(b[a[i].pos].word);
			len=b[a[i].pos].word.length();
		}
		cout<<" ";
		cout<<b[a[i].pos].word;
	}
	return 0;
}
