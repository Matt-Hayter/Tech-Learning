"""
Making distinct 2D arrays
"""
n = 4
arr1 = [[0] * 3 for _ in range(n)]

arr1[0].append(4)
print(arr1)

"""
Making duplicated 2D arrays.

- Each change to individual arrays also changes all others
- Uses * operator
"""
arr2 = [[0] * 3]*4

arr2[0].append(4)
print(arr2)


"""
1D arrays of a set size

- Only one array, so * method doesn't duplicate array
"""
arr3 = [0]*4
arr3[0] = 5
print(arr3)