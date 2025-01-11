-- Add up migration script here
CREATE TABLE categories
(
    id          serial primary key,
    name        varchar(100) not null,
    description text
);