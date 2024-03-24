"""
Dunder method = double underscore method = special methods assigned to class instances
eg. __init__, __name__, __repr__ (string rep of object)

Dunder methods are also used for operator overloading
"""

class Person():

  def __init__(self): # Called just after constructor
    pass

  def __repr__(self):
    return "String representation of Person"

if __name__ == "__main__": # Interpreter sets __name__ variable to __main__ for file being run. For imports, its the name of the import.
  some_person = Person()
  # Investigate __repr__
  some_person.__repr__() # Calls method
  print(some_person) # Prints return value of method