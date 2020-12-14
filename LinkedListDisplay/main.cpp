//
//  main.cpp
//  LinkedListDisplay
//
//  Created by Kozart Carter on 12/5/20.
//

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

struct node
{
    int number;
    node *next;
};
node *headOfList = nullptr;


bool isEmpty(node *head);
char menu();
void insertAsFirstElement(node *head, node *last, int number);
void insert(node *head, node *last, int number);
void remove(node *head, node *last);
void showList(node *current);


bool isEmpty(node *head)
{
   if(head == NULL)
       return false;
   else return false;
    
    
}
char menu()
{
    
    char choice;
    cout << "Menu\n";
    cout << "1. Add an item.\n";
    cout << "2. Remove an item.\n";
    cout << "3. Show the list.\n";
    cout << "4. Exit.\n";
    
    cin >> choice;
    return choice;
    
    
}
void insertAsFirstElement(int number)
{
    
    node *temp = new node;
    temp->number = number;
    temp->next = nullptr;
    headOfList = temp;
    
}
void insert(int number)
{
    
  if(headOfList == nullptr)
      insertAsFirstElement(number);
    else
    {
        node *temp = new node;
        temp->number = number;
        temp->next = nullptr;
        
        
        // Needs to find the end of the list and connect the last nodes next variable to our new node that will be inserted
        // Use a while loop to start at head of list and say do you point to a node meaning is your next value not nullptr, if not nullptr want to keep going down the list follow chain one linka at time
        node *lastNode = nullptr;
        node *current = headOfList;
        
        while(current != nullptr)
            { if(current ->next == nullptr)
                {
            
            lastNode = current;
            
                }
            // make current go to the next node in my chain of nodes
            current = current->next;
            } // end of while loop
        
        lastNode->next = temp; // combined last node with temp 
    }
}
void removeLastItem()
{
  if(headOfList == nullptr)
      cout << "The list is already empty. \n";
  else
  {
      cout << "The list contains: \n";
      node *current;
        node *secondTolast;
      current = headOfList;
      // checking if it is a one item list going to remove it so head of list points nullptr
     
      if (headOfList -> next == nullptr)
      {
          current = headOfList;
          headOfList = nullptr;
          // testing testing
    
          delete current;
      } else
      {
          
          do
          {
              secondTolast = current;
              current = current->next;
          } while(current -> next != nullptr);
          secondTolast -> next = nullptr;
          delete current;
          
      } // close of if else for list size checking
      
    }
    
    
}
void showList()
{
    if(headOfList == nullptr)
        cout << "The list is empty\n";
    else
    {
        cout << "The list contains: \n";
        node *current;
        current = headOfList;
       
        do
        {
            cout << current->number << endl;
            current = current->next;
        } while(current != nullptr);
        
    } // close for else

}


int main()
{
    char choice;
    int number;
    
    do{
        
        choice = menu();
        
        switch(choice)
        {
            case '1': cout << "Please enter a number: ";
                cin >> number;
                insert(number);
                break;
            case '2': removeLastItem();
                break;
            case '3': showList();
                break;
            default: cout << "System Exit\n";
        }
    }while(choice != '4' );
    
    return 0;
    }
