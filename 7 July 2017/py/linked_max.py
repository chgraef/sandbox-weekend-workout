#
# Adapted from the "Algorithms (IVth ed.) 
# by Robert Sedgewick and Kevin Wayne.
#
# Write a method linked_max() that takes a reference to the first 
# node in a linked list as argument and returns the value of the 
# maximum key in the list. Assume that all keys are positive 
# integers, and return None if the list is empty.
#
#

class Node:
    def __init__(self, val, nxt=None):
        self.val = val
        self.nxt = nxt

def linked_max(head):
    
    def helper(curnode, maxnode):
        if curnode == None:
            return maxnode

        maxnode = max(curnode, maxnode, key=lambda node: node.val)
        return helper(curnode.nxt, maxnode)

    if head == None:
        raise ValueError('"head" cannot be None')

    return helper(head.nxt, head)

def ary_to_linked(ary):
    if ary == None:
        raise ValueError('"ary" cannot be None')

    dummy = Node(0)
    node  = dummy

    for item in ary:
        node.nxt = Node(item)
        node     = node.nxt

    return dummy.nxt

def linked_to_s(head):

    def helper(node, stack=None):
        stack = stack or []

        if node == None:
            values = map(lambda node: str(node.val), stack)
            return '->'.join(values)

        stack.append(node)
        return helper(node.nxt, stack)

    if head == None:
        return str(None)

    return helper(head)

def generate_ary(length):
    if length == None:
        raise ValueError('"length" cannot be None')

    if length < 0:
        raise ValueError('"length" cannot be negative')
    
    import random

    return [random.randint(0, length - 1) for times in range(length)]

length  = 32
numbers = generate_ary(length)

print(numbers)

head = ary_to_linked(numbers)

print(linked_to_s(head))

maxnode = linked_max(head)

print(maxnode.val)
