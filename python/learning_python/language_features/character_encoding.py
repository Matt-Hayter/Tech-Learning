"""
Character Encoding
- Character Encoding = Trasforming human language characters -> format required for processing (eg. machine code) or transfer
- ASCII is the standardised encoding for text. Each character given a code point (integer value) and a unique byte (8 bits) (eg. 00100101)
- 256 ways of arranging 8 bits -> 256 unique bytes/characters
- Unicode is a more advanced system of mapping code point to binary (eg. U+0041 (Hexidecimal) -> 0010101...)
- UTF-8 is an encoding system for unicode. It converts unicode code points to machine code, which is 1-4 bytes.
- More common characters -> 1 byte. Less common -> multiple bytes (purely to save memory in strings)
"""
string = "some string"
utf8_encoded_string = string.encode("utf-8") # String -> code point -> machine code
print(utf8_encoded_string) # Number of bytes in encoded string

# Iterate through alphabet
for i in range(0, 26):
  print(chr(i+97))
