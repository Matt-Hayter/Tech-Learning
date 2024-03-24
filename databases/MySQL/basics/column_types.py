# Different data types in MySQL

# General format when declaring column types
"""
CREATE TABLE table_name (
      column1_name data type(length),
      column2_name data type(length),
);
"""

# Type overview
"""
- Numeric
- Date and time
- String
- Spatial
- JSON
"""

# String types
"""
- TEXT (TINYTEXT, TEXT, MEDIUMTEXT, LONGTEXT): non-binary long text strings
- BLOB (TINYBLOB, BLOB, MEDIUMBLOB, LONGBLOB): binary strings, which can story binary media data. eg. audio, video, files
- CHAR: non-binary strings of a fixed length, up to 255
- VARCHAR: non-binary strings of variable length, up to 65535
- BINARY: binary string, of fixed size measured in bytes
- VARBINARY: binary string, of variable size measured in bytes
- ENUM: list of pre-defined values that a column can take. eg. ENUM ('small', 'medium', 'large')
- SET: store 0 or any number of pre-defined values. eg. SET ("one", "two", "three") NOT NULL
"""

# Numeric types
"""
INT (TINYINT, SMALLINT, INT, MEDIUMINT, BIGINT): store integer values
BOOL: True/False types. These are actually stored as TINYINT
FLOAT: Single precision number, 4-bytes
DOUBLE: Double precision number, 8-bytes
DECIMAL(p, s): Exact and fixed amounts, with precision p (# digits) and scale (digits after decimal) s
BIT: binary values either 0 or 1. eg. bit(7) could store 0101010. Could eb used for any True/False representations
"""

# Date and Time types
"""
DATE: Stores date in format "YYYY-MM-DD"
TIME: Stores time in format "HH:MM:SS"
DATETIME: Stores date and time in format "YYYY-MM-DD HH:MM:SS"
TIMESTAMP: Stores date and time converted in UTC ?, format "YYYY-MM-DD HH:MM:SS"
YEAR: Stores year values in format "YYYY"

Difference between Dates/Time: DATEDIFF(<to>, <from>)
"""

# Additional type specifiers
"""
CREATE TABLE <table> (
      product_ID INT UNSIGNED AUTO_INCREMENT, # Unsigned int that's incremented upon new row entry
      product_item VARCHAR(255) NOT NULL # Can't be null
      product_value FLOAT 
);
"""

# Change data type
"""
ALTER TABLE <table_name>
MODIFY COLUMN <column_name> <newdatatype>;
"""


