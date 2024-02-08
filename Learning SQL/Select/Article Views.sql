# Write your MySQL query statement below
select distinct author_id as id from Views #distinct makes sure everything is unique & renames the column as id
where author_id = viewer_id
order by id #sorts the id in ascending order
