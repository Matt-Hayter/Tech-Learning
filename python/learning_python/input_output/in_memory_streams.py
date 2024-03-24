"""
Memory stream = sequence of data elements stored in memory (RAM)

One advantage of a MemoryStream is that there is not need to create temporary
buffers and files in an application.

Input stream = sequence of data elements being parsed into program
Output stream = sequence of data elements being outputted from program

For all stream types, data elements can be inserted or removed from the stream

StringIO and BytesIO are useful for mimicking files in RAM
"""

import io #For io streams
import requests

"""
StringIO
- IO stream for storing string data in RAM
- Can behave like a file stream
"""
string ='This is initial string.'
sstream = io.StringIO(string) #Initialise sstream with string - cursor will remain at position 0 of stream
sstream.write(" Welcome to geeksforgeeks.") #Add to stream
sstream.seek(0) #Position back to start of stream
print('The string after writing is:', sstream.read())

"""
BytesIO
- IO stream for storing binary data in RAM
- Behaves like a file stream
- Binary data is useful for things like files, images etc.
"""
r = requests.get("https://images.unsplash.com/photo-1452857576997-f0f12cd77844?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=2850&q=80")
with io.BytesIO() as buf:
    buf.write(r.content)
    buf.seek(0)
    buf.read()