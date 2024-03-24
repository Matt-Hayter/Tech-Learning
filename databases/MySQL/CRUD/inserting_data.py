# Inserting data into database

# Insert row. If all NOT NULL types, columns should match up with database
"""
INSERT INTO <table> (<column1>, <column2>, <column3>) VALUES (<value1>, <value2>, <value3>);
"""

# Insert row if some fields are optional (not all columns need to be specified)
"""
INSERT INTO <table> (<column1>) VALUES (<value1>);
"""

# Insert multiple rows at once, where only one column is required
"""
INSERT INTO <table> (<column1>) VALUES (<value1>, <value2>, <value3>);
"""

# Insert into table from another table
"""
INSERT INTO user (id, name, username, opted_in)
SELECT id, name, username, opted_in 
FROM user
LEFT JOIN user_permission AS userPerm ON user.id = userPerm.user_id
"""