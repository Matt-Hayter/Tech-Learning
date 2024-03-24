"""
Inheritance with no constructor function for child -> uses parent
"""

class Person:

  def __init__(self, fname, lname):
    self.firstname = fname
    self.lastname = lname

  def printname(self):
    print(self.firstname, self.lastname)

class Student(Person):
  pass

x = Student("Mike", "Olsen")
x.printname()

"""
Inheritance with constructor function for parent and child
"""

class Person:

  def __init__(self, fname, lname):
    self.firstname = fname
    self.lastname = lname

  def printname(self):
    print(self.firstname, self.lastname)

class Student(Person):

  def __init__(self, fname, lname, year):
    Person.__init__(self, fname, lname) #REQUIRED IF CHILD INIT DEFINED
    #could also use: super().__init__(fname, lname)
    self.graduation_year = year

x = Student("Mike", "Olsen", 2022)
x.printname()

"""
Function overriding and multiple inheritance
"""
class Person():
  
  def __init__(self, name):
    self.name: int = name

  def print_name(self):
    print(self.name)

class Proffessional():
  
  def __init__(self, salary):
    self.salary = salary

  def print_salary(self):
    print(self.salary)

class Teacher(Person, Proffessional): # Multiple inheritance

  def __init__(self, name, salary):
    Person.__init__(self, name) #Need to feed to each parent constructor separately
    Proffessional.__init__(self, salary)

  def do_work(self):
    print(f"{self.name} is doing work in the teacher way")

class Student(Person):

  def do_work(self): # Overriding (polymorphism)
    print(f"{self.name} is doing work in the student way")

some_student = Student("Matt")
some_student.print_name()
some_student.do_work()
some_teacher = Teacher("Tracey", 50_000)
some_teacher.print_name()
some_teacher.print_salary()
some_teacher.do_work()