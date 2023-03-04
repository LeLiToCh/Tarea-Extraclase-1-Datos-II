#include <iostream>
using namespace std;
#include<conio.h>

struct Node {
	int data;
	Node* next;
};
void initNode(struct Node *head,int n){
	head->data = n;
	head->next =NULL;
}
void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}
void insertFront(struct Node **head, int n){
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

int main() {
    struct Node *newHead;
	struct Node *head = new Node;
    bool first=true;
    int value;
    char answer;
	bool status= true;
    do{
        if(first==true){
            cout << "Ingrese valor: ";
            cin >> value;
            initNode(head,value);
            cout <<"Ingresar otro valor (y/n)";
            answer = getch();
            first=false;
        }
        if(answer=='n' && first!=true){
            cout <<"Desea ver los elementos de la lista? (y/n)";
            answer = getch();
            if(answer=='y'){
                display(head);
                return 0;
            }
            else{
               status==false;
            }
        }
        if(answer=='y'  && first!=true){
            cout << "Ingrese valor: ";
            cin >> value;
            addNode(head,value);
            cout <<"Ingresar otro valor (y/n)";
            answer = getch();
        }

    }while (status==true);

    

	return 0;
}