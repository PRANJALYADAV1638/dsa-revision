#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

node* add(node* head, node* temp){
    if(head == temp){
        if(head->data == 9){
            head->data = 0;
            node* newnode = new node(1);
            newnode->next = head;
            return newnode;
        }
        head->data++;
        return head;
    }
    if(temp->data >= 0 && temp->data < 9){
        temp->data = temp->data + 1;
        return head;
    }
    else{
        temp->data = 0;
    
        node* prev = head;
        while(prev->next != temp) {
            prev = prev->next;
        }
        head = add(head, prev);  
        return head;
    }
}

void print(node* head){
    while(head){
        cout << head->data;
        head = head->next;
    }
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(9);
    head->next->next->next = new node(9);
    head->next->next->next->next = new node(9);

    if(head == nullptr){
        cout << "1";
        return 0;
    }

    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }

    print(head);
    cout << endl;

    head = add(head, temp);  
    print(head);
}

/*
node* add(node* head, node* temp) {
    // Find the rightmost non-9 node
    node* lastNonNine = nullptr;
    node* cur = head;
    while (cur != nullptr) {
        if (cur->data != 9)
            lastNonNine = cur;
        cur = cur->next;
    }

    // If all digits are 9, create new head
    if (lastNonNine == nullptr) {
        node* newHead = new node(1);
        newHead->next = head;
        // set all original digits to 0
        cur = head;
        while (cur != nullptr) {
            cur->data = 0;
            cur = cur->next;
        }
        return newHead;
    }

    // Increment the rightmost non-9 digit
    lastNonNine->data++;

    // Set all following digits to 0
    cur = lastNonNine->next;
    while (cur != nullptr) {
        cur->data = 0;
        cur = cur->next;
    }

    return head;
}
    */