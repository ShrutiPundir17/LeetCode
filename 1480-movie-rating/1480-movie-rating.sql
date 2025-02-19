select results
from (
  select u.name results
  from MovieRating mr
  join users u on mr.user_id = u.user_id
  group by u.name
  order by count(mr.rating) desc, name
  limit 1 
  ) as ratings
union all
select results 
from (
  select m.title results
  from MovieRating mr2
  join Movies m on mr2.movie_id = m.movie_id 
  where DATE_FORMAT(mr2.created_at, "%Y-%m") = '2020-02'
  group by m.title
  order by avg(mr2.rating) desc, m.title 
  limit 1
) movie_ratings
