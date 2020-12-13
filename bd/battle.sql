DROP DATABASE IF EXISTS Canadska;

CREATE DATABASE Canadska;
USE Canadska;

CREATE TABLE Person(
    id int auto_increment not null ,
    name varchar(50) unique,
    PRIMARY KEY (id)
);

CREATE TABLE Battle(
    id int auto_increment not null,
    winner_id int,
    looser_id int,
    CHECK (winner_id != looser_id),
    PRIMARY KEY(id),
    FOREIGN KEY (winner_id) REFERENCES Person(id),
    FOREIGN KEY (looser_id) REFERENCES Person(id)
);

INSERT INTO Person(name) VALUES("Misho");
INSERT INTO Person(name) VALUES("Alexandro");
INSERT INTO Person(name) VALUES("Gorg");
INSERT INTO Person(name) VALUES("Alonso");
INSERT INTO Person(name) VALUES("Kosio");

INSERT INTO Battle(winner_id, looser_id) VALUES(1,2);
INSERT INTO Battle(winner_id, looser_id) VALUES(1,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(1,4);
INSERT INTO Battle(winner_id, looser_id) VALUES(1,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,4);
INSERT INTO Battle(winner_id, looser_id) VALUES(2,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,2);
INSERT INTO Battle(winner_id, looser_id) VALUES(5,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,4);
INSERT INTO Battle(winner_id, looser_id) VALUES(3,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,2);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,3);
INSERT INTO Battle(winner_id, looser_id) VALUES(4,5);
INSERT INTO Battle(winner_id, looser_id) VALUES(5,1);
INSERT INTO Battle(winner_id, looser_id) VALUES(5,2);

Select Count(*) from Battle
LEFT JOIN Person
ON Person.id = Battle.winner_id
Where Person.name = "Alonso";

Select Person.name, Count(*) from Battle
LEFT JOIN Person
ON Person.id = Battle.winner_id
GROUP BY Person.name;

Select distinct Winner.name as "Winner", Looser.name as "Looser" from Battle 
LEFT JOIN Person as Looser
ON Looser.id = Battle.looser_id
LEFT JOIN Person as Winner
ON Winner.id = Battle.winner_id
WHERE Looser.name Like "Alonso";


Select Battle.id, Winner.name as "Winner", Looser.name as "Looser" from Battle 
LEFT JOIN Person as Looser
ON Looser.id = Battle.looser_id
LEFT JOIN Person as Winner
ON Winner.id = Battle.winner_id;
