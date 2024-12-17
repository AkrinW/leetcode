# Write your MySQL query statement below
with FirstLogin as (
    select player_id,min(event_date) as first_login_date
    from activity
    group by player_id
), SecondDayLogin as(
    select f.player_id
    from FirstLogin as f
    join activity as a
    on f.player_id = a.player_id and a.event_date= date_add(f.first_login_date,interval 1 day)
) select round(count(distinct s.player_id)/count(distinct f.player_id),2 ) as fraction 
from FirstLogin f 
left join SecondDayLogin s
on f.player_id=s.player_id