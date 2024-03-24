# Built in SQL aggregate functions: perform calculations on rows and returns single value

# MAX & MIN: find max/min element
"""
SELECT MIN(<column_name>) FROM <table>;
SELECT MAX(<column_name>) FROM <table>;
"""

# COUNT: Count number of entries that satisfy condition
"""
SELECT COUNT(<column_name>) AS column_count FROM <table>;
SELECT COUNT(<column_name>) AS column_count FROM <table> WHERE <colunm_name> = <value>;
SELECT country, COUNT(city) c AS city_count_per_country GROUP BY country ORDER BY c DESC;
"""

# SUM: Sum total of numeric column
"""
SELECT SUM(<column_name>) AS column_sum FROM <table>;
"""

# AVG: Find average of numeric column
"""
SELECT AVG(<column_name>) AS column_sum FROM <table>;
"""