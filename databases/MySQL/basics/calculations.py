
# Can write mathematical expressions, using +/-/* etc.
"""
SELECT product_id, ROUND(SUM(price*units)/SUM(units), 2) AS average_price FROM Prices
GROUP BY product_id;
"""