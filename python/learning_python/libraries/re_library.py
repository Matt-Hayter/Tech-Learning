import re

s2 = "dogdog32323dof3223dogdog" #4

def matching():
  match1 = re.search("dog", s2) #If found, returns a match object
  if match1: #Evaluates to True if match found
    print(match1.start()) #Start index
    print(match1.end()) #End index

  match2 = re.search("abcd", s2) #Returns None if not found
  if match2:
    print("Problem")

def non_overlapping_occurances():
  match = re.findall("dog", s2)
  print(len(match)) #Number of non-overlapping occurances



matching()
non_overlapping_occurances()