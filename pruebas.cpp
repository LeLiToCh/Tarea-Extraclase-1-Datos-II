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
    
    int valor; // se queda
     
    Node *next; // se queda
   
    Node (int valor){
        this->valor = valor;
        this->next = NULL; // se queda
    }
    
    void * operator new(size_t size) // se queda
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
   
    void operator delete(void * p) // se queda
    
    {
        std::cout<<"The pointer to delete is: " << p <<std::endl;
        collector->set_collector(p);
        free(p);
    }
};
    
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
    
    void set_node_head(Node *&head, int value){
        Node *new_node = new Node(value);
        // aqui se garda el head
        Node *aux = head;
        head = new_node;
        head->next = aux;
    }
};
   
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

void LinkedList::insertFront(Node **head, int n) {
	Node* newNode = new Node(n);
	newNode->valor = n;
	newNode->next = *head;
	*head = newNode;
}
void LinkedList::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
    // Insert at the last.
    temp->next = newNode;
};

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
                        list.insertFront(&(list.head),value);
                    }
                    else if(first_final=='e'){
                        cout << "Set node value: ";
                        cin >> value;
                        list.insertNode(value);
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
            
            break;
        case 6:
            break;
        default:
            break;
        }

    }while(option != 6);

    
    return 0;
}

