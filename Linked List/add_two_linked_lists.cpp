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
        
        // NOTE: This functions returns CARRY
        int addListsUtil(Node *num1, int placeValue1, Node *num2, int placeValue2, LinkedList& ans)
        {
            // Base case - when both numbers are over (i.e extreme right)
            if(num1 == nullptr && num2 == nullptr){
                // return carry = 0
                return 0;
            }
            
            int sum = 0;
            
            if(placeValue1 > placeValue2){
                // this current num1->data can't be added with current num2->data
                // Thus, move num1 forward => placeValue1 gets decremented by 1
                int prevCarry = addListsUtil(num1->next, placeValue1 - 1, num2, placeValue2, ans);
                
                // Here NO num2->data to add to num1->data. So, only add prevCarry
                sum = num1->data + prevCarry;
            }
            
            else if(placeValue1 < placeValue2){
                // this current num2->data can't be added with current num1->data
                // Thus, move num2 forward => placeValue2 gets decremented by 1
                int prevCarry = addListsUtil(num1, placeValue1, num2->next, placeValue2 - 1, ans);
                
                // Here NO num1->data to add to num2->data. So, only add prevCarry
                sum = num2->data + prevCarry;
            }
            
            else{
                // both numbers are at correct place-value and can be added
                // BUT ADDITION HAS TO BE DONE FROM RIGHT TO LEFT, ALONG WITH CARRY
                // SO, move both nums forward & DO ADDITION WHEN RECURSION FOLDS BACK
                int prevCarry = addListsUtil(num1->next, placeValue1 - 1, num2->next, placeValue2 - 1, ans);
                
                sum = num1->data + num2->data + prevCarry;
            }
            
            // COMMON PART FOR ALL RECURSION FOLDBACKS
            int data = sum % 10;
            int newCarry = sum / 10;
                
            // put data in ans linked-list
            ans.addFirst(data);
            
            // return newCarry which will act as prevCarry for the next recursion foldback
            return newCarry;
        }
        
        LinkedList addLists(LinkedList l1, LinkedList l2)
        {
            // NOTE: We will pass 5 things to utility function
            // (1) l1.head (MSB of l1)  
            // (2) Place-value of l1->head (i.e index of MSB = l1.size)
            // (3) l2.head (MSB of l2)
            // (4) Place-value of l2->head (i.e index of MSB = l2.size)
            // (5) A new linked-list (BY REFERENCE), to store result of addition
            
            LinkedList ans;
            int carry = addListsUtil(l1.head, l1.size, l2.head, l2.size, ans);
            
            if(carry > 0){
                ans.addFirst(carry);
            }
            
            return ans;
        }
};


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
    
    res = res.addLists(list1, list2);
    
    list1.display();
    list2.display();
    res.display();
    
    // for test case checking
    res.addFirst(firstVal);
    res.addLast(lastVal);
    res.display();
    
    return 0;
}