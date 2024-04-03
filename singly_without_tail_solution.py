class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
    
    def __str__(self):
        return str(self.data)

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def __str__(self):
        nodes_str = []
        current = self.head
        while current is not None:
            nodes_str.append(str(current))
            current = current.next
        nodes_str.append("None")
        output = " -> ".join(nodes_str)
        return output

    def add(self, item):
        temp = Node(item, self.head)
        self.head = temp
        self.size += 1

    def is_empty(self):
        return self.head is None

    def remove(self, item):
        current = self.head
        previous = None

        while current is not None:
            if current.data == item:
                break
            previous = current
            current = current.next

        if current is None:
            raise ValueError(str(item) + " is not in list.")
        if previous is None:
            self.head = current.next
        else:
            previous.next = current.next
        self.size -= 1

    def search(self, item):
        current = self.head
        while current is not None:
            if current.data == item:
                return True
            current = current.next

        return False

    def append(self, item):
        new_node = Node(item)
        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = new_node
        self.size += 1

    def insert(self, pos, item):
        if pos > self.size:
            raise IndexError("Index out of bounds")
        if pos == 0:
            self.add(item)
            return
        if pos == self.size:
            self.append(item)
            return

        new_node = Node(item)
        current = self.head
        for _ in range(pos - 1):
            current = current.next
        new_node.next = current.next
        current.next = new_node
        self.size += 1
    
    def pop(self, pos=None):
        if self.size == 0:
            raise IndexError("List is empty")
        if pos is None:
            pos = self.size - 1
        elif pos >= self.size:
            raise IndexError("Index out of bounds")
        
        current = self.head
        previous = None
        for _ in range(pos):
            previous = current
            current = current.next

        if previous is None:
            self.head = current.next
        else:
            previous.next = current.next
        self.size -= 1
        return current.data
    


# Test 0: Basic add()
def test_0():
    my_list = LinkedList()
    my_list.add(44)
    assert my_list.size == 1, "Test 0 Failed - size is incorrect"
    assert str(my_list) == "44 -> None", "Test 0 Failed - list is incorrect"
    print("Test 0 Complete")


# Test 1: Basic is_empty()
def test_1():
    my_list = LinkedList()
    assert my_list.is_empty(), "Test 1 Failed"
    print("Test 1 Complete")


# Test 2: is_empty() after add
def test_2():
    my_list = LinkedList()
    my_list.add(13)
    assert not my_list.is_empty(), "Test 2 Failed"
    print("Test 2 Complete")


# Test 3: is_empty() after add/remove
def test_3():
    my_list = LinkedList()
    my_list.add(426)
    my_list.remove(426)
    assert my_list.is_empty(), "Test 3 Failed"
    print("Test 3 Complete")


# Test 4: remove shouldn't work on empty list
def test_4():
    my_list = LinkedList()
    try:
        my_list.remove(0)
        assert False, "Test 4 Failed - ValueError not raised"
    except ValueError:
        print("Test 4 Complete")


# Test 5: remove head
def test_5():
    my_list = LinkedList()
    my_list.add(42)
    my_list.add(231)
    my_list.remove(231)
    assert str(my_list.head) == "42", "Test 5 Failed"
    assert my_list.size == 1, "Test 5 Failed - size is incorrect"
    print("Test 5 Complete")


# Test 6: remove resets prev and next properly
def test_6():
    my_list = LinkedList()
    my_list.add(42)
    my_list.add(231)
    my_list.add(111)
    my_list.remove(231)
    assert str(my_list) == "111 -> 42 -> None", "Test 6 Failed"
    print("Test 6 Complete")


# Test 7-8: Testing search
def test_search(item, test_number):
    my_list = LinkedList()
    my_list.add(1)
    my_list.add(2)
    my_list.add(3)
    assert my_list.search(item) == True, f"Test {test_number} Failed"
    print(f"Test {test_number} Complete")


# Test 7:
def test_7():
    test_search(1, 7)


# Test 8:
def test_8():
    test_search(3, 8)


# Test 9: 
def test_9():
    my_list = LinkedList()
    my_list.add(1)
    my_list.add(2)
    my_list.add(3)
    assert my_list.search(0) == False, "Test 9 Failed"
    print("Test 9 Complete")


# Test: Testing append
def test_10():
    my_list = LinkedList()
    my_list.append(72)
    assert str(my_list.head) == "72", "Test 10 Failed"
    print("Test 10 Complete")


# Test: Testing append
def test_11():
    my_list = LinkedList()
    my_list.append(72)
    my_list.append(23)
    my_list.append(40)
    assert str(my_list) == "72 -> 23 -> 40 -> None", "Test 11 Failed"
    print("Test 11 Complete")


# Test: Testing append/remove
def test_12():
    my_list = LinkedList()
    my_list.append(72)
    my_list.append(23)
    my_list.append(40)
    my_list.remove(23)
    assert my_list.size == 2, "Test 12 Failed - size is incorrect"
    assert str(my_list) == "72 -> 40 -> None", "Test 12 Failed - list is incorrect"
    print("Test 12 Complete")


# Test: Testing insert
def test_13():
    my_list = LinkedList()
    my_list.add(61)
    try:
        my_list.insert(2, 32)
        assert False, "Test 13 Failed - IndexError not raised"
    except IndexError:
        print("Test 13 Complete")


# Test: Testing insert
def test_14():
    my_list = LinkedList()
    my_list.add(61)
    my_list.add(12)

    my_list2 = LinkedList()
    my_list2.insert(0, 61)
    my_list2.insert(0, 12)

    assert str(my_list) == str(my_list2), "Test 14 Failed"
    print("Test 14 Complete")


# Test 15: Testing insert
def test_15():
    my_list = LinkedList()
    my_list.insert(0, 13)
    my_list.insert(1, 8)
    my_list.insert(2, 16)
    assert str(my_list) == "13 -> 8 -> 16 -> None", "Test 15 Failed"
    print("Test 15 Complete")


# Test 16: 
def test_16():
    my_list = LinkedList()
    my_list.add(11)
    my_list.add(27)
    my_list.add(34)
    assert my_list.pop(1) == 27, "Test 16 Failed"
    assert str(my_list) == "34 -> 11 -> None", "Test 16 Failed - list is incorrect"
    print("Test 16 Complete")


# Test 17:
def test_17():
    my_list = LinkedList()
    try:
        my_list.pop(2)
        assert False, "Test 17 Failed - IndexError not raised"
    except IndexError:
        print("Test 17 Complete")


# Test 18:
def test_18():
    my_list = LinkedList()
    my_list.add(11)
    try:
        my_list.pop(2)
        assert False, "Test 18 Failed - IndexError not raised"
    except IndexError:
        print("Test 18 Complete")


# Test 19:
def test_19():
    my_list = LinkedList()
    my_list.add(11)
    my_list.add(135)
    assert my_list.pop() == 11, "Test 19 Failed"
    assert my_list.size == 1, "Test 19 Failed - size is incorrect"
    print("Test 19 Complete")


for i in range(20):
    eval("test_" + str(i) + "()")
