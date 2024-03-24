"""
- Variables

  Variables are names that are binded to a memory addresses.
  At this memory address there is a value of a certain type and quantity.
  
  In most static/other languages, declaring a variable creates a name and a memory location. The value at this address can be defined at a later point. 
  Python works slightly differently - initialising a variable is only creating a reference variable to an existing object.

  In python:
    1. All variables are references to an object (reference variables). Objects have their own internal "actual" name (id(variable), usually just memory location).
       This object must be created before/at same time as reference variable (can't declare variable (create name and allocate memory) without initialising (creating object)), as otherwise there is no value to reference.
    2. Each object also contains a pointer to its type (this is why we can use type()), and many contain len methods etc.

- References

  A reference is just an alias (another name/binding) to an existing value/object. This binding can be considered a "constant pointer", with automatic indirection (de-referencing)
  All python variables are references (don't have pointer variables and variables don't create their own space in memory)

- Pointers

  A pointer is a variable that stores the address of another variable as its value.
  So the pointer has a name, which is binded to its memory location, then at its memory location there is its value, which is another memory location.

  In Python:
    1. We don't have explicit pointers
    2. Pointers are used under the hood, eg. elements in lists are pointers to objects, which are actually inplemented in C.

note: sometimes references are described as pointing to their values
"""