
class Stack:
    def __init__(self):
        self.items = []

    def size(self):
        return len(self.items)

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.size()==0:
            return None
        else:
            return self.items.pop()

def equation_checker(equation):
    """
    Check equation for balanced parentheses

    Args:
       equation(string): String form of equation
    Returns:
       bool: Return if parentheses are balanced or not
    """

    pstack = Stack()

    for c in equation:
        if c == '(':
            pstack.push(c)
        elif c == ')':
            top = pstack.pop()
            if top == '(':
                continue
            else:
                return False
        else:
            pass

    if pstack.size() == 0:
        return True
    else:
        return False


    # # TODO: Intiate stack object
    # mystack = Stack()
    # # TODO: Interate through equation checking parentheses
    # for stt in equation:
    #     if stt == '(':
    #         mystack.push(stt)
    #     elif stt == ')':
    #         if mystack.pop() == None:
    #             return False
    # # TODO: Return True if balanced and False if not
    #
    # return mystack.size() == 0


print ("Pass" if (equation_checker('((3^2 + 8)*(5/2))/(2+6)')) else "Fail")
print ("Pass" if not (equation_checker('((3^2 + 8)*(5/2))/(2+6))')) else "Fail")
