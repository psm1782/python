 # coding=utf-8
  
 ilist = list(raw_input('���ڸ� �Է��ϼ���.(������ �޸���):'))
 n = list(range(len(ilist)))
 for i in n:
      if ilist[i] == ',':
          del ilist[i]
          del n[len(ilist)]
          i-=1
 ituple = tuple(ilist)
 print ilist
print ituple
