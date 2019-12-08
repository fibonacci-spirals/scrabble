#include<iostream.h>
#include<conio.h>
struct word
{
	char value1,value2;
}s1,s2,s3,s4;

void main()
{
	clrscr();
	s1.value1='T';
	s1.value2='L';
	s2.value1='D';
	s2.value2='W';
	s3.value1='T';
	s3.value2='W';
	s4.value1='D';
	s4.value2='L';
	int a[100],i,j,k;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<" ";
			cout<<"---";
		       //	cout<<" ";
		}
		cout<<"\n";
		for(k=0;k<9;k++)
		{
		      cout<<"|";
			if(i==4 && k==4)
			cout<<" # ";
			else if((i==2 || i==6) && (k==2 || k==6))
			cout<<" "<<s1.value1<<s1.value2;
			else if((i==1 || i==7) && (k==1 ||k==7))
			cout<<" "<<s2.value1<<s2.value2;
			else if((i==0 || i==4 || i==8 ) && (k==0  || k==4 ||k==8))
			cout<<" "<<s3.value1<<s3.value2;
			else if(((i==0 ||i==4||i==8) && (k==2 || k==6))|| ((i==2 ||i==6)&& (k==0||k==8))||((i==3||i==5)&&(k==3||k==5)))
			cout<<" "<<s4.value1<<s4.value2;
			else
			cout<<"   ";
		       //	cout<<"|";

		}cout<<"|";
		cout<<"\n";
	}
	for(k=0;k<9;k++)
	{
		cout<<" ";
		cout<<"---";
	       //	cout<<" ";
	}
	getch();
}