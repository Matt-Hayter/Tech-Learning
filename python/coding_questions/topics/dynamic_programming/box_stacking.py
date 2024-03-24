def solution(boxes):
  # Sub problems: smaller boxes being set as the base
  # Top boxes need the same or larger widths and heights
  boxes.sort(key = lambda x: x[0]) # Sort widths, can be widths or heights
  max_heights = [box[2] for box in boxes] # Array of box heights
  # Now from smallest widths to largest
  for i in range(len(boxes)):
    for j in range(0, i):
      if boxes[j][1] < boxes[i][1]:
        max_heights[i] = max(max_heights[i], max_heights[j] + boxes[i][2])
  return max(max_heights)

if __name__ == "__main__":
  print("1. correct") if solution([(1, 5, 4), (1, 2, 2), (2, 3, 2), (2, 4, 1), (3, 6, 2), (4, 5, 3)]) == 8 else print("1. incorrect")
