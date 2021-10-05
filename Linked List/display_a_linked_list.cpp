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
            if(word == "addLast"){
                // get the int argument for the function
                ss >> word;
                
                // call the function
                list.addLast(stoi(word));
                
                // move to next input
                continue;
            }
            
            if(word == "display"){
                list.display();
                continue;
            }
            
            if(word == "size"){
                cout<<list.list_size()<<endl;
                continue;
            }
            
            if(word == "quit"){
                break;
            }
        }
        
    }
    
    return 0;
}