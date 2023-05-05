class SortedList:
    def __init__(self, iterable=[]):
        self.items = []
        for item in iterable:
            self.add(item)

    def add(self, item):
        # 이진 탐색으로 정렬된 위치를 찾아 삽입
        low = 0
        high = len(self.items) - 1
        while low <= high:
            mid = (low + high) // 2
            if self.items[mid] < item:
                low = mid + 1
            else:
                high = mid - 1
        self.items.insert(low, item)

    def remove(self, item):
        self.items.remove(item)

    def __getitem__(self, index):
        return self.items[index]

    def __len__(self):
        return len(self.items)
