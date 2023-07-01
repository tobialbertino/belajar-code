ALTER DATABASE belajar SET TIMEZONE TO 'Asia/Jakarta';

CREATE DATABASE belajar;
SHOW TIMEZONE;
SET TIMEZONE TO 'Asia/Jakarta';

CREATE TABLE barang
(
    kode       INT          NOT NULL,
    name       VARCHAR(100) NOT NULL,
    harga      INT          NOT NULL,
    jumlah     INT          NOT NULL DEFAULT 0,
    created_ar TIMESTAMP    NOT NULL DEFAULT CURRENT_TIMESTAMP
);

ALTER TABLE barang
    ADD COLUMN deskripsi TEXT;

ALTER TABLE barang
    DROP
        COLUMN deskripsi;

ALTER TABLE barang
    RENAME COLUMN name TO barang;

TRUNCATE
    barang;

DROP TABLE barang;

CREATE TABLE products
(
    id          VARCHAR(100) NOT NULL,
    name        VARCHAR(100) NOT NULL,
    description TEXT,
    price       INT          NOT NULL,
    quantity    INT          NOT NULL DEFAULT 0,
    created_at  TIMESTAMP    NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id)
);

INSERT INTO products(id, name, price, quantity)
VALUES ('P0001', 'Mie Ayam Original', 15000, 100);

INSERT INTO products(id, name, description, price, quantity)
VALUES ('P0002', 'Mie Ayam Bakso Tahu', 'Mie Ayam Original + Bakso Tahu', 20000, 100);

INSERT INTO products(id, name, price, quantity)
VALUES ('P0003', 'Mie Ayam Ceker', 20000, 100),
       ('P0004', 'Mie Ayam Spesial', 25000, 100),
       ('P0005', 'Mie Ayam Yamin', 25000, 100);

SELECT *
FROM products;

SELECT id, name
FROM products;

ALTER TABLE products
    ADD
        PRIMARY KEY (id);

SELECT id, name, price, quantity
FROM products
WHERE quantity = 100;

CREATE TYPE PRODUCT_CATEGORY AS ENUM ('Makanan', 'Minuman', 'Lain-lain');

ALTER TABLE products
    ADD COLUMN category PRODUCT_CATEGORY;

UPDATE products
SET category = 'Makanan'
WHERE id = 'P0001';

UPDATE products
SET category    = 'Makanan',
    description = 'Mie Ayam + Ceker'
WHERE id = 'P0003';

UPDATE products
SET price = price + 3000
WHERE id = 'P0004';

INSERT INTO products(id, name, price, quantity, category)
VALUES ('P0009', 'Contoh', 10000, 10, 'Minuman');

DELETE
FROM products
WHERE id = 'P0009';

SELECT p.id          AS "kode barang",
       p.price       AS "harga barang",
       p.description AS deksripsi
FROM products AS p;

SELECT *
FROM products
WHERE price > 15000;

SELECT *
FROM products
WHERE price <= 15000;

SELECT *
FROM products
WHERE products.category != 'Minuman'
  AND (price > 10000 OR quantity > 100);

INSERT INTO products(id, name, price, quantity, category)
VALUES ('P0006', 'Es Campur', 20000, 100, 'Minuman'),
       ('P0007', 'Es Milo', 25000, 100, 'Minuman'),
       ('P0008', 'Es Susu', 25000, 100, 'Minuman');


SELECT *
FROM products
WHERE name ILIKE '%mie%';

SELECT *
FROM products
WHERE name ILIKE '%es%';

SELECT *
FROM products
WHERE description IS NOT NULL;

SELECT *
FROM products
WHERE price BETWEEN 10000 AND 20000;
SELECT *
FROM products
WHERE price NOT BETWEEN 10000 AND 20000;

SELECT *
FROM products
WHERE products.category IN ('Makanan', 'Minuman');

SELECT *
FROM products
ORDER BY id, price DESC;

SELECT *
FROM products
ORDER BY price DESC, id
LIMIT 2 OFFSET 2;

