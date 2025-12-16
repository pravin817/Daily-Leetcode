-- SELECT MAX(salary) as SecondHighestSalary
-- FROM employee 
-- WHERE salary < (
--     SELECT max(salary) 
--     FROM employee
-- );

SELECT MAX(salary) as SecondHighestSalary
FROM (
    SELECT DISTINCT Salary 
    FROM employee
    ORDER BY Salary DESC
    LIMIT 1 OFFSET 1
) t;