from itertools import combinations
room, num = map(int, input().split())
data = {}
for i in range(num):
    item, start, over = map(int, input().split())
    data[str(item)] = [start, over]
mininum = min(room, num)
possiblenum = []
a = []
for i in range(1, num+1):
    a.append(str(i))
for i in range(mininum, num+1):
    possiblenum.append(list(combinations(a, i)))

adding = 0
def check(data, yes, adding):
    if yes == []:
        return True
    else:
        for i in yes:
            if data[0]<i[0] and data[1]<=i[0]:
                adding += 1
            elif i[1]<=data[0] and i[1]<data[1]:
                adding += 1
            else:
                adding = 0
        if adding == len(yes):
            return True
        else:
            return False

if room==0 or num==0:
    print(0)
elif room==1:
    ans = []
    for i in possiblenum:
        for j in i:
            yes = []
            add = 0
            for k in range(len(j)):
                if check(data[j[k]], yes, adding):
                    yes.append(data[j[k]])
                    add = 1
                if add == 0:
                    break
            if add == 1:
                time = 0
                for i in yes:
                    time += i[1] - i[0]
                ans.append(time)
    ans.sort()
    print(ans[-1])
else:
    ans = []
    for i in possiblenum:
        for j in i:
            yes = {}
            for k in range(room):
                yes[k] = []
            yes[0].append(data[j[0]]) 
            for k in range(1, len(j)):
                add = 0
                for l in range(room):
                    if check(data[j[k]], yes[l], adding):
                        yes[l].append(data[j[k]])
                        add = 1
                        break
                if add == 0:
                    break
            time = 0
            if add == 1:
                for k in j:
                    time += data[k][1] - data[k][0]
                ans.append(time)
    ans.sort()
    print(ans[-1])