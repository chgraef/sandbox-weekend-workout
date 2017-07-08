class Node:
    def __init__(self, val, nxt=None):
        self.val = val
        self.nxt = nxt

    def __iter__(self):
        node = self

        while node != None:
            yield node
            node = node.nxt

def ary_to_linked(ary):
    if ary == None:
        raise ValueError('"ary" cannot be None')

    dummy = Node(0)
    node  = dummy

    for item in ary:
        node.nxt = Node(item)
        node     = node.nxt

    return dummy.nxt

def generate_ary(length):
    if length == None:
        raise ValueError('"length" cannot be None')

    if length < 0:
        raise ValueError('"length" cannot be negative')
    
    import random

    return [random.randint(0, length - 1) for times in range(length)]

def linked_max(head):
    if head == None:
        return None

    return max((node for node in head), key=lambda node: node.val)

def linked_to_s(head):
    if head == None:
        return str(None)

    return '->'.join(map(str, (node.val for node in head)))

length  = 32
numbers = generate_ary(length)

print(numbers)

head = ary_to_linked(numbers)

print(linked_to_s(head))

maxnode = linked_max(head)

print(maxnode.val)
