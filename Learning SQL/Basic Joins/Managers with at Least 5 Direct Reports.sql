# Write your MySQL query statement below
SELECT e.name from Employee as e
INNER JOIN Employee as em #inner join allows you to make sure the two values align
ON e.id = em.managerId #where the manageriD = id, ON is the join condition 
GROUP BY e.id # you can also choose em.managerId
HAVING COUNT(em.managerID) >= 5 #the condition