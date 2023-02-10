CREATE DATABASE belajar_mysql_notification;

USE belajar_mysql_notification;
SHOW TABLES;

-- USER

CREATE TABLE user(
    id VARCHAR(100) NOT NULL,
    name VARCHAR(100) NOT NULL,

    PRIMARY KEY (id)
);

INSERT INTO user(id, name) VALUES ("tobi", "tobi albertino");
INSERT INTO user(id, name) VALUES ("tobi2", "tobi albertino2");
SELECT * FROM user ORDER BY id;

CREATE TABLE notification(
    id INT NOT NULL AUTO_INCREMENT,
    title VARCHAR(255) NOT NULL,
    detail TEXT NOT NULL,
    created_at TIMESTAMP NOT NULL,
    user_id VARCHAR(100),

    PRIMARY KEY (id)
);
DESCRIBE notification;

INSERT INTO notification(title, detail, created_at, user_id)
VALUES ('Contoh Pesanan', 'Detail Pesanan', CURRENT_TIMESTAMP(), 'tobi');
INSERT INTO notification(title, detail, created_at, user_id)
VALUES ('Contoh Promo', 'Detail Promo', CURRENT_TIMESTAMP(), NULL);
INSERT INTO notification(title, detail, created_at, user_id)
VALUES ('Contoh Pembayaran', 'Detail Pembayaran', CURRENT_TIMESTAMP(), 'tobi2');

SELECT * FROM notification;
SELECT *
FROM notification
WHERE (
        user_id = 'tobi'
        OR user_id IS NULL
    )
ORDER BY created_at DESC;

SELECT *
FROM notification
WHERE (
        user_id = 'tobi2'
        OR user_id IS NULL
    )
ORDER BY created_at DESC;

-- Category

CREATE TABLE category(
    id VARCHAR(100) NOT NULL,
    name VARCHAR(100) NOT NULL,

    PRIMARY KEY (id)
);
SHOW TABLES;

ALTER TABLE notification
ADD COLUMN category_id VARCHAR(100);

DESCRIBE notification;

ALTER TABLE notification
ADD CONSTRAINT fk_notification_category
FOREIGN KEY (category_id) REFERENCES category(id);

DESC notification;

INSERT INTO category(id, name) VALUES ('INFO', 'Info');
INSERT INTO category(id, name) VALUES ('PROMO', 'Promo');

SELECT * FROM category;

UPDATE notification SET category_id = 'INFO'
WHERE id = 1;
UPDATE notification SET category_id = 'PROMO'
WHERE id = 2;
UPDATE notification SET category_id = 'INFO'
WHERE id = 3;

SELECT *
FROM notification
WHERE (
        user_id = 'tobi2'
        OR user_id IS NULL
    )
ORDER BY created_at DESC;

SELECT *
from notification n
    JOIN category c ON (n.category_id = c.id)
WHERE (
        n.user_id = 'tobi'
        OR n.user_id IS NULL
    )
ORDER BY n.created_at DESC;

SELECT *
from notification n
    JOIN category c ON (n.category_id = c.id)
WHERE (
        n.user_id = 'tobi2'
        OR n.user_id IS NULL
    )
    AND c.id = 'INFO'
ORDER BY n.created_at DESC;