#include <iostream>
#include<conio.h>
#include "Collector.cpp"
using namespace std;
    /**
        @brief instanciacion de la clase collector para su porterior uso dentro de la clase Lista (lista enlazada),
        la cual contiene los valores con los cuales se puede interactuar.
        
    */
Collector *collector = new Collector;
    /**
        @param Creacion de la clase Nodo misma que se relaciona con la clase Lista, aqui se almacenan 
        los valores de head, ademas del set y get respectivo.
    */
class Node{
  
public:

   
    /**
        @brief Valor que se utiliza en la sobrecarga del new y delete, este sirve para almacenar
        la variable que el usuario desea eliminar de la lista, para su posterior envio a la clase
        collector.
    */
    int valor;
      /**
       @brief Nodo next que sirve para la transicion de la cabeza de la linked lis
    */
    Node *next;
    /**
        @brief Metodo set 
        @param valor para insertar en la lista
    */
    Node (int valor){
        this->valor = valor;
        this->next = NULL;
    }
    /**
        @brief Sobrecarga del metodo new para asi poder extraer alguna direccion disponible de la clase collector
        @param Valor para crear en el heap (a este se le asigna el possible valor de direccion disponible de la clase collector).
        @return valor de lo que se inserto en la lista enlazada
    */
    void * operator new(size_t size)
    {
        if (collector->check() == false) {

          
            void * p = ::operator new(size);
            std::cout<<"Garbage collector is empty" << std::endl;
            return p;
        }
        else {
          
            void * p = reinterpret_cast<void *>(collector->get_collector_value());
            std::cout<<"New direccion of node is: " << p <<std::endl;
            return p;
        }
    }
    /**
        @brief Sobrecarga del metodo delete, el cual envia el valor del nodo seleccionado a la clase collector 
        y posteriormente elimina el valor como normalmente se hace.
        @param valor a eliminar
    */
    void operator delete(void * p)
    
    {
        std::cout<<"The pointer to delete is: " << p <<std::endl;
        collector->set_collector(p);
        free(p);
    }
};
    /**
        @brief Clase lista (lista enlazada), la cual almacena todos los valores que el usuario desee annadir.
    */
class LinkedList{ 

private:
   
    void set_node_head(Node *&head, int value){
        Node *new_node = new Node(value);
        Node *aux = head;
        head = new_node;
        head->next = aux;

    }
    void eliminate_node_head(Node *&head){
      
        if(head != NULL){
            Node *aux_eliminar;
            aux_eliminar = head;

            head = head->next;
            delete(aux_eliminar);


        }
    }
    void shoow_list(Node *head){
     

        Node *actual;
        actual = head;
        cout << "[";
        while(actual != NULL){
            if (actual->next == NULL){
                cout<<actual->valor;
            }
            else{
                cout<<actual->valor << ",";
            }            
            actual = actual->next;
        }
        cout << "]";
    }
public:
    /**
        @brief puntero auxiliar del primer valor de la lista, es el euivalente a la cabeza de la lista.
    */
    Node *first = NULL;
    /**
        @brief Metodo para insertar nodo al final de la lista. 
        @param valor para insertar en la lista
    */
    void set_new_node(int value){
        set_node_head(first, value);
    }
    /**
        @brief Metodo para insertar un valor al inicio de la lista (cambiar al valor de la cabeza)
        @param ffff
        @return
    */
     void set_head(int new_value){
 
        first->valor = new_value;
    }

    /**
        @brief metodo para eliminar un nodo, ademas llama el delete sobrecargado.
        
    */
    void eliminate_node(){
        eliminate_node_head(first);
    }
    /**
        @brief Metodo que imprime todos lo elementos de la lista
    */
    void show_list(){
        shoow_list(first);
    }

};

    /**
        @brief Metodo main del programa el cual inicializa la clase lista y las variables necesarias 
        para que el programa corra correctamente
    */
int main(int argc, char const *argv[])
{   
    /**
        @brief Instanciacion de la clase lista
    */
    LinkedList list;
    /**
        @brief variable que almacena el tamanno de la lista
    */
    int size;
    /**
        @brief variable que almacena la opcion elegida por el usuario en la terminal 
    */
    int option;
    /**
        @brief variable tipo char que selecciona el tipo de insercion al la lista enlazada
    */
    char first_final;
    /**
        @brief valor escogido por el usuario
    */
    int value;
    /**
        @brief metodo do que inicializa el menu de uso para que el usuario seleccione la opcion que asi desee
    */
    do{
        
        cout << "1.Create new list " << endl;
        cout << "2.Set nodes" << endl;
        cout << "3.Remove node" << endl;
        cout << "4.Print list" << endl;
        cout << "5.Show list of garbage collector" << endl;
        cout << "6.Exit" << endl;
        cout << "Opcion: ";

        cin >> option;

        cout << endl;

        switch ((option))
        {
        case 1:
            cout << "Set list size: ";
            cin >>  size;
            break;
        case 2:
            if (size == NULL){
                cout << "No list created" << endl;
            }
            else{
                for (int i = 0; i < size; i++){

                    cout << "Set value in beginning or end (b/e) ";
                    cin >> first_final;
                    if(first_final=='b'){
                        cout << "Set node value: ";
                        cin >> value;
                        list.set_head(value);
                       

                    }
                    else if(first_final=='e'){
                        cout << "Set node value: ";
                        cin >> value;
                        list.set_new_node(value);
            }
                }
            }
            break;
            case 3:
            if (size == NULL){
                cout << "No list created" << endl;
            }
            else {
                size--;
                cout << "Set node to eliminate: ";
                    cin >> value;
                    list.eliminate_node();
                    cout << "--------------------------------------------------- " <<endl;
                    list.show_list(); 
                    cout << "--------------------------------------------------- " <<endl;
            }
            break;
        case 4:
            if (size == NULL){
                cout << "No list created" << endl;
            }
            else{
                cout << "The list is: ";
                list.show_list(); 
                cout << endl;
            }
            break;
        case 5:
            
            break;
        case 6:
            break;
        default:
            break;
        }

    }while(option != 6);

    
    return 0;
}
