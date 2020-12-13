DROP DATABASE IF EXISTS Store;

CREATE DATABASE Store;
USE Store;

CREATE TABLE Person(
    id int auto_increment not null,
    name varchar(100) not null unique,
);
