-- Add up migration script here
CREATE TABLE brands
(
    id   varchar(100) primary key,
    name varchar(100) not null,
    description text
);