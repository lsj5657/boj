-- 코드를 작성해주세요
select item_id, item_name
from item_info
natural join item_tree
where parent_item_id is null
