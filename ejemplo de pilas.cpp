/*
Pila: una pila es una estructura de datos ordenada 
solo se pueden intriducir y eliminar por una lado.
Estructura lifo: el ultimo en entrar es el primero en salir
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Alumno{
	int clave;
	char nombre[30];
	float calificacion;
};

struct Nodo{
	Alumno datos;
	Nodo *siguiente;
};
void menu();
void agregarDatos(Alumno &);
void inDatos(Nodo *&,Alumno);

int main(){
	Alumno datos;
	Nodo *pila=NULL;
	Nodo *aux=NULL;
	char opcion;
	
	do{
		menu();
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				agregarDatos(datos);
				inDatos(pila,datos);
				break;
			case '2':
				cout<<"Mostrando productos."<<endl;
    			aux=pila;//nodo aux toma valor de frente para poder usar todos los datos de elnodo frente
    			cout<<"CLAVE"<<"\tNOMBRE\t\t\t"<<"CALIFICACION"<<endl;
	    		while(aux !=NULL){
	    			cout<<aux->datos.clave<<"\t"<<aux->datos.nombre<<"\t\t\t"<<aux->datos.calificacion<<endl;
	    			aux=aux->siguiente;
				}
				break;
			case '3':
				cout<<"Salio del programa"<<endl;
				break;
			default:
				cout<<"\nOpcion invalida"<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar"<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
}

void menu()
{
	cout<<"\nPrograma usando pilas"<<endl;
	cout<<"MENU"<<endl
	    <<"1.Ingresar datos"<<endl
	    <<"2.Mostrar datos"<<endl
	    <<"3.Salir"<<endl
	    <<"Ingresar el numero de opcion: ";
}

void agregarDatos(Alumno &datos){
	cout<<"\nIngresar nombre del alumno: "; cin.getline(datos.nombre,30,'\n');
	cout<<"Ingresar clave del alumno: "; cin>>datos.clave;
	cout<<"Ingresar calificacion del alumno: "; cin>>datos.calificacion;
	cout<<endl;
}

void inDatos(Nodo *&pila,Alumno datos){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->datos=datos;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

