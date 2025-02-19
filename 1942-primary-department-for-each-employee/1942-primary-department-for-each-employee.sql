# Write your MySQL query statement below
SELECT
    employee_id,
    department_id 
FROM 
    employee 
WHERE 
    primary_flag = "Y" 
GROUP BY 
    employee_id

UNION

SELECT 
    employee_id,
    department_id
FROM 
    (SELECT employee_id, department_id, COUNT(employee_id) 
    FROM employee 
    GROUP BY employee_id 
    HAVING COUNT(employee_id) = 1) AS t1;