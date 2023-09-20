//一刷

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node
{
    int coefficient;    // 系数
    int exponent;       // 指数 
    Node* next;         // 下一个节点指针

};
//结点是否加*?
//结点不加*，你记住只有**才需要加*
//总之你就记，**就加一个*
//而*就不用加.			
Node* create_node(int coefficient, int exponent)
{
    Node* new_node = new Node;
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;

    return new_node;
}

void insert(Node** head, int coefficient, int exponent)
{
    //！:结点都没创建就插入
    Node* newNode = create_node(coefficient, exponent);
    //	Node* head; 直接用上传上来的head作为头结点，没必要自己建一个
    //	Node* cur = *x;
        //无意义的cur

    if (*head == NULL)//头结点为空时
    {
        *head = newNode;

    }
    /*else err：思路不清晰
    {
        while (*x != NULL)
        {
            cur->next = *x;
            *x = *x->next;

        }

    }

    cur->next = head;*/

    //1.原则保留头结点，也就是链表起始位置，防止初始结点丢失
    //即不动 head。因此我们要引入新的指针来建立连接，于是使用
    //Node* cur
    //	2.head就是为了确定链表的位置，然后开始遍历
    //	遍历到空位后开始插入，即下一个位置插入此次的数据

    //	首先我们要明白，head结点就是为了确认链表的位置
    //	所以每次打开函数的 Node* current = *head;是必要的

    //	其次，一般来说计算机遍历位置是很快的，没必要
    //	注重每次从头开始的遍历，如果实在注重，也可以写个
    //	双**。这样插入就每次都是上一次的位置。
    //	但就对题目的多项式来说，忽略不计。  

    else {
        Node* cur = *head;//从链表头开始遍历
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = newNode;
        //遍历到空后，插入当前数据结点
    }


    //return *cur;
    //插入不需要返回链表
    //因为已经**永远的记录在head结点上了




}

