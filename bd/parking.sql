DROP DATABASE IF EXISTS Parking;

CREATE DATABASE Parking;
USE Parking;

CREATE TABLE Person(
    id int auto_increment not null,
    name varchar(100) not null unique,
    number_of_parked_car int DEFAULT 0,
    PRIMARY KEY (id)
);

CREATE TABLE Car(
    id int auto_increment not null,
    plate varchar(30) not null unique,
    person_id int,
    PRIMARY KEY (id),
    FOREIGN KEY (person_id) REFERENCES Person(id)
    
);

CREATE TABLE ParkingPlace(
    id int auto_increment not null,
    name varchar(30) not null unique,
    car_id int,
    PRIMARY KEY (id),
    FOREIGN KEY (car_id) REFERENCES Car(id)
    
);

INSERT INTO Person(name) VALUES("Misho");
INSERT INTO Person(name) VALUES("Geri");
INSERT INTO Person(name) VALUES("Nikola");
INSERT INTO Person(name) VALUES("MartiV");
INSERT INTO Person(name) VALUES("Marti<3");
INSERT INTO Person(name) VALUES("Gosho");
INSERT INTO Person(name) VALUES("LadyPopular");

INSERT INTO Car(plate, person_id) VALUES("CB0000BC", 1);
INSERT INTO Car(plate, person_id) VALUES("CB1111BC", 3);
INSERT INTO Car(plate, person_id) VALUES("CB2222BC", 3);
INSERT INTO Car(plate, person_id) VALUES("CB3333BC", 2);
INSERT INTO Car(plate, person_id) VALUES("CB4444BC", 4);
INSERT INTO Car(plate, person_id) VALUES("CB5555BC", 5);
INSERT INTO Car(plate, person_id) VALUES("CB6666BC", 6);
INSERT INTO Car(plate, person_id) VALUES("CB7777BC", 7);
INSERT INTO Car(plate, person_id) VALUES("CB8888BC", 8);
INSERT INTO Car(plate, person_id) VALUES("CB9999BC", 1);

INSERT INTO ParkingPlace(car_id, name) VALUES( 2, "A01");
INSERT INTO ParkingPlace(car_id, name) VALUES( 3, "A02");
INSERT INTO ParkingPlace(car_id, name) VALUES( 5, "A03");
INSERT INTO ParkingPlace(car_id, name) VALUES( 1, "A04");
INSERT INTO ParkingPlace(car_id, name) VALUES( 6, "G05");
INSERT INTO ParkingPlace(car_id, name) VALUES( 4, "A06");
INSERT INTO ParkingPlace(car_id, name) VALUES( 8, "A07");

SELECT * FROM Person;

SELECT * FROM ParkingPlace
WHERE name like "G%";

/*Delimiter $$

Create Trigger Update_parked_cars_count
    After Insert
    on ParkingPlace for each row
Begin
    
End $$

DELIMITER ;*/







