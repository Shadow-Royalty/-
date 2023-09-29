//总结
//指针可以直接改变自己储存的数据
//但是要改变指针自己本身，就必须要使用**//总结
//指针可以直接改变自己储存的数据
//但是要改变指针自己本身，就必须要使用**

#include <iostream>
using namespace std;
#define MAX_SIZE 100  // 假设线性表的最大容量为100

struct SeqList {
	int data[MAX_SIZE];  // 存放元素的数组
	int size;  // 当前元素个数
};

// 建立线性表
void create(SeqList& list) {
	list.size = 0;  // 初始时元素个数为0
}

// 初始化线性表
void init(SeqList& list, int arr[], int arrSize) {
	if (arrSize <= MAX_SIZE) {
		for (int i = 0; i < arrSize; i++) {
			list.data[i] = arr[i];
		}
		list.size = arrSize;
		std::cout << "线性表已初始化。" << std::endl;
	}
	else {
		std::cout << "初始化失败，数组大小超过线性表最大容量。" << std::endl;
	}
}

// 增加元素
void add(SeqList& list, int elem) {
	if (list.size < MAX_SIZE) {
		list.data[list.size] = elem;
		list.size++;
		std::cout << "元素 " << elem << " 已添加到线性表末尾。" << std::endl;
	}
	else {
		std::cout << "增加失败，线性表已满。" << std::endl;
	}
}

// 插入元素
void insert(SeqList& list, int elem, int position) {
	//if (pos >= 0 && pos <= 100) err
		//这里不是<=100,而是小于顺序表的大小!
	if (position >= 0 && position <= list.size && list.size < MAX_SIZE) {
		for (int i = list.size - 1; i >= position; i--) {
			list.data[i + 1] = list.data[i];  // 元素后移
		}
		list.data[position] = elem;

		list.size++; //!:长度可以不加了是吧？
		std::cout << "元素 " << elem << " 已插入到位置 " << position << "。" << std::endl;
	}
	else {
		std::cout << "插入失败，位置不合法或线性表已满。" << std::endl;
	}
}

//不同于插入，插入是从无到有，自然要写出插入的数字是什么
//而删除不同，删除是你通过下标就能得出该数据的操作，所以是不需要导入
//该数字的！
// 
// 删除元素
//void delete(lianbiao& myList, int num, int pos)  err
void remove(SeqList& list, int position) {

	//删除不同于插入，本身就是减少大小没必要再判定size！
//if (myList.size >= 0 && myList.size <= 100) err

	if (position >= 0 && position < list.size) {
		int elem = list.data[position];
		for (int i = position; i < list.size - 1; i++) {
			list.data[i] = list.data[i + 1];  // 元素前移
		}
		list.size--;	//同理，上面一样的错误不会减小长度
		std::cout << "元素 " << elem << " 已从位置 " << position << " 删除。" << std::endl;
	}
	else {
		std::cout << "删除失败，位置不合法。" << std::endl;
	}
}

void display(SeqList& list)

{
	// cout << list.data;  err
	 //你直接不写序号，直接给你打印一个数据的地址
	 //所以说还得老老实实的写序号！

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