//void 相减(Node* x, Node* y) err
//这次无法像head结点那样上传指针，所以要用Node*来返回给result指针的值！
Node* subtractPolynomials(Node* p1, Node* p2)
{
    Node* result = NULL;
    //使用新的链表，将两个多项式相减的结果插入至此

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exponent > p2->exponent) {
            insert(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else if (p1->exponent < p2->exponent) {
            insert(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        else {

            int coefficientDiff = p1->coefficient - p2->coefficient;
            if (coefficientDiff != 0)
            {
                insert(&result, coefficientDiff, p1->exponent);
            }//当相减等于0时，直接跳过这两个指针不管它丢弃了就好了

//你是真的憨批，难道指数相同相减就一定等于0？
            //你就一定能直接跳过？
            //那当然是要判断系数



            p1 = p1->next;
            p2 = p2->next;
        }
    }

    //补充剩下的项


    while (p1 != NULL)
    {
        //	x->next = p1;
        /*	规范化，是统一插入在新的result链表中
            也规范的使用函数，分工简洁明了
            不要什么功能都重复写！*/
        insert(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        //x->next = p2;
        insert(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
    //注意别忘了返回result
}

//有个核心思想，插入的问题
//我们一般以头结点作为链表的起始
//它也代表了一个链表。
//所以你在插入之前要考虑好插入到哪里，而不是随便乱插！
//这里是创建了一个result链表，以result作为链表的起始点
//而不是就插入p1,p2的后面！
//然后顺着result插入下去
//不用担心,因为最后合并的多项式的方法只使用一次
//因此不会出现多个result指针，
//而上传到插入方法的时候,是解引用了的
//因此result的值，也就是链表是一直在更新并且保存下来的

//同时一个经验就是解引用，要修改指针的如**就要在上传时写&
//而普通指针则只写名字即可
//
//因此，也就是没有创建好一个新的链表，然后返回的这个逻辑
//自己需要重新建一个链表，然后返回该指针！
//新建的链表通过头结点就能找到！
//我们通过访问头结点，就能顺藤摸瓜访问整个链表！

void printPolynomial(Node* head)//打印
{
    Node* current = head;
    //直接使用head也是可以的，只要没解引用是不会改变
    //head初始指向的， 指向的变化仅仅只在这一周期的函数中生效而已

    while (current != nullptr) {
        cout << current->coefficient << "x^" << current->exponent;
        current = current->next;
        if (current != nullptr) {
            cout << " + ";
        }
    }

    cout << endl;
}
void freePolynomial(Node* x)
{
    while (x != NULL)
    {
        Node* next = x;
        x = x->next;
        delete next;
    }
}





int main()
{
    // 构造第一个多项式：3x^4 + 2x^3 + 5x^2 + 1
    Node* poly1 = nullptr;
    insert(&poly1, 3, 4);
    insert(&poly1, 2, 3);
    insert(&poly1, 5, 2);
    insert(&poly1, 1, 0);

    // 构造第二个多项式：2x^3 + 4x + 1
    Node* poly2 = nullptr;
    insert(&poly2, 2, 3);
    insert(&poly2, 4, 1);
    insert(&poly2, 1, 0);

    cout << "第一个多项式: ";
    printPolynomial(poly1);

    cout << "第二个多项式: ";
    printPolynomial(poly2);
    // 相减多项式
    Node* result = subtractPolynomials(poly1, poly2);//再开一个链表记录最终的结果
    cout << "相减结果: ";
    printPolynomial(result);

    // 释放内存
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);



    return 0;
}



//也是经典的链表教学

//这里作为解释部分链表内容，作为笔记就好了，
//因为有些代码有些错误，放弃这种算法

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

// 定义一个结构体表示多项式的每一个节点
struct Node {
    int coef;  // 系数
    int exp;   // 指数
    struct Node* next; // 下一个节点指针
};

// 创建一个新节点
Node* create_node(int coef, int exp) {
    Node* new_node = new Node;
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;

    return new_node;
}

// 向多项式链表中插入节点
//明确一个过程，
//我们采用的是头插法，而且最大的指数项我们是放在最前面的
//符合头插法原则。
//如果指数小的我们会插在后面，也就是使用当前结点的next
//观察插入过程不难发现，我们每次指向的当前结点
void insert_node(Node** head, int coef, int exp) {
   //Node** 表示指向指针的指针，通常用于传递指向指针的指针（或者说是指针的引用）作为参数，
    //实现对指针本身的修改。

  //   在链表中，使用 Node** 可以修改头指针。
    //例如，在插入节点的函数中，我们可以通过传递 Node** head 来修改头指针，
    //使头指针指向新插入的节点。
    //两个*也就是解引用的意思，而本质上还是只有一个*head，多一个*只是解引用。
    //多一个是为了解引用，也就是为了改变指针本身的值,即起到&的作用
    //直接用值的时候只需要一个*表示是这个指针就好了
    //即*head

    if (*head == NULL || exp > (*head)->exp) {
     
        //*head == NULL：这个条件判断链表是否为空。如果链表为空，意味着当前没有任何节点，所以需要插入的新节点应该成为链表的第一个节点。
      
        //因为Node** head,我们已经写了解引用了，也就是这个*head只能在一开始上传的时候指向空，
        //后面会因为解引用而修改成上次的结点，也就成为了当前结点
        //就不再是头结点了，这就是为什么需要**的原因，因为要不断地修改指针head指向地位置，其实它相当于是当前节点



        Node* new_node = create_node(coef, exp);

        new_node->next = *head;//这个是起到连接链表的作用
        //头插法

        *head = new_node;//给头结点赋值
        //从这个时候开始头结点就已不再是空，并且不断地被修改

    }
  /*  写new_node->next = *head; 的目的是将新节点的next指针指向当前链表的头节点。
        这是因为在将新节点插入链表的开头时，需要保持原来的链表结构。
        通过将新节点的next指针指向当前的头节点，可以将原先的链表连接到新节点之后。

        假设有一个链表A : A1->A2->A3，现在要在链表开头插入一个新节点B，
        希望得到的链表为B->A1->A2->A3。为了达到这个目的，
        我们需要将新节点B的next指针指向原来的头节点A1，即new_node->next = *head; */

    else if (exp == (*head)->exp) {
        (*head)->coef -= coef;
        if ((*head)->coef == 0) //系数相减为0时，直接删除该结点
        
        {
            Node* temp = *head;//这个是指针，不同于变量。temp指针指向head时，此时的temp就已经代表了head

            *head = (*head)->next;//此时head结点改变，因为地址的变化，已经不是先前的head结点了，但是
            //先前的head结点=是依然存在的，所以要删除！
            delete temp;
            //删去temp就等于删去了先前的head结点，一定注意变量和指针的区别！
        }
    }
    //那既然是指针，为什么还要**？
    
    //指针确实是指向内存地址的，通过指针可以访问和修改该内存地址中存储的变量或对象。
    //但是在函数调用中，当我们将一个指针传递给函数时，实际上是将这个指针的副本传递给了函数。

    //具体来说，当我们将一个指针作为函数的参数进行传递时，实际上是将这个指针在内存中的副本复制给了函数调用栈中的另一个位置。
    //因此，当在函数内部修改这个指针的值时，只会影响到这个副本的值，而不会对原始的指针产生影响。

  /* 如果我们想要在函数内部修改指针本身的值，并且希望这个修改能够影响到函数外部的指针，那么就需要使用指向指针的指针，即** 。

        当我们使用** 传递指针作为函数的参数时，实际上传递给函数的是这个指针的地址，即指向指针的指针。
       在函数内部，我们可以解引用这个指向指针的指针，得到指向原始指针的指针，并且可以通过修改这个指针的值，来直接影响到函数外部的指针。*/
    
    //总结来说就是，指针可以修改地址中储存的变量，也就是修改别人，但是它无法修改它本身，所以要双重指针才能修改指针自己本身。
    else {
        insert_node(&((*head)->next), coef, exp);
        //传递下一个结点
        //也就是把当前的结点放在后继位置插入
        //因为coef 和exp的值依然存在，
        //还没新建结点，我们目前只是选中位置插入而已。
    }
    
}

// 输出多项式
void print_polynomial(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->coef << "x^" << temp->exp;
        if (temp->next != NULL) {
            cout << " + ";
        }
        temp = temp->next;
    }

    cout << endl;
}

// 一元多项式相减函数
Node* subtract_polynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp > temp2->exp) {
            insert_node(&result, temp1->coef, temp1->exp);
            temp1 = temp1->next;
        }
        else if (temp1->exp < temp2->exp) {
            insert_node(&result, -temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
        else {
            int coef_diff = temp1->coef - temp2->coef;
            if (coef_diff != 0) {
                insert_node(&result, coef_diff, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // 将剩余节点添加到结果链表中
    while (temp1 != NULL) {
        insert_node(&result, temp1->coef, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insert_node(&result, -temp2->coef, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// 释放链表内存
void delete_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 创建第一个多项式: 3x^4 + 2x^3 + 5x^2 + 7x + 6
    Node* poly1 = NULL;

    //我懂了，也对，不用这难，按照顺序输入标准多项式就好了，别乱排序插入，
    //这点不考虑就完事了。

    insert_node(&poly1, 3, 4);
    insert_node(&poly1, 2, 3);
    insert_node(&poly1, 5, 2);
    insert_node(&poly1, 7, 1);
    insert_node(&poly1, 6, 0);

    // 创建第二个多项式: 2x^3 + 4x^2 + 8
    Node* poly2 = NULL;
    insert_node(&poly2, 2, 3);
    insert_node(&poly2, 4, 2);
    insert_node(&poly2, 8, 0);

    // 输出两个多项式
    cout << "第一个多项式: ";
    print_polynomial(poly1);
    cout << "第二个多项式: ";
    print_polynomial(poly2);

    // 计算相减结果
    Node* result = subtract_polynomials(poly1, poly2);

    // 输出相减结果
    cout << "相减结果: ";
    print_polynomial(result);

    // 释放内存
    delete_list(poly1);
    delete_list(poly2);
    delete_list(result);

    return 0;
}


//笔记二

#include <iostream>

// 定义多项式的节点结构
struct Node {
    int coefficient;    // 系数
    int exponent;       // 指数
    Node* next;         // 下一个节点指针

    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

// 插入节点到多项式链表
void insert(Node** head, int coefficient, int exponent) {
    Node* newNode = new Node(coefficient, exponent);
    if (*head == nullptr) {
        *head = newNode;//建立头结点
    }
    else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;//最后指回头结点，闭合
    }
}

// 打印多项式链表
void printPolynomial(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->coefficient << "x^" << current->exponent;
        current = current->next;
        if (current != nullptr) {
            std::cout << " + ";
        }
    }

    std::cout << std::endl;
}

// 一元多项式相减
Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* current = nullptr;

    Node* p1 = poly1;
    Node* p2 = poly2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->exponent > p2->exponent) {
            insert(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else if (p1->exponent < p2->exponent) {
            insert(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
        else {
            int coefficientDiff = p1->coefficient - p2->coefficient;
            if (coefficientDiff != 0) {
                insert(&result, coefficientDiff, p1->exponent);
            }
            p1 = p1->next;
            p2 = p2->next;
            //如果等于0，直接跳到下一个指针即可
        }

    }

    //前面的条件是&&，两个中有一个不满足就会退出循环，所以要写剩余的项补充!
    //明白了，是一个个系数互相比对加减，而不是直接一口气排好先，根本不必排好，直接先插入后再逐项比对加减即可！
    // 将剩余的项添加到结果中

    //后面的是为了避免那种，就比如p1的指数全部都比p2大的情况，或者说，对比完后，p1的已经输出完全部了
    //而p2还有比它最后一个指数还要小的数，所以直接插入到后面即可

    while (p1 != nullptr) {
        insert(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != nullptr) {
        insert(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

// 释放多项式链表的内存
void freePolynomial(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
        //你不能直接current=current->next
        //必须要拿另一个指针提前存放，否则会丢失
    }
}

int main() {
    // 构造第一个多项式：3x^4 + 2x^3 + 5x^2 + 1
    Node* poly1 = nullptr;
    insert(&poly1, 3, 4);
    insert(&poly1, 2, 3);
    insert(&poly1, 5, 2);
    insert(&poly1, 1, 0);

    // 构造第二个多项式：2x^3 + 4x + 1
    Node* poly2 = nullptr;
    insert(&poly2, 2, 3);
    insert(&poly2, 4, 1);
    insert(&poly2, 1, 0);

    std::cout << "第一个多项式: ";
    printPolynomial(poly1);

    std::cout << "第二个多项式: ";
    printPolynomial(poly2);

    // 相减多项式
    Node* result = subtractPolynomials(poly1, poly2);//再开一个链表记录最终的结果
    std::cout << "相减结果: ";
    printPolynomial(result);

    // 释放内存
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
