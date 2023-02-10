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

CREATE TABLE category (
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

-- Notification Read

CREATE TABLE notification_read (
    id INT NOT NULL AUTO_INCREMENT,
    is_read BOOLEAN NOT NULL,
    notification_id INT NOT NULL,
    user_id VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
);

ALTER TABLE notification_read
ADD CONSTRAINT fk_notification_read
FOREIGN KEY (notification_id) REFERENCES notification(id);

ALTER TABLE notification_read
ADD CONSTRAINT fk_notification_read_user
FOREIGN KEY (user_id) REFERENCES user(id);

DESC notification_read;

INSERT INTO notification_read(is_read, notification_id, user_id)
VALUES (true, 2, 'tobi');
INSERT INTO notification_read(is_read, notification_id, user_id)
VALUES (true, 2, 'tobi2');

SELECT * FROM notification_read;

SELECT *
from notification n
    JOIN category c ON (n.category_id = c.id)
    LEFT JOIN notification_read nr ON (nr.notification_id = n.id)
WHERE (
        n.user_id = 'tobi'
        OR n.user_id IS NULL
    )
    AND (
        nr.user_id = 'tobi'
        OR nr.user_id IS NULL
    )
ORDER BY n.created_at DESC;

INSERT INTO notification(title, detail, created_at, user_id, category_id)
VALUES ('Contoh Pesanan Lagi', 'Detail Pesanan Lagi', CURRENT_TIMESTAMP(), 'tobi', 'INFO');

INSERT INTO notification(title, detail, created_at, user_id, category_id)
VALUES ('Contoh Promo Lagi', 'Detail Promo Lagi', CURRENT_TIMESTAMP(), NULL, 'PROMO');

-- COUNTER

SELECT COUNT(*)
from notification n
    JOIN category c ON (n.category_id = c.id)
    LEFT JOIN notification_read nr ON (nr.notification_id = n.id)
WHERE (
        n.user_id = 'tobi'
        OR n.user_id IS NULL
    )
    AND (
        nr.user_id IS NULL
    )
ORDER BY n.created_at DESC;

SELECT * FROM notification;

INSERT INTO notification_read(is_read, notification_id, user_id)
VALUES (true, 6, 'tobi');
INSERT INTO notification_read(is_read, notification_id, user_id)
VALUES (true, 7, 'tobi');
INSERT INTO notification_read(is_read, notification_id, user_id)
VALUES (true, 1, 'tobi');
