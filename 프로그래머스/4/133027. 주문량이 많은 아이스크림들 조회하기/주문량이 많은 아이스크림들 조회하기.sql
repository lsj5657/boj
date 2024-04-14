-- 코드를 입력하세요

select a.flavor
from first_half as a
join (select flavor, sum(total_order) as total_order from july group by flavor) as b
on a.flavor = b.flavor
order by (a.total_order+b.total_order) desc limit 3