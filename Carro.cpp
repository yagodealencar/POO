#include<iostream>

using namespace std;


class Carro{
	public:
	float gas = 0;
	float gasMax = 10;
	int pass = 0;
	int passMax = 2;
	float km = 0;
	
	void show(){
		cout<<"pass: "<<pass<<" gas: "<<gas<<" km: "<<km<<endl;
	}
	
	void in(){
		if(pass<passMax){
				pass++;
			cout<<"Sucess"<<endl;
		
		}
		else cout<<"failure: limite de pessoas atingido"<<endl;
	}
	
	void out(){
		if(pass>0){
			pass--;
			cout<<"Sucess"<<endl;
		}
		else cout<<"failure: nao ha ninguem no carro"<<endl;
	}
	
	void fuel(float gasolina){
		if(gasolina+gas>=gasMax){
			gas = gasMax;
			cout<<"Sucess"<<endl;
		}
		else if(gasolina+gas<gasMax){
			gas = gas +gasolina;
			cout<<"Sucess"<<endl;
		}
	}
	
	bool drive(float distance){
		if(pass>0){
			if(gas-(distance/10.0)<0){
				cout<<"failure: Combustivel insuficiente"<<endl;
				return false;
			}
			gas = gas - (distance/10.0);
			km = km+distance;
			cout<<"Sucess"<<endl;
			return true;
		}
		else cout<<"failure: nao ha ninguem no carro"<<endl;
		return false;
	}
};



int main(){
Carro c;
string op;
while(true){

cin>>op;
if(op=="show"){
	c.show();
}
if(op=="in"){
	c.in();
}

if(op=="out"){
	c.out();
}
if(op=="fuel"){
	float g;
	cin>>g;
	c.fuel(g);
}
if(op=="drive"){
	float d;
	cin>>d;
	c.drive(d);
}
if(op=="exit") break;
}
}
