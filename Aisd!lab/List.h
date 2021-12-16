#pragma once
#include <stdlib.h>
#include <iostream>



using namespace std;



class List
{
private:

    size_t size_of_list;

    struct Element
    {
        int member;
        Element* Next, * Previous;
     };
     Element* Head, * Tail;

public:

    


    List()                             //Constructor
    {
        Head = Tail = NULL;
        Element* temp = new Element;
        temp->Previous = NULL;
        temp->Next = NULL;
        temp->member = NULL;
        size_of_list = 0;
    }

    ~List()                           //Destructor
    {
        clear();
    }


    void clear()
    {
        Element* temp = Head; // Create temporary node
                        
        while (Head != NULL) {
            Element* temp = Head->Next;
            delete Head;
            Head = temp;
        }
        Tail = Head;
        size_of_list = 0;
    }

    size_t get_size()                  
    {
        return size_of_list;
    }
    bool contains(List& secondList)                                 //Checking for the content of another list in the list
    {
        int temporary = 0;
        
        if ((size_of_list == 0) || (secondList.get_size() == 0))   //If one of the lists is empty
        {
            if (secondList.get_size() == 0)
                return true;
            if (size_of_list == 0)
                return false;
            
        }
        Element* temp = Head;
        if (size_of_list < secondList.get_size())                   //If the size of the first list is smaller than the second
            return false;
        for (int i = 0; i < size_of_list; i++)
        {
            if(i> secondList.get_size()-1)
                return false;

            if ((temp == NULL))
                return false;
           
            if (temp->member == secondList.at(i))
            {
                
                temporary = i;
                break;
            }

            else
                temp = temp->Next;
        }
        
        while ((temp != Tail) && (temporary < secondList.get_size() - 1))
        {
            
            if (temp->member == secondList.at(temporary))
            {
                temp = temp->Next;
                temporary++;
            }
            else
                return false;
        }
        if ((temp == Tail) && (temporary < secondList.get_size()) - 1)
        {
            return false;
        }
        if ((temporary == secondList.get_size()) - 1)
        {
            
            if (temp->member == secondList.at(temporary))
                return true;
            else
                return false;
        }
        
    }
    void remove(size_t number)                       //Removing element with key
    {
        if (number < get_size())
        {
            if (number == 0)
            {
                return pop_front();
            }
            else if (number == size_of_list - 1)
            {
                return pop_back();
            }
            else {
                Element* temp = Head;
                Element* newTemp;
                for (int i = 0; i < number - 1; i++)
                    temp = temp->Next;
                newTemp = temp->Next;
                temp->Next = newTemp->Next;
                delete newTemp;
                size_of_list--;

            }
        }
        else
        {
            throw out_of_range("Out of range");
        }
    }

    void push_front(int newMember)                            //Add a new element forward
    { 
        Element* temp = new Element;
        temp->Next = NULL;
        temp->member = newMember;
       

        if (Head != NULL)                             //If List is empty
        {  
            temp->Next = Head;
            Head->Previous = temp;
            Head = temp;
            size_of_list++;
        }
        else                                          //If List is not empty
        {
            
            temp->Previous = NULL;
            Head = Tail = temp;
            size_of_list++;
        }
    }

    void push_back(int newMember)                           //Add a new element to the end
    {
            Element* temp = new Element;
            temp->Next = NULL;
            temp->member = newMember;

            if (Head != NULL)                           //If List is not empty
            {
                temp->Previous = Tail;
                Tail->Next = temp;
                Tail = temp;
                size_of_list++;
            }
            else                                        //If List is empty
            {
                temp->Previous = NULL;
                Head = Tail = temp;
                size_of_list++;
            }

        

        
    }

    void pop_back()                                           //Removing the element from the end                                    
    {
        if (isEmpty() == 0)                                     //If List is not empty
        {
            if (Head == Tail)                                 //If there is only one element in the list
            {
                Head->Next = NULL;
                Head = NULL;
                delete Head;
                size_of_list--;
            }
            else                                               //If there is more then  one element in the list
            {
                Element* temp = Tail;
                Tail = Tail->Previous;
                Tail->Next = NULL;
                delete temp;
                size_of_list--;
            }

        }
        else 
        {
            throw invalid_argument("List is empty");
        }
       
    }

    void pop_front()                                                //Removing the element from the beginning 
    {
        if (Head != NULL)
        {         
             Element* current = Head;
             Head = Head->Next;
             delete current;
             size_of_list--;
               
        }
        else {
            throw invalid_argument("List is empty");
        }
    }

   

    bool isEmpty()                                                     //Checking for emptiness
    {
        if (Head == NULL)
            return true;
        else
            return false;
    }

    int at(size_t elem)                                                 //Getting an element by index
    {

        if (elem < get_size()) // If index is in List range
        {
            Element* temp = Head; // Create temporary node
            for (int i = 0; i < elem; i++) {
                temp = temp->Next;
            }
            return temp->member;
        }
        else {
            throw out_of_range("Out of range");
        }


    }

    void set(size_t elem, int newMember)                                        //Replacing an element by index with the transmitted element
    {
        if (elem > get_size() - 1) {         //Out of range
            throw out_of_range("Out of range");
        }
        else {
            Element* temp = Head;
            for (int i = 0; i < elem; i++)
                temp = temp->Next;
            temp->member = newMember;
           
        }
    }

    void insert(int value, size_t elem)                                //Inserting before an element that was previously available by this index
    {

         if(elem > get_size() - 1)
            throw out_of_range("Out of range");
         else
         {
             if ((elem == 0) || (elem = get_size() - 1))                         //Adding to extreme points
             {
                 if (elem == 0)
                     push_front(value);
                 if (elem = get_size() - 1)
                     push_back(value);
             }

                      



             else                                                             //Adding to the middle
             {
                 Element* temp = Head, * save;
                 for (int i = 0; i < elem - 1; i++)
                     temp = temp->Next;
                 Element* newElement = new Element;

                 newElement->member = value;
                 save = temp->Next;
                 temp->Next;
                 temp->Next = newElement;
                 newElement->Next = save;
                 size_of_list++;
             }
             
         }
    }
            
        
                   


    
    


friend ostream& operator << (ostream& stream, const List& list);


};

ostream& operator << (ostream& stream, const List& list)
{
    List::Element* write = list.Head;
    while (write != NULL) {
        stream << write->member << " ";
        write = write->Next;
    }
    return stream;
}
