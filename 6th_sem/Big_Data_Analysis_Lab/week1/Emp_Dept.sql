create database Big_Data;
use Big_Data;

create table Department(
dep_id int,
dep_name varchar(20),
dep_location varchar(15),
primary key(dep_id)
);

create table Employee(
emp_id int,
emp_name varchar(20),
job_name varchar(20),
manager_id int,
hire_date date,
salary decimal(10,2),
commision decimal(7,2),
dep_id int,
primary key(emp_id),
foreign key(dep_id) references Department(dep_id)
);

insert into Department(dep_id,dep_name,dep_location)
values 
(1,"Development","Marathalli"),
(2,"Analyst","Whitefeild");
select * from Department;


insert into Employee
values 
(1,"Raghu","Data Analyst",0,'2023-12-12',50000,5000,2),
(2,"Ravi","Data Analyst",1,'2021-12-12',180000,30000,2),
(3,"Rohan","Back-end Developer",0,'2023-10-12',45000,4000,1),
(4,"Raju","Senior Developer",1,'2020-11-12',150000,15000,1);
select * from Employee;


# Find salaries of all employees

Select emp_name,salary
from Employee;

# Find employees whose hire date like nov 12 2020 #

Select *
from Employee
where hire_date = '2020-11-12';

# Calculate average salary of employyes who work as analyst

Select avg(salary)
from Employee
where dep_id = ( Select dep_id
				 from Department
                 where dep_name = 'Analyst');
                 
# Find those employees who are manager

select emp_name
from Employee
where manager_id = 1;

#Search for all the employees with annual salries between 24000 and 50000

Select emp_name,salary
from Employee
where salary between 24000 and 50000;
