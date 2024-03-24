"""
1. If s is divisible by t
2. If yes, find the smallest common divisor and return it's length, otherwise return -1
"""

def solution(s, t):
  """
  If s is divisible by t, smallest divisor of t will also be that of s
  -> find smallest divisor of t
  """
  #Check if s isn't divisible by t:
  if t * (len(s)//len(t)) != s:
    return -1

  #Now find smallest divisor of t:
  for i in range(1, len(t) + 1):
    if t[:i] * (len(t)//i) == t:
      return i

if __name__ == "__main__":
  print(solution("ABCABCABC", "ABC")) #3
  print(solution("ABCABCABC", "ABCABC")) #-1
  print(solution("LEET", "CODE")) #-1
  print(solution("ABCDABCDABCDABCD", "ABC")) #-1
  print(solution("ABCDABCDABCDABCD", "ABCD")) #4
  print(solution("ABABABABABAB", "ABAB")) #2