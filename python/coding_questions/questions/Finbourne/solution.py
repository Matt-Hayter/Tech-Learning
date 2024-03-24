"""
Rearrange array into k arrays in which the max-min of each array in minimised.
"""

# Example:
# [1, 2, 3, 4, 22, 25, 28, 100, 100, 105, 106, 110, 115]
# -> rearrange [115, 100, 2, 25, 1, 3, 22, 105, 100, 4, 106, 28, 110]
# Ans = max(3, 6, 15) -> 15


def solution(arr, k):
  # Want to separate on max differences between adjacent items
  # k arrays -> k-1 separations
  if len(arr) <= k: return 0
  arr.sort()
  differences = sorted([(arr[i+1]-arr[i], i) for i in range(0, len(arr)-1)])
  border_indices = sorted([border_index for _, border_index in differences[-(k-1):]])
  curr_max_diff = arr[border_indices[0]] - arr[0]
  for i in range(1, len(border_indices)-1):
    curr_max_diff = max(arr[border_indices[i]+1] - arr[border_indices[i-1]+1], curr_max_diff)
  curr_max_diff = max(curr_max_diff, arr[-1] - arr[border_indices[-1]+1])
  return curr_max_diff
    


if __name__ == "__main__":
  print(solution([115, 100, 2, 25, 1, 3, 22, 105, 100, 4, 106, 28, 110], 3)) #15