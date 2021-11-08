#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<windows.h>
#include<queue>
using namespace std;
char dp[1001][1001];char ul[1001][1001];
int n;int x;queue<int>qx;queue<int>qy;
void ghi()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		cout<<ul[i][j]<<" ";
		cout<<"\n";
		cout<<"\n";
	}
}
void ghingam()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		cout<<dp[i][j]<<" ";
		cout<<"\n";
		cout<<"\n";
	}
}
void set()
{
	n=9;
	srand(time(0));
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			dp[i][j]='.';ul[i][j]='0';
		}
	}
	x=10;
//	cout<<x<<" ";
	for(int i=1;i<=x;i++)
	{
		c:;
		int p=rand()%10+1;
		int q=rand()%10+1;
		if(p>=10)p--;
		if(q>=10)q--;
		if(ul[p][q]=='x')
		goto c;
		ul[p][q]='x';
	}// 
	int sl=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sl=0;
			if(ul[i][j]!='x'){
			if(ul[i+1][j]=='x') sl++; 
			if(ul[i][j+1]=='x') sl++; 
			if(ul[i+1][j+1]=='x') sl++; 
			if(ul[i+1][j-1]=='x') sl++; 
			if(ul[i][j-1]=='x') sl++; 
			if(ul[i-1][j]=='x') sl++; 
			if(ul[i-1][j+1]=='x') sl++; 
			if(ul[i-1][j-1]=='x') sl++;
			ul[i][j]=(char)(sl+48);}
			 
		}
	} // */
	//ghi();
//	ghingam();
}
int a[9]={0,1,0,-1,0,1,1,-1,-1};
int b[9]={0,0,1,0,-1,1,-1,1,-1};
int nx,ny;int dd[1000][1000];
void fill()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if(ul[i][j]=='x')
			dd[i][j]=2;
			else if(ul[i][j]=='0')
			dd[i][j]=0;
			else
			dd[i][j]=1;
		}
	}
}
void bfs(int x,int y)
{
	int z,t;
	qx.push(x);qy.push(y);dd[x][y]=1;
	while(!qx.empty()&&!qy.empty())
	{
		z=qx.front();t=qy.front();
		qx.pop();qy.pop();
		for(int i=1;i<=9;i++)
		{
			z=z+a[i];
			t=t+b[i];
			if(ul[z][t]=='x');
			else
			dp[z][t]=ul[z][t];
			if(dd[z][t]==0&&(ul[z][t]=='0'&&z>=1&&t>=1&&z<=9&&t<=9)){
			dd[z][t]=1;
			dp[z][t]=ul[z][t];
			qx.push(z);qy.push(t);
			}
			z=z-a[i];
			t=t-b[i];
		}		
	}
}
bool kt()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
		if(ul[i][j]!=dp[i][j]&&ul[i][j]!='x')
		return false;
		if(ul[i][j]!='x'&&dp[i][j]=='?')
		return false;
		}
	}
	return true;
}
void play()
{
	//ghi();
	ghingam();
	char danhdau;
	bool chet=false;
	while(!chet)
	{	
		nhap:;
		cin>>nx>>ny;
		cin>>danhdau;
		if(danhdau=='?')
		{dp[nx][ny]=danhdau;
		system("cls");ghingam();continue;}
		else if(danhdau=='!'){
		if(nx>9||ny>9||nx<1||ny<1)
		{
			system("cls");
			ghingam();
			continue;
		}
		if(ul[nx][ny]!='x')
		{
			system("cls");
			if(ul[nx][ny]=='0')
			{
				bfs(nx,ny);	
			}
			dp[nx][ny]=ul[nx][ny];
			ghingam();
		}
		else
			chet=true;
		}
		else
		continue;
		if(kt()==true)
		{
			cout<<"You win!\n";
			return;
		}
	}
	system("cls");
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if(ul[i][j]=='x')
			cout<<ul[i][j]<<" ";
			else
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
		cout<<"\n";
	}
	cout<<"You lose\n";
	
}
void display()
{
	start:;
	system("cls");
	cout<<"          MINESWEEPER ( 9 * 9 )\n";
	cout<<"\n"<<"\n"<<"Press 1 to play\n";	
	cout<<"\n"<<"\n"<<"Press 2 to view introduction\n";
	cout<<"\n"<<"\n"<<"Press 3 to exit\n";
	Sleep(500);
	char press='0';
	cin>>press;
	if(press=='1')
	{
		system("cls");
		play();
	}	
	else if(press=='2')
	{
		system("cls");
		cout<<"       INTRODUCTION:\n";
		cout<<"Nhap x,y tuong ung voi hang x,cot y\n";
		cout<<"Nhap t de chon\n";
		cout<<"Neu t= ! thi do la chon luon\n";		
		cout<<"Neu t= ? thi do la dat co\n";
		cout<<"\n"<<"\n"<<"nhan phim bat ki de tiep tuc\n";
		char pq;
		cin>>pq;
		goto start;	
	}
	else if(press=='3')
	exit(0);
	else
	goto start;	
}
main()
{
	char a;
	while(1){
	clock_t start=clock();
	//input();
	set();
	fill();
	display();
	clock_t finish=clock();
	double x=(finish-start)/1000;
	cout<<x<<"\n";
	n:;
	cout<<"co choi nua khong? (y/n)\n";
	cin>>a;
	if(a=='y')
	continue;
	else if(a=='n')
	{
		display();
	}
	else
	goto n;
	}
}
