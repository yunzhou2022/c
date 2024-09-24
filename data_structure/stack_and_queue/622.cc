class MyCircularQueue {
public:
  int arr[1005], head, tail, cnt, total;
  MyCircularQueue(int k) {
    cnt = 0;
    total = k;
    head = 0;
    tail = 0;
  }

  bool enQueue(int value) {
    if (total == cnt)
      return false;
    arr[tail] = value;
    tail = (tail + 1) % total;
    cnt++;
    return true;
  }

  bool deQueue() {
    if (cnt == 0) {
      return false;
    }
    head = (head + 1) % total;
    cnt--;
    return true;
  }

  int Front() {
    if (cnt == 0)
      return -1;
    return arr[head];
  }

  int Rear() {
    if (cnt == 0)
      return -1;
    return arr[(tail - 1 + total) % total];
  }

  bool isEmpty() { return cnt == 0; }

  bool isFull() { return cnt == total; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
