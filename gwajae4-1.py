 1 class InputOutString():
  2     def __init__(self):
  3         self.s = ''
  4     def getString(self):
  5         self.s = raw_input('Enter the string: ')
  6     def printString(self):
  7         print self.s.upper()
  8 
  9 sexy = InputOutString()
 10 sexy.getString()
 11 sexy.printString()
