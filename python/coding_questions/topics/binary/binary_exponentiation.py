"""
Aim: Convert from O(power) or exponentials to O(logn), using binary exponentiation
(2^1)^2 = 2^2
(2^2)^2 = 2^4
(2^4)^2 = 2^8
-> Multiplying these squares, rather that 2s individually, saves operation
   time when calculating exponents. These power of twos can be translated into
   binary

powers of two for base 2 in binary:
Binary: [1, 1, 1, 1, 1, 1, 1, 1, 1]
Powers of two to convert into base 10: 876543210
"""

def solution(num, exponent):
  """
  Simple solution by converting to binary
  Re-implement!
  """
  res = 0
  num_tracker = 1
  bin_expon = str(bin(exponent))[2:]
  for i in range(len(bin_expon)-1, -1, -1):
    if bin_expon[i] == "1":  
      res += num * num_tracker
    num_tracker *= 2
  
  return res
  

if __name__ == "__main__":
  print(solution(3, 16))