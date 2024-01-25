num = int(input())
school = {}
for i in range(num):
    s = input().split()
    school[s[0]] = []
    for j in range(1, len(s)):
        school[s[0]].append(s[j])
require = input().split('+')
for i in range(len(require)):
    require[i] = require[i].strip()

schoolNum = {}
for i in school:
    schoolNum[i] = 0
    for j in require:
        item = j.split(' ')
        num = 0
        for k in item:
            if k[0] == '!':
                if k[1:] not in school[i]:
                    num += 1
            else:
                if k in school[i]:
                    num += 1
        if num == len(item):
            schoolNum[i] += 1

num = []
for i in schoolNum:
    if (schoolNum[i] not in num) and (schoolNum[i] != 0):
        num.append(schoolNum[i])
num.sort(reverse = 1)
ans = ''
for i in num:
    for j in schoolNum:
        if i == schoolNum[j]:
            ans += j + ',' + str(i) + ' '

print(ans.strip())