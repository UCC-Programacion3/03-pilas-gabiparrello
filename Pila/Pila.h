#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Pila {
private:

    Nodo<T> *inicio;

public:
    Pila();

    ~Pila();

    void push(T dato);

    T pop();

    bool esVacia();
};


/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T>
Pila<T>::Pila() {
    inicio = NULL;
}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Pila<T>::~Pila() {

    while (!esVacia()) pop();
}


/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Pila<T>::push(T dato) {
    auto *aux = new Nodo<T>(dato, inicio);
    inicio = aux;
}


/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Pila<T>::pop() {

    if (!esVacia()) {
        T dato = inicio->getDato();
        auto *aux = inicio;
        inicio = inicio->getNext();
        delete aux;

        return dato;
    } else throw 4;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Pila<T>::esVacia() {
    return inicio == NULL;
}

#endif //LISTA_H