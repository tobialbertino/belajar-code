CREATE
DATABASE belajar_rust_database;

SELECT datname
FROM pg_database;

CREATE TABLE category
(
    id          varchar(100) primary key,
    name        varchar(100) not null,
    description text
);

SELECT *
FROM category;

CREATE TABLE brands
(
    id          varchar(100) primary key,
    name        varchar(100) not null,
    description text,
    created_at  timestamp    NOT NULL default now(),
    updated_at  timestamp    NOT NULL default now()
);

SELECT *
FROM brands;

CREATE TABLE sellers
(
    id   serial primary key,
    name varchar(100) not null
);