SELECT DISTINCT category
FROM products;

SELECT 10 + 10 AS hasil;

SELECT id, name, price / 1000 as price_in_k
FROM products;

SELECT pi();
SELECT power(10, 2);
SELECT cos(10), sin(10), tan(10);
SELECT id, name, power(quantity, 2) as quantity_power_2
FROM products;

CREATE TABLE admin
(
    id         SERIAL       NOT NULL,
    first_name VARCHAR(100) NOT NULL,
    last_name  VARCHAR(100),
    PRIMARY KEY (id)
);

INSERT INTO admin(first_name, last_name)
VALUES ('Eko', 'Khannedy'),
       ('Budi', 'Nugraha'),
       ('Joko', 'Morro');

SELECT *
FROM admin;

SELECT currval('admin_id_seq');

CREATE SEQUENCE contoh_sequence;

SELECT nextval('contoh_sequence');

SELECT currval('contoh_sequence');

-- melihat semua sequence
-- \ds

SELECT id, lower(name), length(name), lower(description)
FROM products;

SELECT id, extract(year FROM created_at), extract(month FROM created_at)
FROM products;

SELECT id,
       category,
       CASE category
           WHEN 'Makanan' THEN 'enak'
           WHEN 'Minuman' THEN 'seger'
           ELSE 'Apa itu?'
           END AS category_case
FROM products;

SELECT id,
       price,
       CASE
           WHEN price <= 15000 THEN 'Murah'
           WHEN price <= 20000 THEN 'Mahal'
           ELSE 'Mahal Banget'
           END AS "apakah murah?"
FROM products;

SELECT id,
       name,
       CASE
           WHEN description IS NULL THEN 'Kosong'
           ELSE description
           END AS description
FROM products;

SELECT count(id) AS "Total Product"
FROM products;
SELECT avg(price) AS "harga rata-rata"
FROM products;
SELECT max(price) AS "harga paling mahal"
FROM products;
SELECT min(price) AS "harga paling murah"
FROM products;

SELECT category, count(id) AS "Total Product"
FROM products
GROUP BY category
ORDER BY category;

SELECT category,
       avg(price) AS "Harga rata-rata",
       min(price) AS "Harga termurah",
       max(price) AS "Harga termahal"
FROM products
GROUP BY category
ORDER BY category;

SELECT category, count(id) AS "Total Product"
FROM products
GROUP BY category
HAVING count(id) > 3;

SELECT category,
       avg(price) AS "Harga rata-rata",
       min(price) AS "Harga termurah",
       max(price) AS "Harga termahal"
FROM products
GROUP BY category
HAVING avg(price) >= 22000
ORDER BY category;

CREATE TABLE customer
(
    id         SERIAL       NOT NULL,
    email      varchar(100) NOT NULL,
    first_name varchar(100) NOT NULL,
    last_name  varchar(100),
    PRIMARY KEY (id),
    CONSTRAINT unique_email UNIQUE (email)
);

INSERT INTO customer(email, first_name, last_name)
VALUES ('test@mail.com', 'Test', 'Lastname Test');

-- Will Error
INSERT INTO customer(email, first_name, last_name)
VALUES ('test@mail.com', 'Test Wrong', 'Lastname Test');

INSERT INTO customer(email, first_name, last_name)
VALUES ('budi@mail.com', 'Budi', 'Nugraha'),
       ('joko@mail.com', 'Joko', 'Morro'),
       ('rully@mail.com', 'Rully', 'Irwansayh');

SELECT *
FROM customer;

ALTER TABLE customer
    DROP CONSTRAINT unique_email;

ALTER TABLE customer
    ADD CONSTRAINT unique_email UNIQUE (email);

ALTER TABLE products
    ADD CONSTRAINT price_check CHECK ( price > 1000 );

ALTER TABLE products
    ADD CONSTRAINT quantity_check CHECK ( products.quantity >= 0 );

