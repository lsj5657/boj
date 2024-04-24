with tmp as(
select author_id, book_id, category, sum(price * sales) as total_sales
from book natural join book_sales
where year(sales_date)=2022 and month(sales_date) = 1
group by author_id, category
)
select author_id, author_name, category, total_sales
from tmp natural join author
order by 1, 3 desc

