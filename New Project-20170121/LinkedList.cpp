#include "LinkedList.h"


LinkedList::LinkedList()
{
    cout << "\nEntering constructor" << endl;
    head = new node;
    head -> song = "head (with no song data)";
    head -> artist = "head (with no artist data)";
    head -> next = NULL;
    listLength 0;
    cout << "Success: head node created. listLength set to 0." << endl;
}

bool LinkedList::insertNode(node * newNode, int position)
{
    cout << "\nEntering insertNode ..." << endl;
    
    if (position <= 0 || (position > listLength + 1))
    {
        cout << "Error: the given position is out of range." << endl;
        return false;
    }
    
    if (!head -> next)
    {
        head -> next = newNode;
        listLength++;
        cout << "Success: added '" << newNode -> song << "' to position " << position << ".\n";
        cout << "listLength = " << listLength << endl;
        return true;
    }
    
    int count = 0;
    node * prevNode = head;
    node * nextNode = head;
    
    while (nextNode)
    {
        if (count == position)
        {
            prevNode -> next = newNode;
            newNode -> next = nextNode;
            listLength++;
            cout << "Success: added '" << newNode -> song << "' to position " << position << ".\n";
            cout << "listLength = " << listLength << endl;
            return true;
        }
        prevNode = nextNode;
        nextNode = prevNode -> next;
        count++;
    }
    
    if (count == position)
    {
        prevNode -> next = newNode;
        newNode -> next = nextNode;
        listLength++;
        cout << "Success: added '" << newNode -> song << "' to position " << position << ".\n";
        cout << "listLength = " << listLength << endl;
        return true;
    }
    
    cout << "Error: song node was not added to list." << endl;
    return false;
}

bool LinkedList::removeNode(int position)
{
    cout << "\nEntering removeNode..." << endl;
    
    if (position <= 0 || (position > listLength + 1))
    {
        cout << "Error: the given position is out of range." << endl;
        return false;
    }
    
    if (!head -> next)
    {
        cout << "Error: there is nothing to remove." << endl;
    }
    
    int count = 0;
    node * prevNode = head;
    node * nextNode = head;
    
    while(nextNode)
    {
        if (count == position)
        {
            prevNode -> next = nextNode -> next;
            delete nextNode;
            listLength--;
            cout << "Success: node at position " << position << " was deleted." << endl;
            cout << "listLength = " << listLength << endl;
            return true;
        }
        prevNode = nextNode;
        nextNode = prevNode -> next;
        count++;
    }
    
    cout << "Error: nothing was removed from the list." << endl;
    return false;
}

void LinkedList::printList()
{
    cout << "\nEntered printList..." << endl;
    
    int count = 0;
    node * prevNode = head;
    node * nextNode = head;
    
    cout << "\n---------------------\n";
    cout << " Song Playlist\n";

    while(nextNode)
    {
        cout << "---------------------\n";
        cout << "\t position: " << count << "\n";
        cout << "\t song: " << nextNode -> song << "\n";
        cout << "\t artist: " << nextNode -> artist << "\n";
        prevNode = nextNode;
        nextNode = prevNode -> next;
        count++;
    }
}

LinkedList::~LinkedList()
{
    cout << "\nEntering Destructor..." << endl;
    node * prevNode = head;
    node * nextNode = head;
    
    while(nextNode)
    {
        prevNode = nextNode;
        nextNode = prevNode -> next;
        delete prevNode;
    }
    
    
    cout << "Success: list is deleted." << endl;
}