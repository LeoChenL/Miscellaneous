'''
Implement a stack using an link list

add or remove the item from the head of the linked list, and update the head reference
pop and push have a time complexity of O(1)
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkStack:
    def __init__(self):
        self.head = None
        self.n_element = 0

    def push(self, data):
        if self.head == None:
            self.head = Node(data)
            self.n_element += 1
        else:
            node = Node(data)
            node.next = self.head
            self.head = node
            self.n_element += 1

    def size(self):
        return self.n_element

    def is_empty(self):
        if self.n_element == 0:
            print("Empty stack")
            return True
        else:
            return False

    def pop(self):
        if ~self.is_empty():
            pop_node = self.head
            self.head = pop_node.next
            self.n_element -= 1
            return pop_node.data

    def print_stack(self):
        if ~self.is_empty():
            tmp = self.head
            while tmp is not None:
                print(tmp.data, ' ')
                tmp = tmp.next
            print('\n')

if __name__ == "__main__":
    stk = LinkStack()
    stk.print_stack()
    stk.push(2)
    stk.push(3)
    stk.push(4)
    stk.push(4)
    stk.push(5)
    stk.print_stack()

    pop = stk.pop()
    print(pop, '\n')
    stk.print_stack()
