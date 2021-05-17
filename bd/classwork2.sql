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
    grade_name ENUM("BEL", "MATH", "SUBD"),
    grade int not null DEFAULT 2,
    CHECK (grade <= 6 and grade >= 2),
    student_id int,
    PRIMARY KEY (id),
    FOREIGN KEY (student_id) REFERENCES Student(id)
);


INSERT INTO Student(name, age) Values("Pesho", 17);
INSERT INTO Student(name, age) Values("Vayer", 17);
INSERT INTO Student(name, age) Values("Andromed", 74);

INSERT INTO Grades(grade_name, grade, student_id)
Values("SUBD", 2, 1);
INSERT INTO Grades(grade_name, grade, student_id)
Values("SUBD", 4, 2);
INSERT INTO Grades(grade_name, grade, student_id)
Values("SUBD", 6, 3);
INSERT INTO Grades(grade_name, grade, student_id)
Values("MATH", 6, 1);
INSERT INTO Grades(grade_name, grade, student_id)
Values("MATH", 6, 2);
INSERT INTO Grades(grade_name, grade, student_id)
Values("MATH", 6, 3);
INSERT INTO Grades(grade_name, grade, student_id)
Values("BEL", 6, 1);
INSERT INTO Grades(grade_name, grade, student_id)
Values("BEL", 6, 2);
INSERT INTO Grades(grade_name, grade, student_id)
Values("BEL", 6, 3);

SELECT * FROM Student;
SELECT * FROM Grades;

SELECT AVG(grade) AS AverageGrade FROM Grades;

SELECT AVG(grade) AS AverageGrade FROM Grades WHERE student_id = 1;

SELECT DISTINCT Student.name
FROM Student
LEFT JOIN Grades ON Student.id = Grades.student_id
WHERE Grades.grade_name = "SUBD" AND Grades.grade BETWEEN 4 AND 6;


