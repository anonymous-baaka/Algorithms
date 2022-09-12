def doit(s,pre):
    if len(s)==0:
        print(pre)
    for i in range(len(s)):
        doit(s[:i]+s[i+1:],pre+s[i])

s='abcd'
doit(s,'')
