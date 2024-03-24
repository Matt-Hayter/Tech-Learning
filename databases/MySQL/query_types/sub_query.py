# Query within a query, often used in WHERE clauses.

# Internal SELECT statemen used in WHERE ... IN/NOT IN statements.
"""
SELECT employee_id FROM Employees WHERE manager_id
NOT IN (SELECT employee_id FROM Employees)
AND salary < 30000
ORDER BY employee_id;
"""

# Create derived table, often used in FROM clauses.
# Requires AS keyword to name derived table
"""
SELECT player_id FROM (
  SELECT player_id, MIN(event_date) AS first_login FROM Activity
  GROUP BY player_id) AS first_login_table;
"""