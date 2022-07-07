#include <iostream>
#include <fstream>
#include <vector> 
#include <cstring> 
#include "../lib/libx.h"
#include "../lib/estructuras.h"

using namespace std;

struct usuario verPersona;
vector<usuario> persona;
const string fileDir = "../datos/base.txt";

//------------------------------------------------------------------------------------------------
void loadInfo(){
	string nombre;
	fstream fBase(fileDir);

	cout<<endl<< "Load Information...!"<<endl;
	if(!fBase)
		cout<< "Error al abrir el archivo" << fileDir << endl;
	
	while(fBase >> nombre){
		struct usuario usu;
		strcpy(usu.nombre, &nombre[0]);
		fBase>> usu.numTarjeta;
		fBase>> usu.pin;
		fBase>> usu.saldo;

		persona.push_back(usu);
	}
	fBase.close();
}

//------------------------------------------------------------------------------------------------
void showInfo(){
	cout<< "------"<<endl;
	for (auto &&usu :persona){
		cout<<"Nombre: "<< usu.nombre<< endl
			<<"Tarjeta: "<< usu.numTarjeta<<endl
			<<"Pin: "<< usu.pin<< endl
			<<"Saldo: $ "<< usu.saldo<< endl<< endl;
	}
	
}

//------------------------------------------------------------------------------------------------
bool existReg(int numero){
	bool ban=false;
	for (auto &&e : persona)
		if(e.numTarjeta == numero){
			cout<<"*"<< e.nombre <<"* Bienvenido a tu cajero de confianza"<<endl;
			strcpy(verPersona.nombre, &e.nombre[0]);
			verPersona.numTarjeta = e.numTarjeta;
			verPersona.pin = e.pin;
			verPersona.saldo = e.saldo;
			ban=true;
			continue;
		}	
	return ban;
}

//------------------------------------------------------------------------------------------------
bool verificarPin(int pin){
	bool ban=false;
	if(pin == verPersona.pin){
		ban=true;
	}
	return ban;
}

//------------------------------------------------------------------------------------------------
void retDinero(){}
void depDinero(){}
void traDinero(){}
void conDinero(){}

//------------------------------------------------------------------------------------------------
int getOp(){
	int op;
	do{
		cout<<endl<<"***** POLICAJERO *****"<<endl
			<<"1. Retirar"<<endl
			<<"2. Depositar"<<endl
			<<"3. Transferir"<<endl
			<<"4. Consultar Saldo"<<endl
			<<"0. Salir"<<endl
			<<endl<<"Ingresa tu opcion > ";
		cin >> op;
	}while(op<0 || op>4);

	return op;
}


//************************************************************************************************
int main(){
	int numeroDeTarjeta, PIN, cont=1;
	loadInfo();
	showInfo();
	cout<<"Ingrese su número de tarjeta > ";	cin>> numeroDeTarjeta;
	if(existReg(numeroDeTarjeta)== true){
		cout<<endl<<"Ingrese su PIN > ";	cin>> PIN;
		while(verificarPin(PIN) == false && cont<3){
			cout<<endl<<"Pin Incorrecto"<<endl;
			cout<<endl<<"Ingrese nuevamente su PIN > ";	cin>> PIN;
			cont++;
		}
		if(cont==3){
			cout<<"Lo sentimos, has superado el límite de intentos"<<endl;
			cout<< "Gracias por utilizar el Policajero"<<endl;
			exit(EXIT_FAILURE);
		}

		do{		
			switch(getOp()){
				case retirar	: retDinero(); 				break;
				case depositar	: depDinero(); 				break;
				case transferir	: traDinero();				break;
				case saldo		: conDinero();				break;
				case salir 		: cout<< "* Gracias por usar el POLICAJERO *"<<endl;
									exit(1);				break;

				default:  cout<<endl<< "Opción no válida..!"<<endl;		break;
			}
		}while(true);
	}else
		cout<<"Lo sentimos, no estás registrado para usar el Plicajero"<<endl;
	
	cout<< "Gracias por utilizar el Policajero"<<endl;
	return 0;
}