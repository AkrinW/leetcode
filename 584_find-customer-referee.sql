# Write your MySQL query statement below
select t1.name
from customer as t1
where t1.referee_id is null or t1.referee_id != 2