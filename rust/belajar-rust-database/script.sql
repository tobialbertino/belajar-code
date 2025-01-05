CREATE DATABASE belajar_rust_database;

SELECT datname
FROM pg_database;

CREATE TABLE category
(
    id          varchar(100) primary key,
    name        varchar(100) not null,
    description text
);

SELECT * FROM category;