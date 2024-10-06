"""
Find 
"""

import time

def binary_search(l, r, threshold, points):
  mid = (r+l)//2
  # [1, 2] -> 1 or 1
  # [2] -> res or fail
  if l < r:
    if points[mid] >= threshold:
      r = mid
    else:
      l = mid + 1
    return binary_search(l, r, threshold, points)
  else:
    if points[mid] >= threshold: # Reached search end point and success
      return mid
    else:
      return -1 # Reached search end point and no success


#More efficient solution, O(nlogn)
def soln1(required_diff, points):
  index = binary_search(0, len(points)-1, required_diff + points[0], points)
  if index == -1:
    return sum(points)
  if index % 2 != 0:
    return (index + 1)/2 + 1
  else:
    return (index)/2 + 1

#Easy solution O(n^2)
def soln2(threshold, points):
  i = 0
  while i < len(points):
    if points[i] - points[0] >= threshold:
      break
    i += 1
  if i == len(points):
    return sum(points)
  
  if i % 2 != 0:
    return (i + 1)/2 + 1
  else:
    return i/2 + 1
  
if __name__ == "__main__":
  print("solution 2:")
  print("1. correct\n") if soln2(228, [12, 64, 65, 100, 100, 100, 170, 210, 230, 245, 260, 340, 400, 401, 500]) == 6 else [print("1. incorrect\n")]
  print("2. correct\n") if soln2(4, [1, 2, 3, 4, 5, 6, 7, 8, 9]) == 3 else [print("2. incorrect\n")]
  print("3. correct\n") if soln2(228, [12, 64, 65, 100, 100, 100, 170, 210, 230, 240, 240, 240, 245, 260, 340, 400, 401, 500]) == 6 else [print("3. incorrect\n")]
  print("4. correct\n") if soln2(0, [12, 64, 65, 100, 100, 100, 170, 210, 230, 240, 240, 240, 245, 260, 340, 400, 401, 500]) == 1 else [print("4. incorrect\n")]
  print("5. correct\n") if soln2(87, [12, 64, 65, 100, 100, 100, 170, 210, 230, 240, 240, 240, 245, 260, 340, 400, 401, 500]) == 3 else [print("5. incorrect\n")]
  print("6. correct\n") if soln2(60, [12, 55]) == 67 else [print("6. incorrect\n")]

  print("solution 1:")
  print("1. correct\n") if soln1(228, [12, 64, 65, 100, 100, 100, 170, 210, 230, 245, 260, 340, 400, 401, 500]) == 6 else [print("1. incorrect\n")]
  print("2. correct\n") if soln1(4, [1, 2, 3, 4, 5, 6, 7, 8, 9]) == 3 else [print("2. incorrect\n")]
  print("3. correct\n") if soln1(228, [12, 64, 65, 100, 100, 100, 170, 210, 230, 240, 240, 240, 245, 260, 340, 400, 401, 500]) == 6 else [print("3. incorrect\n")]
  print("4. correct\n") if soln1(0, [12, 64, 65, 100, 100, 100, 170, 210, 230, 240, 240, 240, 245, 260, 340, 400, 401, 500]) == 1 else [print("4. incorrect\n")]
  print("5. correct\n") if soln1(87, [12, 64, 65, 100, 100, 100, 170, 210, 230, 240, 240, 240, 245, 260, 340, 400, 401, 500]) == 3 else [print("5. incorrect\n")]
  print("6. correct\n") if soln1(60, [12, 55]) == 67 else [print("6. incorrect\n")]




