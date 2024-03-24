# Slicing creates a new object: shallow copy of range within target array
def solution1(some_list):
  list_slice = some_list[3:5] # Shallow copy
  print(f"Same ids of elements after slicing: {id(list_slice[0])}, {id(some_list[3])}")

# A slice of an array can be replaced by references to elements from another slice
def solution2(some_list):
  print(f"Before: {some_list}")
  temp_arr = [-1, -1]
  some_list[2:4] = temp_arr # Assignment
  print(f"After: {some_list}")
  print(f"Same ids of elements after replacing slice: {id(temp_arr[0])}, {id(some_list[2])}")

if __name__ == "__main__":
  print("soln 1")
  solution1([0, 1, 2, 3, 4])
  print("\n")
  print("soln 2")
  solution2([0, 1, 2, 3, 4])
  print("\n")
