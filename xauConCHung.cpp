//bai tim xau con chung de bao ve
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
//int k[50][50]={0};
void taoBang(int k[50][50], char a[50], char b[50]){
int i,j;
for(i=0;i<strlen(a);i++)
    for(j=0;j<strlen(b);j++)
		    if(i==0||j==0) k[i][j]==0;
		else {
		//	if(a[i]!=b[j]) k[i][j]=max(k[i-1][j],k[i][j-1]);
		if(a[i]!=b[j]) k[i][j]=k[i-1][j] > k[i][j-1] ? k[i-1][j]:k[i][j-1];
			else {k[i][j]=k[i-1][j-1]+1; 
			}
		}
}
//xuat bang
void xuatbang(int k[50][50],char a[50],char b[50]){
	int i,j;
for(i=0;i<strlen(a);i++)
{
    for(j=0;j<strlen(b);j++)
        cout<<k[i][j]<<"  ";
        cout<<endl;
 }        
}
void truyna(int k[50][50], char a[50], char b[50]){
	int x=strlen(a)-1;
	int y=strlen(b)-1;
	char temp[50];int i=0;
	while(k[x][y]!=0){
		if(k[x][y] > k[x-1][y] && k[x-1][y]==k[x][y-1] && k[x-1][y-1]==k[x][y-1])
		{
		temp[i]=a[x];
		i++;
		x--;y--;
	    }
		else if(k[x][y]==k[x-1][y])
		{
			x--;
		}
		else if(k[x][y]==k[x][y-1])
		{
			y--;
		}
	}
	cout<<"\n"<<strrev(temp);	
}
main(){
	char a[50];
	char b[50];
fstream f;
f.open("in.txt");
f>>a;
f>>b;
f.close();
for(int i=strlen(a);i>=0;i--) swap(a[i],a[i+1]);
a[0]=' ';
for(int i=strlen(b);i>=0;i--) swap(b[i],b[i+1]);
b[0]=' ';
 int k[50][50]={0};
  taoBang(k,a,b);
  xuatbang(k,a,b);
  cout<<endl;
 truyna(k,a,b);
}
