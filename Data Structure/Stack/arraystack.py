'''
Implement a stack using an array
'''

class ArrayStack:
    def __init__(self, init_size = 5):
        self.arr = [0.0 for _ in range(init_size)]
        self.top = -1
        self.n_element = 0

    def push(self, data):
        if self.n_element == len(self.arr):
            print("Increase capacity")
            self._increase_capacity()
        self.top += 1
        self.arr[self.top] = data
        self.n_element += 1

    def pop(self):
        if self.is_empty:
            print("Empty stack")
            return None
        pop = self.arr[self.top]
        self.top -= 1
        self.n_element -= 1
        return pop

    def size(self):
        return self.n_element

    def is_empty(self):
        if self.top < 0:
            return True
        else:
            return False

    def print_stack(self):
        if self.is_empty():
            print("Empty stack")
            return
        else:
            print(self.arr[0:self.top+1])

    def _increase_capacity(self):
        new_size = len(self.arr) * 2
        new_arr = [0.0 for _ in range(new_size)]
        for i, elem in enumerate(self.arr):
            new_arr[i] = elem
        self.arr = new_arr


if __name__ == "__main__":
    stk = ArrayStack(5)
    stk.push(2)
    stk.push(3)
    stk.push(4)
    stk.push(4)
    stk.print_stack()
    stk.push(5)
    stk.push(5)
    stk.print_stack()
