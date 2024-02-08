# Write your MySQL query statement below
select name from customer # this is for the part of the table you actually want to extract
where referee_id is null or referee_id != 2 #the conditions
