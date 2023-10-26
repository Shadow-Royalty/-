#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data; // 字符
    int freq; // 频率
    Node* left;
    Node* right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}


//    这里的Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
// 是一个构造函数，用于创建Node对象并进行初始化。
//        它采用了成员初始化列表的方式，将传入的参数d和f分别赋值给data和freq成员变量，
// 并将left和right指针初始化为nullptr（空指针）。
//使用成员初始化列表的方式可以提高代码的效率和可读性。
//        在构造函数体中，如果需要对成员变量进行赋值，
// 需要使用赋值运算符，这会导致多余的内存分配和拷贝操作。
//        而使用成员初始化列表可以直接对成员变量进行初始化，
// 避免了这些额外的操作，从而提高了代码的效率。

    //就相当于java的构造函数
        
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;   
    }
};
//权值越大，在树的前面越小，就是最优的路径解


// 创建哈夫曼树
Node* createHuffmanTree(map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;//排序
    //这个容器相当于是队列的容器，是其中里面的，
    //是队列中存放的空间为容器。


    //插入数据的步骤,导入数据和排序
    for (const auto& pair : freqMap) {
        Node* node = new Node(pair.first, pair.second);


        //    for (const auto& pair : freqMap) { ... } 是 C++11 引入的一种新的循环语法，
        // 叫做基于范围的 for 循环（range - based for loop）。
        //
        //        在这个循环中，freqMap 是你要遍历的容器，c
        // onst auto& pair 是每次迭代时从 freqMap 中取出的元素。
        //
        //        解释一下 const auto& pair：
        //
        //        auto 是 C++11 引入的一种新的类型推断机制。
        // 编译器会自动推断 pair 的类型，你不需要显式地指定。
        //        在这个例子中，freqMap 是一个 map<char, int> 类型的容器，
        // 所以 pair 的类型会被推断为 pair<const char, int>。
        //
        //        const 表示这个变量是常量，你不能修改它的值。
        // 这是一种好的编程习惯，因为它可以防止你在循环中意外地修改了 pair 的值。
        //
        //        & 表示引用。如果没有& ，那么每次迭代时，
        // 都会从 freqMap 中复制一个元素到 pair。
        //如果 pair 的类型很大，那么这将会是一个很耗时的操作。
        // 但是有了& ，pair 就是 freqMap 中元素的一个引用，不会发生复制，可以提高代码的效率。


   /*     new Node(pair.first, pair.second) 这部分代码调用了 Node 类的构造函数，
            创建一个新的 Node 对象。这个构造函数接受两个参数：pair.first 和 pair.second。
            在这个上下文中，pair 是 freqMap 中的一个元素，它是一个键值对。
            pair.first 是字符（char 类型），pair.second 是该字符的频率（int 类型）。*/

        pq.push(node);//插入
    }

    //开始构建哈夫曼树
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq); // 虚拟节点
        //这里的$只是随便找了个字符充当字符的位置，没什么特殊意义
        //核心是为了合成根节点

        parent->left = left;
        parent->right = right;
        //这两步就是为了连接后面的数据的
        //返回的只是根节点，但是后面节点的遍历和数据都存在left和right节点中

        pq.push(parent);
    }

    return pq.top();//最后size为1时，一定是根节点

}

// 遍历哈夫曼树获取编码
void getHuffmanCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) { // 叶子节点
        huffmanCodes[root->data] = code;
        //获取编码关键步骤
    }

    getHuffmanCodes(root->left, code + "0", huffmanCodes);
    getHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// 输出哈夫曼编码
void printHuffmanCodes(map<char, string>& huffmanCodes) {
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
        //      char                   string
    }
}

// 计算平均编码长度
float getAverageCodeLength(map<char, int>& freqMap, map<char, string>& huffmanCodes) {
    float totalFreq = 0;
    float totalCodeLen = 0;

    for (const auto& pair : freqMap) {
        totalFreq += pair.second;
        totalCodeLen += pair.second * huffmanCodes[pair.first].length();
        //频率*单个字符的编码长度
        //huffmanCodes[pair.first]其实就是huffmanCodes的pair.second
        //只不过我们现在在按照freqMap循环.
        //而他们的pair.first是相同的
        //其实本质上来说,
        //freqMap用于存放频率
        //huffmanCodes用于存放编码
    }

    return totalCodeLen / totalFreq;
}

int main() {
    map<char, int> freqMap = {
        {'A', 19},
        {'B', 18},
        {'C', 16},
        {'D', 14},
        {'E', 12},
        {'F', 8},
        {'G', 6},
        {'H', 4},
        {'I', 2},
        {'J', 1}
    };//原始数据

    Node* root = createHuffmanTree(freqMap);
    //哈夫曼树的根节点，里面包括整个哈夫曼树

    map<char, string> huffmanCodes;//这个是用来获取哈夫曼树编码的哈希表
    getHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    printHuffmanCodes(huffmanCodes);

    float averageCodeLength = getAverageCodeLength(freqMap, huffmanCodes);
    cout << "Average Code Length: " << averageCodeLength << endl;

    return 0;
}
