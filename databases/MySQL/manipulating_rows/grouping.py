# Create summary rows by grouping

# GROUP BY: group rows into summary rows
"""
SELECT <column_name(s)> FROM <table_name> WHERE <condition>
GROUP BY <column_name(s)>
"""

# GROUP BY. Often used alongside aggregate functions
"""
SELECT COUNT(CustomerID), Country FROM Customers
GROUP BY Country;
"""

# GROUP BY - Multiple same value for mulitple columns
"""
SELECT Country, City, COUNT(CustomerID) FROM Customers
GROUP BY Country, City;
"""

# HAVING: Apply conditions on groups (groups that don't satisfy will be avoided)
"""
SELECT email FROM Person 
GROUP BY email HAVING COUNT(email) > 1
"""