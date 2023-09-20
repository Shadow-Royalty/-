//һˢ

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
    int coefficient;    // ϵ��
    int exponent;       // ָ�� 
    Node* next;         // ��һ���ڵ�ָ��

};
//����Ƿ��*?
//��㲻��*�����סֻ��**����Ҫ��*
//��֮��ͼǣ�**�ͼ�һ��*
//��*�Ͳ��ü�.			
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
    //��:��㶼û�����Ͳ���
    Node* newNode = create_node(coefficient, exponent);
    //	Node* head; ֱ�����ϴ�������head��Ϊͷ��㣬û��Ҫ�Լ���һ��
    //	Node* cur = *x;
        //�������cur

    if (*head == NULL)//ͷ���Ϊ��ʱ
    {
        *head = newNode;

    }
    /*else err��˼·������
    {
        while (*x != NULL)
        {
            cur->next = *x;
            *x = *x->next;

        }

    }

    cur->next = head;*/

    //1.ԭ����ͷ��㣬Ҳ����������ʼλ�ã���ֹ��ʼ��㶪ʧ
    //������ head���������Ҫ�����µ�ָ�����������ӣ�����ʹ��
    //Node* cur
    //	2.head����Ϊ��ȷ�������λ�ã�Ȼ��ʼ����
    //	��������λ��ʼ���룬����һ��λ�ò���˴ε�����

    //	��������Ҫ���ף�head������Ϊ��ȷ�������λ��
    //	����ÿ�δ򿪺����� Node* current = *head;�Ǳ�Ҫ��

    //	��Σ�һ����˵���������λ���Ǻܿ�ģ�û��Ҫ
    //	ע��ÿ�δ�ͷ��ʼ�ı��������ʵ��ע�أ�Ҳ����д��
    //	˫**�����������ÿ�ζ�����һ�ε�λ�á�
    //	���Ͷ���Ŀ�Ķ���ʽ��˵�����Բ��ơ�  

    else {
        Node* cur = *head;//������ͷ��ʼ����
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = newNode;
        //�������պ󣬲��뵱ǰ���ݽ��
    }


    //return *cur;
    //���벻��Ҫ��������
    //��Ϊ�Ѿ�**��Զ�ļ�¼��head�������




}

//void ���(Node* x, Node* y) err
//����޷���head��������ϴ�ָ�룬����Ҫ��Node*�����ظ�resultָ���ֵ��
Node* subtractPolynomials(Node* p1, Node* p2)
{
    Node* result = NULL;
    //ʹ���µ���������������ʽ����Ľ����������

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
            }//���������0ʱ��ֱ������������ָ�벻���������˾ͺ���

//������ĺ������ѵ�ָ����ͬ�����һ������0��
            //���һ����ֱ��������
            //�ǵ�Ȼ��Ҫ�ж�ϵ��



            p1 = p1->next;
            p2 = p2->next;
        }
    }

    //����ʣ�µ���


    while (p1 != NULL)
    {
        //	x->next = p1;
        /*	�淶������ͳһ�������µ�result������
            Ҳ�淶��ʹ�ú������ֹ��������
            ��Ҫʲô���ܶ��ظ�д��*/
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
    //ע������˷���result
}

//�и�����˼�룬���������
//����һ����ͷ�����Ϊ�������ʼ
//��Ҳ������һ������
//�������ڲ���֮ǰҪ���Ǻò��뵽�������������Ҳ壡
//�����Ǵ�����һ��result������result��Ϊ�������ʼ��
//�����ǾͲ���p1,p2�ĺ��棡
//Ȼ��˳��result������ȥ
//���õ���,��Ϊ���ϲ��Ķ���ʽ�ķ���ֻʹ��һ��
//��˲�����ֶ��resultָ�룬
//���ϴ������뷽����ʱ��,�ǽ������˵�
//���result��ֵ��Ҳ����������һֱ�ڸ��²��ұ���������

