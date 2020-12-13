DROP DATABASE IF EXISTS hw2;

CREATE DATABASE hw2;
USE hw2;

CREATE TABLE Student(
    id int auto_increment not null,
    name varchar(50) not null,
    age int not null,
    PRIMARY KEY (id)
);

CREATE TABLE Grades(
    grade_name Enum('Bel', 'Math', 'Subd'),
    grade int DEFAULT 2,
    CHECK (grade <= 6 and grade >= 2),
    student_id int,
    FOREIGN KEY (student_id) REFERENCES Student(id)
);
