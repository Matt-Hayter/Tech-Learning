"""
Default parameters and alt. printing syntax
"""

# Using =... creates a default variable if the argument is not given in function call
# It is defined only once (at function definition) -> multiple non defined calls use the same global param
# This is true because variables are references in python, so once object is created, it is referenced from then on within the function.

"""
Global func example
"""

def extendList(val, some_list=[]):
    some_list.append(val)
    return some_list

list1 = extendList(10) #list 1 = [10]
list2 = extendList(123,[]) #list2 = [123]
list3 = extendList('a') #list3 = [10, "a"], list1 = [10, "a"]

print("Function level:")
print("list1 = %s" % list1)
print("list2 = %s" % list2)
print("list3 = %s\n" % list3)

"""
Class func example
"""

class ListExtender():

    def extend_list(self, val, some_list=[]):
        some_list.append(val)
        return some_list

list_extender = ListExtender()
list1 = list_extender.extend_list(10)
list2 = list_extender.extend_list(123, [])
list3 = list_extender.extend_list("a")

print("Class level:")
print("list1 = %s" % list1)
print("list2 = %s" % list2)
print("list3 = %s" % list3)