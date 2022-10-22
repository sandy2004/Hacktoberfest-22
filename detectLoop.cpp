#include<iostream>
#include<map>
using namespace std;

// implementation of node

class Node{
    public:
        int data;
        Node* next;

        Node(int data){          //constructor
            this->data = data;
            this->next = NULL;
        }
};

//singly linked list
//insert at head
void insertAtHead(Node* &head, int d){
    //create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

//insert at tail/end
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

//insert at middle
void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
    //to insert at start
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    Node *temp = head;
    int cnt=1;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    //create a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

//Detect a cycle in list by using map

// bool isDetect(Node* head){
//     if(head == NULL){
//         return false;
//     }
//     map<Node* ,bool>visited;
//     Node* temp = head;
//     while(temp!=NULL){
//         //cycle is present
//         if(visited[temp] == true){
//             cout<<"Present at "<<temp->data<<endl;
//             return true;
//         }
//         visited[temp] = true;
//         temp= temp->next;
//     }
//     return false;

// }
//time complexity->O(n)
//space complexity->O(n)

//Detect the cycle using floyd's detection algo

Node* floydDetectLoop(Node* head){
    if(head == NULL ){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            cout<<"Present at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
//Space Complexity = O(1)
//Time Complexity = o(n)

//traverse linked list
void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

int main(){
    //created a new node
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    //head pointed to node1
   Node* head = node1;

   //tail pointed to node1
   Node* tail = node1;

    print(head);
    //insertAtHead(head,12);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,45);
    print(head);
    insertAtTail(tail,95);
    print(head);
    //insertAtPosition(head,3,5);

    //insertAtPosition(head,1,34);

    insertAtPosition(tail,head,5,22);
    print(head);

    // cout<<head->data<<endl;
    // cout<<tail->data<<endl;
    Node* temp = head;
    tail->next = temp->next;

    // if(isDetect(head)){
    //     cout<<"Cycle is present"<<endl;
    // }
    // else{
    //     cout<<"Cycle is not present"<<endl;
    // }

    if(floydDetectLoop(head)!=NULL){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

   
    return 0;
}