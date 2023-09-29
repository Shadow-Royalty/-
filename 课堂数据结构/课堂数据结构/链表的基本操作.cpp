������ʹ��C++ʵ����������Ĵ���ʾ����

```cpp
#include <iostream>

// ����ڵ�ṹ
struct ListNode {
    int val;                // �ڵ�洢��ֵ
    ListNode* next;         // ָ����һ���ڵ��ָ��
};

// ��ʼ������
void initList(ListNode*& head) {
    head = nullptr;
}

// ������β����ӽڵ�
void appendNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode;      // �����½ڵ�
    newNode->val = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;                     // �������Ϊ�գ�ֱ�ӽ��½ڵ���Ϊͷ�ڵ�
    }
    else {
        ListNode* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;                 // ���������ҵ�β���ڵ�
        }
        tmp->next = newNode;                 // ���½ڵ����ӵ�β���ڵ��nextָ����
    }
}

// ��ָ��λ�ò���ڵ�
void insertNode(ListNode*& head, int value, int pos) {
    if (pos <= 0) {
        ListNode* newNode = new ListNode;  // �����½ڵ�
        newNode->val = value;
        newNode->next = head;               // ���½ڵ����ӵ�ͷ�ڵ�֮ǰ
        head = newNode;                     // ���½ڵ���Ϊͷ�ڵ�

    }
    else {
        ListNode* tmp = head;
        int count = 1;
        while (tmp != nullptr && count < pos)
        //tmp != nullptr����Ϊ���ǲ����Ǳ���Ҫ�������߶������ݲ��ܽв��룬
            //��Ȼ��ֻ����ӣ�������ֱ������һ����Զ�Ŀռ����Ȼ���˷ѿռ���
        {
            tmp = tmp->next;                 // ���������ҵ�ָ��λ�õ�ǰһ���ڵ�
            count++;
        }
        if (tmp != nullptr)
        //��������tmp��Ϊ��ʱ��������ɲ��롣
        {
            ListNode* newNode = new ListNode;  // �����½ڵ�
            newNode->val = value;
            newNode->next = tmp->next;         // ���½ڵ����ӵ���ǰ�ڵ��nextָ����
            tmp->next = newNode;
        }
        else {
            std::cout << "����λ�ó��������ȣ�" << std::endl;
        }
    }
}

// ɾ��ָ��λ�õĽڵ�
void deleteNode(ListNode*& head, int pos) {
    if (head == nullptr) {
        std::cout << "����Ϊ�գ��޷�ɾ���ڵ㣡" << std::endl;
        return;
    }

    if (pos <= 0) {
        ListNode* tmp = head;
        head = head->next;          // ɾ��ͷ�ڵ�
        delete tmp;

    }
    else {
        ListNode* tmp = head;
        int count = 1;
        while (tmp->next != nullptr && count < pos) {
            tmp = tmp->next;        // ���������ҵ�ָ��λ�õ�ǰһ���ڵ�
            count++;
        }
        if (tmp->next != nullptr) {
            ListNode* delNode = tmp->next;
            tmp->next = delNode->next;   // ��ǰһ���ڵ��nextָ������Ҫɾ���Ľڵ�
            delete delNode;
        }
        else {
            std::cout << "ɾ��λ�ó��������ȣ�" << std::endl;
        }
    }
}

// ��ӡ����
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

    // ������β�����ӽڵ�
    appendNode(myList, 1);
    appendNode(myList, 2);
    appendNode(myList, 3);

    printList(myList);  // �����1 2 3

    // ��ָ��λ�ò���ڵ�
    insertNode(myList, 4, 2);

    printList(myList);  // �����1 4 2 3

    // ɾ���ڵ�
    deleteNode(myList, 2);

    printList(myList);  // �����1 2 3

    return 0;
}
```

���ϴ���ʵ������������Ľ�������ʼ�������ӡ������ɾ������������Ը�����Ҫ������Ӧ�ĺ���������������ʹ��`printList`������ӡ��������

ϣ�������а����������������⣬����ʱ���ʣ