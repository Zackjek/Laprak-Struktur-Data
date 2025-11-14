#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++; 
        Q.info[Q.tail] = x;
    } else {
        cout << "Antrean Penuh!" << endl;
    }
}

int dequeue(Queue &Q) {
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head]; 
        Q.head++; 
        
        if (Q.head > Q.tail) {
            CreateQueue(Q); 
        }
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q) {
    
    if (Q.head >= 0) {
        cout << " ";
    }
    cout << Q.head << " -- ";

    
    if (Q.tail >= 0) {
        cout << " ";
    }
    cout << Q.tail << " | ";
    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << (i == Q.tail ? "" : " ");
        }
        cout << endl;
    }
}