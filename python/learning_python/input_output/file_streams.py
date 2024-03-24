"""
File stream = Sequence of data elements stored in, or taken from, a file (on disk). Python file stream = File object.

Input stream = sequence of data elements being parsed into program
Output stream = sequence of data elements being outputted from program

Data elements can be inserted or removed from the stream
"""

"""
Input File Streams
r:
 - No truncation
 - Throws error if file doens't exist
 - File pointer at beggining of file
"""
def input_file_streams():
  #File stream object created using open()
  with open("demofile.txt", "r") as f: #Open input file stream
    print(f.name()) #Name of file
    f.seek(20) #Jump to the 20th position in the file stream (skip 19 characters)
    f.tell() #Prints current pointer position
    parsed_list = f.readlines() #Option A v1. Parse entire file stream into a list, by elements seperated by new space characters (\n)
    for line in f: #Option A v2. Parse each line
      print(f)
    parsed_line = f.readline() #Option B. Parse one line from file stream into program.
    parsed_string = f.read() #Option C. Parse entire file stream into a string
    parsed_byte = f.read(1) #Option D. Parse a single byte (1 ASCII character or part of a unicode character)
input_file_streams()

"""
Output File Streams
w:
  - Creates new file if doesn't exit, truncates existing file
  - File pointer at beggining of file
a:
  - Creates new file if it doesn't exist
  - File pointer at end of file
  - seek() operation doesn't work
"""
def writing_file_stream():
  f = open("demofile.txt", "w") #Open output file stream. Truncates if exists, creates file if not already present
  f.write('Hello world!\n') #Add to file stream
  f.truncate() #Delete delete file data
  f.close() #Close output file stream
def appending_file_stream():
  f = open("demofile.txt", "a") #Open output file stream. Create file if not already present
  f.write('Hello world!\n') #Add to file stream
  f.close() #Close output file stream


"""
Input/Output File Stream
+:
  - Adds addidtional read/write functionality to current functionality
  - eg. r+ follows r rules, w+ follows w rules, a+ follows a rules
"""
def input_output_streams():
  with open("demofile.txt", "r+") as f: #Open input/output file stream (for reading and writing). Creates file if not already present
    f.read() #Parse whole io stream
    f.seek(0) #Move cursor to begging of stream
    f.write('Hello world!\n') #Insert text to beginning of stream
    f.read() #Read again

"""
Byte streams

Useful for efficeint parsing of binary data, eg. images, audio files, any non-text data.
b:
  - Additional specifier for consuming/outputting binary data (Bytes type)
  - eg. rb, wb, ab, ab+
"""
def input_output_binary():
  with open("demofile.bin", "rb") as binary_file:
    data = file.read()
  print(data) # Outputs b'binary file content'



