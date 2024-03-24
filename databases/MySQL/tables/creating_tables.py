# Creating and structuring systems of tables

# Create simple table, with given column names and types
# Primary key set after other columns in MySQL
# MySQl automatically adds UNIQUE NOT NULL to primary keys
"""
CREATE TABLE members (
    member_id INT AUTO_INCREMENT,
    name VARCHAR(255),
    PRIMARY KEY (member_id)
);
"""

# Primary key made up of multiple columns
"""
CREATE TABLE members (
    id INT
    building_name VARCHAR(255)
    name VARCHAR(255),
    CONSTRAINT person PRIMARY KEY (id, building_name)
);
"""

# Create a table only if table name doesn't already exist
"""
CREATE TABLE IF NOT EXISTS members (
    name VARCHAR(255),
    PRIMARY KEY (name),
);
"""

# Create table from another table
"""
CREATE TABLE <table_name> AS
  SELECT <column1>, <column2>
  FROM <existing_table_name>
  WHERE <column> = <value>
"""

# Create table with default column values
"""
CREATE TABLE t1 (
  i INT DEFAULT -1,
  c VARCHAR(10) DEFAULT '',
  price DOUBLE(16,2) DEFAULT 0.00
);
"""

# Parent and child tables:
"""
# Parent holds PRIMARY KEY
CREATE TABLE <parent_table_name> (
  id INT AUTO_INCREMENT,
  prop2 VARCHAR(255) NOT NULL,
  PRIMARY KEY (prop1),
);
"""
# Child holds FOREIGN KEY, refering to PRIMARY KEY of parent
# FOREIGN KEY contarint prevents changes that would destroy links between parent and childs tables
"""
CREATE TABLE <child_table_name> (
  id INT AUTO_INCREMENT,
  owner_id INT NOT NULL ,
  propb DECIMAL(5, 2) UNIQUE NOT NULL,
  PRIMARY KEY (propa),
  FOREIGN KEY (owner_id) REFERENCES parent_table_name(id)
)
"""