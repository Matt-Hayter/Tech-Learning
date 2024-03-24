# All variables passed by assignment (object reference, param = existing_object) in python
# Reassignment of parameter drops prev. reference, creating reference to new object

# Mutable variables: can alter original object without reassignment
def solution1(some_list):
  if some_list[-1] < 10:
    some_list.append(some_list[-1]+1)
    solution1(some_list)
  return some_list

# Immutable variables: can't alter original object -> require reassignment
def solution2(some_string):
  if some_string <= 10:
    some_string += 1
    solution2(some_string)
  return some_string

if __name__ == "__main__":
  print(solution1([0, 1]))
  print(solution2(2))