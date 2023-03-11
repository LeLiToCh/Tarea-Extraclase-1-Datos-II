#include <iostream>
using namespace std;
/**
    @brief clase nodo de la clase collector, la cual almecena las direcciones eliminadas
    por el usuario para su posterior uso 
*/
class OtherNode{
public:
    /**
        @brief instanciacion del metodo set.
    */
    OtherNode(void);
    /**
        @brief variable del valor a insertar en la lista collector.
    */
    void* value;
    /**
        @brief Nodo auxiliar que almacena el next.
    */
    OtherNode *next;
    /**
        @brief metodo set
        @param valor a asignar
    */
    OtherNode (void* value){
        this->value = value;
        this->next = NULL;
    }
    /**
        @brief metodo set
        @param valor a asignar
    */
       void* get_value(){
        return value;
    }
};
    /**
        @brief clase collector la cual almacena los valores de las posibles variables a guardar
    */
class Collector{

private:


    void set_collector_private(OtherNode *&head, void* value){
  

        OtherNode *new_node = new OtherNode(value);

        OtherNode *temp = head;

        head = new_node;
        head->next = temp;
        std::cout<<"New pointer is: " << value <<std::endl;
    }
    void eliminate_node_collector(OtherNode *&head){
 

        if(head != NULL){
            OtherNode *aux_eliminar;

            aux_eliminar = head;


            head = head->next;
            delete(aux_eliminar);

        }
    }
    void show_collector_private(OtherNode *head){


        OtherNode *current;
        current = head;
        std::cout<<"Current cololector is: " << std::endl;
        while(current != NULL){
            std::cout<<current->value<<"->";
            current = current->next;
        }
    }
public:
    /**
        @brief variable que asigna al primer valor de la lista (inicialmente debe estar vacio si no se ha borrado nada).
    */
    OtherNode *first = NULL;

    /**
        @brief Metodo para agregar algun valor a la clase collector, este se comunica directamente con la clase LinkedList
        @param ffff
        @return
    */
    void set_collector(void *value){
 
        set_collector_private(first, value);
    }
    /**
        @brief metodo para chequear si la lista del collector esta o no vacia para 
        proceder con base a los condicionales del new
        @return valor booleano de si la lista esta o no vacia.
    */
    bool check(){
 
        if (first != NULL){
            return true;
        } else{
            std::cout<<"Garbage collector is empty" << std::endl;
            return false;
        }
    }
    /**
        @brief adaptacion del metodo get para obtener el valor a asignar a la sobrecarga del new.
        @return direccion donde se va a asignar el nuevo valor (donde antes ya estuvo otro nodo)
    */
    void* get_collector_value (){
 
        void* x = first->get_value();
        eliminate_node_collector(first);
        std::cout<<"Value of collector is: " << x <<std::endl;

        return x;
    }
    /**
        @brief metodo para mostrar todos los elementos de la clase collector.
    */
    void show_collector(){

        show_collector_private(first);
    }
};