//ͬʱһ��������ǽ����ã�Ҫ�޸�ָ�����**��Ҫ���ϴ�ʱд&
//����ָͨ����ֻд���ּ���
//
//��ˣ�Ҳ����û�д�����һ���µ�����Ȼ�󷵻ص�����߼�
//�Լ���Ҫ���½�һ������Ȼ�󷵻ظ�ָ�룡
//�½�������ͨ��ͷ�������ҵ���
//����ͨ������ͷ��㣬����˳�����Ϸ�����������

void printPolynomial(Node* head)//��ӡ
{
    Node* current = head;
    //ֱ��ʹ��headҲ�ǿ��Եģ�ֻҪû�������ǲ���ı�
    //head��ʼָ��ģ� ָ��ı仯����ֻ����һ���ڵĺ�������Ч����

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
    // �����һ������ʽ��3x^4 + 2x^3 + 5x^2 + 1
    Node* poly1 = nullptr;
    insert(&poly1, 3, 4);
    insert(&poly1, 2, 3);
    insert(&poly1, 5, 2);
    insert(&poly1, 1, 0);

    // ����ڶ�������ʽ��2x^3 + 4x + 1
    Node* poly2 = nullptr;
    insert(&poly2, 2, 3);
    insert(&poly2, 4, 1);
    insert(&poly2, 1, 0);

    cout << "��һ������ʽ: ";
    printPolynomial(poly1);

    cout << "�ڶ�������ʽ: ";
    printPolynomial(poly2);
    // �������ʽ
    Node* result = subtractPolynomials(poly1, poly2);//�ٿ�һ�������¼���յĽ��
    cout << "������: ";
    printPolynomial(result);

    // �ͷ��ڴ�
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);



    return 0;
}



//Ҳ�Ǿ���������ѧ

//������Ϊ���Ͳ����������ݣ���Ϊ�ʼǾͺ��ˣ�
//��Ϊ��Щ������Щ���󣬷��������㷨

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

// ����һ���ṹ���ʾ����ʽ��ÿһ���ڵ�
struct Node {
    int coef;  // ϵ��
    int exp;   // ָ��
    struct Node* next; // ��һ���ڵ�ָ��
};

// ����һ���½ڵ�
Node* create_node(int coef, int exp) {
    Node* new_node = new Node;
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;

    return new_node;
}

