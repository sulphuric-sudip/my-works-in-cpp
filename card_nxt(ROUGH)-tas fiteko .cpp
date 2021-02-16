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

class Card{
	int n,cn,cc;
	char ch;
public:
	void setno(int x){
		n=x;
	}
	void cardface(int x,int y){
		changeColor(252);
		for(int i=y;i<=y+12;i++){
			gotoxy(x,i);cout<<"               ";
		}
	}	
	void diamond(int x,int y){
		changeColor(252);
		ch=4;
		gotoxy(x+1,y+2);cout<<ch;
	  	gotoxy(x+13,y+10);cout<<ch;
		gotoxy(x+5,y+5);cout<<ch;
		gotoxy(x+9,y+5);cout<<ch;
		gotoxy(x+5,y+7);cout<<ch;
		gotoxy(x+9,y+7);cout<<ch;
		gotoxy(x+7,y+6);cout<<ch;
	}
	void heart(int x,int y){
		changeColor(252);
		ch=3;
		gotoxy(x+1,y+2);cout<<ch;
		gotoxy(x+13,y+10);cout<<ch;
		gotoxy(x+5,y+5);cout<<ch;
		gotoxy(x+9,y+5);cout<<ch;
		gotoxy(x+5,y+7);cout<<ch;
		gotoxy(x+9,y+7);cout<<ch;
		gotoxy(x+7,y+6);cout<<ch;	
	}
	void club(int x,int y){
		changeColor(240);
		ch=5;
		gotoxy(x+1,y+2);cout<<ch;
		gotoxy(x+13,y+10);cout<<ch;
		gotoxy(x+5,y+5);cout<<ch;
		gotoxy(x+9,y+5);cout<<ch;
		gotoxy(x+5,y+7);cout<<ch;
		gotoxy(x+9,y+7);cout<<ch;
		gotoxy(x+7,y+6);cout<<ch;
	}
	void shade(int x, int y){
		changeColor(240);
		ch=6;
		gotoxy(x+1,y+2);cout<<ch;
		gotoxy(x+13,y+10);cout<<ch;
		gotoxy(x+5,y+5);cout<<ch;
		gotoxy(x+9,y+5);cout<<ch;
		gotoxy(x+5,y+7);cout<<ch;
		gotoxy(x+9,y+7);cout<<ch;
		gotoxy(x+7,y+6);cout<<ch;
	}
	
	void display(int x,int y){
		n=n%52;
		cn=n/4;
		cc=n%4;
		cardface(x,y);
		if(cc==0){
			diamond(x,y);
		}
		else if(cc==1){
			heart(x,y);
		}
		else if(cc==2){
			club(x,y);
		}
		else if(cc==3){
			shade(x,y);
		}
		gotoxy(x+1,y+1);
		if(cn==8){
			cout<<"10";
			gotoxy(x+12,y+11);
			cout<<"10";
		}
		else if(cn==9){
			cout<<"JJ";
			gotoxy(x+12,y+11);
			cout<<"JJ";
		}
		else if(cn==10){
			cout<<"QQ";
			gotoxy(x+12,y+11);
			cout<<"QQ";
		}
		else if(cn==11){
			cout<<"KK";
			gotoxy(x+12,y+11);
			cout<<"KK";
		}
		else if(cn==12){
			cout<<"AA";
			gotoxy(x+12,y+11);
			cout<<"AA";
		}
		else{
			cout<<cn+2;
			gotoxy(x+13,y+11);
			cout<<cn+2;
		}
	}
};

int main(){
	hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
	SetConsoleScreenBufferSize(hConsole, {155,200});
	Card C[52],T[52];
	for(int i=0;i<=51;i++){
		C[i].setno(i);
	}
	srand(time (NULL) ); 
	for(int j=0; j<=51; j++){
		int k=rand() % 52;
		Card temp=C[j];
		C[j]=C[k];
		C[k]=temp;
	}
	for(int i=0;i<=25;i++){
		T[2*i]=C[i];
		T[2*i+1]=C[26+i];
	}
}
