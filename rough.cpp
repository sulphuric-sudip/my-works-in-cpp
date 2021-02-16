#include<iostream>

using namespace std;

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
	int n[3];
	void setcard(int x,int y,int z){
		n[0]=x;n[1]=y;n[2]=z;
	}
//	void display(int x,int y){
//		Card Tt[3];
//		for(int i=0;i<=2;i++){
//			Tt[i].n=n[i];
//			Tt[i].display(x+17*i,y);
//		}
//	}
	bool operator < (sequence)  const;
};
bool sequence ::operator < (sequence s2) const{
	int rs1=Result(n[0],n[1],n[2]);
	int rs2=Result(s2.n[0],s2.n[1],s2.n[2]);
	return (rs1 < rs2) ? true : false;
}


int main(){
	sequence Seq[2];
	Seq[0].setcard(0,1,2);
	Seq[1].setcard(4,8,12);
	if(Seq[0] < Seq[1]){
		cout<<"Seq[0] is less";
	}else
		cout<<"Seq[1] is less";
}




