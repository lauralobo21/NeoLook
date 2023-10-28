/*
Nome dos integrantes da dupla:
    Hugo das Chagas Silva - 553635
    Laura Soléria Lobo Vitorino Maciel - 555523
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept> // cabecalho que contem as classes de exception
#include <iostream>  // para usar o std::swap


template <typename Type>
struct Node {
    Type value; 
    Node *next; 

  
    Node(const Type& val, Node *nextPtr) { 
        value = val;
        next = nextPtr;
    }

    // Destrutor.
    // Complexidade O(1)
    ~Node() {
        delete next;
    }

}; // fim da classe Node<T>

//
template <typename Type>
class Queue {
private:
    Node<Type>* m_first {};     // Ponteiro apontando para o primeiro elemento
    Node<Type>* m_last {};      // Ponteiro apontando para o último elelmento
    unsigned m_size {};         // Tamanho atual da lista

public:
    // Construtor default
    // Complexidade O(1)
    Queue() = default;

    // Funcao const que retorna o numero de elementos na fila
    // Complexidade O(1)
    unsigned size() const {
        return m_size;
    }

    // Funcao const que retorna se a fila esta vazia
    // Complexidade O(1)
    bool empty() const {
        return m_size == 0;
    }

    // Funcao que insere elemento na fila (sempre no final da fila: politica FIFO)
    // Complexidade O(1)
    void push(const Type& elem) {
        if(m_first == nullptr) { // Caso 1: fila vazia
            m_last = m_first = new Node<Type>(elem, nullptr);
        }
        else { // Caso 2: fila nao-vazia
            m_last->next = new Node<Type>(elem, nullptr);
            m_last = m_last->next;
        }
        m_size++;
    }

    // Funcao que remove um elemento da fila (sempre no inicio da fila: politica FIFO).
    // Se a fila estiver vazia nao faz nada.
    // Complexidade O(1)
    void pop() {
        if(m_size != 0) {
            Node<Type> *aux = m_first;
            m_first = m_first->next;
            aux->next = nullptr;
            delete aux;
            m_size--;
            if(m_size == 0) {
                m_last = nullptr;
            }
        }
    }

    // Funcao que acessa o primeiro elemento da fila
    // Se a lista estiver vazia, lanca uma exception
    // Complexidade O(1)
    Type& front() {
        if(m_size == 0) {
            throw std::runtime_error("fila vazia");
        }
        else {
            return m_first->value;
        }
    }

    // Funcao const que acessa o primeiro elemento da fila.
    // Se a lista estiver vazia, lanca uma exception
    // Complexidade O(1)
    const Type& front() const {
        if(m_size == 0) {
            throw std::runtime_error("fila vazia");
        }
        else {
            return m_first->value;
        }
    }

    // Funcao que acessa o ultimo elemento da fila.
    // Se a lista estiver vazia, lanca uma exception
    // Complexidade O(1)
    Type& back() {
        if(m_size == 0) {
            throw std::runtime_error("fila vazia");
        }
        else {
            return m_last->value;
        }
    }

    // Funcao const que acessa o ultimo elemento da fila.
    // Se a lista estiver vazia, lanca uma exception
    // Complexidade O(1)
    const Type& back() const {
        if(m_size == 0) {
            throw std::runtime_error("fila vazia");
        }
        else {
            return m_last->value;
        }
    }

    // Destrutor: deleta todos os nos da fila
    // Ao chamar o destrutor de m_first, os destrutores dos demais nos
    // na lista encadeada sao chamados e os nos vao sendo deletados de 
    // tras para frente recursivamente.
    // Complexidade O(1)
    ~Queue() {
        delete m_first;
    }

    // Funcao que troca duas filas.
    // Essa funcao recebe uma referencia para uma fila e troca essa fila
    // com a fila que chamou essa funcao.
    // Usamos a funcao auxiliar std::swap do cabecalho <iostream>
    // Complexidade O(n)
    void swap(Queue& f) {
        std::swap(m_size, f.m_size);
        std::swap(m_first, f.m_first);
        std::swap(m_last, f.m_last);
    }

}; // fim da classe Queue<T>

#endif