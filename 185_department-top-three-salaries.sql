# Write your MySQL query statement below
select dp.Name as Department, ep1.Name as Employee, ep1.Salary
from Employee ep1
join Department dp
on ep1.DepartmentId = dp.Id
where (select count(distinct(ep2.Salary))
        from Employee ep2
        where ep2.Salary > ep1.Salary
        and ep2.DepartmentId = ep1.DepartmentId) < 3;
