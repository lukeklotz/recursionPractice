#include <iostream>
using namespace std;

struct LLLNode {
    int data;
    LLLNode* next;

    LLLNode(int val) : data(val), next(nullptr) {}
};

int countHelper(LLLNode * head, int firstNum)
{
    if(!head)
    {
        return 0;
    }
    if(head->data == firstNum)
    {
        return countHelper(head->next, firstNum) + 1;
    }
    else
    {
        return countHelper(head->next, firstNum);
    }
}

// Function to count items same as the first node
int countSameAsFirstLLL(LLLNode* head) {
    if (head == nullptr) return 0; // Base case: empty list

    int firstNum = head->data;
    return countHelper(head, firstNum);
}

// Function to add a node at the end of the list
void appendLLL(LLLNode*& head, int data) {
    if (head == nullptr) {
        head = new LLLNode(data);
    } else {
        LLLNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new LLLNode(data);
    }
}

// Test the program
int main() {
    LLLNode* lllHead = nullptr;
    
    appendLLL(lllHead, 3);
    appendLLL(lllHead, 1);
    appendLLL(lllHead, 1);
    appendLLL(lllHead, 1);
    appendLLL(lllHead, 1);
    appendLLL(lllHead, 1);
    appendLLL(lllHead, 1);
    appendLLL(lllHead, 2);
    appendLLL(lllHead, 3);

    //count == 5

    // Count items same as the first node
    std::cout << "Count of items same as first: " << countSameAsFirstLLL(lllHead) << std::endl;

    return 0;
}



  