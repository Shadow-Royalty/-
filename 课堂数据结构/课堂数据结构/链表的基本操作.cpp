
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
    //创建新的空间
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
            //再次判断是因为我们只选取count遍历到pos的位置的这种情况，而不是空的链表的情况。
            
        {
            ListNode* newNode = new ListNode;  // 创建新节点
            newNode->val = value;
            newNode->next = tmp->next;         // 将新节点连接到当前节点的next指针上
            //这是链接步骤的代码，把数据插入
            //至于next是因为我们是要插入在数据的中间，也就是tmp的next的位置
            tmp->next = newNode;
            //这个是指向新的插入数据的步骤，方便下一次数据的插入。
         
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
            ListNode* delNode = tmp->next;//先指向当前数据
            tmp->next = delNode->next;
            //直接将当前数据跳到下一个，前面已经链接好的数据不会丢失因为都在同一个位置
            //我们不过是把当前数据覆盖成下一个罢了
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
