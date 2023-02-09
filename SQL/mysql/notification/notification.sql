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