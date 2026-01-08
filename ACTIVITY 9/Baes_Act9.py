# Activity 9: Heap Implementation

class MinHeap:
    def __init__(self):
        self.heap = []
    
    def parent(self, i):
        return (i - 1) // 2
    
    def leftChild(self, i):
        return 2 * i + 1
    
    def rightChild(self, i):
        return 2 * i + 2
    
    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    
    def insert(self, value):
        self.heap.append(value)
        self.heapifyUp(len(self.heap) - 1)
        print(f"Inserted {value} into the heap")
    
    def heapifyUp(self, i):
        while i > 0 and self.heap[i] < self.heap[self.parent(i)]:
            self.swap(i, self.parent(i))
            i = self.parent(i)
    
    def deleteMin(self):
        if len(self.heap) == 0:
            print("Heap is empty, cannot delete")
            return None
        
        if len(self.heap) == 1:
            return self.heap.pop()
        
        minVal = self.heap[0]
        self.heap[0] = self.heap.pop()
        self.heapifyDown(0)
        
        print(f"Deleted minimum value: {minVal}")
        return minVal
    
    def heapifyDown(self, i):
        minIndex = i
        left = self.leftChild(i)
        right = self.rightChild(i)
        
        if left < len(self.heap) and self.heap[left] < self.heap[minIndex]:
            minIndex = left
        
        if right < len(self.heap) and self.heap[right] < self.heap[minIndex]:
            minIndex = right
        
        if minIndex != i:
            self.swap(i, minIndex)
            self.heapifyDown(minIndex)
    
    def heapify(self, arr):
        self.heap = arr.copy()
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self.heapifyDown(i)
        print(f"Heapified array: {arr}")
    
    def display(self):
        if len(self.heap) == 0:
            print("Heap is empty")
        else:
            print(f"Current heap: {self.heap}")
    
    def getMin(self):
        if len(self.heap) == 0:
            return None
        return self.heap[0]


def testHeap():
    print("=" * 50)
    print("Testing Min-Heap Implementation")
    print("=" * 50)
    
    heap = MinHeap()
    
    print("\n--- Test 1: Inserting elements ---")
    heap.insert(10)
    heap.insert(5)
    heap.insert(20)
    heap.insert(1)
    heap.insert(15)
    heap.insert(30)
    heap.display()
    
    print("\n--- Test 2: Get minimum element ---")
    print(f"Minimum element: {heap.getMin()}")
    
    print("\n--- Test 3: Deleting minimum elements ---")
    heap.deleteMin()
    heap.display()
    heap.deleteMin()
    heap.display()
    
    print("\n--- Test 4: Insert more elements ---")
    heap.insert(3)
    heap.insert(8)
    heap.display()
    
    print("\n--- Test 5: Heapify from array ---")
    heap2 = MinHeap()
    testArray = [25, 10, 35, 5, 15, 40, 30]
    heap2.heapify(testArray)
    heap2.display()
    
    print("\n--- Test 6: Delete all elements ---")
    while heap2.getMin() is not None:
        heap2.deleteMin()
        heap2.display()
    
    print("\n--- Test 7: Delete from empty heap ---")
    heap2.deleteMin()
    
    print("\n" + "=" * 50)
    print("All tests completed!")
    print("=" * 50)


if __name__ == "__main__":
    testHeap()
