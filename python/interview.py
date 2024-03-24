from collections import Counter

if __name__ == "__main__":
  freq_dist = Counter([1, 1, 2, 2, 3, 4, 5, 5])
  print(sum(freq_dist.elements()))