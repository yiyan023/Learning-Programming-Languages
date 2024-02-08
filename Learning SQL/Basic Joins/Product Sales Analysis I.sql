# Write your MySQL query statement below
select Sales.price, Sales.year, Product.product_name 
from Sales 
INNER JOIN Product  #inner join creates a new table, slightly faster than LEFT JOIN
on Sales.product_id = Product.product_id #alias makes it slower