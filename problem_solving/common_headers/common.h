// my_class.h
#ifndef COMMON_H // include guard
#define COMMON_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

//print with new line
template <typename T>
void printl(T print)
{
    std::cout << print << std::endl;
}

//print with no new line
template <typename T>
void print(T print)
{
    std::cout << print << " ";
}


//Linked list implementation
class Node
{
public:
    //Don't allow to create an object of type Node without any data.
    // Node()
    // {
    //     mData = 0;
    //     mNext = nullptr;
    // }
    Node(int data)
    {
        mData = data;
        mNext = nullptr;
    }

    //doesn't make sense to allow Node class to know what the next Node is.
    // Node(int data, Node *next)
    // {
    //     mData = data;
    //     mNext = next;
    // }

    int mData;
    Node *mNext;
};

class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList()
    {
        //delete each node in Linked List.
    }
    //this to me right now doesn't make sense. creating a linked list with a Node already made.
    // LinkedList(int data)
    // {
    //     head = Node(data);
    // }
    void addNode(int data)
    {
        //want to add node at the end.

        //first node
        if(head == nullptr)
        {
            head = new Node(data);
            return;
        }

        //traverse through linked list.
        Node *current = head;
        while(current->mNext != nullptr)
        {
            current = current->mNext;
        }

        //we are at the last node now
        //Node *newNode = new Node(data);
        current->mNext = new Node(data);

    }
    bool removeNode(int data)
    {
        std::cout << "Entering removeNode, removing node with data = " << data << std::endl;
        //traverse through the linkedlist until we find data, then remove it.

        if(head == nullptr)
        {
            return false;
        }

        //first traverse through the data and find the node.
        Node *current = head;
        Node *previous = current;
        while( (current != nullptr) && (current->mData != data) )
        {
            previous = current;
            current = current->mNext;
        }
        //if we couldn't find data
        if(current == nullptr)
        {
            std::cout << "Couldn't find Node to be removed." << std::endl;
            return false;
        }

        //at this point we assume we have the node with the correct data
        //head -> 5, 10, 15
        //also have previous node
        //want to remove 5
        if(current == head)
        {
            head = current->mNext;
        }
        else
        {
            previous->mNext = current->mNext;
        }
        delete current;

        return true;
    }
    void print()
    {
        std::cout << "LinkedList = ";
        Node *current = head;
        while(current != nullptr)
        {
            std::cout << "Node{ "<< current->mData << " } ";
            current = current->mNext;
        }
        std::cout << std::endl;
    }
protected:
private:
    Node *head;
};

#endif /* COMMON_H */