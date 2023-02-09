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