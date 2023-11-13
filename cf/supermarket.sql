create database supermarket;
use supermarket;

show databases;
create table Employee(
    employee_id int primary key,
    first_name varchar(15),
    middle_name varchar(15),
    last_name varchar(15),
    role varchar(25),
    address text,
    DOB date
);
desc employee;
create table department(
    department_id int primary key,
    department_name varchar(20),
    employee_id int,
    foreign key (employee_id) references Employee(employee_id)
);
desc department;
create table Emp_mobile(
    emp_id int,
    emp_Mob varchar(10),
    foreign key (emp_id) references Employee(employee_id)
);
desc Emp_mobile;

alter table Employee
add column sex char(1);

desc Employee;

alter table Employee
MODIFY COLUMN sex varchar(6);

INSERT INTO Employee (employee_id, first_name, middle_name, last_name, role, address, DOB, sex)
VALUES
    (123, 'Rajesh', 'Kumar', 'Sharma', 'Manager', '123 Main St, Delhi', '1980-05-15', 'M'),
    (234, 'Sunita', 'Rani', 'Verma', 'Cashier', '456 Elm St, Mumbai', '1990-08-22', 'F'),
    (345, 'Amit', 'Kumar', 'Singh', 'Stock Clerk', '789 Oak St, Bangalore', '1985-04-10', 'M'),
    (456, 'Priya', 'Devi', 'Gupta', 'Manager', '101 Pine St, Kolkata', '1979-12-02', 'F'),
    (567, 'Vikram', 'Singh', 'Yadav', 'Cashier', '202 Cedar St, Mumbai', '1993-06-18', 'M'),
    (678, 'Anita', 'Devi', 'Shukla', 'Stock Clerk', '303 Maple St, Delhi', '1991-03-25', 'F'),
    (789, 'Arun', 'Kumar', 'Mishra', 'Cashier', '404 Birch St, Kolkata', '1988-09-14', 'M'),
    (890, 'Meena', 'Rani', 'Gupta', 'Stock Clerk', '505 Redwood St, Bangalore', '1983-07-11', 'F'),
    (901, 'Sanjay', 'Kumar', 'Sharma', 'Manager', '606 Spruce St, Delhi', '1977-02-08', 'M'),
    (102, 'Neha', 'Devi', 'Verma', 'Cashier', '707 Sycamore St, Mumbai', '1995-01-30', 'F'),
    (213, 'Rahul', 'Kumar', 'Singh', 'Stock Clerk', '808 Willow St, Kolkata', '1987-11-19', 'M'),
    (324, 'Pooja', 'Devi', 'Gupta', 'Cashier', '909 Juniper St, Delhi', '1992-10-07', 'F'),
    (435, 'Alok', 'Kumar', 'Mishra', 'Manager', '1210 Oak St, Mumbai', '1976-06-03', 'M'),
    (546, 'Nisha', 'Rani', 'Sharma', 'Cashier', '1311 Cedar St, Kolkata', '1994-04-29', 'F'),
    (657, 'Raj', 'Kumar', 'Yadav', 'Stock Clerk', '1412 Pine St, Bangalore', '1984-08-17', 'M');


INSERT INTO department (department_id, department_name, employee_id)
VALUES
    (1, 'Management', 123),
    (2, 'Cashiers', 234),
    (3, 'Stocking', 345),
    (4, 'Management', 456),
    (5, 'Cashiers', 567),
    (6, 'Stocking', 678);


INSERT INTO Emp_mobile (emp_id, emp_Mob)
VALUES
    (123, '9876543210'),
    (123, '9999999999'),
    (234, '7777777777'),
    (234, '8888888888'),
    (345, '6666666666'),
    (456, '5555555555'),
    (567, '4444444444'),
    (567, '3333333333'),
    (678, '2222222222'),
    (789, '1111111111'),
    (890, '1231231231'),
    (901, '4564564564'),
    (102, '7897897897'),
    (213, '1112223333'),
    (324, '4445556666'),
    (435, '7778889999'),
    (546, '5554443333'),
    (657, '2223334444'),
    (890, '3334445555'),
    (901, '4445556666');

select * from Employee;

select * from department;

select * from Emp_mobile;

select employee_id,first_name,role,DOB from Employee limit 10;

update department
set department_name='Electronics'
where department_id=4;

delete from Employee where employee_id=123;

select count(employee_id),role from Employee
group by role;

alter table Employee
rename column sex to gender;

alter table Employee
rename to Employee_table;

desc Employee_table;

drop database supermarket;