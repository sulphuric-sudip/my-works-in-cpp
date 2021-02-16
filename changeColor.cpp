#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

int main(){
	
	for(int i=0;i<272;i++){
		cout<<"\n";
		changeColor(i);
		cout<<i<<". Color No."<<i;
	}
	getch();
}
