# Write your MySQL query statement below
select a.player_id, MIN(a.event_date) as first_login
from activity as a
group by a.player_id
order by a.event_date asc