inputs = input().split()

pointList = []
symbolList = []
for i in inputs:
    card = i[:-1]
    symbol = i[-1]
    if card == 'J':
        point = 11
    elif card == 'Q':
        point = 12
    elif card == 'K':
        point = 13
    elif card == 'A':
        point = 14
    else:
        point = int(card)
    pointList.append(point)
    symbolList.append(symbol)  

pointNum = {}
for i in pointList:
    pointNum[i] = pointList.count(i)

NumList = []
for i in pointNum:
    NumList.append(pointNum[i])

def straight(pointList):
    d = []
    for i in range(1, 5):
        d.append(pointList[i] - pointList[i-1])
    if (d.count(1) == 4) or ((d.count(1) == 3) and (d.count(-12) == 1)):
        return True
    else:
        return False

ans = 0
if 2 in NumList:
    ans = 1
if NumList.count(2) == 2:
    ans = 2
if 3 in NumList:
    ans = 3
if straight(pointList):
    ans = 4
if symbolList.count(symbolList[0]) == 5:
    ans = 5
if (3 in NumList) and (2 in NumList):
    ans = 6
if 4 in NumList:
    ans = 7
if straight(pointList) and (symbolList.count(symbolList[0]) == 5):
    ans = 8
print(ans)