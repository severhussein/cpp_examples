#include "common.h"
#include <list>


void remove_dups(LinkedList &list)
{

}

void remove_dups(std::list<int> &list)
{

}

/*remove duplicates from an unsorted linked list
* additionally, how would you solve this if a temporary buffer was not allowed.
*/
int main()
{
    printl("remove_dups.cpp");

    //1, 10, 2, 2, 5, 4 --> dup in middle
    //1, 10, 2, 5, 4 --> no dups
    //1, 1, 10, 2, 2, 5, 4 --> dup at front
    //1, 10, 2, 2, 5, 4, 4 --> dup at end

    //create list
    LinkedList llist{};
    std::list<int> list{};
    //have a temporary buffer
    std::vector<int> buffer{};

    //iterate through the list, at each iteration check the temporary buffer for duplicates, if duplicate found set a boolean.
    bool duplicate_found{false};
    int duplicate{};

    //create a list
    list.emplace_back(1);
    list.emplace_back(10);
    list.emplace_back(2);
    list.emplace_back(5);
    list.emplace_back(4);
    list.emplace_back(4);

    for(auto elem : list)
    {
        print(elem);
    }
    printl("");

    for(auto list_element : list)
    {
        for(auto vector_element : buffer)
        {
            if(vector_element == list_element)
            {
                duplicate_found = true;
                duplicate = list_element;
            }
        }
        buffer.emplace_back(list_element);
    }

    if(duplicate_found)
    {
        print("We found the duplicate = ");
        print(duplicate);
        
    }
    else
    {
        printl("There was no duplicate found");
    }


    remove_dups(llist);
    remove_dups(list);
    return EXIT_SUCCESS;
}

//Takeaways:
// 1. read the propblem carefully, it said to remove the elements, not only find them.
// 2. instead of a vector, a map would have been a better temporary buffer since it has o{1} time for finding an element, instead of traversing through the whole vector. ie, map.find.
// 3. state the time and space complexity for the problems.