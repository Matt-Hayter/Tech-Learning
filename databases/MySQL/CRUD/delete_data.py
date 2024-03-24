# Deleting rows

# Delete specific rows
"""
DELETE FROM <table> WHERE <condition>
"""

# Delete all table rows: DANGER
"""
DELETE FROM <table>
"""

# Complex deletions: DELETE ... JOIN
# Rows in joined table are then deleted from specified table

# Delete rows with duplicate emails, leaving email for person with smallest id
# Any rows in joined table will be deleted from p1 (any duplicate emails with larger ids than another).
"""
DELETE p1 FROM Person p1
INNER JOIN Person p2
ON p1.Email = p2.Email AND p1.id > p2.id;
"""