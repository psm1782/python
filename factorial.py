   # coding=utf-8
   def fac(x):
       if x <= 1:
           return 1
       else:
           return x * fac(x-1)
   
   x = int(raw_input('계승할 숫자를 입력! :'))
   print x, '의 계승 값은', fac(x), '입니다.'
