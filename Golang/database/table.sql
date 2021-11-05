CREATE TABLE customer
(
  id VARCHAR(100) NOT NULL,
  name VARCHAR(100) NOT NULL,
  PRIMARY KEY (id)
)ENGINE = InnoDB;

DELETE * FROM customer;
DROP TABLE customer;

ALTER TABLE customer
  ADD COLUMN email VARCHAR(100),
  ADD COLUMN balance INT DEFAULT 0,
  ADD COLUMN rating DOUBLE DEFAULT 0.0,
  ADD COLUMN created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  ADD COLUMN birth_date DATE,
  ADD COLUMN married BOOLEAN DEFAULT false;

INSERT INTO customer(id, name, email, balance, rating, birth_date, married) 
		VALUES('eko', 'Eko', 'eko@gmail.com', 100000, 5.0, '2000-9-9', true),
		('budi', 'Budi', 'budi@gmail.com', 100000, 5.0, '2000-9-9', true),
		('joko', 'Joko', 'joko@gmail.com', 100000, 5.0, '2000-9-9', true);

UPDATE customer
SET email = NULL,
    birth_date = NULL
WHERE id = 'joko';

CREATE TABLE user
(
  username VARCHAR(100) NOT NULL,
  password VARCHAR(100) NOT NULL,
  PRIMARY KEY (username)
)ENGINE = InnoDB;

INSERT INTO user(username, password) VALUES ('admin', 'admin');

CREATE TABLE comments(
  id INT NOT NULL AUTO_INCREMENT,
  email VARCHAR(100) NOT NULL,
  comment TEXT,
  PRIMARY KEY(id)
) ENGINE="InnoDB";

select * from comments;