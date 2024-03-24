
def solution(arr):
  # Sub problems: Longest increasing sub sequence of previous items in chain
  longest_subsequence = [1]*len(arr)
  for i in range(len(arr)):
    for j in range(0, i):
      if arr[j] < arr[i]:
        longest_subsequence[i] = max(longest_subsequence[i], longest_subsequence[j] + 1)
  return max(longest_subsequence)

if __name__ == "__main__":
  print("1. correct") if solution([3, 1, 8, 2, 5]) == 3 else print("1. incorrect")
  print("2. correct") if solution([5, 2, 8, 6, 3, 6, 9, 5]) == 4 else print("2. incorrect")