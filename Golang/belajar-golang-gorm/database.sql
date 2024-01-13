CREATE TABLE sample
(
    id   VARCHAR(100) NOT NULL,
    name VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

SELECT *
FROM sample;

CREATE TABLE users
(
    id         VARCHAR(100) NOT NULL,
    password   VARCHAR(100) NOT NULL,
    name       VARCHAR(100) NOT NULL,
    created_at TIMESTAMP    NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP    NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    primary key (id)
);

SELECT *
FROM users;

alter table users
    rename column name to first_name;

alter table users
    add column middle_name varchar(100) null after first_name;

alter table users
    add column last_name varchar(100) null after middle_name;

CREATE TABLE user_logs
(
    id         INT AUTO_INCREMENT,
    user_id    VARCHAR(100) NOT NULL,
    action     VARCHAR(100) NOT NULL,
    created_at timestamp    NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at timestamp    NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    PRIMARY KEY (id)
);

delete
from user_logs;

alter table user_logs
    modify created_at bigint not null;

alter table user_logs
    modify updated_at bigint not null;

SELECT * FROM user_logs;

create table todos
(
    id          bigint       not null auto_increment,
    user_id     varchar(100) not null,
    title       varchar(100) not null,
    description text         null,
    created_at  timestamp    not null default current_timestamp,
    updated_at  timestamp    not null default current_timestamp on update current_timestamp,
    deleted_at  timestamp    null,
    primary key (id)
);

SELECT * FROM todos;

create table wallets
(
    id         varchar(100) not null,
    user_id    varchar(100) not null,
    balance    bigint       not null,
    created_at timestamp    not null default current_timestamp,
    updated_at timestamp    not null default current_timestamp on update current_timestamp,
    primary key (id),
    foreign key (user_id) references users (id)
);

DESC wallets;

SELECT * FROM wallets;

create table addresses
(
    id         bigint       not null auto_increment,
    user_id    varchar(100) not null,
    address    varchar(100) not null,
    created_at timestamp    not null default current_timestamp,
    updated_at timestamp    not null default current_timestamp on update current_timestamp,
    primary key (id),
    foreign key (user_id) references users (id)
);

DESC addresses;

create table products
(
    id         varchar(100) not null,
    name       varchar(100) not null,
    price      bigint       not null,
    created_at timestamp    not null default current_timestamp,
    updated_at timestamp    not null default current_timestamp on update current_timestamp,
    primary key (id)
);

DESC products;

create table user_like_product
(
    user_id    varchar(100) not null,
    product_id varchar(100) not null,
    primary key (user_id, product_id),
    foreign key (user_id) references users (id),
    foreign key (product_id) references products (id)
);

desc user_like_product;

SELECT * FROM user_like_product;

select * from addresses;