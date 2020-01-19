#!/usr/bin/env python
# coding: utf-8

# In[516]:


# import numpy as np
import random

from pip._vendor.msgpack.fallback import xrange


class Heap():
    def __init__(self, size):
        self.heap = [None for i in range(size)]
        self.size = size
        self.count = -1

    def parent(self, i):
        return i // 2 if i // 2 > -1 else 0

    def left(self, i):
        return 2 * i

    def right(self, i):
        return 2 * i + 1

    def isFull(self):
        return self.count == self.size - 1

    def isEmpty(self):
        return self.count == 0

    def expand(self, count):
        if self.isFull():
            self.heap += [None for i in range(count)]
            self.size += count

    def insert(self, data):
        if not self.isFull():
            self.count += 1
            self.heap[self.count] = data


        elif self.isFull():
            self.expand(1)
            self.count += 1
            self.heap[self.count] = data
        self.reheap(1, self.count)

    def reheap(self, status, data_index):
        if status == -1:  # delete data from heap tree

            root = data_index
            smallest = root
            if (self.left(root) < self.count) or (self.right(root) < self.count):
                if self.heap[self.left(root)] < self.heap[smallest]:
                    smallest = self.left(root)
                if self.heap[self.right(root)] < self.heap[smallest]:
                    smallest = self.right(root)
                if smallest != self.heap[root]:
                    self.heap[root], self.heap[smallest] = self.heap[smallest], self.heap[root]
                    data_index += 1
                    self.reheap(-1, data_index)

        elif status == 1:  # insert data in heap tree
            if self.heap[data_index] < self.heap[self.parent(data_index)]:
                self.heap[data_index], self.heap[self.parent(data_index)] = self.heap[self.parent(data_index)], \
                                                                            self.heap[data_index]
                index = self.heap.index(self.heap[self.parent(data_index)])
                self.reheap(1, index)

    def delete(self):
        result = self.heap[0]
        self.heap[0] = self.heap[self.count]
        self.heap[self.count] = None
        self.count -= 1
        self.reheap(-1, 0)
        return result


class Sort:
    def __init__(self):
        # self.arr = random.sample(range(1, 100), 5)
        self.arr = [50, 3, 25, 75, 85, 95, 2, 1, 33, 41, 51, 62, 53, 47, 46, 42]

    def Selection(self):
        for i in range(len(self.arr) - 1, -1, -1):
            max = self.arr[i]
            for k in range(i):
                if self.arr[k] > max:
                    max = self.arr[k]
                    self.arr[i], self.arr[k] = self.arr[k], self.arr[i]
        return self.arr

    def Insertion(self):
        for i in range(len(self.arr)):
            k = i - 1
            if k > -1:
                if self.arr[i] < self.arr[i - 1]:
                    self.arr[i], self.arr[i - 1] = self.arr[i - 1], self.arr[i]

                    while ((self.arr[k] < self.arr[k - 1]) and k):
                        self.arr[k], self.arr[k - 1] = self.arr[k - 1], self.arr[k]
                        k -= 1
        return self.arr

    def Bubble(self):
        for i in range(len(self.arr) - 1, -1, -1):
            for k in range(i):
                if self.arr[k] > self.arr[k + 1]:
                    self.arr[k], self.arr[k + 1] = self.arr[k + 1], self.arr[k]
        return self.arr

    def Quick(self, first=0, last=None):
        if last is None:
            last = len(self.arr) - 1

        return self._Quick(first, last)

    def partition(self, first, last):

        pivot = first
        for i in range(first + 1, last + 1):

            if self.arr[i] <= self.arr[first]:
                pivot += 1
                self.arr[pivot], self.arr[i] = self.arr[i], self.arr[pivot]
                print(first, '\tfirst', last, '\tlast')
                print(self.arr, '\treplace pivot with counter because arr[pivot] > arr[count] ')
        self.arr[pivot], self.arr[first] = self.arr[first], self.arr[pivot]
        print(self.arr, '\t', first, 'embedded in true location in array')
        return pivot

    def Merge(self, arr):

        if len(arr) > 1:
            mid = len(arr) // 2
            left = arr[:mid]  # index 1
            right = arr[mid:]  # index 2

            self.Merge(left)
            self.Merge(right)

            self.concatenate(left, right, arr)

        return arr

    def heap(self):
        heappop = Heap(5)
        res = []
        for i in self.arr:
            heappop.insert(i)
            # print(heappop.heap , "\tinsert")
        for i in self.arr:
            res.append(heappop.delete())
            # print(heappop.heap , "\tdelete")

        return res

    def concatenate(self, left, right, arr):

        index_1, index_2, index_0 = 0, 0, 0

        while index_1 < len(left) and index_2 < len(right):

            if left[index_1] < right[index_2]:

                arr[index_0] = left[index_1]
                index_1 += 1
            else:

                arr[index_0] = right[index_2]
                index_2 += 1

            index_0 += 1

        for i in range(len(left) - index_1):
            arr[index_0] = left[index_1]
            index_1 += 1
            index_0 += 1

        for i in range(len(right) - index_2):
            arr[index_0] = right[index_2]
            index_2 += 1
            index_0 -= -1

        return arr

    def _Quick(self, first, last):
        if first >= last:
            return
        pi = self.partition(first, last)
        self._Quick(first, pi - 1)
        self._Quick(pi + 1, last)


class KFold:
    def __init__(self, k):
        self.heap = Heap(4)
        self.array = []
        for i in range(k):
            self.array.append(random.sample(range(1, 100), 10))
            self.array[i].sort()
    def fold(self):
        

s = Sort()
print(s.arr)
# s.Insertion()

# s.Selection()

# s.Bubble()

# s.merge(s.arr)

# print(s.heap())

# s.Quick()
# print(s.arr)

kh = KFold(4)
print(kh.array)
