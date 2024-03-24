# Grabbing data from database

# Get all rows from table
"""
SELECT * FROM <table>;
"""

# Get specific column data from table, for rows where condition is matched
"""
SELECT <column1>, <column2> FROM <table> WHERE <column> = <value>;
"""

# AS keyword -> alias for table/column to improve readability on returned set
"""
SELECT MIN(Price) AS SmallestPrice FROM Products;
"""

#As keyword for multiple columns
"""
SELECT COUNT(CustomerName) AS num_names, Country AS listed_country FROM Customers
GROUP BY Country;
"""

# Check if rows exist, return boolean
"""
SELECT EXISTS(SELECT * FROM <table> WHERE <column> = <value> LIMIT 1)
"""

# Select number/which rows to return, as returning lots of unwanted rows is inefficient.
# LIMIT: number of records to return
# Getting top 3 items
"""
SELECT * FROM Customers LIMIT 3;
"""

# Select top 3 results where Country='Germany'
"""
SELECT * FROM Customers WHERE Country='Germany' LIMIT 3;
"""

# Select top 3 after sorting result
"""
SELECT * FROM Customers
ORDER BY CustomerName DESC
LIMIT 3;
"""