show databases;
use siddhudb;

drop TABLE TCS;

CREATE TABlE TCS (
  emp_id int UNIQUE,
  emp_name varchar(255) NOT NULL,
  designation varchar(255),
  age int,
  salary int,
  city varchar(255),
  country varchar(255),
  CHECK (Age>=24)
);

INSERT INTO TCS (emp_id, emp_name, designation, age, salary, city, country)
VALUES (1, 'sid', 'a', 26, 10000, 'phagwara', 'india');
INSERT INTO TCS (emp_id, emp_name, designation, age, salary, city, country)
VALUES (2, 'vik', 'b', 29, 20000, 'florida', 'usa');
INSERT INTO TCS (emp_id, emp_name, designation, age, salary, city, country)
VALUES (3, 'Ram', 'c', 32, 50000, 'jalandhar', 'india');
INSERT INTO TCS (emp_id, emp_name, designation, age, salary, city, country)
VALUES (4, 'Shyam', 'd', 28, 30000, 'jalandhar', 'india');


ALTER TABLE TCS ADD COLUMN state varchar(20);
select * from TCS;

Update TCS set state= 'punjab';

SELECT emp_name FROM TCS order by salary;


