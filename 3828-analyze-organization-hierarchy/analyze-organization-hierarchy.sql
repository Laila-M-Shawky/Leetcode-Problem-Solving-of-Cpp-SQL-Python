# Write your MySQL query statement below
WITH RECURSIVE hierarchy AS (
    -- Base case: CEO (level 1)
    SELECT
        employee_id,
        employee_name,
        manager_id,
        salary,
        1 AS level
    FROM Employees
    WHERE manager_id IS NULL

    UNION ALL

    -- Recursive step: find direct reports, increment level
    SELECT
        e.employee_id,
        e.employee_name,
        e.manager_id,
        e.salary,
        h.level + 1 AS level
    FROM Employees e
    JOIN hierarchy h
      ON e.manager_id = h.employee_id
),
-- Build a mapping of each manager to all their subordinates (direct + indirect)
manager_tree AS (
    SELECT
        employee_id AS manager_id,
        employee_id AS subordinate_id
    FROM Employees
    UNION ALL
    SELECT
        mt.manager_id,
        e.employee_id
    FROM manager_tree mt
    JOIN Employees e
      ON e.manager_id = mt.subordinate_id
)
SELECT
    h.employee_id,
    h.employee_name,
    h.level,
    -- team_size = total subordinates minus 1 (exclude self)
    COUNT(mt.subordinate_id) - 1 AS team_size,
    -- budget = sum of salaries of self and all subordinates
    SUM(e2.salary) AS budget
FROM hierarchy h
JOIN manager_tree mt
  ON h.employee_id = mt.manager_id
JOIN Employees e2
  ON mt.subordinate_id = e2.employee_id
GROUP BY h.employee_id, h.employee_name, h.level
ORDER BY h.level ASC, budget DESC, h.employee_name ASC;
