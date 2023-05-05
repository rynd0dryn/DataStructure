class Stack():
    def __init__(self,size = 10):
            self.size = size
        self.stack = []
        
    def push(self, data):
        if(self.isFull()):
            print("Stack is Full")
        else:
            self.stack.append(data)
        
    def pop(self):
        if self.isEmpty():
            print("Stack is Empty")
        else:
            return self.stack.pop()
            
            
    def top(self):
        if self.isEmpty():
            print("Stack is Empty")
        else:
            return self.stack[-1]
            
    def makeEmpty(self):
        self.stack.clear()
            
    def isEmpty(self):
        is_empty = False
        if len(self.stack) == 0:
            is_empty = True
        return is_empty
        
    def isFull(self):
        if(len(self.stack) == size):
            return True
        else return False

    def size(self):
        return len(self.size)
