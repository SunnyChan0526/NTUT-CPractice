##input
num = int(input())
data = {}
for i in range(num):
    s = input().split()
    data[s[0]] = []
    for j in range(1, len(s)):
        data[s[0]].append(s[j])

requirement = input()
a = requirement.split('+')
for i in range(len(a)):
    a[i] = a[i].strip()
    a[i] = a[i].split()

##processing
count = {}
ans = {}
for i in data:
    ans[i] = 0
for i in a:
    for j in data:
        count[j] = 0
    for j in i:
        if j[0] == '!':
            for k in data:
                if j[1:] not in data[k]:
                    count[k] += 1
        else:
            for k in data:
                if j in data[k]:
                    count[k] += 1
    for j in count:
        if count[j] == len(i):
            ans[j] += 1

##output
lst = []
lst2 = []
answer = ''
for i in ans:
    lst.append(ans[i])
lst.sort(reverse = 1)
for i in lst:
    if i not in lst2:
        lst2.append(i)
for i in lst2:
    for j in ans:
        if (i == ans[j]) and (i != 0):
            answer += j + ',' + str(i) + ' '
print(answer.strip())