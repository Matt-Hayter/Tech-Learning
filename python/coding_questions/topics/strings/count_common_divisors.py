"""
Count number of common divisors between substrings
"""

def solution(a, b):
  count = 0
  for i in range(1, min(len(a), len(b)) + 1):
      if a[:i] != b[:i]: # If prefixes match
        break
      if a[:i] * (len(a)//i) == a and b[:i] * (len(b)//i) == b: # If both strings are divisible by prefix
        count += 1
  return count


if __name__ == "__main__":
  print(solution("xaxa", "xaxaxaxa")) #2
  print(solution("xabxa", "xaxaxaxa")) #0
  print(solution("xaxaxaxa", "xaxaxaxaxaxaxaxa")) #3
  print(solution("xaxaxa", "xbxbxb")) #0