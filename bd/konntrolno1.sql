drop database if exists db;
create database db;
use db;

create table Office(
    id int auto_increment not null primary key,
    name varchar(100) not null unique
);

create table Person(
    id int auto_increment not null primary key,
    name varchar(100) not null unique,
    age int not null,
    CHECK (age > 0),
    office_id int not null,
    foreign key (office_id) references Office(id)
);

-- DEFAULT GETDATE(),

create table Entered(
    id int auto_increment not null primary key,
    date_of_entering date,
    person_id int not null,
    foreign key (person_id) references Person(id)
);


INSERT INTO Office(name) VALUES("Robopartans");
INSERT INTO Office(name) VALUES("Work and Share");
INSERT INTO Office(name) VALUES("Deliveroo");


INSERT INTO Person(name, age, office_id) VALUES("Misho", 25, 1);
INSERT INTO Person(name, age, office_id) VALUES("Ivan", 28, 1);
INSERT INTO Person(name, age, office_id) VALUES("Kiko", 35, 1);
INSERT INTO Person(name, age, office_id) VALUES("Georgi", 25, 2);
INSERT INTO Person(name, age, office_id) VALUES("Alex", 25, 2);


INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-02", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-03", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-04", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-01", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-03", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-04", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-03-03", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-04", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-01", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-03-03", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-01", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-04", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-30", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-05", 4);







-- [Датата на всяко влизане, Името на офис] => За всеки офис, който има влизания в него.
select date_of_entering, Office.name from Entered
left join Person
on person_id = Person.id
left join Office
on Person.office_id = Office.id;


-- [Името на човек, колко пъти е влизал в офиса] => За човек, който най-малко пъти е влизал в офиса си през месец April 2020; Очакваме заявката да върне един човек, например [Pesho, 24]
select Count(*) from Person
left join Entered
on person_id = Person.id
where Person.name = "Ivan";


-- [Името на човек, колко пъти е влизал в офиса] => За човек, който най-малко пъти е влизал в офиса си през месец April 2020; Очакваме заявката да върне един човек, например [Pesho, 24]
select Person.name, Count(Person.id)
from Person
left join Entered
on Entered.person_id = Person.id
where Entered.date_of_entering LIKE '2020-04%'
GROUP BY name;

-- [Името на офис, колко пъти е влизано в него] => За всеки офис.
select Office.name, Count(*)
from Office
right join Person
on Person.office_id = Office.id
right join Entered
on Entered.person_id = Person.id
GROUP BY name;



-- [Името на офис] => За всеки офис, който няма хора в него;
select DISTINCT Office.name from Office
right JOIN Person
on Person.office_id = Office.id;

-- [Името на чокве] => За всеки човек, който е влизал в офиса си поне един път. Очакваме да изпишем името на човек само единт път.
select distinct Person.name from Person
right join Entered
on Person.id = Entered.person_id;


