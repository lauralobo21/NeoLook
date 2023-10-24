#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdexcept>

template <typename Type>
class PriorityQueue {
private:
   struct Node {
        Type value;
        Node* next;

        Node(const Type& val, Node* nextPtr)
            : value(val), next(nextPtr) {}
    };

    Node* m_first{};

public:
    // Construtor default
    PriorityQueue() = default;

    // Função const para retornar o tamanho da fila de prioridade.
    unsigned int size() const {
        unsigned int count = 0;
        Node* current = m_first;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
    
    // Parte principal do codigo.
    // Funcao que insere elemento na fila.
    // Complexidade O(1).
     void push(const Type& elem) {
        Node* newNode = new Node(elem, nullptr);
        //Caso 1: se a fila estiver vazia ou o numero for menor que o primeiro
        //ele se torna o primeiro nó da fila.
        if (!m_first || elem < m_first->value) {
            newNode->next = m_first;
            m_first = newNode;
        }
        //Caso contrario, percorre toda a lista até encontrar a posição adequada. 
        else {
            Node* current = m_first;
            while (current->next && elem >= current->next->value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    
    //Esta função remove o elemento de maior prioridade da fila.
    //Usa um auxiliar para armazenar o m_first, e realonar o proximo.
    //Se a lista estiver vazia, lanca uma exception
    //Complexidade O(1).
    void pop() {
        if (empty()) {
            throw std::runtime_error("fila de prioridade vazia");
        }
        Node* temp = m_first;
        m_first = m_first->next;
        delete temp;
    }

    //Esta função retorna o elemento de maior prioridade na fila, sem removê-lo.
    //Se a lista estiver vazia, lanca uma exception
    Type& top() {
        if (empty()) {
            throw std::runtime_error("fila de prioridade vazia");
        }
        return m_first->value;
    }

    // Função const para verificar seja a fila está vazia.
    //Complexidade O(1).
    bool empty() const {
        return m_first == nullptr || m_first == 0;
    }

    // Destrutor: deleta todos os nos da fila
    // Enquanto houver algum elemento na lista, ele o destroi o primeiro
    // torna o segundo o primeiro, e assim sucessivamente.
    ~PriorityQueue() {
        while (m_first) {
            Node* temp = m_first;
            m_first = m_first->next;
            delete temp;
        }
    }
};
#endif