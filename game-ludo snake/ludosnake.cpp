#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<iomanip>
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
	char ch;
	ch=24;
	gotoxy(11,58);changeColor(12);cout<<"START";
	gotoxy(13,57);cout<<ch;
	ch=27;
	gotoxy(4,8);changeColor(12);cout<<"END"<<ch;
	changeColor(15);
	clear_area(0,59,50);
	clear_area(0,60,50);
	clear_area(0,61,50);
}
void boardbg(){
	for(int i=0;i<50;i++){
		gotoxy(9,i+6);cout<<" ";
		gotoxy(80,i+6);cout<<" ";
	}
	for(int i=9;i<81;i++){
		gotoxy(i,5);cout<<" ";
		gotoxy(i,56);cout<<" ";
	}
}
void dicebg(){
	changeColor(127);
	for(int i=0;i<5;i++){
		gotoxy(100,i+20);cout<<"       ";
	}
}
void showdice(int x){
	dicebg();
	char ch=2;
	if(x==1){
		gotoxy(103,22);cout<<ch;	
	}else if(x==2){
		gotoxy(102,22);cout<<ch;
		gotoxy(104,22);cout<<ch;
	}else if(x==3){
		gotoxy(103,22);cout<<ch;
		gotoxy(105,21);cout<<ch;
		gotoxy(101,23);cout<<ch;
	}else if(x==4){
		gotoxy(102,21);cout<<ch;
		gotoxy(102,23);cout<<ch;
		gotoxy(104,21);cout<<ch;
		gotoxy(104,23);cout<<ch;
	}else if(x==5){
		gotoxy(103,22);cout<<ch;
		gotoxy(101,21);cout<<ch;
		gotoxy(105,21);cout<<ch;
		gotoxy(101,23);cout<<ch;
		gotoxy(105,23);cout<<ch;
	}else if(x==6){
		gotoxy(102,21);cout<<ch;
		gotoxy(102,22);cout<<ch;
		gotoxy(102,23);cout<<ch;
		gotoxy(104,21);cout<<ch;
		gotoxy(104,22);cout<<ch;
		gotoxy(104,23);cout<<ch;
		
	}
}

