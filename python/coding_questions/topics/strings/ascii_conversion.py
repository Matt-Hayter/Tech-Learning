"""
Convert reversed string of ASCII values (code points) to characters
String can have:
  A-Z: 65 - 90
  a-z: 97 - 122
  spapce: 32

"""

def solution(string: str):
  res = ""
  string = string[::-1] 
  i = 0
  while i < len(string):
    if 65 <= (segment := int(string[i:i+2])) <= 99 or segment == 32:
      res += chr(segment)
      i += 2
    else:
      res += chr(int(string[i:i+3]))
      i += 3
  
  return res

if __name__ == "__main__":
  print(solution("796115110113721110141108"))