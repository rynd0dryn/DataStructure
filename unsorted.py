class UnsortedList(list):
    def __init__(self, *args, **kwargs):
        super(UnsortedList, self).__init__(*args, **kwargs)

    def append(self, item):
        super(UnsortedList, self).append(item)

    def remove(self, item):
        super(UnsortedList, self).remove(item)