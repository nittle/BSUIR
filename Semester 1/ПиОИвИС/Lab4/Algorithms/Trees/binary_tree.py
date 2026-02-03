class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


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
    return root


root = TreeNode(10)
root.left = TreeNode(7)
root.right = TreeNode(12)

root.left.left = TreeNode(4)
root.left.right = TreeNode(9)

root.right.left = TreeNode(11)
root.right.right = TreeNode(13)

insertValue(root, 15)
insertValue(root, 3)
print(inOrderTraversal(root))

delete(root, 13)
print(inOrderTraversal(root))
