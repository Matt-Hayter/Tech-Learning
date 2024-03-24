"""
Iteratively remove k+ consecutive characters from string

Use stack, storing (char, count)
"""
from collections import deque

def removeDuplicates(s: str, k: int) -> str:
  tracker = deque()

  for char in s:
    if not tracker:
      tracker.append((char, 1))
    elif char != tracker[-1][0]: # If adjacent chars do not match, perform checks
      if tracker[-1][1] >= k: # Check for 3+ duplicates
        for i in range(tracker[-1][1]):
          tracker.pop()
        # If empty or no match after removal
      if not tracker or tracker[-1][0] != char: 
          tracker.append((char, 1))
      else: # Match after removals
        tracker.append((char, tracker[-1][1]+1))
    else: # If duplicate
        tracker.append((char, tracker[-1][1]+1)) # Add one to count

  # Final check for 3+ duplicates  
  if tracker[-1][1] >= k:
    for i in range(tracker[-1][1]):
      tracker.pop()

  return "".join(char for char, count in tracker)

if __name__ == "__main__":
  print(removeDuplicates("aceeeed", 3)) # acd
  print(removeDuplicates("aaaccddeeedzzzzzzzz", 3)) # cc