"""
Assignment: Creates new reference variable to existing object
Shallow copy: Creates new variable and new object, then populates it with references of the old objects (top-level copy).
              Only changes to existing objects, below the top level, are shared between variables.
Deep copy: Makes the copying process recursive - creates a new variable and object, then recursively
           populates it with copies of the old object's child components. Unlinked from prior object.
"""

"""
Assignment
For immutable objects, assignment creates new object, and reference to this object.
For mutable, assignment creates reference to original object.
"""
def assignment():
  print("Assignment:")
  int1 = 6
  int2 = int1
  int2 += 1
  print("Integer 1 =", int1, "Integer 2 =", int2)
  #Can't change a tuple's value
  tuple1 = (6, 7)
  tuple2 = tuple1
  print("Tuple 1 =", tuple1, "Tuple 2 =", tuple2, "- Kind of pointless")
  str1 = "abc"
  str2 = str1
  str2 += "z"
  print("String 1: {string1}, String 2: {string2}".format(string1 = str1, string2 = str2))
  #Mutable objects
  dict1 = {0: "a", 1: "b"}
  dict2 = dict1
  dict2[0] += "zzzz"
  output_string = "Dict 1: {}, Dict 2: {}".format(dict1, dict2)
  print(output_string)
assignment()

"""
Shallow Copy
"""
def shallow_copy():
  print("\nShallow copy:")
  arr1 = [[1, 2, 3], 10, [1, 2, 3], [1, 2, 3]]
  arr2 = arr1.copy()
  print("arr1[1] the same object as arr2[1]?") # Even immutable elements have references
  print(id(arr1[1]) == id(arr2[1])) # id() is the actual name binded to python objects, which other variables reference
  print("Original nested objects are updated by nested reference within new object")
  arr1[0][0] = "new"
  print(f"arr1: {arr1}, arr2: {arr2}")
  print("Popped new array reference, doesn't effect old array")
  arr2.pop()
  print(f"arr1: {arr1}, arr2: {arr2}")
  print("Added to new array, doesn't effect old array")
  arr2.append(["new", "array"])
  print(f"arr1: {arr1}, arr2: {arr2}")
  print("Original nested objects are still updated by nested reference within new object")
  arr2[0].append("new")
  print(f"arr1: {arr1}, arr2: {arr2}")
shallow_copy()

"""
Deep copy
"""
import copy
def deep_copy():
  print("\ndeep copy:")
  #Mutable objects
  dict1 = {0: "a", 1: "b"}
  dict2 = copy.deepcopy(dict1)
  dict2[0] += "zzzz"
  output_string = "Dict 1: {}, Dict 2: {}".format(dict1, dict2)
  print(output_string)
deep_copy()