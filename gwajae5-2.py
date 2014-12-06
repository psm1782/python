  1 #encoding=utf-8
  2 class DividenumberErr(Exception):
  3     """ A user-defined divide exception class."""
  4     def __init__(self):
  5         Exception.__init__(self)
  6 
  7 try:
  8     nume = int(raw_input('Enter the numerator.: '))
  9     denom = int(raw_input('Enter the denominator: '))
 10     if denom == 0:
 11         raise DividenumberErr()
 12     # if denom is 0, raise the error and exit the program
 13 except DividenumberErr as Di:
 14     print 'You must enter the value, that isn\'t equal to zero.'
 15 else:
 16     print 'result value is!: ', nume/denom
 17 
 18 
