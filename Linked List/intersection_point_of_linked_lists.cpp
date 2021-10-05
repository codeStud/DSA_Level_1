// NOTE: CORRECT SOLUTION (Pepcoding testcases aren't proper)

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
    private:
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
        
        int intersectionPoint(LinkedList list1, LinkedList list2)
        {
            // find out the difference in the sizes of list1, list2
            int sizeDiff = abs(list1.size - list2.size);
            
            Node *l1 = list1.head;
            Node *l2 = list2.head;
            
            // Whichever is larger, move it's pointer ahead by sizeDiff
            if(list1.size > list2.size){
                for(int i = 0; i < sizeDiff; i++){
                    l1 = l1->next;
                }
            }
            else if(list2.size > list1.size){
                for(int i = 0; i < sizeDiff; i++){
                    l2 = l2->next;
                }
            }
            
            // Now, keep moving both pointers until they meet
            while(l1 != l2){
                l1 = l1->next;
                l2 = l2->next;
            }
            
            if(l1 != nullptr){
                return l1->data;
            }
            else{
                return -1;
            }
        }
        
};


// NOTE: CORRECT SOLUTION (Pepcoding testcases aren't proper)

int main()
{
    int s1, s2;
    cin>>s1;
    
    int x;
    
    LinkedList list1 = LinkedList();
    LinkedList list2 = LinkedList();
    
    for(int i = 0; i < s1; i++){
        cin>>x;
        list1.addLast(x);
    }
    
    cin>>s2;
    
    for(int i = 0; i < s2; i++){
        cin>>x;
        list2.addLast(x);
    }
    
    int firstVal;
    cin>>firstVal;
    
    int lastVal;
    cin>>lastVal;
    
    // Default Constructed will anyways be called. So, below instantiation is simalar
    // to LinkedList res = LinkedList();
    LinkedList res;
    
    // NOTE: CORRECT SOLUTION (Pepcoding testcases aren't proper)
    
    int intersectionValue = res.intersectionPoint(list1, list2);
    
    cout<<intersectionValue;
    
    return 0;
}