# Sort rows

# Sort result set in ascending order
"""
SELECT * FROM Products
ORDER BY Price;
"""

# Sort result in descending order
"""
SELECT * FROM Products
ORDER BY Price DESC;
"""

# Apply multiple sorts, with different directions
"""
SELECT * FROM Customers
ORDER BY Country ASC, CustomerName DESC;
"""

# ORDER BY + GROUP BY: Order summary rows:
"""
SELECT Country, COUNT(City) AS num_cities FROM Customers
GROUP BY Country
ORDER BY COUNT(City) DESC;
"""