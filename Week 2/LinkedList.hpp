#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class Node {
    public:
  int data;
  Node* next;
  explicit Node(const int& v){   //deafult construtor 
    data=v;
    next=nullptr;
     }  


};
class LinkedList {
    private:
    Node* head_;
    Node* curr_;
    int size_;

   public:
   
   LinkedList() {  //default constructor 
    head_=nullptr;  
    size_=0; 
      }   


  // Destructor   
   ~LinkedList() { clear();
   }
    
   bool empty() const { return size_==0;}
   int size()  const  {return size_;}
   

   void insert_front( const int& value){
    Node*n= new Node(value);
    n->next=head_;   // this new node point to old head 
    head_=n;         // head is now new node
    ++size_;
      
    }

    void insert_end(const int& value){
       if(empty()){
        insert_front(value);
        return; 
      }
      curr_=head_;
      while(curr_->next){
           curr_=curr_->next;
      }
      Node*n= new Node(value);
        curr_->next=n;
        ++size_;
           
            

    }
   
    void insert_at(const int& value , int position){
       if(position <0 || position > size_) { throw out_of_range("insert_at: position out of range"); }
       if(position==0) { insert_front(value); return; }
       if(position==size_) { insert_end(value);  return; }  //    in case the position is equal to size we can just insert at the end 

       Node* prev=head_;
       for(int i=0; i<position-1; ++i){
           prev=prev->next;
          }

      Node* n= new Node(value);
      n->next=prev->next; 
      prev->next=n;
      ++size_;



    }
   
   
   
   void remove_front(){
    if(empty()) return ;
     Node* temp = head_; // store old head
     head_=head_->next;  // move head  forward
     delete temp;     // delete old hed
     --size_;
     
   }

   void remove_end(){
    if(empty()){ return;}
    if(size_==1) {remove_front();  return;}
    curr_=head_;
    while(curr_->next->next!=nullptr){
      curr_=curr_->next;
    }
    delete curr_->next;
    curr_->next=nullptr;
    --size_;


   }
   
   
   void remove_at(int position){
      if(position<0 || position>=size_) { throw out_of_range("remove_at:out of range");}
      if(position==0) {remove_front(); return;}
      if(position==size_-1){ remove_end(); return;}
     
      Node* prev=head_;
      for(int i=0;i<position-1;i++){
        prev=prev->next;
      }
      Node* victim=prev->next;
      prev->next=victim->next;
      delete victim;
      --size_;
   }

   bool Searchlist(const int&value){
        curr_=head_;
        while(curr_!=nullptr){
          if(curr_->data==value){
            return true;
           }
          curr_=curr_->next;
        }
     
        return false;
   }


   void Swap(const int& x , const int& y){
      if(x==y) {return;}

         Node *prevX=nullptr , *prevY=nullptr;
         Node *currX=nullptr, *currY=nullptr;
         curr_=head_;
         while(curr_!=nullptr){
               if(curr_->data==x){
                currX=curr_;
                break;
               }
               prevX=curr_;
               curr_=curr_->next;

         }
         curr_=head_;
         while(curr_!=nullptr){
             if(curr_->data==y){
              currY=curr_;
              break;
             }
             prevY=curr_;
             curr_=curr_->next;

         }
           if(currX==nullptr || currY==nullptr){
            return;
         }

         if(currX->next==currY){
              
          if(prevX){
            prevX->next=currY;
          }else{
            head_=currY;

          }

          currX->next=currY->next;
          currY->next=currX;
       } 

       else if(currY->next==currX){
              if(prevY){
                prevY->next=currX;
              }
              else {
                head_=currX;
              }
              currY->next=currX->next;
              currX->next=currY;

         } 
       
        
         else {
        
        if(prevX!=nullptr){
              prevX->next=currY;
        }
        else{
          head_=currY;
        }

        if(prevY!=nullptr){
              prevY->next=currX;
        }
        else{
          head_=currX;
        }

        Node* temp=currY->next;
        currY->next=currX->next;
        currX->next=temp;
         }
         
   }
   
   
   
   //utilities
 void clear(){
    while(!empty()){
       remove_front();
    }
  }

   void printlist(){
         curr_=head_;
    while(curr_!=nullptr){
        cout<<curr_->data<<"->";
        curr_=curr_->next;
    }
    cout<<endl;
   }

   
 


};
