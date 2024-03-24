def validate_input(int_list):
  return False if len(int_list) < 2 else True

def calculate_distance(coord_pair):
  dist = ((coord_pair[0][0] - coord_pair[1][0])**2
    + (coord_pair[0][1] - coord_pair[1][1])**2)**0.5
  return dist

def brute_force(coord_list):
  return_pair = (float("inf"), ())
  for i in range(0, len(coord_list)):
    for j in range(i + 1, len(coord_list)):
      coord_pair = (coord_list[i], coord_list[j])
      if calculate_distance(coord_pair) < return_pair[0]:
        return_pair = coord_pair
  return return_pair


def find_min_dist(x_sorted_coords, y_sorted_coords):
  """
  Use divide and conquer method
  0. Sort array seperately by x and y
  1. Recursively sub-divide array to find shortest distance for individual subarrays
  2. Recombine subarrays, finding upper_min_dist = min(L_short_dist, R_short_dist)
     Onced two subarrays are combined, we have an upper bound for the shortest distance for those arrays
     We haven't accounted for distances between nodes in different subarrays, which could be shorter
  2. As we have an upper bound, we know that distances in each subarray require:
     dist(x) < upper_min_dist & dist(y) < upper_min_dist
     to potentially be shorter than current selection
     -> Constraint on x: Form new sorted y list, for pairs within mid_x - upper_min_dist < coord[x] < mid_x + upper_min_dist
     -> Constraint on x & y: visualise allowed rectangle for points after it, 2delta x 1delta
  4. From allowed rectangle, only 8 points can actually exist and be less than min dist
     -> for each coord calc dist with 7 other coords infront (behind coords will be accounted for in prev iterations)
     -> use strip array sorted in y for this part
     update min_dist if found
     
  """
  if len(x_sorted_coords) == 2:
    #Return both min distance and coord pair
    return (calc_distance(x_sorted_coords), (x_sorted_coords[0], x_sorted_coords[1]))
  elif len(x_sorted_coords) == 3:
    #Cannot subdivide further into pairs -> use brute force on these 
    return brute_force(x_sorted_coords)
  mid_index = len(x_sorted_coords)//2
  mid_x = x_sorted_coords[mid_index][0]
  #To maintain sorted y array in each x halves
  y_sorted_left = []
  y_sorted_right = []
  #O(n), would be O(nlogn) if sorted each recursion layer rather than initially
  for coord in y_sorted_coords:
    y_sorted_left.append(coord) if coord[0] < mid_x else y_sorted_right.append(coord)
  #Recursively split left and right according to xs
  L_min_coords = find_min_dist(x_sorted_coords[:mid_index], y_sorted_left)
  R_min_coords = find_min_dist(x_sorted_coords[mid_index:], y_sorted_right)
  min_return_pair = min(L_min_coords[0], R_min_coords[0]) #Upper bound on min dist, (min_dist, coord)
  #Now take points within +- min_dist in x from centre
  strip_y_sorted = [coord for coord in y_sorted if mid_x - coord[0] < min_dist < mid_x + coord[0]]
  for i in range(len(strip_y_sorted)):
    for j in range(i + 1, min(i + 8, len(strip_y_sorted))): #Need indices within range
      coord_pair = (strip_y_sorted[i], strip_y_sorted[j])
      if min_return_pair[0] < (temp_dist := calculate_distance(coord_pair)):
        min_return_pair = (temp_dist, coord_[air])
  return min_return_pair




  return

def solution(coord_list):
  #Sort here for improved efficiency
  x_sorted_coords = sorted(coord_list, key = lambda x: x[0]) #Sort by x value
  y_sorted_coords = sorted(coord_list, key = lambda x: x[1]) #Sort by y value
  return find_min_dist(x_sorted_coords, y_sorted_coords)[1] #Coord pair for min distance

if __name__ == "__main__":
  coord_list = [(3, 7), (6, 2), (13, 15), (1, 4), (16, 5), (2, 33), (25, 2), (5, 3), (7, 2), (10, 11), (15, 35), (11, 12)]
  if validate_input(coord_list):
    solution(coord_list)
  else:
    print("Invalid integer list")