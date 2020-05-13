'''
Implement a queue using a link list
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class ListQueue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.n_element = 0

    def enqueue(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
            self.n_element += 1
        else:
            self.tail.next = new_node
            self.tail = self.tail.next
            self.n_element += 1

    def dequeue(self):
        if self.is_empty():
            return
        else:
            data = self.front()
            self.head = self.head.next
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
            return self.head.data

if __name__ == "__main__":
    # Setup
    q = ListQueue()
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
