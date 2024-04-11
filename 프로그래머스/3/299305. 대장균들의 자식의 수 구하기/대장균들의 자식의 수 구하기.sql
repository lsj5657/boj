-- 코드를 작성해주세요

select a.id, count(b.parent_id) as child_count
from ecoli_data a
left join (select id,parent_id
     from ecoli_data) as b
on a.id = b.parent_id
group by id
     
