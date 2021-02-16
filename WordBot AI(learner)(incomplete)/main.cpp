#include <iostream>
//#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
//#include <stdio.h>
//#include <sstream>
#include  <string>
//#include <vector>

using namespace std;

int main(){
	int check,j;
	check = 0;
	j=0;
	cout<<"\t\t\tWelcome to Word Bot.\t";
	getch();
	cout<<"\nHey, Are you good?\n";
	char jpt[j],ch1;
	ch1=getch();
	while(ch1!=13){
		jpt[j]=ch1;
		j++;
		cout<<ch1;
		ch1=getch();
	inputa:
		if(ch1=='\b'){
			j--;
			putch('\b');
			cout<<" ";
			putch('\b');
			ch1=getch();
			goto inputa;
		}
	}
	for(int i=0;i<=j;i++){
	if((jpt[i]=='a'||'A')&&(jpt[i+1]=='n'||'N')&&(jpt[i+2]=='d'||'D')&&(jpt[i+3]==' ')&&(jpt[i+4]=='y'||'Y')&&(jpt[i+5]=='o'||'O')&&(jpt[i+6]=='u'||'U')){
		check=1;
		}
	else if((jpt[i]=='w'||'W')&&(jpt[i+1]=='h'||'H')&&(jpt[i+2]=='a'||'A')&&(jpt[i+3]=='t'||'T')&&(jpt[i+4]==' ')&&(jpt[i+5]=='a'||'A')&&(jpt[i+6]=='b'||'B')&&(jpt[i+7]=='o'||'O')&&(jpt[i+8]=='u'||'U')&&(jpt[i+9]=='t'||'T')&&(jpt[i+10]==' ')&&(jpt[i+11]=='y'||'Y')&&(jpt[i+12]=='o'||'O')&&(jpt[i+13]=='u'||'U')&&(jpt[i+14]=='r'||'R')&&(jpt[i+15]=='s'||'S')){
		check=1;
		}
	}
	j=0;
	if(check==1){
		cout<<"\nI am good. Machines are always good as long as you care.\n";
		Sleep(1000);
	}
	check=0;
	cout<<"\nI feel comfortable to chat if I get your name.\n";
	cout<<"\t\t(Write only your name.)\n";
	string name;
	cin>>name;
	cout<<"\nHey "<<name<<", ";
	getch();
	return 1;
}
