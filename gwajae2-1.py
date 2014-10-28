  1 # coding=utf-8
  2 for i in range(2000,3200):
  3     if i % 7 == 0:
  4         if i % 5 == 0:
  5             continue
  6         else:
  7             print '7로 나누어지고 5로 나누어지지 않는 수:', i
  8 
  9 print '끝.'
                       