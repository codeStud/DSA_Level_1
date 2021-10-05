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
        
        void reverseDI()
        {
            int li = 0;
            int ri = size - 1;
            
            while(li < ri){
                Node *left = getNodeAt(li);
                Node *right = getNodeAt(ri);
                
                int temp = left->data;
                left->data = right->data;
                right->data = temp;
                
                li++;
                ri--;
            }
        }
};


int main()
{
    string str;
    
    // Instantiate object of LinkedList (No need of dynamic memory allocation in heap)
    LinkedList list = LinkedList();
    
    while(str != "quit"){
        getline(cin, str, '\n');
        
        stringstream ss;
        // taking value from str and passing it to ss, Just like "cout" stream..
        ss << str;      
        string word;
        
        // taking value from ss and storing it in word, Just like "cin" stream..
        while(ss >> word){
            if(word == "display"){
                list.display();
                continue;
            }
            
            if(word == "size"){
                cout<<list.list_size()<<endl;
                continue;
            }
            
            if(word == "getFirst"){
                list.getFirst();
                continue;
            }
            
            if(word == "getLast"){
                list.getLast();
                continue;
            }
            
            if(word == "getAt"){
                // get the index
                ss >> word;
                list.getAt(stoi(word));
                continue;
            }
            
            if(word == "addFirst"){
                // get the value to add
                ss >> word;
                list.addFirst(stoi(word));
                continue;
            }
            
            if(word == "addLast"){
                // get the int argument for the function
                ss >> word;
                
                // call the function
                list.addLast(stoi(word));
                
                // move to next input
                continue;
            }
            
            if(word == "addAt"){
                // get the index to add
                int idx;
                ss >> word;
                idx = stoi(word);
                
                // get the value to add
                int val;
                ss >> word;
                val = stoi(word);
                
                list.addAt(idx, val);
                continue;
            }
            
            if(word == "removeFirst"){
                list.removeFirst();
                continue;
            }
            
            if(word == "removeLast"){
                list.removeLast();
                continue;
            }
            
            if(word == "removeAt"){
                // get the idx
                ss >> word;
                list.removeAt(stoi(word));
                continue;
            }
            
            if(word == "reverseDI"){
                list.reverseDI();
                continue;
            }
            
            if(word == "quit"){
                break;
            }
        }
        
    }
    
    return 0;
}