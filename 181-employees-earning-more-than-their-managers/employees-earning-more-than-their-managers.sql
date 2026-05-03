# Write your MySQL query statement below
select e.name as Employee
from Employee e, Employee em
where e.managerId is not null and e.managerid = em.id and e.salary > em.salary