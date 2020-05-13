'''
Implement a queue using an array
'''

class ArrayQueue:
    def __init__(self, init_size = 5):
        self.arr = [0.0 for _ in range(init_size)]
        self.head = None
        self.tail = None
        self.n_element = 0

    def enqueue(self, data):
        if self.is_empty():
            self.head = 0
            self.tail = 0
            self.arr[self.tail] = data
            self.n_element += 1
        else:
            if self.n_element == len(self.arr):
                self._increase_capacity()

            self.tail += 1
            self.tail = self.tail % len(self.arr)
            self.n_element += 1
            self.arr[self.tail] = data

    def dequeue(self):
        if self.is_empty():
            return
        else:
            data = self.arr[self.head]
            self.head += 1
            self.head = self.head % len(self.arr)
            self.n_element -= 1
            return data

    def size(self):
        return self.n_element

    def is_empty(self):
        if self.n_element == 0:
            print("Empty queue")
            return True
        else:
            return False

    def front(self):
        if self.is_empty():
            return None
        else:
            return self.arr[self.head]

    def _increase_capacity(self):
        new_size = len(self.arr) * 2
        new_arr = [0.0 for _ in range(new_size)]
        for idx, elem in enumerate(self.arr):
            new_arr[idx] = elem
        self.arr = new_arr

if __name__ == "__main__":
    # Setup
    q = ArrayQueue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)

    # Test size
    print ("Pass" if (q.size() == 3) else "Fail")

    # Test dequeue
    print ("Pass" if (q.dequeue() == 1) else "Fail")

    # Test enqueue
    q.enqueue(4)
    print ("Pass" if (q.dequeue() == 2) else "Fail")
    print ("Pass" if (q.dequeue() == 3) else "Fail")
    print ("Pass" if (q.dequeue() == 4) else "Fail")
    q.enqueue(5)
    print ("Pass" if (q.size() == 1) else "Fail")
