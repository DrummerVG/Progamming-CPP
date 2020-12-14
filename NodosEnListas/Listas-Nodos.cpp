/*____________Instituto Politécnico Nacional_____________/
 /__Escuela Superior de Ingenieria Mecanica y Electrica__/
 /______Ingenieria en Comunicaciones y Electronica_______/
 /____________By Cortés David, México City_______________*/
 
#include<iostream>
using namespace std;

class Lista;

class Nodo
{
	friend class Lista;
	private:
		int Boleta;
		string Clave;
		char Nombre[100];
		float Cal[3];
		Nodo *apSig;
		Nodo *apAnt;
	
	public:
		Nodo(Nodo *apsig=NULL, Nodo*apant=NULL);
		void Leer(void);
		float Promedio(void);
		void Imprimir(void);
		
};//Fin clase Nodo

Nodo::Nodo(Nodo *apsig, Nodo *apant):apSig(apsig),apAnt(apant)
{}//Fin Constructor

void Nodo::Leer(void)
{
	cout<<"Capturar Clave: ";
	cin>>Clave;
	cout<<"Capturar Boleta: ";
	cin>>Boleta;
	fflush(stdin);
	cout<<"Capturar Nombre: ";
	cin>>Nombre;
	for(int i=0;i<3;i++)
	{
		cout<<"Capturar calificacion "<<i+1<<":  ";
		cin>>Cal[i];
	}
}//Fin leer Nodo

float Nodo::Promedio(void)
{
	return((Cal[0]+Cal[1]+Cal[2])/3);
}//Fin Promedio

void Nodo::Imprimir(void)
{
	cout<<"Clave: "<<Clave<<endl;
	cout<<"Boleta: "<<Boleta<<endl;
	cout<<"Nombre: "<<Nombre<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"Calificacion "<<i+1<<" : "<<Cal[i]<<endl;
	}
	cout<<"Promedio: "<<Promedio()<<endl<<endl;
}//Fin Imprimir

//***********FIN CLASE NODO*******************

class Lista
{
	private:
		Nodo *apPrimero;
		Nodo *apUltimo;
	
	public:
		Lista(Nodo *apprimero=NULL, Nodo *apultimo=NULL);
		void InsertarAlFinal(void);
		void InsertarAlInicio(void);
		void BorrarAlFinal(void);
		void BorrarAlInicio(void);
		void Imprimir(void);
		void Imprimir2(void);
		
		Nodo *CrearNodo(void)
		{
			Nodo *Nuevo=new Nodo;
			Nuevo->Leer();
			return Nuevo;
		}
	
};//Fin clase lista

Lista::Lista(Nodo *apprimero,Nodo *apultimo):apPrimero(apprimero),apUltimo(apultimo)
{
	
}//Fin Constructor

void Lista::InsertarAlInicio(void)
{
	Nodo *Nuevo=CrearNodo();
	
	if (apPrimero==NULL)
	{
	    apPrimero=apUltimo=Nuevo;
	}
	else
	{
		Nuevo->apSig=apPrimero;
		apPrimero->apAnt=Nuevo;
		apPrimero=Nuevo;
	}
	
}//Fin Insertar al inicio

void Lista::InsertarAlFinal(void)
{
	Nodo *Nuevo=CrearNodo();
	
	if (apPrimero==NULL)
	{
		apPrimero=apUltimo=Nuevo;
	}
	else
	{
		Nuevo->apAnt=apUltimo;
		apUltimo->apSig=Nuevo;
		apUltimo=Nuevo;

	}

}//Fin Insertar Al Final

void Lista::BorrarAlInicio(void)
{
	if(apPrimero==NULL)
	{
		cout<<"LISTA VACIA"<<endl;
		system("pause");
	}
	else
	{
		Nodo *apAux=apPrimero;
		if(apPrimero==apUltimo)
		{
			apPrimero=apUltimo=NULL;
		}
		else
		{
			apPrimero=apPrimero->apSig;
			apPrimero->apAnt=NULL;
		}
		cout<<apAux->Nombre<<" Eliminado"<<endl;
		system("pause");
		delete []apAux;
	}
}

void Lista::BorrarAlFinal(void)
{
	if(apPrimero==NULL)
	{
		cout<<"Lista vacia"<<endl;
		system("pause");
		
	}
	
	else
	{
		Nodo *Aux=apUltimo;
		if(apPrimero==apUltimo)
		{
			apPrimero=apUltimo=NULL;
		}
		else
		{
			apUltimo=apUltimo->apAnt;
			apUltimo->apSig=NULL;
		
			
		}
		cout<<Aux->Nombre<<" Eliminado"<<endl;
		system("pause");
		
		delete[]Aux;
	}
	
	
}//Fin borrar al final

void Lista::Imprimir(void)
{
	if(apPrimero==NULL)
	{
		cout<<"LISTA VACIA!"<<endl;
	}
	else
	{
		Nodo *Aux=apPrimero;
		while(Aux!=NULL)
		{
			Aux->Imprimir();
			Aux=Aux->apSig;
		}
	}
	
}//Fin Imprimir

void Lista::Imprimir2(void)
{
	if(apPrimero==NULL)
	{
		cout<<"LISTA VACIA!"<<endl;
	}
	else
	{
		Nodo *Aux=apUltimo;
		while(Aux!=NULL)
		{
			Aux->Imprimir();
			Aux=Aux->apAnt;
		}
	}
	
}//Fin Imprimir2

void Menu(void)
{
	Lista Lista;
	int opc;
	
	do
	{
		cout<<"¡BIENVENIDO AL MENU!"<<endl<<endl;
		cout<<"1.- Insertar al Final"<<endl;
		cout<<"2.- Insertar al Inicio"<<endl;
		cout<<"3.- Borrar al Inicio"<<endl;
		cout<<"4.- Borrar al Final"<<endl;
		cout<<"5.- Imprimir del Inicio al Final"<<endl;
		cout<<"6.- Imprimir del Final al Inicio"<<endl;
		cout<<"7.- Salir"<<endl<<endl;
		
		cout<<"Seleccione una opcion: ";
		cin>>opc;
		system("cls");
		
		
		switch(opc)
		{
			case 1:
				{
					
					Lista.InsertarAlFinal();
					system("cls");
					break;
					
				}//Fin caso 1
			
			case 2:
				{
					Lista.InsertarAlInicio();
					system("cls");
					break;
				}//Fin caso 2
				
			case 3:
				{
					Lista.BorrarAlInicio();
					system("cls");
					break;
				}
			
			case 4:
				{
					Lista.BorrarAlFinal();
					system("cls");
					break;
				}
			
			
			case 5:
				{
					Lista.Imprimir();
					system("pause");
					system("cls");
					break;
				}
			
			case 6:
				{
					Lista.Imprimir2();
					system("pause");
					system("cls");
					break;
				}
			
			case 7:
				{
					cout<<"Good Bye!"<<endl<<endl;
					break;
				}
			default:
				{
					cout<<"¡OPCION INVALIDA!"<<endl;
					system("pause");
					system("cls");
					break;
				}
		
		}//Fin switch
		
	}while(opc!=7);//Fin do - while
}

int main(void)
{
	
	Menu();
	
	system("pause");
	return 0;
}
