#include <iostream>
using namespace std;

void insert(int* p_arr ,int &n,int size=7){
    int value; int pos;
    cout<<"Insert number :";
    cin>>value;
    cout<<"At index: ";
    cin>>pos;

    if(pos>=size || pos > n){
        cout<<"----Error :Invaild----"<<endl;
        return;
    } 
    if(p_arr[pos]==0){
        p_arr[pos]=value;

        n++;

    }
    else {
    for(int i=n;i>pos;i--){
        p_arr[i]=p_arr[i-1];
    }
    p_arr[pos]=value;

    n++;

    }
}

void delete_arr(int* p_arr, int &n,int size=7){
    int pos;
     cout<<"Delete index: ";
     cin>>pos;
     if(pos>=size || pos>n){
        cout<<"----Error : Invaild----"<<endl;
        return;
     }
    if(n==0){
        cout<<"--Error : Invaild---"<<endl;
        return;
    }

     
     int index=n-1;
     for(int i=pos;i<index;i++){
        p_arr[i]=p_arr[i+1];
     }

     n--;
    


}


void print(int p_arr[],int n){
    for(int i=0;i<n;i++){
        cout<<p_arr[i]<<" ";
    }
    cout<<endl;
}






  int main(){
    
    int arr[7]={5,4,3,2,1};
    int n=5;
    int options;
    do {
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Print"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Insert your option: ";
        cin>>options;
        switch(options){
          case 1:
          insert(arr,n);
          break;
          case 2:
          delete_arr(arr,n);
          break;
          case 3:
          print(arr,n);
          break;

         
        }


    }while(options!=4);




    return 0;
  }


