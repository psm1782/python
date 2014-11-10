 # coding=utf-8
  
 ilist = list(raw_input('숫자를 입력하세요.(구분은 콤마로):'))
 n = list(range(len(ilist)))
 for i in n:
      if ilist[i] == ',':
          del ilist[i]
          del n[len(ilist)]
          i-=1
 ituple = tuple(ilist)
 print ilist
print ituple
