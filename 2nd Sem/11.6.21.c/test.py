repeat = int(input())
x = []
for i in range(0, repeat):
    com = input().split()
    cmd = com[0]
    if cmd == "insert":
        x.insert(int(com[1]), com[2])
    elif cmd=="print":
        print(x)
    elif cmd =="remove":
        x.remove(com[1])
    elif cmd =="append":
        x.append(com[1])
    elif cmd=="pop":
        x.pop()
    elif cmd == "sort":
        x.sort()
    else:
        x.reverse()
