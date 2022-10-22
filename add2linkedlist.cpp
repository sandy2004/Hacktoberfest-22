#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this->data = d;
            this->next = NULL;
        }
};

void insertAtEnd(Node* &head, Node* &end, int d){
    if(head == NULL){
        Node* node1 = new Node(d);
        head = node1;
        end = node1;
    }
    else{
        Node* node1 = new Node(d);
        end->next = node1;
        end = node1;
    }

}

Node* reverse(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* forw = NULL;
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;

}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* node1 = new Node(d);
        head = node1;
        tail = node1;
    }
    else{
        Node* node1 = new Node(d);
        tail->next = node1;
        tail = node1;
    }

}

void insertAtHead(Node* &head, int d){
    //create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* add(Node* first,Node* second){
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first!=NULL || second!=NULL ||carry!=0){
        int val1 = 0;
        if(first!=NULL){
            val1 = first->data;
        }
        int val2 = 0;
        if(second!=NULL){
            val2 = second->data;
        }
        int sum = carry+val1+val2;
        int digit = sum%10;

        //create node and push ans in ans linked list
        insertAtTail(ansHead,ansTail, digit);
        carry=sum/10;

        if(first!=NULL){
            first = first->next;
        }
        if(second!=NULL){
            second = second->next;
        }
    }
    return ansHead;
}

Node* sum(Node* first, Node* second){
    
    //Step 1 to reverse both list
    first = reverse(first);
    second = reverse(second);

    //Step2 add from left
    Node* ans = add(first,second);
    
    //Step3 reverse ans list
    ans = reverse(ans);
    return ans;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    Node* end = NULL;
    insertAtEnd(head,end,3);
    insertAtEnd(head,end,5);
    print(head);

    Node* head1 = NULL;
    Node* end1 = NULL;
    insertAtEnd(head1,end1,4);
    insertAtEnd(head1,end1,7);
    insertAtEnd(head1,end1,8);
    print(head1);


    Node* result = sum(head,head1);
    print(result);

    return 0;
 
}