# Write your MySQL query statement below
select a.name as Employee 
from employee as a 
right join employee as b on b.id = a.managerId
where a.salary > b.salary