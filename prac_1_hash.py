class hashtable:
    def __init__(self):
        self.size = int(input("Enter the size of Hash Table : "))
        self.teles = []
        self.names = []
        for i in range(self.size):
            self.teles.append(0)
            self.names.append("")

    def display(self):
        for i in range(self.size):
            print(self.names[i]," : ",self.teles[i])

    def linear(self,name,x):
        index = x % self.size
        if self.teles[index]==0:
            self.teles[index] = x
            self.names[index] = name
        else:
            id = (index + 1) % self.size
            while id != index:
                if self.teles[id] == 0:
                    self.teles[id] = x
                    self.names[id] = name
                    return
                id = (id + 1) % self.size

    def quad_insert(self,name,x):
        index = x % self.size
        if self.teles[index] == 0:
            self.teles[index] = x
            self.names[index] = name
        else:
            i = 1
            cnt = 0
            while self.teles[index] != 0:
                index = (index + i*i) % self.size
                cnt+=1
                i+=1
                if(cnt==1000):
                    print("Exception of quad_search")
                    return
            self.teles[index] = x
            self.names[index] = name

    def linear_search(self,x):
        index = x % self.size
        cnt = 1
        id = (index + 1) % self.size
        if x == self.teles[index]:
            print(self.names[index], " : ", self.teles[index], " ", cnt)
            return
        while id != index :
            cnt += 1
            if x == self.teles[id]:
                print(self.names[id]," : ",self.teles[id]," ",cnt)
                return
            elif self.teles[id] == 0:
                print("not found",cnt)
                return
            id = (id + 1) % self.size

    def quad_search(self,x):
        index = x % self.size
        cnt = 1
        i=1
        if x == self.teles[index]:
            print(self.names[index], " : ", self.teles[index], " ", cnt)
            return
        else:
            while self.teles[index] != 0:
                cnt+=1
                index = (index + i*i )% self.size
                if x == self.teles[index]:
                    print(self.names[index], " : ", self.teles[index], " ", cnt)
                    return
                i+=1
                if cnt==1000:
                    print("Exception quad_search")
                    return
            print("not found", cnt)


h = hashtable()
print("1. linear probing       2. Quadratic probing")
ch = int(input("Enter the choice : "))
while True :
    if ch==1:
        print("1. insert      2. search     3. display all      4. exit")
        ch1 = int(input("Enter choice : "))
        if ch1 == 1:
            x = int(input("Enter the tele number : "))
            name = (input("Enter the name : "))
            h.linear(name,x)
        elif ch1 ==2:
            x = int(input("Enter the tele number : "))
            h.linear_search(x)
        elif ch1==3:
            h.display()
        else:
            ch = 3
    elif ch==2:
        print("1. insert      2. search     3. display all      4. exit")
        ch1 = int(input("Enter choice : "))
        if ch1 == 1:
            x = int(input("Enter the tele number : "))
            name = (input("Enter the name : "))
            h.quad_insert(name, x)
        elif ch1 == 2:
            x = int(input("Enter the tele number : "))
            h.quad_search(x)
        elif ch1 == 3:
            h.display()
        else:
            ch = 3
    else:
        break