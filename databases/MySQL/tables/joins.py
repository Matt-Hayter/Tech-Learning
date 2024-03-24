# Joins are used to query and access/join data from multiple tables,
# based on relationships between the tables.

# INNER JOIN
# Creates new table with all columns from both tables, only with rows that are linked.
"""
SELECT * FROM <child_table> INNER JOIN <parent_table>
ON <child_table>.<foreign_key> = <parent_table>.<primary_key>;
"""
# Creates new table with selected columns
"""
SELECT <column1>, <column2>, <column3> FROM <child_table> INNER JOIN <parent_table>
ON <child_table>.<foreign_key> = <parent_table>.<primary_key>;
"""

# LEFT JOIN
# Creates new table with all columns from both table, including all rows from left table (even if linked column has no data)
"""
SELECT * FROM <child_table> LEFT JOIN <parent_table>
ON <child_table>.<foreign_key> = <parent_table>.<primary_key>;
"""

# RIGHT JOIN
# Creates new table with all columns from both table, including all rows from right table (even if linked column has no data)
"""
SELECT * FROM <child_table> RIGHT JOIN <parent_table>
ON <child_table>.<foreign_key> = <parent_table>.<primary_key>;
"""

# Multiple join conditions
# Can use AND statements to add additional JOIN conditions
# A WHERE clause is used to filter data
"""
SELECT p.product_id, AVG(price) AS average_price FROM Prices p 
LEFT JOIN UnitsSold u_s 
ON p.product_id = u_s.product_id AND
u_s.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY product_id;
"""

# Joining 3 tables -> Order matters
# WHERE applied to end table
"""
SELECT sp.name FROM Company c
INNER JOIN Orders o ON c.com_id = o.com_id AND c.name = "RED"
RIGHT JOIN SalesPerson sp ON sp.sales_id = o.sales_id
WHERE o.order_id IS NULL;
"""