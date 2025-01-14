#include <iostream>

using namespace std;

class myList
{
private:
    string listName;
    int size;
    int *list;

public:
    myList()
    {
        size = 0;
        list = nullptr;
    }
    myList(const myList &listCpy)
    {
        size = listCpy.size;
        list = new int[size];
        for (int i = 0; i < size; i++)
            list[i] = listCpy.list[i];
    }

    //opertor Assignment overloaded on the dedault copy constructor
    void operator = (const myList &listCpy)
    {
        delete[] list;
        size = listCpy.size;
        list = new int[size];
        for (int i = 0; i < size; i++)
            list[i] = listCpy.list[i];
    }

    void setName(string listName)
    {
        this->listName = listName;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    void setList()
    {
        list = new int[size];
        for (int i = 0; i < size; i++)
        {
            list[i] = (rand() % 20) + 1;
        }
    }
    void setValue(int changeValue, int index)
    {
        if (index < size)
        {
            *(list + index) = changeValue;
        }
    }
    void displayList() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << " ";
        }
        cout << "\n";
    }
    ~myList()
    {
        delete[] list;
        list = nullptr;
    }
};
int main()
{
    myList list1;
    list1.setName("PH values");
    list1.setSize(10);
    list1.setList();
    list1.displayList(); // 2 8 15 12 10 5 19 19 3 5

    myList list2;
    list2.setName("PH values");
    list2.setSize(10);
    list2.setList();
    list2.displayList(); // 6 6 2 8 2 12 16 3 8 17

    list2 = list1;//(OPERATOR_ASSIGNMENT_OVERLOADED)
    list2.displayList(); // 2 8 15 12 10 5 19 19 3 5

    list1.setValue(100, 3); // only change in list1

    list1.displayList(); // 2 8 15 100 10 5 19 19 3 5
    list2.displayList(); // 2 8 15 1 10 5 19 19 3 5

    return 0;
}