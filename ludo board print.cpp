#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>

HANDLE hConsole;

using namespace std;

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
void clear_area(int x, int y, int l){
	gotoxy(x,y);changeColor(15);for(int i=0;i<=l;i++)cout<<" ";
}
int cellx(int n){
	int r;
	n=n-1;
	r=n%10;
	n=n/10;
	if(n%2==0)
		return(r*7+13);
	else if(n%2!=0)
		return((9-r)*7+13);	
}
int celly(int n){
	n=n-1;
	n=n/10;
	return((9-n)*5+8);
}
void board(){
	for(int i=1;i<=100;i++){
		int x,y,d,r;
		x=cellx(i);
		y=celly(i);
		if(i==1)
			changeColor(172);
		else if(i==100)
			changeColor(234);
		else if(i%2==0)
			changeColor(240);
		else if(i%2==1)
			changeColor(208);
		gotoxy(x-3,y-2);cout<<"       ";
		gotoxy(x-3,y-1);cout<<"       ";
		gotoxy(x-3,y);  cout<<"       ";
		gotoxy(x-3,y+1);cout<<"       ";
		gotoxy(x-3,y+2);cout<<"       ";
		if(i<10){
			gotoxy(x,y);cout<<i;
		}else{
			d=i/10;
			r=i%10;
			gotoxy(x-1,y);cout<<d;
			gotoxy(x+1,y);cout<<r;
		}
	}
	changeColor(153);
	for(int i=0;i<50;i++){
		gotoxy(9,i+6);cout<<" ";
		gotoxy(80,i+6);cout<<" ";
	}
	for(int i=9;i<81;i++){
		gotoxy(i,5);cout<<" ";
		gotoxy(i,56);cout<<" ";
	}
	char ch;
	ch=24;
	gotoxy(11,58);changeColor(12);cout<<"START";
	gotoxy(13,57);cout<<ch;
	ch=27;
	gotoxy(4,8);changeColor(12);cout<<"END"<<ch;
	changeColor(15);
	clear_area(0,59,150);
	clear_area(0,60,150);
	clear_area(0,61,150);
}
int main(){
	hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
	SetConsoleScreenBufferSize(hConsole, {155,65});
	board();
}
