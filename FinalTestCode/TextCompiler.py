s, com = map(int, input().split())
sentence = []
command = []
for i in range(s):
    sentence.append(input().split())
for i in range(com):
    command.append(input().split())

count = 0
for i in command:
    if i[0] == 'ADD_W_FRONT':
        sentence[int(i[1])-1].insert(int(i[2])-1, i[3])
    elif i[0] == 'ADD_W_AFTER':
        sentence[int(i[1])-1].insert(int(i[2]), i[3])
    elif i[0] == 'ADD_S_FRONT':
        for j in range(len(i)-1, 1, -1):
            sentence[int(i[1])-1].insert(0, i[j])
    elif i[0] == 'ADD_S_AFTER':
        for j in range(2, len(i)):
            sentence[int(i[1])-1].append(i[j])
    elif i[0] == 'INSERT_FRONT':
        for j in sentence:
            k = 0 
            if i[1] in j: 
                while 1:
                    if k >= len(j):
                        break
                    elif j[k] == i[1]:
                        j.insert(k, i[2])
                        k += 2
                    else:
                        k += 1
    elif i[0] == 'INSERT_AFTER':
        for j in sentence:
            k = 0 
            if i[1] in j:
                while 1:
                    if k >= len(j):
                        break
                    elif j[k] == i[1]:
                        j.insert(k+1, i[2])
                        k += 2
                    else:
                        k += 1
    elif i[0] == 'DEL_W':
        sentence[int(i[1])-1].pop(int(i[2])-1)
    elif i[0] == 'DEL_L':
        sentence.pop(int(i[1])-1)
    elif i[0] == 'REPLACE':
        for j in range(len(sentence)):
            for k in range(len(sentence[j])):
                if sentence[j][k] == i[1]:
                    sentence[j][k] = i[2]
    elif i[0] == 'COUNT':
        for j in sentence:
            count += len(j)
    elif i[0] == 'COPY_L':
        copy = sentence[int(i[1])-1]
        copying = ' '.join(copy)
    elif i[0] == 'COPY':
        copying = sentence[int(i[1])-1][int(i[2])-1]
    elif i[0] == 'PASTE_FRONT':
        copy = copying.split(' ')
        if len(copy) == 1:
            sentence[int(i[1])-1].insert(int(i[2])-1, ''.join(copy))
        else:
            k = 0
            for j in copy:
                sentence[int(i[1])-1].insert(int(i[2])-1+k, j)
                k += 1
    elif i[0] == 'PASTE_AFTER':
        copy = copying.split(' ')
        if len(copy) == 1:
            sentence[int(i[1])-1].insert(int(i[2]), ''.join(copy))
        else:
            k = 0
            for j in copy:
                sentence[int(i[1])-1].insert(int(i[2])+k, j)
                k += 1

if count != 0:
    print(count)
for i in sentence:
    print(' '.join(i))