void rolldice(){
	Sleep(100);
	showdice(3);
	Sleep(250);
	showdice(5);
	Sleep(250);
	showdice(1);
	Sleep(250);
	showdice(4);
	Sleep(250);
	showdice(6);
	Sleep(250);
	showdice(2);
	Sleep(250);
	showdice(5);
	Sleep(250);
	showdice(1);
	Sleep(250);
	showdice(3);
	Sleep(250);
}
void coin(int x,int y){
	char ch=2;
	gotoxy(x-2,y-1);cout<<" \\|/ ";
	gotoxy(x-2,y);cout<<"--"<<ch<<"--";
	gotoxy(x-2,y+1);cout<<" /|\\ ";
}
void ch_color(int i){
	if(i==0)
		changeColor(12);
	if(i==1)
		changeColor(9);	
	if(i==2)
		changeColor(14);	
	if(i==3)
		changeColor(10);	
	
}
class Coins{
public:
	int coinp,ca,c,colorno,coincolor;
	string color;
	void showcoin(){
		if(coinp!=0&&coinp!=100){
			int x,y;
			x=cellx(coinp);
			y=celly(coinp);
			if(coinp==1)
				changeColor(coincolor);
			else if(coinp%2==0)
				changeColor(coincolor);
			else if(coinp%2==1)
				changeColor(coincolor);
			coin(x,y);
		}else if(coinp==0){
			changeColor(coincolor);
			coin(18+colorno*5,60);
		}else if(coinp==100){
			changeColor(coincolor);
			coin(10+colorno*5,2);
		}
	}
};
int main(){
	hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
	SetConsoleScreenBufferSize(hConsole, {155,65});
	
	Coins C[4];
	C[0].color="RED";
	C[1].color="BLUE";
	C[2].color="YELLOW";
	C[3].color="GREEN";
coinchoice:
	for(int i=0;i<=3;i++){
		ch_color(i);
		cout<<"\n\n\n\t\t\t\t"<<C[i].color<<" COIN :\n\t\t\t1. HUMAN\n\t\t\t2. CPU\n\t\t\t0. DO NOT INCLUDE\n\t\t\t\t\t\tPRESS UR CHOICE AND HIT ENTER ";
		cin>>C[i].ca;
	}
	system("cls");
	if(C[0].ca==0&&C[1].ca==0&&C[2].ca==0&&C[3].ca==0){
		cout<<"WRONG COMBINATION\a\a\a\a\a\a\tTRY AGAIN";
		Sleep(1000);
		goto coinchoice;
	}
	if((C[0].ca==1||2)&&C[1].ca==0&&C[2].ca==0&&C[3].ca==0){
		cout<<"WRONG COMBINATION\a\a\a\a\a\a\tTRY AGAIN";
		Sleep(1000);
		goto coinchoice;
	}
	if(C[0].ca==0&&(C[1].ca==1||2)&&C[2].ca==0&&C[3].ca==0){
		cout<<"WRONG COMBINATION\a\a\a\a\a\a\tTRY AGAIN";
		Sleep(1000);
		goto coinchoice;
	}
	if(C[0].ca==0&&C[1].ca==0&&(C[2].ca==1||2)&&C[3].ca==0){
		cout<<"WRONG COMBINATION\a\a\a\a\a\a\tTRY AGAIN";
		Sleep(1000);
		goto coinchoice;
	}
	if(C[0].ca==0&&C[1].ca==0&&C[2].ca==0&&(C[3].ca==1||2)){
		cout<<"WRONG COMBINATION\a\a\a\a\a\a\tTRY AGAIN";
		Sleep(1000);
		goto coinchoice;
	}
	for(int i=0;i<=3;i++){
		C[i].coinp=0;
		C[i].colorno=i;
	}
	C[0].coincolor=207;
	C[1].coincolor=159;
	C[2].coincolor=224;
	C[3].coincolor=160;
	board();
	for(int i=0;i<=3;i++){
		C[i].showcoin();
	}
	showdice(1);
	for(int i=0;i<=3;i++){
		if(C[i].ca==1||C[i].ca==2){
			gotoxy(90,40+2*i);ch_color(i);cout<<setw(18)<<C[i].color<<" COIN : "<<C[i].coinp<<" ";
		}
	}
	int j=0;
coin:
	if(C[j].ca==1||C[j].ca==2){
		gotoxy(90,4);ch_color(j);cout<<C[j].color<<"'s Turn<>>>";
		gotoxy(90,6);cout<<"Press SPACE key to roll dice";
		changeColor(C[j].coincolor);for(int i=0;i<=10;i++){
			gotoxy(133,15+i);cout<<"                   ";
		}
		boardbg();
		if(C[j].ca==1)
			getch();
		srand(time (NULL) ); 
		C[j].c=rand() % 6 + 1;
		clear_area(90,6,35);
		gotoxy(90,6);ch_color(j);cout<<"  ROLLING <<<..";
		rolldice();
		showdice(C[j].c);
		gotoxy(105,30);ch_color(j);cout<<"+"<<C[j].c<<"\a";
		if(C[j].coinp==0){
			if(C[j].c==1)
				C[j].coinp=C[j].coinp+C[j].c;
		}else if(C[j].coinp>100-C[j].c){
			C[j].coinp=C[j].coinp;
		}
		else{
			C[j].coinp=C[j].coinp+C[j].c;
		}
		Sleep(2000);
		gotoxy(90,40+2*j);ch_color(j);cout<<setw(18)<<C[j].color<<" COIN : "<<C[j].coinp<<" ";
		if(C[j].coinp==100)
			C[j].ca=0;
		if(C[j].coinp!=0&&C[j].coinp!=100){
			for(int i=0;i<=3;i++){
				if(i!=j){
					if(C[j].coinp==C[i].coinp){
						C[i].coinp=0;
						gotoxy(90,40+2*i);ch_color(i);cout<<setw(18)<<C[i].color<<" COIN : "<<C[i].coinp<<" \a\a\a";
					}
				}
			}
		}
		board();
		for(int i=0;i<=3;i++){
				C[i].showcoin();
		}
		clear_area(90,6,35);
		clear_area(90,4,35);
		clear_area(105,30,4);
		Sleep(900);
	}
	if((C[j].ca==1||C[j].ca==2)&&(C[j].c==1||C[j].c==6))
		goto coin;
	j=(j+1)%4;//j++, j%4;
if((C[0].ca==0&&C[1].ca==0&&C[2].ca==0)||(C[1].ca==0&&C[2].ca==0&&C[3].ca==0)||(C[2].ca==0&&C[3].ca==0&&C[0].ca==0)||(C[3].ca==0&&C[0].ca==0&&C[1].ca==0)){
		gotoxy(100,27);cout<<"GAME FINISHED  RESTART??(y/n)";
		char cha;
		cha=getch();
		if(cha=='y'){
			system("cls");
			system("ludosnake.exe");
		}
		exit(0);	
}
	goto coin;

}
