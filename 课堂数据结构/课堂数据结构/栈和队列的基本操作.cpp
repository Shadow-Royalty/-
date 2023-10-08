//1. ջ�Ͷ��е����ݽṹ���壺

// ջ�����ݽṹ����
typedef struct {
    int top;             // ջ��ָ��
    int capacity;        // ջ����
    int* array;          // ջ����
} Stack;

// ���е����ݽṹ����
typedef struct {
    int front;           // ����ָ��
    int rear;            // ��βָ��
    int capacity;        // ��������
    int* array;          // ��������
} Queue;

//��C / C++�У���������������һ��ָ��������Ԫ�ص�ָ�롣
//��ˣ���ʹ�� int* array; ����һ��ָ��ʱ��arrayָ�����һ��int���͵��ڴ�ռ䣬
//�����Ա������洢�������ݣ�Ҳ���Ա���������ʹ�á�



//2. ջ�Ľ�������ʼ�����пա���ջ����ջ�Ȳ�����


// ����һ���µ�ջ
Stack * createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    //��Ҫ�ڴ�ķ��ʣ�Ҫ���������������ú�����ڴ�ռ�
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// �ж�ջ�Ƿ�����
int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}
//��-1��ʼ����ȻҪ-1

// ��ջ
void push(Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("ջ�������޷���ջ��\n");
        return;
    }
    stack->array[++stack->top] = item;
   // stack->top��һ�����壬��ʾջ��
    //Ȼ�����++����ʾ������һ��λ��
    printf("%d ��ջ�ɹ���\n", item);
}

// ��ջ
int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("ջΪ�գ��޷���ջ��\n");
        return -1;
    }
    int item = stack->array[stack->top--];
    //ֻ��Ҫ��Top����һ����
    printf("%d ��ջ�ɹ���\n", item);
    return item;
}

// ���ջ
void clearStack(Stack* stack) {
    stack->top = -1;
}

// ����ջ
void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
```

//3. ���еĽ�������ʼ�����пա���ӡ����ӵȲ�����

// ����һ���µĶ���
Queue * createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

// �ж϶����Ƿ�����
int isQueueFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
   
}

// ���
void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("�����������޷���ӡ�\n");
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        //����һ��λ�ø��µ�����
    }
    

    queue->array[queue->rear] = item;
    printf("%d ��ӳɹ���\n", item);
}

// ����
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("����Ϊ�գ��޷����ӡ�\n");
        return -1;
    }
    int item = queue->array[queue->front];//��ͷ����
    if (queue->front == queue->rear) //���ʱ��˵�������н���һ��Ԫ�أ����Գ������Ԫ�غ��ֱ������Ϊ�ӿռ���
    {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;//ֱ���滻����һ��front
    }
    printf("%d ���ӳɹ���\n", item);
    return item;
}

// ��ն���
void clearQueue(Queue* queue) {
    queue->front = queue->rear = -1;
}

// ���ٶ���
void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}
