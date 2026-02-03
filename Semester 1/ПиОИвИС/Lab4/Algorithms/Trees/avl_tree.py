class TreeNode:
    def __init__(self, data):
        self.height = 1
        self.data = data
        self.left = None
        self.right = None


def getHeight(node):
    if not node:
        return 0
    return node.height


def getBalance(node):
    if not node:
        return 0
    return getHeight(node.left) - getHeight(node.right)


def rightRotate(y):
    print('Rotate right on node', y.data)
    x = y.left
    T2 = x.right
    x.right = y
    y.left = T2
    y.height = 1 + max(getHeight(y.left), getHeight(y.right))
    x.height = 1 + max(getHeight(x.left), getHeight(x.right))
    return x


def leftRotate(x):
    print('Rotate left on node', x.data)
    y = x.right
    T2 = y.left
    y.left = x
    x.right = T2
    x.height = 1 + max(getHeight(x.left), getHeight(x.right))
    y.height = 1 + max(getHeight(y.left), getHeight(y.right))
    return y


def preOrderTraversal(root):
    if root is not None:
        print(root.data)
        preOrderTraversal(root.left)
        preOrderTraversal(root.right)


def inOrderTraversal(root):
    if root is not None:
        return inOrderTraversal(root.left) + [root.data] + inOrderTraversal(root.right)
    return []


def searchBinaryTree(root, target):
    if (not root):
        return None

    if (target == root.data):
        return root
    elif target <= root.data:
        return searchBinaryTree(root.left, target)
    elif target >= root.data:
        return searchBinaryTree(root.right, target)


def insertValue(root, value):
    if root is None:
        return TreeNode(value)

    if (value < root.data):
        root.left = insertValue(root.left, value)
    elif (value > root.data):
        root.right = insertValue(root.right, value)

    root.height = 1 + max(getHeight(root.left), getHeight(root.right))
    balance = getBalance(root)
    if balance > 1 and getBalance(root.left) >= 0:
        return rightRotate(root)

    if balance > 1 and getBalance(root.left) < 0:
        root.left = leftRotate(root.left)
        return rightRotate(root)

    if balance < -1 and getBalance(root.right) <= 0:
        return leftRotate(root)

    if balance < -1 and getBalance(root.right) > 0:
        root.right = rightRotate(root.right)
        return leftRotate(root)

    return root


def findLowest(root):
    current_node = root
    while (current_node.left):
        current_node = current_node.left

    return current_node


def delete(root, data):
    if not root:
        return None

    if (data < root.data):
        root.left = delete(root.left, data)
    elif (data > root.data):
        root.right = delete(root.right, data)
    else:
        if not root.left:
            temp = root.right
            root = None
            return temp
        elif not root.right:
            temp = root.left
            root = None
            return temp

        root.data = findLowest(root.right).data
        root.right = delete(root.right)

    root.height = 1 + max(getHeight(root.left), getHeight(root.right))
    balance = getBalance(root)
    if balance > 1 and getBalance(root.left) >= 0:
        return rightRotate(root)

    if balance > 1 and getBalance(root.left) < 0:
        root.left = leftRotate(root.left)
        return rightRotate(root)

    if balance < -1 and getBalance(root.right) <= 0:
        return leftRotate(root)

    if balance < -1 and getBalance(root.right) > 0:
        root.right = rightRotate(root.right)
        return leftRotate(root)
    return root


root = TreeNode(10)
root.left = TreeNode(7)
root.right = TreeNode(12)

root.left.left = TreeNode(4)
root.left.right = TreeNode(9)

root.right.left = TreeNode(11)
root.right.right = TreeNode(13)

root = insertValue(root, 15)
root = insertValue(root, 3)
print(inOrderTraversal(root))

delete(root, 13)
print(inOrderTraversal(root))
