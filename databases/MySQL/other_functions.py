
# HAVING vs WHERE:
# WHERE evaluates all rows individually
"""
SELECT class FROM Courses WHERE student >= 5;
"""
# HAVING evaluates rows after they've been aggregated
"""
SELECT class FROM Courses
GROUP BY class HAVING COUNT(student) >= 5;
"""


# UNION: Combine result-set of two or more SELECT statements
# Must have same number of columns
# Columns must have similar types
"""
SELECT employee_id, department_id FROM Employee
WHERE primary_flag = "Y"
UNION
SELECT employee_id, department_id FROM Employee 
GROUP BY employee_id
HAVING COUNT(employee_id) = 1;
"""

# IFNULL: if first argument is null, use second argument as default.
"""
SELECT id, IFNULL(location, "unavailable") FROM <table>
"""

# DISTINCT: Removes duplicate rows from query
"""
SELECT DISTINCT email from Person;
"""

# DATEDIFF(<to>, <from>): Find the time between dates
"""
SELECT MAX(DATEDIFF(<to_date_column>, <from_date_column>)) FROM <table>
"""

# BETWEEN: Shorthand for <= ... AND <= ...
"""
SELECT col WHERE col BETWEEN ... AND ...
SELECT col WHERE col NOT BETWEEN ... AND ...
"""