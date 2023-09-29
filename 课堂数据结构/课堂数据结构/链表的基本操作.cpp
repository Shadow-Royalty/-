以下是使用C++实现线性链表的代码示例：

```cpp
#include <iostream>

// 链表节点结构
struct ListNode {
    int val;                // 节点存储的值
    ListNode* next;         // 指向下一个节点的指针
};

// 初始化链表
void initList(ListNode*& head) {
    head = nullptr;
}

// 在链表尾部添加节点
void appendNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode;      // 创建新节点
    newNode->val = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;                     // 如果链表为空，直接将新节点作为头节点
    }
    else {
        ListNode* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;                 // 遍历链表，找到尾部节点
        }
        tmp->next = newNode;                 // 将新节点连接到尾部节点的next指针上
    }
}

// 在指定位置插入节点
void insertNode(ListNode*& head, int value, int pos) {
    if (pos <= 0) {
        ListNode* newNode = new ListNode;  // 创建新节点
        newNode->val = value;
        newNode->next = head;               // 将新节点连接到头节点之前
        head = newNode;                     // 将新节点作为头节点

    }
    else {
        ListNode* tmp = head;
        int count = 1;
        while (tmp != nullptr && count < pos)
        //tmp != nullptr是因为我们插入是必须要左右两边都有数据才能叫插入，
            //不然就只能添加，不可以直接填在一个很远的空间里，不然就浪费空间了
        {
            tmp = tmp->next;                 // 遍历链表，找到指定位置的前一个节点
            count++;
        }
        if (tmp != nullptr)
        //必须是在tmp不为空时，才能算成插入。
        {
            ListNode* newNode = new ListNode;  // 创建新节点
            newNode->val = value;
            newNode->next = tmp->next;         // 将新节点连接到当前节点的next指针上
            tmp->next = newNode;
        }
        else {
            std::cout << "插入位置超过链表长度！" << std::endl;
        }
    }
}

// 删除指定位置的节点
void deleteNode(ListNode*& head, int pos) {
    if (head == nullptr) {
        std::cout << "链表为空，无法删除节点！" << std::endl;
        return;
    }

    if (pos <= 0) {
        ListNode* tmp = head;
        head = head->next;          // 删除头节点
        delete tmp;

    }
    else {
        ListNode* tmp = head;
        int count = 1;
        while (tmp->next != nullptr && count < pos) {
            tmp = tmp->next;        // 遍历链表，找到指定位置的前一个节点
            count++;
        }
        if (tmp->next != nullptr) {
            ListNode* delNode = tmp->next;
            tmp->next = delNode->next;   // 将前一个节点的next指针跳过要删除的节点
            delete delNode;
        }
        else {
            std::cout << "删除位置超过链表长度！" << std::endl;
        }
    }
}

// 打印链表
void printList(ListNode* head) {
    ListNode* tmp = head;
    while (tmp != nullptr) {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* myList;
    initList(myList);

    // 在链表尾部增加节点
    appendNode(myList, 1);
    appendNode(myList, 2);
    appendNode(myList, 3);

    printList(myList);  // 输出：1 2 3

    // 在指定位置插入节点
    insertNode(myList, 4, 2);

    printList(myList);  // 输出：1 4 2 3

    // 删除节点
    deleteNode(myList, 2);

    printList(myList);  // 输出：1 2 3

    return 0;
}
```

以上代码实现了线性链表的建立、初始化、增加、插入和删除操作。你可以根据需要调用相应的函数来操作链表，并使用`printList`函数打印链表结果。

希望对你有帮助，如有其他问题，请随时提问！