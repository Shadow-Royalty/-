//�ܽ�
//ָ�����ֱ�Ӹı��Լ����������
//����Ҫ�ı�ָ���Լ������ͱ���Ҫʹ��**//�ܽ�
//ָ�����ֱ�Ӹı��Լ����������
//����Ҫ�ı�ָ���Լ������ͱ���Ҫʹ��**

#include <iostream>
using namespace std;
#define MAX_SIZE 100  // �������Ա���������Ϊ100

struct SeqList {
	int data[MAX_SIZE];  // ���Ԫ�ص�����
	int size;  // ��ǰԪ�ظ���
};

// �������Ա�
void create(SeqList& list) {
	list.size = 0;  // ��ʼʱԪ�ظ���Ϊ0
}

// ��ʼ�����Ա�
void init(SeqList& list, int arr[], int arrSize) {
	if (arrSize <= MAX_SIZE) {
		for (int i = 0; i < arrSize; i++) {
			list.data[i] = arr[i];
		}
		list.size = arrSize;
		std::cout << "���Ա��ѳ�ʼ����" << std::endl;
	}
	else {
		std::cout << "��ʼ��ʧ�ܣ������С�������Ա����������" << std::endl;
	}
}

// ����Ԫ��
void add(SeqList& list, int elem) {
	if (list.size < MAX_SIZE) {
		list.data[list.size] = elem;
		list.size++;
		std::cout << "Ԫ�� " << elem << " ����ӵ����Ա�ĩβ��" << std::endl;
	}
	else {
		std::cout << "����ʧ�ܣ����Ա�������" << std::endl;
	}
}

// ����Ԫ��
void insert(SeqList& list, int elem, int position) {
	//if (pos >= 0 && pos <= 100) err
		//���ﲻ��<=100,����С��˳���Ĵ�С!
	if (position >= 0 && position <= list.size && list.size < MAX_SIZE) {
		for (int i = list.size - 1; i >= position; i--) {
			list.data[i + 1] = list.data[i];  // Ԫ�غ���
		}
		list.data[position] = elem;

		list.size++; //!:���ȿ��Բ������ǰɣ�
		std::cout << "Ԫ�� " << elem << " �Ѳ��뵽λ�� " << position << "��" << std::endl;
	}
	else {
		std::cout << "����ʧ�ܣ�λ�ò��Ϸ������Ա�������" << std::endl;
	}
}

//��ͬ�ڲ��룬�����Ǵ��޵��У���ȻҪд�������������ʲô
//��ɾ����ͬ��ɾ������ͨ���±���ܵó������ݵĲ����������ǲ���Ҫ����
//�����ֵģ�
// 
// ɾ��Ԫ��
//void delete(lianbiao& myList, int num, int pos)  err
void remove(SeqList& list, int position) {

	//ɾ����ͬ�ڲ��룬������Ǽ��ٴ�Сû��Ҫ���ж�size��
//if (myList.size >= 0 && myList.size <= 100) err

	if (position >= 0 && position < list.size) {
		int elem = list.data[position];
		for (int i = position; i < list.size - 1; i++) {
			list.data[i] = list.data[i + 1];  // Ԫ��ǰ��
		}
		list.size--;	//ͬ������һ���Ĵ��󲻻��С����
		std::cout << "Ԫ�� " << elem << " �Ѵ�λ�� " << position << " ɾ����" << std::endl;
	}
	else {
		std::cout << "ɾ��ʧ�ܣ�λ�ò��Ϸ���" << std::endl;
	}
}

void display(SeqList& list)

{
	// cout << list.data;  err
	 //��ֱ�Ӳ�д��ţ�ֱ�Ӹ����ӡһ�����ݵĵ�ַ
	 //����˵��������ʵʵ��д��ţ�

	for (int i = 0; i < list.size; i++) {
		cout << list.data[i] << " ";
	}

	cout << endl;
}

int main() {
	SeqList myList;
	create(myList);

	int arr[] = { 1, 2, 3, 4, 5 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	init(myList, arr, arrSize);
	display(myList);
	add(myList, 6);
	display(myList);
	insert(myList, 7, 2);
	display(myList);
	remove(myList, 3);
	display(myList);

	return 0;
}
