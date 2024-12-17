# Write your MySQL query statement below

select t3.name
from salesperson as t3
where t3.sales_id not in (
    select t1.sales_id
    from orders as t1
    left join company as t2 on t1.com_id = t2.com_id
    where t2.name = 'RED'
)