INSERT INTO products(id, name, description, price, quantity, category)
VALUES ('XXX1', 'contoh gagal', 'deskripsi', 0, 0, 'Minuman');

INSERT INTO products(id, name, description, price, quantity, category)
VALUES ('XXX1', 'contoh gagal', 'deskripsi', 10000, -2, 'Minuman');

CREATE TABLE sellers
(
    id    SERIAL       NOT NULL,
    name  varchar(100) NOT NULL,
    email varchar(100) NOT NULL,
    PRIMARY KEY (id),
    CONSTRAINT email_unique UNIQUE (email)
);

INSERT INTO sellers(name, email)
VALUES ('Galeri Olahraga', 'galeriO@mail.com'),
       ('Toko A', 'toko_a@mail.com'),
       ('Toko b', 'toko_b@mail.com'),
       ('Toko c', 'toko_c@mail.com'),
       ('Toko d', 'toko_d@mail.com');

CREATE INDEX selelrs_id_and_name_index ON sellers (id, name);
CREATE INDEX selelrs_email_and_name_index ON sellers (email, name);
CREATE INDEX selelrs_name_index ON sellers (name);

SELECT *
FROM sellers
WHERE id = 1;

SELECT *
FROM sellers
WHERE id = 1
   OR name = 'Toko A';

SELECT *
FROM sellers
WHERE email = 'toko_a@mail.com'
   OR name = 'Toko b';
SELECT *
FROM sellers
WHERE name = 'Toko d';

SELECT *
FROM products
WHERE name ILIKE '%mie%';

SELECT *
FROM products
WHERE to_tsvector(name) @@ to_tsquery('mie');

-- Create Index for fFll-Text Search
SELECT cfgname
FROM pg_ts_config;

CREATE INDEX products_name_search ON products USING gin (to_tsvector('indonesian', name));
CREATE INDEX description_name_search ON products USING gin (to_tsvector('indonesian', description));

SELECT *
FROM products
WHERE name @@ to_tsquery('''mie ayam yamin''');
SELECT *
FROM products
WHERE name @@ to_tsquery('mie & ayam | yamin');
SELECT *
FROM products
WHERE products.description @@ to_tsquery('mie');

CREATE TABLE wishlist
(
    id          SERIAL       NOT NULL,
    id_product  varchar(100) NOT NULL,
    description TEXT,

    Primary Key (id),
    CONSTRAINT fk_wishlist_product FOREIGN KEY (id_product) REFERENCES products (id)
);

INSERT INTO wishlist(id_product, description)
VALUES ('P0001', 'Mie Ayam Kesukaan'),
       ('P0002', 'Mie Ayam Kesukaan'),
       ('P0003', 'Mie Ayam Kesukaan');

SELECT *
FROM wishlist;

ALTER TABLE wishlist
    DROP CONSTRAINT fk_wishlist_product;

ALTER TABLE wishlist
    ADD CONSTRAINT fk_wishlist_product FOREIGN KEY (id_product) REFERENCES products (id)
        ON DELETE CASCADE ON UPDATE CASCADE;

INSERT INTO products(id, name, price, quantity, category)
VALUES ('xxx', 'xxx', 10000, 10, 'Minuman');

SELECT *
FROM products;

INSERT INTO wishlist(id_product, description)
VALUES ('xxx', 'contoh deskripsi');

SELECT *
FROM wishlist;
DELETE
FROM products
WHERE id = 'xxx';

SELECT *
FROM wishlist AS w
         JOIN products AS p on p.id = w.id_product;
SELECT p.id, p.name, w.description
FROM wishlist w
         JOIN products p on p.id = w.id_product;

ALTER TABLE wishlist
    ADD COLUMN id_customer INT;

ALTER TABLE wishlist
    ADD CONSTRAINT fk_wishlist_customer FOREIGN KEY (id_customer) REFERENCES customer (id);

UPDATE wishlist
SET id_customer = 1
WHERE id IN (2, 3);

UPDATE wishlist
SET id_customer = 3
WHERE id IN (4);

