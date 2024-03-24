import collections

"""
"Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing"
"""

class solution():

  def solution_func_2(self, s):
    return_dict = {}
    open_queue = collections.deque([])
    for i, char in enumerate(s):
      if char == "(":
        open_queue.append(i)
      elif char == ")":
        return_dict[open_queue.pop()] = i
    
    return return_dict


  def solution_func_1(self, s):
    depth = 0
    max_depth = 0
    for char in s:
      if char == "(":
        depth += 1
        max_depth = max(max_depth, depth)
      elif char == ")":
        depth -= 1

    return max_depth

    

if __name__ == "__main__":
  interview_solution = solution()
  print(interview_solution.solution_func_1("Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing"))
  print(interview_solution.solution_func_2("Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing"))