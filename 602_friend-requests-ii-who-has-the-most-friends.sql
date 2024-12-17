select t1.ids as id,count(*) as num
from(
        select requester_id as ids from RequestAccepted 
        union all
        select accepter_id as ids from RequestAccepted
) as t1
group by id
order by num desc
limit 1;