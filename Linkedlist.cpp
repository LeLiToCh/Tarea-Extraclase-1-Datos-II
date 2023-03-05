#include <iostream>

using namespace std;

class Node {
public:

    int data;
    Node* next;
  
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
  
class Linkedlist {
    
public:

    Linkedlist() { head = NULL; }

    Node* head;
  
    void insertNode(int);

    void printList();
  
    void deleteNode(int);

    void insertFront(Node **head, int n);
};
  
// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
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
        delete temp1;
        return;
    }
  
    while (nodeOffset-- > 0) {
  
        temp2 = temp1;
  
        temp1 = temp1->next;
    }
  
    temp2->next = temp1->next;
  
    delete temp1;
}
void Linkedlist::insertFront(Node **head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}
  
void Linkedlist::insertNode(int data)
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
  
void Linkedlist::printList()
{
    Node* temp = head;
  
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(int argc, char const *argv[])
{
    Linkedlist list;

    int size;

    int opcion;

    char inicio_final;

    int value;

    do{
        cout << "*****************" << endl;
        cout << "1.Crear Lista simple " << endl;
        cout << "2.Insertar valores en la lista" << endl;
        cout << "3.Eliminar nodo de la lista" << endl;
        cout << "4.Imprimir lista" << endl;
        cout << "5.Ver lista de el bote de basura" << endl;
        cout << "6.Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;

        cout << endl;

        switch ((opcion))
        {
        case 1:
            cout << "Ingrese Valor del tamaño de la lista: ";
            cin >>  size;
            break;
        case 2:
            if (size == NULL){
                cout << "No se ha creado ninguna lista" << endl;
            }
            else{
                for (int i = 0; i < size; i++){

                    cout << "Ingresar el valor al inicio o final (i/f) ";
                    cin >> inicio_final;
                    if(inicio_final=='i'){
                        cout << "Ingrese el valor del primer nodo: ";
                        cin >> value;
                        list.insertFront(&(list.head),value);
                    }
                    else if(inicio_final=='f'){
                        cout << "Ingrese el valor del primer nodo: ";
                        cin >> value;
                        list.insertNode(value);
            }
                }
            }
            break;
        case 3:
            if (size == NULL){
                cout << "No se ha creado ninguna lista" << endl;
            }
            else {
                    size--;
                cout << "Ingrese el valor del elemento que desea eliminar: ";
                cin >> value;
                list.deleteNode(value);
                cout << "--------------------------------------------------- " <<endl;
                list.printList(); 
                cout << "--------------------------------------------------- " <<endl;
            }
            break;
        case 4:
            if (size == NULL){
                cout << "No se ha creado ninguna lista" << endl;
            }
            else{
                cout << "La lista es: ";
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

    }while(opcion != 6);

    
    return 0;
}
