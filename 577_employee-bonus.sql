# Write your MySQL query statement below
select t1.name, t2.bonus
from employee as t1
left join bonus as t2 on t1.empId = t2.empId
where t2.bonus is null or t2.bonus < 1000