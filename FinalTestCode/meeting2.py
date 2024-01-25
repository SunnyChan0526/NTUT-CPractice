from itertools import combinations
room, num = map(int, input().split())
room_people = {}
for i in range(room):
    name, people = map(int, input().split())
    room_people[i] = people
data = {}
meeting_people = {}
for i in range(num):
    item, people, start, over = map(int, input().split())
    data[str(i+1)] = [start, over]
    meeting_people[str(i+1)] = people
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
                thisMeetingPeople = meeting_people[j[k]]
                if check(data[j[k]], yes, adding) and room_people[0] >= thisMeetingPeople:
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
    sequence = []
    for i in range(room):
        s = ''
        s += str(i)
        for j in range(i+1, room):
            s += str(j)
        for j in range(0, 5-len(s)):
            s += str(j)
        sequence.append(s)

    for i in possiblenum:
        for j in i:
            for l in range(len(sequence)):
                add = 0
                yes = {}
                for k in range(room):
                    yes[k] = []
                for k in range(len(j)):
                    add = 0
                    thisMeetingPeople = meeting_people[j[k]]
                    for m in range(room):
                        thisRoomPeople = room_people[int(sequence[l][m])]
                        if check(data[j[k]], yes[int(sequence[l][m])], adding) and thisRoomPeople >= thisMeetingPeople:
                            yes[int(sequence[l][m])].append(data[j[k]])
                            add = 1
                            break
                    if add == 0:
                        break
                if add == 1:
                    break

            time = 0
            if add == 1:
                for k in j:
                    time += data[k][1] - data[k][0]
                ans.append(time)
    ans.sort()
    print(ans[-1])