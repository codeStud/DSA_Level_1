#include<iostream>
#include<vector>
#include<sstream>   // for stringstream
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    public:
        Node *head = nullptr;
        Node *tail = nullptr;
        int size = 0;
        
        Node* getNodeAt(int idx)
        {
            Node *temp = head;
            for(int i = 0; i < idx; i++){
                temp = temp->next;
            }
            
            return temp;
        }
        
    public:
        void addLast(int val)
        {
            // cout<<size<<" ";
            // create object in heap (dynamic space allocation + access using pointer)
            Node *newNode = new Node();
            newNode->data = val;
            // nullptr is a "null pointer" but NULL is simply a value=0
            newNode->next = nullptr;
            
            if(size == 0){
                head = tail = newNode;
            }
            
            else{
                tail->next = newNode;
                tail = newNode;
            }
            
            size++;
            
        }
        
        // can't have same name members in a c++ class this don't write "size()"
        int list_size()
        {
            return size;
        }
        
        void display()
        {
            Node *temp = new Node();
            temp = head;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            
            cout<<endl;
        }
        
        void removeFirst()
        {
            if(size == 0){
                cout<<"List is empty"<<endl;
            }
            else if(size == 1){
                Node *temp = head;
                head = tail = nullptr;
                delete temp;
                
                size--;
            }
            else{
                Node *temp = head;
                head = head->next;
                delete temp;
                
                size--;
            }
        }
        
        void getFirst()
        {
            if(size == 0){
                cout<<"List is empty"<<endl;
            }
            else{
                cout<<head->data<<endl;
            }
        }
        
        void getLast()
        {
            if(size == 0){
                cout<<"List is empty"<<endl;
            }
            else{
                cout<<tail->data<<endl;
            }
        }
        
        void getAt(int idx)
        {
            if(size == 0){
                cout<<"List is empty"<<endl;
            }
            else if(idx < 0 || idx >= size){
                cout<<"Invalid arguments"<<endl;
            }
            else{
                Node *temp = head;
                for(int i = 0; i < idx; i++){
                    temp = temp->next;
                }
                cout<<temp->data<<endl;
            }
        }
        
        void addFirst(int val)
        {
            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = head;
            head = newNode;
            
            if(size == 0){
                tail = newNode;
            }
            
            size++;
        }
        
        void addAt(int idx, int val)
        {
            if(idx < 0 || idx > size){
                cout<<"Invalid arguments"<<endl;
            }
            else if(idx == 0){
                addFirst(val);
            }
            else if(idx == size){
                addLast(val);
            }
            else{
                Node *newNode = new Node();
                newNode->data = val;
                
                // go till idx-1 th node
                Node *temp = head;
                for(int i = 0; i < idx - 1; i++){
                    temp = temp->next;
                }
                
                newNode->next = temp->next;
                temp->next = newNode;
                
                size++;
            }
        }
        
        void removeLast()
        {
            if(size == 0){
                cout<<"List is empty"<<endl;
            }
            else if(size == 1){
                Node *temp = tail;
                head = tail = nullptr;
                delete temp;
                
                // DON'T FORGET TO DECREMENT THE size
                size--;
            }
            else{
                Node *temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                
                Node *temp2 = tail;
                tail = temp;
                tail->next = nullptr;
                
                delete(temp2);
                
                // DON'T FORGET TO DECREMENT THE size
                size--;
            }
        }
        
        void removeAt(int idx)
        {
            if(idx < 0 || idx >= size){
                cout<<"Invalid arguments"<<endl;        
            }
            else if(idx == 0){
                removeFirst();
            }
            else if(idx == size - 1){
                removeLast();
            }
            else{
                Node *temp = head;
                for(int i = 0; i < idx - 1; i++){
                    temp = temp->next;
                }
                
                Node *temp2 = temp->next;
                
                temp->next = temp->next->next;
                
                delete(temp2);
                
                // DON'T FORGET TO DECREMENT THE size
                size--;
            }
        }
        
        Node* midNode(Node *head, Node *tail)
        {
            Node *slow, *fast;
            slow = fast = head;
            
            while(fast != tail && fast->next != tail){
                slow = slow->next;
                fast = fast->next->next;
            }
            
            return slow;
        }
        
        LinkedList mergeLists(LinkedList l1, LinkedList l2)
        {
            Node *p1 = l1.head;
            Node *p2 = l2.head;
            
            LinkedList final;
            
            while(p1 != nullptr && p2 != nullptr){
                if(p1->data < p2->data){
                    final.addLast(p1->data);
                    p1 = p1->next;
                }
                else{
                    final.addLast(p2->data);
                    p2 = p2->next;
                }
            }
            
            // add the remaining list
            while(p1 != nullptr){
                final.addLast(p1->data);
                p1 = p1->next;
            }
            
            while(p2 != nullptr){
                final.addLast(p2->data);
                p2 = p2->next;
            }
            
            return final;
        }
        
        
        LinkedList mergeSort(LinkedList li, Node *head, Node *tail)
        {
            // base case - when you've a single node to sort
            if(head == tail){
                // create a new List -> add the node's value -> return list
                LinkedList baseList;
                baseList.addLast(head->data);
                
                return baseList;
            }
            
            // get the mid-node
            Node *mid = midNode(head, tail);
            
            // get the first sorted half list
            LinkedList firstSortedHalf = mergeSort(li, head, mid);
            
            // get the next sorted half list
            LinkedList secondSortedHalf = mergeSort(li, mid->next, tail);
            
            // create a new list by merging two sorted-half lists
            LinkedList res;
            res = res.mergeLists(firstSortedHalf, secondSortedHalf);
            
            return res;
        }
        
        LinkedList removeDuplicates()
        {
            // create a new list
            LinkedList res;
            
            while(this->size != 0){
                int val = this->head->data;
                // move to the next node and remove first node
                this->removeFirst();
                
                // add unique values of list into res
                if(res.size == 0 || res.tail->data != val){
                    res.addLast(val);
                }
            }
            
            return res;
        }
        
        void k_reverse(int k)
        {
            // keep only single copy of prev
            LinkedList prev;
            
            while(this->size > 0){
                // declare new cur every time after 'k' reversal
                LinkedList cur;
                
                // if the "list" has at least 'k' nodes remaining => do k-reverse
                if(this->size >= k){
                    for(int i = 0; i < k; i++){
                        // keep deleting nodes from "list" to keep CONSTANT SPACE
                        int val = this->head->data;
                        this->removeFirst();
                        
                        cur.addFirst(val);
                    }
                }
                
                // if size of "list" < k => DON'T reverse
                else{
                    int n = this->size;
                    
                    for(int i = 0; i < n; i++){
                        int val = this->head->data;
                        this->removeFirst();
                        
                        // addLAST to make sure nodes don't get reversed
                        cur.addLast(val);
                    }
                }
                
                // if prev is empty => make prev = cur
                if(prev.size == 0){
                    prev = cur;
                }
                // else - (a) set prev.tail->next as cur.head (b) set prev.tail to cur.tail (c) increment prev.size
                else{
                    prev.tail->next = cur.head;
                    prev.tail = cur.tail;
                    prev.size += cur.size;
                }
                
            }
            
            // UPDATE "this" ptr
            this->head = prev.head;
            this->tail = prev.tail;
            this->size = prev.size;
        }
        
};


int main()
{
    int n;
    cin>>n;
    
    int x;
    
    LinkedList list;
    
    for(int i = 0; i < n; i++){
        cin>>x;
        list.addLast(x);
    }
    
    int k;
    cin>>k;
    
    int firstVal;
    cin>>firstVal;
    
    int lastVal;
    cin>>lastVal;
    
    // NOTE: removeDuplicates take O(n) time and O(1) space bcz we remove nodes
    // from list and then only add to res. Thus, no extra space taken.
    
    // we are calling k_reverse() ON list (& will use this keyword).
    
    // NOTE NOTE: "this" pointer has been appropriately set at the end of the function above.

    list.display();
   
    list.k_reverse(k);
    
    list.display();
    
    // for test case checking
    list.addFirst(firstVal);
    list.addLast(lastVal);
    list.display();
    
    return 0;
}