// �����ʽ�����в���ڵ�
//��ȷһ�����̣�
//���ǲ��õ���ͷ�巨����������ָ���������Ƿ�����ǰ���
//����ͷ�巨ԭ��
//���ָ��С�����ǻ���ں��棬Ҳ����ʹ�õ�ǰ����next
//�۲������̲��ѷ��֣�����ÿ��ָ��ĵ�ǰ���
void insert_node(Node** head, int coef, int exp) {
   //Node** ��ʾָ��ָ���ָ�룬ͨ�����ڴ���ָ��ָ���ָ�루����˵��ָ������ã���Ϊ������
    //ʵ�ֶ�ָ�뱾����޸ġ�

  //   �������У�ʹ�� Node** �����޸�ͷָ�롣
    //���磬�ڲ���ڵ�ĺ����У����ǿ���ͨ������ Node** head ���޸�ͷָ�룬
    //ʹͷָ��ָ���²���Ľڵ㡣
    //����*Ҳ���ǽ����õ���˼���������ϻ���ֻ��һ��*head����һ��*ֻ�ǽ����á�
    //��һ����Ϊ�˽����ã�Ҳ����Ϊ�˸ı�ָ�뱾���ֵ,����&������
    //ֱ����ֵ��ʱ��ֻ��Ҫһ��*��ʾ�����ָ��ͺ���
    //��*head

    if (*head == NULL || exp > (*head)->exp) {
     
        //*head == NULL����������ж������Ƿ�Ϊ�ա��������Ϊ�գ���ζ�ŵ�ǰû���κνڵ㣬������Ҫ������½ڵ�Ӧ�ó�Ϊ����ĵ�һ���ڵ㡣
      
        //��ΪNode** head,�����Ѿ�д�˽������ˣ�Ҳ�������*headֻ����һ��ʼ�ϴ���ʱ��ָ��գ�
        //�������Ϊ�����ö��޸ĳ��ϴεĽ�㣬Ҳ�ͳ�Ϊ�˵�ǰ���
        //�Ͳ�����ͷ����ˣ������Ϊʲô��Ҫ**��ԭ����ΪҪ���ϵ��޸�ָ��headָ���λ�ã���ʵ���൱���ǵ�ǰ�ڵ�



        Node* new_node = create_node(coef, exp);

        new_node->next = *head;//��������������������
        //ͷ�巨

        *head = new_node;//��ͷ��㸳ֵ
        //�����ʱ��ʼͷ�����Ѳ����ǿգ����Ҳ��ϵر��޸�

    }
  /*  дnew_node->next = *head; ��Ŀ���ǽ��½ڵ��nextָ��ָ��ǰ�����ͷ�ڵ㡣
        ������Ϊ�ڽ��½ڵ��������Ŀ�ͷʱ����Ҫ����ԭ��������ṹ��
        ͨ�����½ڵ��nextָ��ָ��ǰ��ͷ�ڵ㣬���Խ�ԭ�ȵ��������ӵ��½ڵ�֮��

        ������һ������A : A1->A2->A3������Ҫ������ͷ����һ���½ڵ�B��
        ϣ���õ�������ΪB->A1->A2->A3��Ϊ�˴ﵽ���Ŀ�ģ�
        ������Ҫ���½ڵ�B��nextָ��ָ��ԭ����ͷ�ڵ�A1����new_node->next = *head; */

    else if (exp == (*head)->exp) {
        (*head)->coef -= coef;
        if ((*head)->coef == 0) //ϵ�����Ϊ0ʱ��ֱ��ɾ���ý��
        
        {
            Node* temp = *head;//�����ָ�룬��ͬ�ڱ�����tempָ��ָ��headʱ����ʱ��temp���Ѿ�������head

            *head = (*head)->next;//��ʱhead���ı䣬��Ϊ��ַ�ı仯���Ѿ�������ǰ��head����ˣ�����
            //��ǰ��head���=����Ȼ���ڵģ�����Ҫɾ����
            delete temp;
            //ɾȥtemp�͵���ɾȥ����ǰ��head��㣬һ��ע�������ָ�������
        }
    }
    //�Ǽ�Ȼ��ָ�룬Ϊʲô��Ҫ**��
    
    //ָ��ȷʵ��ָ���ڴ��ַ�ģ�ͨ��ָ����Է��ʺ��޸ĸ��ڴ��ַ�д洢�ı��������
    //�����ں��������У������ǽ�һ��ָ�봫�ݸ�����ʱ��ʵ�����ǽ����ָ��ĸ������ݸ��˺�����

    //������˵�������ǽ�һ��ָ����Ϊ�����Ĳ������д���ʱ��ʵ�����ǽ����ָ�����ڴ��еĸ������Ƹ��˺�������ջ�е���һ��λ�á�
    //��ˣ����ں����ڲ��޸����ָ���ֵʱ��ֻ��Ӱ�쵽���������ֵ���������ԭʼ��ָ�����Ӱ�졣

  /* ���������Ҫ�ں����ڲ��޸�ָ�뱾���ֵ������ϣ������޸��ܹ�Ӱ�쵽�����ⲿ��ָ�룬��ô����Ҫʹ��ָ��ָ���ָ�룬��** ��

        ������ʹ��** ����ָ����Ϊ�����Ĳ���ʱ��ʵ���ϴ��ݸ������������ָ��ĵ�ַ����ָ��ָ���ָ�롣
       �ں����ڲ������ǿ��Խ��������ָ��ָ���ָ�룬�õ�ָ��ԭʼָ���ָ�룬���ҿ���ͨ���޸����ָ���ֵ����ֱ��Ӱ�쵽�����ⲿ��ָ�롣*/
    
    //�ܽ���˵���ǣ�ָ������޸ĵ�ַ�д���ı�����Ҳ�����޸ı��ˣ��������޷��޸�����������Ҫ˫��ָ������޸�ָ���Լ�����
    else {
        insert_node(&((*head)->next), coef, exp);
        //������һ�����
        //Ҳ���ǰѵ�ǰ�Ľ����ں��λ�ò���
        //��Ϊcoef ��exp��ֵ��Ȼ���ڣ�
        //��û�½���㣬����Ŀǰֻ��ѡ��λ�ò�����ѡ�
    }
    
}

