SELECT AVG(grade) FROM Grades;

SELECT AVG(grade) 
FROM Grades
WHERE student_id = 1;

SELECT grade_name, AVG(grade)
FROM Grades 
GROUP BY grade_name;

SELECT Student.name, Grades.grade
FROM Grades
LEFT JOIN Student
ON Student.id = Grades.student_id;

