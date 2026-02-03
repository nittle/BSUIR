class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def deleteNode(head, nodeToDelete):
    if nodeToDelete is head:
        return head.next

    currentNode = head
    while currentNode.next and currentNode.next is not nodeToDelete:
        currentNode = currentNode.next

    currentNode.next = nodeToDelete.next

    return head


def insertNode(head, position, newNode):
    if position == 1:
        newNode.next = head
        return newNode

    currentNode = head
    for _ in range(position - 2):
        if currentNode is None:
            break
        currentNode = currentNode.next
    newNode.next = currentNode.next
    currentNode.next = newNode
    return head


node1 = Node(10)
node2 = Node(20)
node3 = Node(30)
node4 = Node(40)

node1.next = node2
node2.next = node3
node3.next = node4

node1 = insertNode(node1, 4, Node(50))

node = node1
while (node != None):
    print(node.data, end=' ')
    node = node.next
