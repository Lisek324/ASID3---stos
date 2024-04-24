#include <iostream>
#include <random>
struct stack {
    int maxSize;
    int topIndex;
    int* items;
};

struct stack* newStack(int capacity) {
    struct stack *stck = (struct stack*)new stack[sizeof(struct stack)];

    stck->maxSize = capacity;
    stck->topIndex = -1;
    stck->items = (int*) new int[sizeof(int)*capacity];

    return stck;
}

int size(struct stack* stck) 
{
    return (stck->topIndex) + 1;
}

bool isFull(struct stack* stck) 
{
    return(size(stck)==stck->maxSize) ? true : false;
}

bool isEmpty(struct stack* stck)
{
    return(stck->topIndex == -1) ? true : false;
}

void push(struct stack* stck, int x) {
    if (isFull(stck)) {
        std::cout << "Stack is full. Operation cancelled" << "\n";
        //exit(EXIT_FAILURE);
    }
    else {
        std::cout << "Stack not full. Item " << x << " pushed" << "\n";
        stck->topIndex++;
        stck->items[stck->topIndex] = x;
        std::cout << "stck->items[" << stck->topIndex << "] = " << x<<"\n";
        std::cout << "------------\n";
    }
}

int top(struct stack* stck) {
    if (!isEmpty(stck)) {
        return stck->items[stck->topIndex];
    }
    else {
        std::cout << "Stack is empty"<<"\n";
        //exit(EXIT_FAILURE);
    }
}

void pop(struct stack* stck) {
    if (isEmpty(stck)) {
        std::cout << "Stack is already empty. Operation cancelled" << "\n";
        //exit(EXIT_FAILURE);
    }
    else {
        std::cout<<"Item " << top(stck) << " removed" << "\n";
        stck->topIndex--;
        if (stck->topIndex!=-1){
            std::cout << "stck->topIndex[" << stck->topIndex << "] = " << top(stck) << "\n";
        }
        else {
            std::cout << "Stack empty"<<"\n";
        }
    }
}



int main()
{
    std::streambuf* old = std::cout.rdbuf();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);
    struct stack* stck = newStack(20);
    std::cout.rdbuf(0);
    for (int i = 0; i < 10; i++)
    {
        push(stck, dist(gen));
    }
    std::cout.rdbuf(old);
    int action = -1;
    int temp = 0;
    while (true) 
    {
        std::cout << "Choose an action" << "\n";
        std::cout << "1. Push an item" << "\n";
        std::cout << "2. Pop an item" << "\n";
        std::cout << "3. Get top item" << "\n";
        std::cout << "4. Exit" << "\n";
        std::cin >> action;
        switch (action)
        {
        case 1:
            std::cout << "Type a number" << "\n";
            std::cin >> temp;
            push(stck, temp);
            break;
        case 2:
            pop(stck);
            break;
        case 3:
            if (isEmpty(stck)) {
                std::cout << "Stack is empty" << "\n";
            }
            else {
                std::cout << "Stack is NOT empty. ";
                std::cout << "Item on top: "<< top(stck)<<"\n";
            }
            break;
        case 4:
            return 0;
            break;
        default:
            std::cout << "Invalid action" << "\n";
            break;
        }
    }
}

