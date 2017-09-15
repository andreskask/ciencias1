#include <iostream>
using namespace std;
struct Nodo{
	int dato;
	Nodo *ant;
	Nodo *sig;
};

class ListaDoble{
	Nodo *cab,*fin;
	//Metodos
	public:
	ListaDoble();
	void agregar(int);
	int eliminar();
	void eliminar(int);
	void mostrar();
	Nodo *buscar(int);
	bool vacia();
};

ListaDoble::ListaDoble(){
	cab=fin=NULL;
}

void ListaDoble::agregar(int dato){
	Nodo *p= new Nodo;
	p->dato=dato;
	p->sig=cab;
	if(cab)
		cab->ant=p;
	else
		fin=p;
	p->ant=NULL;
	cab=p;
}

void ListaDoble::mostrar(){
	Nodo *p=cab;
	while (p!=NULL){ // while(p)
		cout<<p->dato<<" ";
		p=p->sig;
	}
}

Nodo *ListaDoble::buscar(int dato){
	Nodo*p=cab;
	while(p)
		if(p->dato==dato)
			return p;
		else
			p=p->sig;
	return p;
}
bool ListaDoble::vacia(){
return cab==NULL;
}

void ListaDoble::eliminar(int dato){
	Nodo *p=cab,*a,*s;
	while(p){
		if(p->dato==dato){
			if(!p->ant){ //eliminar primer elemento
				cab=p->sig;
				delete p;
			}
			else if(!p->sig){
				fin=p->ant;
				fin->sig=NULL;
				cout<<fin->dato;
				 //eliminar elemento del final
				delete p;
			}else{
				a=p->ant;
				s=p->sig;
				a->sig=s; //eliminar elemento intermedio
				s->ant=a;
				delete p;
			}
			cout<<"se elimino el dato\n";
		}else{
			p=p->sig;
		}
	}
}

char menu();
int main(){
	ListaDoble lista;
	//Pila lista;
	//Cola lista;
	//ListaDinamica lista;
	char opcion;
	int dato;
	do{
		opcion=menu();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Digite el elemento a agregar: ";
				cin>>dato;
				lista.agregar(dato);
				break;
			case 'e':
			case 'E':
				cout<<"digite el elemento a eliminar\n ";
				cin>>dato;
				lista.eliminar(dato);
				cout<<"s";
				break;
			case 'o':
			case 'O':
				cout<<"La lista a sido ordenada";
				//lista.ordenar();
				break;
			case 'm':
			case 'M':
				cout<<"Los elementos almacenados son:\n";
				lista.mostrar();
				break;
			case 'b':
			case 'B':
				cin>>dato;
				if(lista.buscar(dato))
					cout<<"el elemento se encuenra en la lista\n";
				else
				cout<<"el elemento no se encuentra en la lista\n";
				break;
		}
	}while(opcion!='t' && opcion!='T');
	lista.agregar(35);
	lista.agregar(20);
	cout<<"los elementos almacenados: \n";
	lista.mostrar();
}

char menu(){
	char opcion;
	cout<<"\n MENU\n";
	cout<<"(A)gregar\n";
	cout<<"(E)liminar\n";
	cout<<"(O)rdenar\n";
	cout<<"(M)ostrar\n";
	cout<<"(B)uscar\n";
	cout<<"(T)erminar\n";
	cout<<"escoja una opcion: ";
	cin>>opcion;
	return opcion;
}

