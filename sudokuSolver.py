def ispossible(number,row,col,ip):
    #vertcial
    for i in range(9):
        if ip[i][col]==number:
            return  False
        i+=1
    #hori
    for  i in range(9):
        if ip[row][i]==number:
            return False
        i+=1
    #box
    startcol= col-col%3
    startrow=row-row%3
    for i in range(startrow,startrow+3):
        for j in range(startcol,startcol+3):
            if ip[i][j]==number:
                return  False
    return True

def solv(ip):
    row=-1
    col=-1
    flag=False
    for  i in range(9):
        for j in range(9):
            if ip[i][j]==0:
                flag=True
                col=j
                row=i
                break
        if flag is True:
            break
    if row ==-1:
       # print(ip)
        return True
    for number in range(1,10):
        if ispossible(number,row,col,ip):
            ip[row][col]=number
            if solv(ip) is True:
                return True
            ip[row][col]=0
    return False


ip=[]
for i in range(9):
    temp=[int(x) for x in input().split()]
    ip.append(temp)
ans=solv(ip)
if ans is True:
    print('true')
else:
    print('false')
