import math

def find_gcd(arr):
  if len(arr) == 2:
    return math.gcd(arr[0], arr[1])

  curr_gcd = find_gcd(arr[1:]) #Recursion
  return math.gcd(arr[0], curr_gcd)



def solution(arr):
  if len(arr) < 2:
    raise ValueError
  gcd = find_gcd(arr)


if __name__ == "__main__":
  print(solution([2, 6, 6, 8, 4, 12, 18, 36]))