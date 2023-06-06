class set:
    def __init__(self):
        self.list = []

    def add(self,x):
        if x not in self.list:
            self.list.append(x)

    def remove(self,x):
        if x in self.list:
            self.list.remove(x)

    def contains(self,x):
        return x in self.list

    def size(self):
        return len(self.list)

    def iterator(self):
        return iter(self.list)

    def intersection(self,list):
        new = set()
        for i in self.list:
            if i in list:
                new.add(i)
        return new.list

    def union(self,list):
        new = set()
        for i in self.list:
            new.add(i)
        for i in list:
            new.add(i)
        return new.list

    def difference(self,list):
        new = set()
        for i in self.list:
            if i not in list:
                new.add(i)
        for i in list:
            if i not in self.list:
                new.add(i)
        return new.list

    def subset(self,list):
        for i in list:
            if i not in self.list:
                return False
        return True

    def display(self):
        for i in self.list:
            print(i," ")

a = set()
while True:
    print("1.add  2.remove  3.contain  4.size  5.iterator  6.intersection  7.union  8.difference  9.subset  10 . display  11.exit")
    ch = int(input("Enter the choice : "))
    if ch == 1:
        x = int(input("Enter the number : "))
        a.add(x)
    elif ch == 2:
        x = int(input("Enter the number : "))
        a.remove(x)
    elif ch == 3:
        x = int(input("Enter the number : "))
        print(a.contains(x))
    elif ch == 4:
        print(a.size())
    elif ch == 5:
        print(a.iterator())
    elif ch ==6:
        l = []
        n = int (input("Enter the size of list : "))
        for i in range(n):
            l.append(int(input("Enter number : ")))
        print(a.intersection(l))
    elif ch == 7:
        l = []
        n = int(input("Enter the size of list : "))
        for i in range(n):
            l.append(int(input("Enter number : ")))
        print(a.union(l))
    elif ch == 8:
        l = []
        n = int(input("Enter the size of list : "))
        for i in range(n):
            l.append(int(input("Enter number : ")))
        print(a.difference(l))
    elif ch == 9:
        l = []
        n = int(input("Enter the size of list : "))
        for i in range(n):
            l.append(int(input("Enter number : ")))
        print(a.subset(l))
    elif ch == 10:
        a.display()
    else:
        break