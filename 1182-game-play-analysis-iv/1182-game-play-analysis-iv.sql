# Write your MySQL query statement below
WITH FirstLogin AS (
    -- Get the first login date for each player
    SELECT player_id, MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
)
SELECT 
    ROUND(
        COUNT(DISTINCT A.player_id) / COUNT(DISTINCT F.player_id), 2
    ) AS fraction
FROM FirstLogin F
LEFT JOIN Activity A
ON F.player_id = A.player_id 
AND A.event_date = DATE_ADD(F.first_login_date, INTERVAL 1 DAY);
