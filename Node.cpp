#include<iostream>
using namespace std;
#include<conio.h>

struct Elem{
    int num;
    struct Elem *sgte;
};

struct Elem *pi,*pa,*pf;

void insertar_elem(int val){
    if (pi == NULL){
    pi = new (Elem);
    pi->num = val;
    pf= pi;
    }else{
        pa= new(Elem);
        pf->sgte=pa;
        pa->num= val;
        pf= pa;
    }
    pf->sgte=NULL;
}
void mostrar_elementos(){
    /* pa es el puntero auxiliar mientras que pi claramente inicial*/
    pa=pi; 
    int i=1;
    cout<< endl << endl<< "Elementos de la lista enlazada"<<endl <<endl;
    while (pa!= NULL){
        cout<< "Elemento numero" << i << ":"<< pa->num <<endl;
        pa = pa->sgte;
        i++;
    }
}
void buscar_elemento(){


}

int main(){
    int valor;
    char answer;
    do{

        cout << "Ingrese valor: ";
        cin >> valor;
        insertar_elem(valor);
        cout <<"Ingresar otro valor (s/n)";
        answer = getch();
    } while (answer=='s');
    mostrar_elementos();




    return 0;
}
