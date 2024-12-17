# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums 
from logs as a
left join logs as b on a.id = b.id-1
left join logs as c on a.id = c.id-2
where a.num = b.num and a.num = c.num