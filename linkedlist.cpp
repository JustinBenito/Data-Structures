#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* nextptr;
} *head, *temp, *tp;
int count_nodes;

void insert_new(int x) {
    struct node* new_node = new struct node;
    new_node->nextptr = NULL;
    new_node->data = x;
    count_nodes++;
    if (head == NULL) {
        head = new_node;
    } else {
        temp = head;
        while (temp->nextptr != NULL) {
            temp = temp->nextptr;
        }
        temp->nextptr = new_node;
    }
}

void find_mid(int mid) {
    if (head == NULL) {
        cout << "The List is empty." << endl;
        return;
    }
    tp = head;
    for (int i = 0; i < mid; i++) {
        tp = tp->nextptr;
    }
    cout << "The Mid element: " << tp->data << endl;
}


int main() {
    head = NULL; 
    count_nodes = 0; 

    int num;
    cout << "Enter Number of nodes: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        int data;
        cout << "Enter Node data " << i + 1 << ": ";
        cin >> data;
        insert_new(data);
    }

    int mid = count_nodes / 2;
    find_mid(mid);
}