SELECT *
FROM customer;
SELECT *
FROM wishlist;

SELECT c.email, p.id, p.name, w.description
FROM wishlist w
         JOIN products p on p.id = w.id_product
         JOIN customer c ON c.id = w.id_customer;

CREATE TABLE wallet
(
    id          SERIAL NOT NULL,
    id_customer INT    NOT NULL,
    balance     INT    NOT NULL DEFAULT 0,
    PRIMARY KEY (id),
    CONSTRAINT wallet_customer_unique UNIQUE (id_customer),
    CONSTRAINT fk_wallet_customer FOREIGN KEY (id_customer) REFERENCES customer (id)
);
SELECT *
FROM customer;
INSERT INTO wallet(id_customer, balance)
VALUES (1, 1000000),
       (3, 2000000),
       (4, 3000000),
       (5, 5000000);

SELECT *
FROM wallet;

SELECT *
FROM customer c
         JOIN wallet w on c.id = w.id_customer;

CREATE TABLE categories
(
    id   varchar(100) NOT NULL,
    name varchar(100) NOT NULL,
    PRIMARY KEY (id)
);

INSERT INTO categories(id, name)
VALUES ('C0001', 'Makanan'),
       ('C0002', 'Minuman');

SELECT *
FROM categories;

ALTER TABLE products
    ADD COLUMN id_category varchar(100);

ALTER TABLE products
    ADD CONSTRAINT fk_products_category FOREIGN KEY (id_category) REFERENCES categories (id);

SELECT *
FROM products;

UPDATE products
SET id_category = 'C0001'
WHERE products.category = 'Makanan';

UPDATE products
SET id_category = 'C0002'
WHERE products.category = 'Minuman';

ALTER TABLE products
    DROP COLUMN category;

SELECT *
FROM products p
         JOIN categories c on p.id_category = c.id;

CREATE TABLE orders
(
    id         SERIAL    NOT NULL,
    total      INT       NOT NULL,
    order_date timestamp NOT NULL DEFAULT current_timestamp,
    PRIMARY KEY (id)
);

CREATE TABLE orders_detail
(
    id_products varchar(100) NOT NULL,
    id_order    INT          NOT NULL,
    price       INT          NOT NULl,
    quantity    INT          NOT NULL,
    PRIMARY KEY (id_products, id_order)
);

ALTER TABLE orders_detail
    ADD CONSTRAINT fk_order_detail_products FOREIGN KEY (id_products) REFERENCES products (id);

ALTER TABLE orders_detail
    ADD CONSTRAINT fk_order_detail_order FOREIGN KEY (id_order) REFERENCES orders (id);

INSERT INTO orders(total)
VALUES (1),
       (1),
       (1);

SELECT *
FROM orders;
SELECT *
FROM products
ORDER BY id;

INSERT INTO orders_detail(id_products, id_order, price, quantity)
VALUES ('P0001', 1, 1000, 2),
       ('P0002', 1, 1000, 2),
       ('P0003', 1, 1000, 2);

INSERT INTO orders_detail(id_products, id_order, price, quantity)
VALUES ('P0004', 2, 1000, 2),
       ('P0005', 2, 1000, 2),
       ('P0006', 2, 1000, 2);

INSERT INTO orders_detail(id_products, id_order, price, quantity)
VALUES ('P0001', 3, 1000, 2),
       ('P0007', 3, 1000, 2),
       ('P0008', 3, 1000, 2);

SELECT *
FROM orders_detail;
SELECT *
FROM orders;

SELECT *
FROM orders o
         JOIN orders_detail od ON od.id_order = o.id
         JOIN products p ON od.id_products = p.id
WHERE o.id = 1;

INSERT INTO categories(id, name)
VALUES ('C0003', 'gadget'),
       ('C0004', 'Laptop'),
       ('C0005', 'Pulsa');

SELECT *
FROM categories;
SELECT *
FROM products;

