#include<iostream>
#include<sstream>

using namespace std;

class Pet{
	public:
	
	int saciedade;
	int saciedadeMax;
	int energia;
	int energiaMax;
	int limpeza;
	int limpezaMax;
	int diamantes;
	int idade;
	
	
	Pet(){
	}
	
	
	Pet(int sacMax,int eneMax, int limpMax){
	diamantes=0;
	idade=0;
	saciedade = sacMax;
	saciedadeMax = sacMax;
	energia = eneMax;
	energiaMax = eneMax;
	limpeza = limpMax;
	limpezaMax = limpMax;
	}
	

	
	string show(){
		stringstream s;
		s<<"E: "<<energia<<"/"<<energiaMax<<" , H: "<<saciedade<<"/"<<saciedadeMax<<" , C: "<<limpeza<<"/"<<limpezaMax<<" , D:"<<diamantes<<" , A: "<<idade;
		return s.str();
	}
	


	void play(){
		energia = energia-2;
		saciedade--;
		limpeza = limpeza -3;
		idade++;
		diamantes++;
	}
	
	void eat(){
		energia--;
		limpeza= limpeza-2;
		saciedade = saciedade +4;
		idade++;
		if(saciedade+4>saciedadeMax) saciedade = saciedadeMax;
	}
	
	void clean(){
		saciedade--;
		energia = energia - 3;
		idade = idade + 2;
		limpeza = limpezaMax;
	}
	
	void sleep(){
	if(energiaMax-energia>=5){
	saciedade--;
	energia = energiaMax;
	idade = energiaMax - energia;
	}
	else cout<<"Nao esta com sono"<<endl;
}

	bool Vivo(){
		if(energia <=0 ) {
		cout<<"Pet morreu de cansaço "<<endl;
		return false;}
		else if(saciedade <=0 ) {
		cout<<"Pet morreu de fome "<<endl;
		return false;}
		else if(limpeza <=0 ) {
		cout<<"Pet morreu de sujeira "<<endl;
		return false;}
		else if(saciedade > 0 && limpeza > 0 && energia > 0 ) {
		return true;
	}
}
	
	

};

class Controller{
	public:	
Pet p;
string shell(string x){
	string op;
	stringstream out;
	stringstream in(x);
	in>>op;
if(op=="show"){
	out<<p.show();
	return out.str();
}

if(p.Vivo() == true){


	if(op=="play"){
	p.play();
	return out.str();
}

	if(op=="eat"){
	p.eat();
	return out.str();
}

	if(op=="sleep"){
	p.sleep();
	return out.str();
}

	if (op=="init"){
	int energiaMax;
	int limpezaMax;
	int fomeMax;
	in>>fomeMax;
	in>>energiaMax;
	in>>limpezaMax;
	p=Pet(fomeMax,energiaMax,limpezaMax);
	return out.str();	
		}
	}
	
	else if(p.Vivo() == false){
		p.Vivo();
	}
}
void exec(){
	string s;
	while(true){
	getline(cin,s);
	
	cout<<shell(s);
	
}
}
	
	
};


int main(){

Controller c;
c.exec();

}
