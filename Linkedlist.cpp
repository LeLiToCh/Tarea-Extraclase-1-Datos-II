#include <iostream>
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

public:
   
    LinkedList() { head = NULL; }
    Node* head;
    void insertNode(int);
    void printList();
    void deleteNode(int);
    void insertFront(Node **head, int n);
    void * operator new(size_t size);
    void operator delete(void * p);
     /**
        @brief Metodo para insertar el primer nodo de toda la lista. 
        @param valor para insertar en la lista
    */
    void set_node_head(Node *&head, int value){
        Node *new_node = new Node(value);
        Node *aux = head;
        head = new_node;
        head->next = aux;
    }
};

    /**
        @brief Metodo para insertar nodo al final de la lista. 
        @param valor para insertar en la lista
    */
    void LinkedList::insertNode(int data)
    {
    
    Node* newNode = new Node(data);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
  
        
        temp = temp->next;
    }
   
    temp->next = newNode;
}
    /**
        @brief Metodo para insertar un valor al inicio de la lista (cambiar al valor de la cabeza)
        @param valor que se desea insertar al inicio de la lista
        @return
    */
void LinkedList::insertFront(Node **head, int n) {
	Node* newNode = new Node(n);
	newNode->valor = n;
	newNode->next = *head;
	*head = newNode;
    }

    /**
        @brief metodo para eliminar un nodo, ademas llama el delete sobrecargado.
        
    */
void LinkedList::deleteNode(int nodeOffset)
    {
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;
  
    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }
  
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset) {
        cout << "Index out of range"
             << endl;
        return;
    }
  
    temp1 = head;

    if (nodeOffset == 0) {
  
        head = head->next;
        delete(temp1);
        delete temp1;
        return;
    }
  
    while (nodeOffset-- > 0) {
        temp2 = temp1;

        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
  
    // Delete the node
    delete temp1;

}
    /**
        @brief Metodo que imprime todos lo elementos de la lista
    */
void LinkedList::printList()
    {
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    cout << "[";
    while (temp != NULL) {
        if (temp->next == NULL){
            cout << temp->valor; 
        }
        else{
            cout << temp->valor << ",";
        }
        temp = temp->next;
    }
    cout << "]";
}

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
        @brief Instanciacion de la clase collector
    */
    Collector col;
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
        @brief variable auxiliar de cantidad de elementos en la lista
    */
    int size_aux = 0;
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
                for (int i = 0; i <size; i++){
                   
                    if (size <= size_aux){
                        cout << "The list is full" << endl;
                        break;
                    }
                    cout << "Set value in beginning or end (b/e) ";
                    cin >> first_final;
                   
                    if(first_final=='b'){
                        cout << "Set node value: ";
                        cin >> value;
                        list.insertFront(&(list.head),value);
                        
                    }
                    if(first_final=='e'){
                        cout << "Set node value: ";
                        cin >> value;
                        list.insertNode(value);
                        
                    }
                    size_aux++;
                    
                    cout << size << endl;
                    cout << size_aux << "el aux"<< endl;
                    
                }
            }
            break;
            case 3:
            if (size == NULL){
                cout << "No list created" << endl;
            }
            else {
                size_aux--;
                cout << "Set node to eliminate: ";
                    cin >> value;
                    list.deleteNode(value);
                    cout << "--------------------------------------------------- " <<endl;
                    list.printList(); 
                    cout << "--------------------------------------------------- " <<endl;
            }
            break;
        case 4:
            if (size == NULL){
                cout << "No list created" << endl;
            }
            else{
                cout << "The list is: ";
                list.printList();  
                cout << endl;
            }
            break;
        case 5:
            col.show_collector();
            break;
        case 6:
            break;
        default:
            break;
        }

    }while(option != 6);

    
    return 0;
}
