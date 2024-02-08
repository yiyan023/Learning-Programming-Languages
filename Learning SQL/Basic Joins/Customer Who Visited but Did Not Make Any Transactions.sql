# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans 
from Visits v 
LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id  
WHERE t.transaction_id IS NULL #means no transaction happens
GROUP BY v.customer_id #tallies the count for each customer id
ORDER BY count_no_trans #orders the count in ascending order 