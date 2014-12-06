 # encoding=utf-8
  2 class SchoolMember():
  3     def __init__(self, name, age):
  4         self.name = name
  5         self.age = age
  6     def Print(self):
  7         print '이름: "{0}", 나이: "{1}"'.format(self.name, self.age),
  8 
  9 class Student(SchoolMember):
 10     def __init__(self, name, age, Marks):
 11         SchoolMember.__init__(self, name, age)
 12         self.Marks = Marks
 13         print '(학생을 초기화합니다.: {})'.format(self.name)
 14     def Print(self):
 15         SchoolMember.Print(self)
 16         print '점수: "{}"'.format(self.Marks)
 17 
 18 class Teacher(SchoolMember):
 19     def __init__(self, name, age,  salary):
 20         SchoolMember.__init__(self, name, age)
 21         self.salary = salary
 22         print '(선생님을 초기화합니다.: {})'.format(self.name)
 23     def Print(self):
 24         SchoolMember.Print(self)
 25         print '급여: "{}"'.format(self.salary)
 26 
 27 sexy = Student('김학생', 18, 75)
 28 unsexy = Teacher('김선생', 47, 2600)
 29 sexy.Print()
 30 unsexy.Print()
