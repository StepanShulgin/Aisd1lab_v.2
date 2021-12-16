#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include "List.h"

using namespace std;




int main()
{
    List MyList;
    List MyList2;
    MyList.push_front(1);
    MyList.push_back(2);
    cout <<"List after adding two elements: " << MyList << endl;
    cout <<"Element with index 0: "<< MyList.at(0) << endl;
    cout <<"Size of List:"<< MyList.get_size() << endl;
    cout <<"Is the List empty? " << MyList.isEmpty() << endl;
    MyList.set(1,1);
    cout <<"List after setting 1 to an element with index 1: "<< MyList << endl;
    MyList.clear();
    MyList.insert(1, 0);
    MyList.push_back(2);
    cout <<"List after clearing and  adding two elements: " << MyList << endl;
    MyList.pop_back();
    MyList.pop_front();
    cout <<"List after deteting two elements: "<< MyList << endl;
    MyList.push_front(1);
    MyList.push_back(2);
    MyList.push_back(1);
    MyList.push_back(2);
    MyList2.push_front(1);
    MyList2.push_back(2);
    cout <<"First List: "<< MyList << endl <<"Second List: "<< MyList2 << endl;
    cout <<"Does the first list contain the second list: " << MyList.contains(MyList2) << endl;
   
    _getch();
    return 0;
}