DROP DATABASE IF EXISTS Facebook;

CREATE DATABASE Facebook;
USE Facebook;

CREATE TABLE GGruop(
    id int auto_increment not null,
    name varchar(50) not null,
    user_id int not null,
    PRIMARY KEY (id)
);

CREATE TABLE User(
    id int auto_increment not null,
    name varchar(50) not null,
    group_id int not null,
    PRIMARY KEY (id)
);

CREATE TABLE GGruopUser(
    id int auto_increment not null,
    FOREIGN KEY GGruop(user_id) REFERENCES Student(id),
    FOREIGN KEY User(group_id) REFERENCES GGruop(id),
    PRIMARY KEY (id)
);

CREATE TABLE Post(
    id int auto_increment not null,
    name varchar(50) not null,
    content varchar(500) not null,
    PRIMARY KEY (id)
);

CREATE TABLE Coment(
    id int auto_increment not null,
    content varchar(500) not null,
    PRIMARY KEY (id)
);

INSERT INTO GGroup(name) VALUES("Obi4mekotki");
INSERT INTO GGroup(name) VALUES("Obi4ameGeri");

INSERT INTO User(name) VALUES("Jorko");
INSERT INTO User(name) VALUES("Andromed");
INSERT INTO User(name) VALUES("Geri");

INSERT INTO Post(name, content, group_id) VALUES("Iskam da leftna", "NE obi4am kotki", 1);
INSERT INTO Post(name, content, group_id) VALUES("Obi4am", "kotki", 1);
INSERT INTO Post(name, content, group_id) VALUES("obGERI", "tq e mnogo qka", 2);
INSERT INTO Post(name, content, group_id) VALUES("geri ob li me", "4udq se", 2);

INSERT INTO Comment(content, user_id, post_id) VALUES("..", 1, 1);
INSERT INTO Comment(content, user_id, post_id) VALUES("...", 2, 1);
INSERT INTO Comment(content, user_id, post_id) VALUES("NE brat", 2, 2);
INSERT INTO Comment(content, user_id, post_id) VALUES("Moje bi nqkoi hora(ne i dankata)", 1, 2);
INSERT INTO Comment(content, user_id, post_id) VALUES("Da", 3, 3);
INSERT INTO Comment(content, user_id, post_id) VALUES("Absolutno", 1, 4);
INSERT INTO Comment(content, user_id, post_id) VALUES("Ne mislq", 3, 4);


INSERT INTO UserGGroup(user_id, group_id) VALUES(1, 2);
INSERT INTO UserGGroup(user_id, group_id) VALUES(1, 1);
INSERT INTO UserGGroup(user_id, group_id) VALUES(2, 1);
INSERT INTO UserGGroup(user_id, group_id) VALUES(3, 2);