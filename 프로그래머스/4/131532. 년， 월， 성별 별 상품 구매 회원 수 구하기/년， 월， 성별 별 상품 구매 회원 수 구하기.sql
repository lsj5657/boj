-- 코드를 입력하세요
select sale.year, sale.month, gender, count(distinct info.user_id) as users
from (SELECT user_info.user_id as user_id, gender, year(joined) as year, month(joined) as month from user_info) as info 
join (SELECT online_sale.user_id as user_id , year(sales_date) as year, month(sales_date) as month from online_sale) as sale
on info.user_id = sale.user_id
where gender is not null
group by 1,2,3
order by 1,2,3;