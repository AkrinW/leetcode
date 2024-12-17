# Write your MySQL query statement below
select t1.request_at as 'Day', Round(
    Sum(if(t1.status = 'completed',0,1))/count(t1.status),2
) as 'Cancellation Rate'
from Trips as t1
join Users as t2 on t1.client_id = t2.users_id and t2.banned = 'No'
join Users as t3 on t1.driver_id = t3.users_id and t3.banned = 'No'
WHERE T1.request_at BETWEEN '2013-10-01' AND '2013-10-03'
group by t1.request_at
