"""
CPython memory allocation/deallocation is automatic and done by the interpretor
"""

"""
CPython Memory allocation

- All objects are stored in heap memory (in a private heap)
- For each function call, references are stored on the stack
- Hence: recursion calls are expensive as they require more stack memory (block allocated for each call) and an overhead of function calls
"""

"""
CPython Memory deallocation

- Python has a garbage collector, which deallocates memory based on reference counts
- When a reference is deleted, the object's reference count is decremented
- If an object's reference count reaches 0, the object is removed from memory
"""
