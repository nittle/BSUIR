binary_tree_array = [10, 20, 30, None, None, 50]


def left_child_index(index):
    return 2*index + 1


def right_child_index(index):
    return 2*index + 2


def get_data(index):
    if 0 <= index < len(binary_tree_array):
        return binary_tree_array[index]
    return None
