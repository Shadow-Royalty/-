#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data; // �ַ�
    int freq; // Ƶ��
    Node* left;
    Node* right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}


//    �����Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
// ��һ�����캯�������ڴ���Node���󲢽��г�ʼ����
//        �������˳�Ա��ʼ���б�ķ�ʽ��������Ĳ���d��f�ֱ�ֵ��data��freq��Ա������
// ����left��rightָ���ʼ��Ϊnullptr����ָ�룩��
//ʹ�ó�Ա��ʼ���б�ķ�ʽ������ߴ����Ч�ʺͿɶ��ԡ�
//        �ڹ��캯�����У������Ҫ�Գ�Ա�������и�ֵ��
// ��Ҫʹ�ø�ֵ���������ᵼ�¶�����ڴ����Ϳ���������
//        ��ʹ�ó�Ա��ʼ���б����ֱ�ӶԳ�Ա�������г�ʼ����
// ��������Щ����Ĳ������Ӷ�����˴����Ч�ʡ�

    //���൱��java�Ĺ��캯��
        
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;   
    }
};
//ȨֵԽ��������ǰ��ԽС���������ŵ�·����


// ������������
Node* createHuffmanTree(map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;//����
    //��������൱���Ƕ��е�����������������ģ�
    //�Ƕ����д�ŵĿռ�Ϊ������


    //�������ݵĲ���,�������ݺ�����
    for (const auto& pair : freqMap) {
        Node* node = new Node(pair.first, pair.second);


        //    for (const auto& pair : freqMap) { ... } �� C++11 �����һ���µ�ѭ���﷨��
        // �������ڷ�Χ�� for ѭ����range - based for loop����
        //
        //        �����ѭ���У�freqMap ����Ҫ������������c
        // onst auto& pair ��ÿ�ε���ʱ�� freqMap ��ȡ����Ԫ�ء�
        //
        //        ����һ�� const auto& pair��
        //
        //        auto �� C++11 �����һ���µ������ƶϻ��ơ�
        // ���������Զ��ƶ� pair �����ͣ��㲻��Ҫ��ʽ��ָ����
        //        ����������У�freqMap ��һ�� map<char, int> ���͵�������
        // ���� pair �����ͻᱻ�ƶ�Ϊ pair<const char, int>��
        //
        //        const ��ʾ��������ǳ������㲻���޸�����ֵ��
        // ����һ�ֺõı��ϰ�ߣ���Ϊ�����Է�ֹ����ѭ����������޸��� pair ��ֵ��
        //
        //        & ��ʾ���á����û��& ����ôÿ�ε���ʱ��
        // ����� freqMap �и���һ��Ԫ�ص� pair��
        //��� pair �����ͺܴ���ô�⽫����һ���ܺ�ʱ�Ĳ�����
        // ��������& ��pair ���� freqMap ��Ԫ�ص�һ�����ã����ᷢ�����ƣ�������ߴ����Ч�ʡ�


   /*     new Node(pair.first, pair.second) �ⲿ�ִ�������� Node ��Ĺ��캯����
            ����һ���µ� Node ����������캯����������������pair.first �� pair.second��
            ������������У�pair �� freqMap �е�һ��Ԫ�أ�����һ����ֵ�ԡ�
            pair.first ���ַ���char ���ͣ���pair.second �Ǹ��ַ���Ƶ�ʣ�int ���ͣ���*/

        pq.push(node);//����
    }

    //��ʼ������������
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq); // ����ڵ�
        //�����$ֻ��������˸��ַ��䵱�ַ���λ�ã�ûʲô��������
        //������Ϊ�˺ϳɸ��ڵ�

        parent->left = left;
        parent->right = right;
        //����������Ϊ�����Ӻ�������ݵ�
        //���ص�ֻ�Ǹ��ڵ㣬���Ǻ���ڵ�ı��������ݶ�����left��right�ڵ���

        pq.push(parent);
    }

    return pq.top();//���sizeΪ1ʱ��һ���Ǹ��ڵ�

}

// ��������������ȡ����
void getHuffmanCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) { // Ҷ�ӽڵ�
        huffmanCodes[root->data] = code;
        //��ȡ����ؼ�����
    }

    getHuffmanCodes(root->left, code + "0", huffmanCodes);
    getHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// �������������
void printHuffmanCodes(map<char, string>& huffmanCodes) {
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
        //      char                   string
    }
}

// ����ƽ�����볤��
float getAverageCodeLength(map<char, int>& freqMap, map<char, string>& huffmanCodes) {
    float totalFreq = 0;
    float totalCodeLen = 0;

    for (const auto& pair : freqMap) {
        totalFreq += pair.second;
        totalCodeLen += pair.second * huffmanCodes[pair.first].length();
        //Ƶ��*�����ַ��ı��볤��
        //huffmanCodes[pair.first]��ʵ����huffmanCodes��pair.second
        //ֻ�������������ڰ���freqMapѭ��.
        //�����ǵ�pair.first����ͬ��
        //��ʵ��������˵,
        //freqMap���ڴ��Ƶ��
        //huffmanCodes���ڴ�ű���
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
    };//ԭʼ����

    Node* root = createHuffmanTree(freqMap);
    //���������ĸ��ڵ㣬�������������������

    map<char, string> huffmanCodes;//�����������ȡ������������Ĺ�ϣ��
    getHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    printHuffmanCodes(huffmanCodes);

    float averageCodeLength = getAverageCodeLength(freqMap, huffmanCodes);
    cout << "Average Code Length: " << averageCodeLength << endl;

    return 0;
}
