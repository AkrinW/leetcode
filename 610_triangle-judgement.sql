# Write your MySQL query statement below
select x,y,z, if(x+y <=z,'No',if (x+z<=y,'No',if (y+z<=x,'No','Yes'))) as triangle
from triangle