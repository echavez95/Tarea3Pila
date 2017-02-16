#include <iostream>
#include <stdlib.h>

using namespace std;
class Elemento
{
    public:
        int Value;
        Elemento *NextElement;

    Elemento(int val)
    {
        Value=val;
        NextElement = 0;
    }

    ~Elemento(){}
};

class Pila
{
    public :
		Elemento *Tope;

	Pila ()
	{
        Tope =0;
	}

    void Push(int valor)
    {
        Elemento* nodo = new Elemento(valor);
        if(Vacia())
        {
            Tope=nodo;
        }
        else
            {
                nodo->NextElement=Tope;
                Tope=nodo;
            }
    }

    int Pop()
    {
        if(Vacia()){
            cout<<"Pila Vacia"<<endl;
        }
        else
            {
                Elemento* nodoTemp;
                int valor=Tope->Value;

                nodoTemp=Tope;
                Tope=Tope->NextElement;

                delete nodoTemp;
                return valor;
            }
    }

    bool Vacia()
    {
        if(Tope==0)
        {
            return true;
        }
        return false;
    }

    void ImprimirPila()
    {
        if(Vacia()){
            cout<<"Pila Vacia"<<endl;
        }
        else
            {
                Elemento* nodoTemp=Tope;
                do
                {
                    cout<<nodoTemp->Value<<endl;
                    nodoTemp=nodoTemp->NextElement;
                }while(nodoTemp->NextElement!=0);
            }
    }

};

int main()
{
    Pila pilaEnteros;
    int res;
    int entero;
    int posicion;
    do{
        system("cls");
        cout << "EJEMPLO PILA" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tope" << endl;
        cout << "4. Vacia" << endl;
        cout << "5. Ver Pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion" << endl;
        cin>>res;
        system("cls");
        switch(res)
        {
            case 1:
                cout << "Escriba un Numero: " << endl;
                cin>>entero;
                pilaEnteros.Push(entero);

                break;
            case 2:
                cout << "Enter para obtener el primer valor de la pila " << endl;
                system("pause");
                cout << pilaEnteros.Pop()<<endl;
                system("pause");
                break;
            case 3:
                cout << "Primer elemento de la pila: "<<pilaEnteros.Tope->Value<< endl;
                system("pause");
                break;
            case 4:
                if(pilaEnteros.Vacia())
                {
                    cout << "La pila esta vacia" << endl;
                }
                else
                {
                    cout << "La pila no esta vacia" << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "Pila:" << endl;
                pilaEnteros.ImprimirPila();
                system("pause");
                break;
        }
    }while(res!=0);

    return 0;
}
