DROP DATABASE IF EXISTS Classbook;

CREATE DATABASE Classbook;
USE Classbook;

CREATE TABLE Student(
    id int auto_increment not null,
    name varchar(100) not null,
    age int,
    CHECK (age > 0),
    PRIMARY KEY (id)
);

CREATE TABLE Grades(
    id int auto_increment not null,
    grade_bg int  not null  DEFAULT 2,
    CHECK (grade_bg <= 6 and grade_bg >= 2),
    grade_math int not null DEFAULT 2,
    CHECK (grade_math <= 6 and grade_math >= 2),
    grade_subd int not null DEFAULT 2,
    CHECK (grade_subd <= 6 and grade_subd >= 2),
    student_id int,
    PRIMARY KEY (id),
    FOREIGN KEY (student_id) REFERENCES Student(id)
    
);


INSERT INTO Student(name, age) Values("Pesho", 17);
INSERT INTO Student(name, age) Values("Vayer", 17);
INSERT INTO Student(name, age) Values("Andromed", 74);

INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id)
Values(2,3,6,1);
INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id)
Values(6,4,6,2);
INSERT INTO Grades(grade_bg, grade_math, grade_subd, student_id)
Values(6,3,6,3);

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student
LEFT JOIN Grades ON Student.id = Grades.student_id
WHERE name = "ALEX";

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student
LEFT JOIN Grades ON Student.id = Grades.student_id
WHERE name LIKE '%a%';

SELECT Student.name, Grades.grade_bg, Grades.grade_math, Grades.grade_subd
FROM Student 
LEFT JOIN Grades ON Student.id = Grades.student_id 
WHERE ((grade_bg + grade_math + grade_subd)/3) > 5;

SELECT Student.name, Grades.grade_bg, Grades.grade_math
FROM Student 
LEFT JOIN Grades ON Student.id = Grades.student_id 
WHERE ((grade_bg + grade_math)/2) > 5;