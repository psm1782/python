   # coding=utf-8
   def fac(x):
       if x <= 1:
           return 1
       else:
           return x * fac(x-1)
   
   x = int(raw_input('����� ���ڸ� �Է�! :'))
   print x, '�� ��� ����', fac(x), '�Դϴ�.'
