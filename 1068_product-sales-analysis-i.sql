# Write your MySQL query statement below
select t2.product_name,t1.year,t1.price
from sales as t1
left join product as t2 on t1.product_id = t2.product_id