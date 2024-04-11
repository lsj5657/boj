-- 코드를 작성해주세요

select item_id, item_name, rarity
from item_info
where item_name not in(
select item_name
from item_info
join item_tree
where item_info.item_id = item_tree.parent_item_id
)
order by 1 desc;