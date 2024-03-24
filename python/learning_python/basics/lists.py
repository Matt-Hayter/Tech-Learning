"""
Python lists are based on dynamic arrays, but with added functionality:
- Mixture of types

Under the hood in C, the list is an array of pointers. As all pointers have the same size, this accounts for the mixture of sizes of types within the list.
"""
class a():
  def __init__(self):
    self.val = 1

print(5 * a())