// �������ʽ
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

// һԪ����ʽ�������
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

    // ��ʣ��ڵ���ӵ����������
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

// �ͷ������ڴ�
void delete_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // ������һ������ʽ: 3x^4 + 2x^3 + 5x^2 + 7x + 6
    Node* poly1 = NULL;

    //�Ҷ��ˣ�Ҳ�ԣ��������ѣ�����˳�������׼����ʽ�ͺ��ˣ�����������룬
    //��㲻���Ǿ������ˡ�

    insert_node(&poly1, 3, 4);
    insert_node(&poly1, 2, 3);
    insert_node(&poly1, 5, 2);
    insert_node(&poly1, 7, 1);
    insert_node(&poly1, 6, 0);

    // �����ڶ�������ʽ: 2x^3 + 4x^2 + 8
    Node* poly2 = NULL;
    insert_node(&poly2, 2, 3);
    insert_node(&poly2, 4, 2);
    insert_node(&poly2, 8, 0);

    // �����������ʽ
    cout << "��һ������ʽ: ";
    print_polynomial(poly1);
    cout << "�ڶ�������ʽ: ";
    print_polynomial(poly2);

    // ����������
    Node* result = subtract_polynomials(poly1, poly2);

    // ���������
    cout << "������: ";
    print_polynomial(result);

    // �ͷ��ڴ�
    delete_list(poly1);
    delete_list(poly2);
    delete_list(result);

    return 0;
}


//�ʼǶ�

#include <iostream>

// �������ʽ�Ľڵ�ṹ
struct Node {
    int coefficient;    // ϵ��
    int exponent;       // ָ��
    Node* next;         // ��һ���ڵ�ָ��

    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

// ����ڵ㵽����ʽ����
void insert(Node** head, int coefficient, int exponent) {
    Node* newNode = new Node(coefficient, exponent);
    if (*head == nullptr) {
        *head = newNode;//����ͷ���
    }
    else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;//���ָ��ͷ��㣬�պ�
    }
}

// ��ӡ����ʽ����
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

// һԪ����ʽ���
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
            //�������0��ֱ��������һ��ָ�뼴��
        }

    }

    //ǰ���������&&����������һ��������ͻ��˳�ѭ��������Ҫдʣ������!
    //�����ˣ���һ����ϵ������ȶԼӼ���������ֱ��һ�����ź��ȣ����������źã�ֱ���Ȳ����������ȶԼӼ����ɣ�
    // ��ʣ�������ӵ������

    //�������Ϊ�˱������֣��ͱ���p1��ָ��ȫ������p2������������˵���Ա����p1���Ѿ������ȫ����
    //��p2���б������һ��ָ����ҪС����������ֱ�Ӳ��뵽���漴��

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

// �ͷŶ���ʽ������ڴ�
void freePolynomial(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
        //�㲻��ֱ��current=current->next
        //����Ҫ����һ��ָ����ǰ��ţ�����ᶪʧ
    }
}

int main() {
    // �����һ������ʽ��3x^4 + 2x^3 + 5x^2 + 1
    Node* poly1 = nullptr;
    insert(&poly1, 3, 4);
    insert(&poly1, 2, 3);
    insert(&poly1, 5, 2);
    insert(&poly1, 1, 0);

    // ����ڶ�������ʽ��2x^3 + 4x + 1
    Node* poly2 = nullptr;
    insert(&poly2, 2, 3);
    insert(&poly2, 4, 1);
    insert(&poly2, 1, 0);

    std::cout << "��һ������ʽ: ";
    printPolynomial(poly1);

    std::cout << "�ڶ�������ʽ: ";
    printPolynomial(poly2);

    // �������ʽ
    Node* result = subtractPolynomials(poly1, poly2);//�ٿ�һ�������¼���յĽ��
    std::cout << "������: ";
    printPolynomial(result);

    // �ͷ��ڴ�
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
