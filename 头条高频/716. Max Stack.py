"""
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. 
If you find more than one maximum elements, only remove the top-most one.
"""

class MaxStack():
    def __init__(self):
        self.s1 = []
        self.s2 = []
    
    def push(self, x):
        if not self.s2 or self.s2[-1] <= x:
            self.s2.append(x)
        self.x1.append(x)
    
    def pop(self):
        if self.s2 and self.s2[-1] == self.s1[-1]:
            self.s2.pop()
        t = self.s1.pop()
        return t
    
    def top(self):
        return self.s1[-1]
    
    def peekMax(self):
        return self.s2[-1]

    def popMax(self):
        mx = self.s2[-1]
        tmp = []
        while self.s1 and self.s1[-1] != mx:
            tmp.append(self.s1[-1])
            self.s1.pop()
        self.s1.pop()
        self.s2.pop()
        while tmp:
            self.s1.append(tmp.pop())
        
        return mx
            