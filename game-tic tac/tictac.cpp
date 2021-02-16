#include<iostream>
#include<conio.h>
#include<windows.h>
#include<process.h>

using namespace std;

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
void clear_line(int x){
	gotoxy(0,x);changeColor(15);for(int i=0;i<80;i++)cout<<" ";
}
class position{
public:	
	int x,o,full;
	void display(){
		if(x==1){
			changeColor(14);cout<<"X";
		}
		if(o==1){
			changeColor(10);cout<<"O";
		}
	}
};
void gotocell(int y){
	if(y==1)
		gotoxy(37,3);
	if(y==2)
		gotoxy(41,3);
	if(y==3)
		gotoxy(45,3);
	if(y==4)
		gotoxy(37,5);
	if(y==5)
		gotoxy(41,5);
	if(y==6)
		gotoxy(45,5);
	if(y==7)
		gotoxy(37,7);
	if(y==8)
		gotoxy(41,7);
	if(y==9)
		gotoxy(45,7);
}
int result(int x9,int x0,int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8){
	if(x0==1&&x1==1&&x2==1)
		return 1;
	else if(x3==1&&x4==1&&x5==1)
		return 1;
	else if(x6==1&&x7==1&&x8==1)
		return 1;
	else if(x0==1&&x3==1&&x6==1)
		return 1;
	else if(x1==1&&x4==1&&x7==1)
		return 1;
	else if(x2==1&&x5==1&&x8==1)
		return 1;
	else if(x0==1&&x4==1&&x8==1)
		return 1;
	else if(x2==1&&x4==1&&x6==1)
		return 1;
}

int main(){
start:	
	system("cls");
	gotoxy(3,0);changeColor(15);cout<<"STARTING TIC_TAC -(: Press any key_";
	getch();
	clear_line(0);
	changeColor(13);
	gotoxy(35,2);cout<<"             ";
 	gotoxy(35,3);cout<<"  1 | 2 | 3  ";
 	gotoxy(35,4);cout<<" ---+---+--- ";
 	gotoxy(35,5);cout<<"  4 | 5 | 6  ";
 	gotoxy(35,6);cout<<" ---+---+--- ";
 	gotoxy(35,7);cout<<"  7 | 8 | 9  ";
 	gotoxy(35,8);cout<<"             ";
	
	changeColor(15);
 	gotoxy(0,11);for(int i=0;i<80;i++)cout<<"-";
 	gotoxy(3,12);changeColor(9);cout<<"SYSTEM IS UNDER CONSTRUCTION, SO GIVE ALL COMMAND AS ASKED>>>>";
	gotoxy(5,13);cout<<" Wrong input Will Terminate The Programme:";
	gotoxy(0,14);changeColor(15);for(int i=0;i<80;i++)cout<<"-";

	position P[10];
	int ip;
	for(int i=0;i<=9;i++){
		P[i].full=0;
		P[i].x=0;
		P[i].o=0;
	}
cross:
	clear_line(16);
	gotoxy(5,16);changeColor(14);cout<<"Its Cross's Turn. Enter cell no. to cross(1-9)(X): ";
	cin>>ip;
	if((ip>0)&&(ip<=9)){
		if(P[ip].full==0){
			P[ip].full=1;
			P[ip].x=1;
			P[ip].o=0;
			gotocell(ip);P[ip].display();
			if(result(P[0].x, P[1].x, P[2].x, P[3].x, P[4].x, P[5].x, P[6].x, P[7].x, P[8].x, P[9].x)==1){
				gotoxy(0,18);changeColor(15);for(int i=0;i<80;i++)cout<<"-";
				gotoxy(5,19);changeColor(14);cout<<"\aCROSS (X) WINS THE GAME.\nThanks for ur correct input.\nRESTART(y/n)";
				getch();
				system("tictac.exe");
				exit(0);							
			}else{
					goto circle;
			}
			
		}else{
			changeColor(12);cout<<ip<<"- Cell is already packed\a\a";
			getch();
			clear_line(17);
			goto cross;
		}
	}
	else{
		changeColor(12);
		cout<<"WRONG INPUT\a\a";
		getch();
		system("tictac.exe");
		exit(0);
	}
circle:
	int pack;
	pack=0;
	for(int i=1;i<=9;i++){
		if(P[i].full==1)
			pack++;
		}
	if(pack==9){
		gotoxy(5,17);changeColor(12);cout<<"ALL CELL PACK\a\a\n";
		cout<<"RESTART(y)";
		getch();
		system("tictac.exe");
		exit(0);
	}else{
		clear_line(16);
		gotoxy(5,16);changeColor(10);cout<<"Its Circle's Turn. Enter cell no. to circle(1-9)(O): ";
		cin>>ip;
		if((ip>0)&&(ip<=9)){
			if(P[ip].full==0){
				P[ip].full=1;
				P[ip].x=0;
				P[ip].o=1;
				gotocell(ip);P[ip].display();
				if(result(P[0].o, P[1].o, P[2].o, P[3].o, P[4].o, P[5].o, P[6].o, P[7].o, P[8].o, P[9].o)==1){
					gotoxy(0,18);changeColor(15);for(int i=0;i<80;i++)cout<<"-";
					gotoxy(5,19);changeColor(10);cout<<"\aCIRCLE (O) WINS THE GAME.\nThanks for ur correct input.\nRESTART(y/n)";
					getch();
					system("tictac.exe");
					exit(0);							
				}else{
					goto cross;
				}				
			}else{
				changeColor(12);cout<<"Cell is already packed\a\a";
				getch();
				clear_line(17);
				goto circle;
			}
		}	
		else{
			changeColor(12);
			cout<<"WRONG INPUT\a\a";
			getch();
			system("tictac.exe");
			exit(0);
		}
	}
}
 
