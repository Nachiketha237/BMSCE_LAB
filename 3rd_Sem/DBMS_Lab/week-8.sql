create database Airline_Database;
use  Airline_Database;

-- creating table flights --

create table flight(
flno int,
ffrom varchar(20),
tto varchar(20),
distance int,
depart time,
arrive time,
price real
);

-- creating Aircraft database --

create table aircraft(
 aid int,
 aname varchar(20),
 cruising_range int,
 primary key(aid)
);

-- cretaing Employee table --

create table employee(
 eid int,
 ename varchar(20),
 salary int,
 primary key(eid)	
);

-- creating certified table --

create table certified(
 aid int,
 eid int,
 foreign key (aid)references aircraft(aid),
 foreign key (eid)references employee(eid)
);


-- inserting elements into tables --

insert into flight values
('1','Bangalore','New Delhi','500','6:00','9:00','5000'),
('2','Bangalore','Chennai','300','7:00','8:30','3000'),
('3','Kochi','New Delhi','800','8:00','11:30','6000'),
('4','Bangalore','Frankurt','10000','6:00','23:30','50000'),
('5','Kolkatta','New Delhi','2400','11:00','3:30','9000'),
('6','Bangalore','Frankurt','8000','9:00','23:00','40000');
select * from flight;


insert into aircraft values
 ('1','Airbus','2000'),
 ('2','Boeing','700'),
 ('3','Jet Airways','550'),
 ('4','Indigo','5000'),
 ('5','Boeing','4500'),
 ('6','Airbus','2200');
 select * from aircraft;
 
 insert into employee values
  ('101','Mark Wood','50000'),
  ('102','Camaroon White','60000'),
  ('103','Steve jensen','70000'),
  ('104','Niel Broom','82000'),
  ('105','Hector Munro','5000');
   select * from employee;
  
 insert into certified values
 ('2','101'),
 ('4','101'),
 ('5','101'),
 ('6','101'),
 ('1','102'),
 ('3','102'),
 ('5','102'),
 ('2','103'),
 ('3','103'),
 ('5','103'),
 ('6','103'),
 ('6','104'),
 ('1','104'),
 ('3','104'),
 ('3','105');
 select * from certified;
 
 
 
 -- week 8 queries --
 
 #todo1
 
 select a.aname
 from aircraft a,certified c,employee e
 where  c.eid=e.eid and e.salary>80000  and c.aid=a.aid;
 
 #todo2
 select c.eid, max(a.cruising_range) 
 from certified c, aircraft a 
 where c.aid=a.aid
 group by eid 
 having count(eid)>=3;
  
  #todo3
  select ename 
  from employee
  where  salary<(select min(price)
                   from flight
                   where ffrom='Bangalore'and tto='Frankurt');
                   
#todo4

select a.aid,a.aname, avg(e.salary) 
from aircraft a, employee e, certified c 
where a.aid in(select aid 
			   from aircraft 
               where cruising_range>=1000) and a.aid=c.aid and c.eid=e.eid group by aid, aname;
               
#todo5

select ename 
from employee 
where eid in (select c.eid 
              from certified c, aircraft a 
              where a.aid=c.aid and a.aname='Boeing');
              
#todo6


select a.aid 
from aircraft a
where a.cruising_range>=(select distance 
						from flight 
						where ffrom='Bangalore'and tto='New Delhi');
