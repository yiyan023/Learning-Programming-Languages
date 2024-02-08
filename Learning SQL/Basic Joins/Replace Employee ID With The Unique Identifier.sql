# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id, Employees.name
FROM Employees 
LEFT JOIN EmployeeUNI #unique_id from EmployeeUNI is placed on the left
ON Employees.id = EmployeeUNI.id #when ids from the tables match

#can also be written in a simplified way using aliases
SELECT eu.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI eu 
ON e.id = eu.id 