INSERT INTO products(id, name, price, quantity)
VALUES ('X00001', 'contoh 1', 10000, 100),
       ('X00002', 'contoh 2', 10000, 100);

SELECT *
FROM categories c
         INNER JOIN products p on c.id = p.id_category;

SELECT *
FROM categories c
         LEFT JOIN products p on c.id = p.id_category;

SELECT *
FROM categories c
         RIGHT JOIN products p on c.id = p.id_category;

SELECT *
FROM categories c
         FULL JOIN products p on c.id = p.id_category;

SELECT avg(price)
FROM products;
SELECT *
FROM products
WHERE price > (SELECT avg(price) FROM products);

SELECT *
FROM products;

SELECT max(price)
FROM (SELECT p.price as price
      FROM categories
               JOIN products p on categories.id = p.id_category) AS contoh;

CREATE TABLE guest_books
(
    id      SERIAL       NOT NULL,
    email   varchar(100) NOT NULL,
    title   varchar(100) NOT NULL,
    content text,
    primary key (id)
);

SELECT *
FROM customer;
INSERT INTO customer(email, first_name, last_name)
VALUES ('joko2@mail.com', 'Joko', 'Marro');

INSERT INTO guest_books(email, title, content)
VALUES ('test@mail.com', 'test title', 'ini conoth content test'),
       ('test@mail.com', 'test title', 'ini conoth content test'),
       ('budi@mail.com', 'test budi', 'ini conoth content budi'),
       ('joko@mail.com', 'test joko', 'ini conoth content joko'),
       ('rully@mail.com', 'test rully', 'ini conoth content rully'),
       ('notregist@mail.com', 'test notregist', 'ini conoth content notregist');

SELECT *
FROM guest_books;

SELECT DISTINCT email
FROM customer
UNION
SELECT DISTINCT email
FROM guest_books;

SELECT email
FROM customer
UNION ALL
SELECT email
FROM guest_books;

SELECT email, count(email)
FROM (SELECT email
      FROM customer
      UNION ALL
      SELECT email
      FROM guest_books) AS contoh
GROUP BY email;

SELECT email
FROM customer
INTERSECT
SELECT email
FROM guest_books;

SELECT email
FROM customer
EXCEPT
SELECT email
FROM guest_books;

START TRANSACTION;
INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'transaction');

INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'transaction 1');

INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'transaction 2');

INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'transaction 3');

SELECT *
FROM guest_books;

COMMIT;

START TRANSACTION;
INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'rollback');

INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'rollback 1');

INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'rollback 2');

INSERT INTO guest_books(email, title, content)
VALUES ('transaction@mail.com', 'transaction', 'rollback 3');

SELECT *
FROM guest_books;

ROLLBACK;

SELECT *
FROM products;

START TRANSACTION;
UPDATE products
SET description='Mie Ayam Original Enak'
WHERE id = 'P0001';

SELECT *
FROM products
WHERE id = 'P0001';
COMMIT;

START TRANSACTION;

SELECT * FROM products WHERE id = 'P0001' FOR UPDATE;
ROLLBACK ;

SELECT current_schema();

-- Create New schema
CREATE SCHEMA contoh;
SET SEARCH_PATH TO contoh;
SELECT current_schema();
SELECT * FROM public.products;
DROP SCHEMA contoh;

SET SEARCH_PATH TO public;
-- User Management
CREATE ROLE budi;

ALTER ROLE budi LOGIN PASSWORD 'password';

GRANT INSERT, UPDATE, SELECT ON ALL TABLES IN SCHEMA public TO budi;
GRANT USAGE, UPDATE, SELECT ON guest_books_id_seq TO budi;

DROP ROLE budi;

-- Perintah sump SQl
-- pg_dump --host=localhost --port=5432 --dbname=belajar --username=postgres --format=plain --file=/Users/dump/dump.sql

-- Restore Database
-- psql --host=localhost --port=5432 --dbname=belajar_restore --username=postgres --file=/Users/dump/dump.sql
-- SELECT DROP Database belajar;
