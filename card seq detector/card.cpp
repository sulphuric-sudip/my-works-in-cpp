#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void cardface(int x){
	for(int i=11;i<=23;i++){
		gotoxy(x,i);cout<<"               ";
	}
}
class cards{
public:	
	int n,c,r;
	char ch;
	
	
	void diamond(int x){
		changeColor(252);
		cardface(x);
		ch=4;
		gotoxy(x+1,13);cout<<ch;
		gotoxy(x+13,21);cout<<ch;
		gotoxy(x+5,16);cout<<ch;
		gotoxy(x+9,16);cout<<ch;
		gotoxy(x+5,18);cout<<ch;
		gotoxy(x+9,18);cout<<ch;
		gotoxy(x+7,17);cout<<ch;
	}
	void heart(int x){
		changeColor(252);
		cardface(x);
		ch=3;
		gotoxy(x+1,13);cout<<ch;
		gotoxy(x+13,21);cout<<ch;
		gotoxy(x+5,16);cout<<ch;
		gotoxy(x+9,16);cout<<ch;
		gotoxy(x+5,18);cout<<ch;
		gotoxy(x+9,18);cout<<ch;
		gotoxy(x+7,17);cout<<ch;	
	}
	void club(int x){
		changeColor(240);
		cardface(x);
		ch=5;
		gotoxy(x+1,13);cout<<ch;
		gotoxy(x+13,21);cout<<ch;
		gotoxy(x+5,16);cout<<ch;
		gotoxy(x+9,16);cout<<ch;
		gotoxy(x+5,18);cout<<ch;
		gotoxy(x+9,18);cout<<ch;
		gotoxy(x+7,17);cout<<ch;
	}
	void shade(int x){
		changeColor(240);
		cardface(x);
		ch=6;
		gotoxy(x+1,13);cout<<ch;
		gotoxy(x+13,21);cout<<ch;
		gotoxy(x+5,16);cout<<ch;
		gotoxy(x+9,16);cout<<ch;
		gotoxy(x+5,18);cout<<ch;
		gotoxy(x+9,18);cout<<ch;
		gotoxy(x+7,17);cout<<ch;
	}
	
	void display(int x){
		c=n/4;
		r=n%4;
		if(r==0){
			diamond(x);
		}
		else if(r==1){
			heart(x);
		}
		else if(r==2){
			club(x);
		}
		else if(r==3){
			shade(x);
		}
		gotoxy(x+1,12);
		if(c==8){
			cout<<"10";
			gotoxy(x+12,22);
			cout<<"10";
		}
		else if(c==9){
			cout<<"JJ";
			gotoxy(x+12,22);
			cout<<"JJ";
		}
		else if(c==10){
			cout<<"QQ";
			gotoxy(x+12,22);
			cout<<"QQ";
		}
		else if(c==11){
			cout<<"KK";
			gotoxy(x+12,22);
			cout<<"KK";
		}
		else if(c==12){
			cout<<"AA";
			gotoxy(x+12,22);
			cout<<"AA";
		}
		else{
			cout<<c+2;
			gotoxy(x+13,22);
			cout<<c+2;
		}
	}
};
class result{
public:	
		result(int N1,int N2, int N3){
		int c1,c2,c3;
		c1=N1/4;
		c2=N2/4;
		c3=N3/4;
		
		int r1,r2,r3;
		r1=N1%4;
		r2=N2%4;
		r3=N3%4;
		
		int alleq, serial, color, twoeq;
		alleq=0;
		serial=0;
		color=0;
		twoeq=0;
		if((c1==c2)&&(c2==c3))	
			alleq=1;
		if((c2-c1==1)&&(c3-c2==1))
			serial=1;
		if((c3==12)&&(c2==1)&&(c1==0))
			serial=1;
		if((r1==r2)&&(r2==r3))
			color=1;
		if((c1==c2)||(c2==c3))	
			twoeq=1;
		gotoxy(5,26);
		cout<<"PROCESSING.";Sleep(700);cout<<".";Sleep(700);cout<<".";Sleep(700);cout<<".";Sleep(700);
		gotoxy(5,26);cout<<"                                           ";
		cout<<"\n\tITS AN \n\t";
		
		if(alleq==1)
			cout<<"TRIEAL";
		else if(serial==1&&color==1)
			cout<<"DOUBLE RUN";
		else if(serial==1)
			cout<<"RUN";
		else if(color==1)
			cout<<"COLOR";
		else if(twoeq==1)
			cout<<"DOUBLE";
		else 
			cout<<"TOP";	
		
	}
};
void planecard(int x){
	changeColor(207);
	for(int i=11;i<=21;i++){
		gotoxy(x,i);cout<<"OXOXOXOXOXOXOXO";
	  gotoxy(x,i+1);cout<<"XOXOXOXOXOXOXOX";
	  i++;
	}
	gotoxy(x,23);cout<<"OXOXOXOXOXOXOXO";
}

int main(){
start:
	cards T1,T2,T3;
	int N[2];
	system("cls");
	planecard(5);
	planecard(30);
	planecard(55);
	changeColor(15);
	gotoxy(0,0);
	cout<<"Give 3 different card combination(1-52)(Dont repeat):\n";
	cin>>N[0]>>N[1]>>N[2];
	N[0]=N[0]-1;
	N[1]=N[1]-1;
	N[2]=N[2]-1;
	if((N[0]!=N[1])&&(N[0]!=N[2])&&(N[1]!=N[2])&&(N[0]>=0)&&(N[1]>=0)&&(N[2]>=0)&&(N[0]<52)&&(N[1]<52)&&(N[2]<52)){
				
		T1.n=N[0];
		T2.n=N[1];
		T3.n=N[2];
		Sleep(800);			
		T1.display(5);
		Sleep(500);
		T2.display(30);
		Sleep(500);
		T3.display(55);
		Sleep(500);
		changeColor(15);
		
		int temp;
		for(int i=0;i<2;i++){
			for(int j=i+1;j<3;j++){
				if(N[i]>N[j]){
					temp=N[i];
					N[i]=N[j];
					N[j]=temp;
				}					
			}
		}
		result R(N[0],N[1],N[2]);	
		
		cout<<"\nPress 'y' to try next.";
		char cin1;
		cin1=getch();
		if(cin1=='y')
			goto start;
		return 0;
	}
	else{
		for(int i=0;i<=4;i++){
			gotoxy(5,5);changeColor(12);cout<<"! Wrong Card Combination\a";
			Sleep(400);
			gotoxy(5,5);cout<<"                                        ";
			Sleep(200);
		}
		goto start;
	}
}
