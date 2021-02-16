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
public:
	int n,cn,cc;
	char ch;
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
int Result(int N1,int N2,int N3){
	int no[3];
	no[0]=N1;
	no[1]=N2;
	no[2]=N3;
	for(int i=0;i<2;i++){
		for(int j=i+1;j<3;j++){
			if(no[i]>no[j]){
				int temp=no[i];
				no[i]=no[j];
				no[j]=temp;
			}
		}
	}
	N1=no[0];
	N2=no[1];
	N3=no[2];

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
	//trieal=6; double_run=5; run=4; color=3; double=2; top=1;
	if(alleq==1)
		return 6;
	else if(serial==1&&color==1)
		return 5;
	else if(serial==1)
		return 4;
	else if(color==1)
		return 3;
	else if(twoeq==1)
		return 2;
	else
		return 1;
	}

class sequence{
public:
	int n[3],no[3],c[3],r[3];
	void setcard(int x,int y,int z){
		n[0]=x;n[1]=y;n[2]=z;
		for(int i=0;i<=2;i++)
			no[i]=n[i];
		for(int i=0;i<2;i++){
			for(int j=i+1;j<3;j++){
				if(no[i]>no[j]){
					int temp=no[i];
					no[i]=no[j];
					no[j]=temp;
				}
			}
		}
		for(int k=0; k<3; k++){
			c[k]=no[k]/4;
			r[k]=no[k]%4;
		}

	}
	int res(){
		return Result(n[0],n[1],n[2]);
	}

	void display(int x,int y){
		Card Tt[3];
		for(int i=0;i<=2;i++){
			Tt[i].n=n[i];
			Tt[i].display(x+17*i,y);
		}
	}
	bool operator < (sequence)  const;
};

bool sequence ::operator < (sequence s2) const{
	int rs1=Result(n[0],n[1],n[2]);
	int rs2=Result(s2.n[0],s2.n[1],s2.n[2]);
	if(rs1 < rs2)
		return true;
	else if(rs1==rs2){
		if(rs1==6){
			return (c[2] < s2.c[2]) ? true:false;
		}else if(rs1==5||rs1==4){
			if(c[2]==12&&s2.c[2]==12)
				return (c[1] < s2.c[1]) ? true:false;
			else
				return (c[2] < s2.c[2]) ? true:false;
		}else if(rs1==3||rs1==1){
			if(c[2]!=s2.c[2])
                return(c[1] < s2.c[1]) ? true:false;
            else{
                if(c[1]!=s2.c[1])
                    return(c[1] < s2.c[1]) ? true:false;
                else{
                    if(c[0]!=s2.c[0])
                        return(c[0] < s2.c[0]) ? true:false;
                }
            }
        }else if(rs1==2){
			if(c[1]!=s2.c[1])
				return(c[1] < s2.c[1]) ? true:false;
			else{
				if(c[2] == s2.c[2])
					return(c[0] < s2.c[0]) ? true:false;
				if(c[0] == s2.c[0])
					return(c[2] < s2.c[2]) ? true:false;
				else
					return(c[2] < s2.c[2]) ? true:false;
			}
		}else
			return false;
	}else
		return false;
}

int main(){
	hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);
	SetConsoleScreenBufferSize(hConsole, {155,200});
	Card C[52],T[52],Ta[52],S1[6],S2[3];
	sequence Seq[100];
	for(int i=0;i<=51;i++){
		C[i].setno(i);
	}
start:
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

	for(int i=0;i<=51;i++)
		Ta[i]=T[i];
	for(int i=0;i<=7;i++){
		for(int j=i+1;j<=8;j++){
			if(Ta[i].n>Ta[j].n){
				Card temp=Ta[i];
				Ta[i]=Ta[j];
				Ta[j]=temp;
			}
		}
	}

	int l=0;
	for(int i=0;i<=6;i++){
		for(int j=i+1;j<=7;j++){
			for (int k=j+1;k<=8;k++){
				Seq[l].setcard(T[i].n,T[j].n,T[k].n);
				l++;
			}
		}
	}
	for(int i=0;i<=l-1;i++){
		for(int j=i+1;j<=l;j++){
			if(Seq[i]<Seq[j]){
				sequence Temp=Seq[i];
				Seq[i]=Seq[j];
				Seq[j]=Temp;
			}
		}
	}
	for(int i=0;i<=8;i++)
		T[i].display(17*i+1,0);
//	for(int i=0;i<=8;i++)
//		Ta[i].display(17*i+1,14);
	if(Seq[0].res()<4){
		cout<<"\n\n\nArranging Again, Press any key";
		getch();
		goto start;
	}
	changeColor(15);
	cout<<"\n\n\n\tMAKING 3-KITTI SEQUENCE OF ABOVE CARDS::Press space";
	cout<<"\n\tMAKING 3-KITTI SEQUENCE OF ABOVE CARDS::Press space";
	getch();
	Seq[0].display(1,30);
	int m=0;
	for(int i=0;i<=8;i++){
		if(T[i].n==Seq[0].n[0]||T[i].n==Seq[0].n[1]||T[i].n==Seq[0].n[2]){

		}else{
			S1[m]=T[i];
			m++;
		}
	}
	l=0;
	for(int i=0;i<=3;i++){
		for(int j=i+1;j<=4;j++){
			for (int k=j+1;k<=5;k++){
				Seq[l].setcard(S1[i].n,S1[j].n,S1[k].n);
				l++;
			}
		}
	}

	for(int i=0;i<=l-1;i++){
		for(int j=i+1;j<=l;j++){
			if(Seq[i]<Seq[j]){
				sequence Temp=Seq[i];
				Seq[i]=Seq[j];
				Seq[j]=Temp;
			}
		}
	}
	Seq[0].display(100,30);
	int n=0;
	for(int i=0;i<=5;i++){
		if(S1[i].n==Seq[0].n[0]||S1[i].n==Seq[0].n[1]||S1[i].n==Seq[0].n[2]){

		}else{
			S2[n]=S1[i];
			n++;
		}
	}
	Seq[0].setcard(S2[0].n,S2[1].n,S2[2].n);
	Seq[0].display(55,45);
}
