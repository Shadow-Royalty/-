//1. 栈和队列的数据结构定义：

// 栈的数据结构定义
typedef struct {
    int top;             // 栈顶指针
    int capacity;        // 栈容量
    int* array;          // 栈数据
} Stack;

// 队列的数据结构定义
typedef struct {
    int front;           // 队首指针
    int rear;            // 队尾指针
    int capacity;        // 队列容量
    int* array;          // 队列数据
} Queue;

//在C / C++中，数组名本质上是一个指向数组首元素的指针。
//因此，当使用 int* array; 声明一个指针时，array指向的是一个int类型的内存空间，
//它可以被用来存储整数数据，也可以被当做数组使用。



//2. 栈的建立、初始化、判空、入栈、出栈等操作：


// 创建一个新的栈
Stack * createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    //需要内存的访问，要访问容量才能设置合理的内存空间
    return stack;
}

// 判断栈是否为空
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}
//从-1开始，自然要-1

// 入栈
void push(Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("栈已满，无法入栈。\n");
        return;
    }
    stack->array[++stack->top] = item;
   // stack->top是一个整体，表示栈顶
    //然后才是++，表示插入下一个位置
    printf("%d 入栈成功。\n", item);
}

// 出栈
int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("栈为空，无法出栈。\n");
        return -1;
    }
    int item = stack->array[stack->top--];
    //只需要把Top数减一即可
    printf("%d 出栈成功。\n", item);
    return item;
}

// 清空栈
void clearStack(Stack* stack) {
    stack->top = -1;
}

// 销毁栈
void destroyStack(Stack* stack) {
    free(stack->array);
    free(stack);
}
```

//3. 队列的建立、初始化、判空、入队、出队等操作：

// 创建一个新的队列
Queue * createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// 判断队列是否为空
int isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

// 判断队列是否已满
int isQueueFull(Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
   
}

// 入队
void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("队列已满，无法入队。\n");
        return;
    }
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        //分配一个位置给新的数据
    }
    

    queue->array[queue->rear] = item;
    printf("%d 入队成功。\n", item);
}

// 出队
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("队列为空，无法出队。\n");
        return -1;
    }
    int item = queue->array[queue->front];//队头出队
    if (queue->front == queue->rear) //相等时，说明队列中仅有一个元素，所以出队完该元素后就直接设置为队空即可
    {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;//直接替换成下一个front
    }
    printf("%d 出队成功。\n", item);
    return item;
}

// 清空队列
void clearQueue(Queue* queue) {
    queue->front = queue->rear = -1;
}

// 销毁队列
void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}
