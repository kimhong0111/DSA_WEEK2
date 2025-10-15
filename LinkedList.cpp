#include <iostream>
#include <stdexcept>
#include <string>
#include "LinkedList.hpp"
using namespace std;



int main(){

    LinkedList mystringlist;
    mystringlist.insert_front(1);
    mystringlist.insert_front(2);
    mystringlist.insert_end(3);
    mystringlist.insert_at(4,3);
    mystringlist.printlist();

    cout<<"current list before remove front"<<'\n';
        mystringlist.printlist();

        cout<<mystringlist.Searchlist(5);
   

    return 0;
   }